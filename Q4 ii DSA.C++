#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int &comparisons, int &swaps) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;  // Increment comparison
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;  // Increment swap
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int comparisons = 0, swaps = 0;
    insertionSort(arr, n, comparisons, swaps);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nComparisons: " << comparisons << ", Swaps: " << swaps << endl;

    return 0;
}
