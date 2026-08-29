#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    cout << "\nFrequency of each element:\n";

    for (auto x : freq)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    return 0;
}