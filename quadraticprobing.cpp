#include <iostream>
using namespace std;

#define SIZE 10

int main()
{
    int hashTable[SIZE];

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;

        int index = key % SIZE;
        int j = 0;

        while (hashTable[(index + j * j) % SIZE] != -1)
        {
            j++;
        }

        hashTable[(index + j * j) % SIZE] = key;
    }

    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " -> " << hashTable[i] << endl;
    }

    return 0;
}