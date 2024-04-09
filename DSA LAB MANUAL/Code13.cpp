// Implement Binary Search algorithm to search an element in an array.

#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

void displayArray(int arr[], int n)
{
    cout << "Array elements: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the sorted elements of the array: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    displayArray(arr, n);

    int target;
    cout << "Enter the element to search for: ";
    cin >> target;

    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1)
        cout << "Element not present in the array";
    else
        cout << "Element found at index " << result;
    return 0;
}
