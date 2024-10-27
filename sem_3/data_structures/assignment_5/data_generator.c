#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
   // Taking argument from command line
   if (argc != 3)
   {
      printf("Only put the number of points and range!");
      return 1;
   }
   int n = atoi(argv[1]);
   int range = atoi(argv[2]);

   // Writing random points to data.txt file
   FILE *fp;
   fp = fopen("./data.txt", "w");
   // Seeding the random funciton with time
   srand(time(NULL));

   fprintf(fp, "%d %d\n", n, range);
   for (int i = 0; i < n; i++)
   {
      fprintf(fp, "%d %d\n", rand() % range, rand() % range);
   }
   fclose(fp);
   printf("Written %d random points in the data.txt\n", n);
   return 0;
}