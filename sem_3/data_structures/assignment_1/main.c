#include <stdio.h>
#include <stdlib.h>

int findMajorityElem(int a[], int n)
{
   // Finding the maximum element in the array
   int max = a[0];
   for (int i = 0; i < n; i++)
      if (a[i] >= max)
         max = a[i];
   // Using a new array as a hashmap using the original array elements as key(here index of array) and their number of occurrences as value
   int *arr = (int *)calloc(max + 1, sizeof(int));

   // Calculating number of occurrences of each element and storing it as key value pairs in arr
   for (int i = 0; i < n; i++)
      arr[a[i]]++;

   // If there is an element whose occurrence is greater than half the length of the array then it is returned otherwise -1 is returned
   for (int i = 0; i < n; i++)
   {
      if (arr[a[i]] > n / 2)
      {
         free(arr);
         return a[i];
      }
   }

   free(arr);
   return -1;
}

int main()
{
   int a[8] = {2, 1, 2, 2, 6, 2, 2, 6};       // Input array
   int n = sizeof(a) / sizeof(a[0]);          // Calculating length of array
   int majorityElem = findMajorityElem(a, n); // Finding the majority element
   majorityElem >= 0 ? printf("The majority element is: %d", majorityElem) : printf("There is no majority element");
   // Priting the majority element if there is any otherwise printing There is no majority element
   return 0;
}