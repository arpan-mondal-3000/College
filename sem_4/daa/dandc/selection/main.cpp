#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

int choosePivot(vector<int> arr, int p, int r);
int partition(vector<int> &arr, int p, int r, int piv);
int select(vector<int> arr, int p, int r, int k);

int choosePivot(vector<int> arr, int p, int r)
{
    // Divide the array into groups of 5 and find local median
    vector<int> local_medians;
    for (int i = p; i < r; i += 5)
    {
        vector<int> grp;
        int j = i;
        while (j - i < 5 && j < r)
        {
            grp.emplace_back(arr[j]);
            j++;
        }
        sort(grp.begin(), grp.end());
        local_medians.emplace_back(grp[grp.size() / 2]);
    }

    // Find median of local medians using select algo
    int pivot = select(local_medians, 0, local_medians.size() - 1, (local_medians.size() / 2) + 1);

    // return the index of the pivot element
    for (int i = p; i < r; i++)
    {
        if (arr[i] == pivot)
            return i;
    }
    return -1;
}

int partition(vector<int> &arr, int p, int r, int piv)
{
    swap(arr[piv], arr[r - 1]);
    int x = arr[r - 1];
    int i = p;

    for (int j = p; j < r - 1; j++)
    {
        if (arr[j] < x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[r - 1]);
    return i;
}

int select(vector<int> arr, int p, int r, int k)
{
    // base case
    if (p == r)
        return arr[p];
    int x = choosePivot(arr, p, r);
    int q = partition(arr, p, r, x);
    int xRank = q - p + 1;
    // kth rank element found
    if (xRank == k)
        return arr[q];
    else if (xRank > k) // search left partition
        return select(arr, p, q - 1, k);
    else // search right partition
        return select(arr, q + 1, r, k - xRank);
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 5000);

    int n;
    cout << "Enter n: ";
    cin >> n;
    // Generating a random array of size n
    vector<int> arr;
    for (int i = 0; i < n; i++)
        arr.emplace_back(distrib(gen));

    cout << "Generated array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    int k;
    cout << "Enter k: ";
    cin >> k;
    if (k >= n || k < 0)
    {
        cout << "Provide a valid k value!" << endl;
        return 1;
    }
    int k_smallest = select(arr, 0, arr.size() - 1, k);
    cout << k << "th smallest element is: " << k_smallest << endl;

    return 0;
}