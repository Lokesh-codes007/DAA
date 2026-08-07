#include <iostream>	
using namespace std;
int main() {
 int n, key;
cout << "Enter size of array: ";
 cin >> n;
  int arr[n];
 cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
cout << "Enter element to search: ";
cin >> key;
int low = 0, high = n - 1;
 int index = -1;
  while (low <= high) {
        int mid = (low + high) / 2;
  if (arr[mid] == key) {
        index = mid;   break;
 }
    else if (arr[mid] < key) {
       low = mid + 1;
        }
    else {
      high = mid - 1;
        }
    }
 if (index != -1)
        cout << "Element found at index: " << index;
    else
        cout << "Element not found";
 return 0;
}
