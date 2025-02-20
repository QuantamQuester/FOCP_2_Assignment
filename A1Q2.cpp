//Array Operations

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    reverse(arr, arr + n);
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    sort(arr, arr + n);
    int secondSmallest = (n > 1 && arr[0] != arr[1]) ? arr[1] : -1;
    int secondLargest = (n > 1 && arr[n-1] != arr[n-2]) ? arr[n-2] : -1;
    
    cout << "Second smallest: " << (secondSmallest == -1 ? "Not found" : to_string(secondSmallest)) << endl;
    cout << "Second largest: " << (secondLargest == -1 ? "Not found" : to_string(secondLargest)) << endl;
    
    return 0;
}
