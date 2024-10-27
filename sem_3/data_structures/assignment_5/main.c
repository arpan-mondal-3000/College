#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int k = 5;
int error_margin = 0;

typedef struct point
{
   float x;
   float y;
   int cluster_id;
} point;

int find_cluster_id(point p, point *clusters)
{
   float min_dist = 1000;
   int cluster_id = 0;
   for (int i = 0; i < k; i++)
   {
      float curr_dist = sqrt(((p.x - clusters[i].x) * (p.x - clusters[i].x)) + ((p.y - clusters[i].y) * (p.y - clusters[i].y)));
      if (curr_dist < min_dist)
      {
         cluster_id = clusters[i].cluster_id;
         min_dist = curr_dist;
      }
   }
   return cluster_id;
}

void find_new_cluster_center(point *points, point *clusters, int n)
{
   for (int i = 0; i < k; i++)
   {
      float total_x = 0;
      float total_y = 0;
      int c = 0;
      for (int j = 0; j < n; j++)
      {
         if (points[j].cluster_id == i)
         {
            total_x += points[j].x;
            total_y += points[j].y;
            c++;
         }
      }
      clusters[i].x = total_x / c;
      clusters[i].y = total_y / c;
   }
}

void clusterize(point *points, point *clusters, int n)
{
   while (1)
   {
      int change_count = 0;
      for (int i = 0; i < n; i++)
      {
         int prev_cluster_id = points[i].cluster_id;
         points[i].cluster_id = find_cluster_id(points[i], clusters);
         if (prev_cluster_id != points[i].cluster_id)
            change_count++;
      }
      if (change_count <= error_margin)
         break;
      find_new_cluster_center(points, clusters, n);
   }
}

int main()
{
   FILE *fpr, *fpw;
   fpr = fopen("./data.txt", "r");
   fpw = fopen("./result.txt", "w");
   srand(time(NULL));
   if (fpr == NULL)
   {
      printf("File cannot be read.\n");
      return 1;
   }
   int n;

   // Input from the data.txt file
   fscanf(fpr, "%d", &n);
   point *points = (point *)malloc(n * sizeof(point));
   point *clusters = (point *)malloc(k * sizeof(point));

   for (int i = 0; i < n; i++)
   {
      fscanf(fpr, "%f %f", &points[i].x, &points[i].y);
      points[i].cluster_id = rand() % k;
   }

   // Randomly generate k clusters
   for (int i = 0; i < k; i++)
   {
      clusters[i].x = rand() % 100;
      clusters[i].y = rand() % 100;
      clusters[i].cluster_id = i;
   }

   // Clusterize the points
   clusterize(points, clusters, n);

   // output to the result.txt file
   fprintf(fpw, "%d %d\n", n, k);
   for (int i = 0; i < n; i++)
   {
      fprintf(fpw, "%.2f %.2f %d\n", points[i].x, points[i].y, points[i].cluster_id);
   }

   fclose(fpr);
   fclose(fpw);
   free(points);
   free(clusters);
   printf("Clusterized %d points\n", n);
   return 0;
}