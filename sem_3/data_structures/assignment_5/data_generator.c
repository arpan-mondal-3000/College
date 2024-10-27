#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
   // Taking argument from command line
   if (argc != 2)
   {
      printf("Only put the number of points required!");
      return 1;
   }
   int n = atoi(argv[1]);

   // Writing random points to data.txt file
   FILE *fp;
   fp = fopen("./data.txt", "w");
   // Seeding the random funciton with time
   srand(time(NULL));

   fprintf(fp, "%d\n", n);
   for (int i = 0; i < n; i++)
   {
      fprintf(fp, "%d %d\n", rand() % 100, rand() % 100);
   }
   fclose(fp);
   printf("Written %d random points in the data.txt\n", n);
   return 0;
}