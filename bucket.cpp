#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(float a[], int n)
{
    vector<float> bucket[n];

    for (int i = 0; i < n; i++)
    {
        int index = n * a[i];
        bucket[index].push_back(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            a[k] = bucket[i][j];
            k++;
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    float a[100];

    cout << "Enter array elements between 0 and 1: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bucketSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}