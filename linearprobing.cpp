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

        while (hashTable[index] != -1)
        {
            index = (index + 1) % SIZE;
        }

        hashTable[index] = key;
    }

    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " -> " << hashTable[i] << endl;
    }

    return 0;
}