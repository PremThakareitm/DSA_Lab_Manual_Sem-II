// Implement Bubble sort algorithm to sort elements of an array in ascending and descending order.

#include <iostream>
using namespace std;

void bubbleSortAscending(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortDescending(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
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
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    bubbleSortAscending(arr, n);
    cout << "Array elements in ascending order: ";
    displayArray(arr, n);

    bubbleSortDescending(arr, n);
    cout << "Array elements in descending order: ";
    displayArray(arr, n);

    return 0;
}
