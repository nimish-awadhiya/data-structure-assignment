#include <iostream>
using namespace std;

template <typename T>
long long getAddress(T* base, int i, int j, int rows, int cols, bool rowMajor) {
    if (rowMajor) {
        return (long long)(base + (i * cols + j));
    } else {
        return (long long)(base + (j * rows + i));
    }
}

int main() {
    int rows, cols;
    char type;
    cout << "Enter type of array (i for int, f for float, c for char): ";
    cin >> type;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    if (type == 'i') {
        int arr[rows][cols];
        cout << "Enter base address: ";
        long long baseAddr;
        cin >> baseAddr;

        cout << "Enter the indices i and j: ";
        int i, j;
        cin >> i >> j;

        bool rowMajor;
        cout << "Enter memory arrangement (1 for row-major, 0 for column-major): ";
        cin >> rowMajor;

        long long address = getAddress((int*)arr, i, j, rows, cols, rowMajor);
        cout << "Address of arr[" << i << "][" << j << "]: " << address << endl;
    } else if (type == 'f') {
        float arr[rows][cols];
        cout << "Enter base address: ";
        long long baseAddr;
        cin >> baseAddr;

        cout << "Enter the indices i and j: ";
        int i, j;
        cin >> i >> j;

        bool rowMajor;
        cout << "Enter memory arrangement (1 for row-major, 0 for column-major): ";
        cin >> rowMajor;

        long long address = getAddress((float*)arr, i, j, rows, cols, rowMajor);
        cout << "Address of arr[" << i << "][" << j << "]: " << address << endl;
    } else if (type == 'c') {
        char arr[rows][cols];
        cout << "Enter base address: ";
        long long baseAddr;
        cin >> baseAddr;

        cout << "Enter the indices i and j: ";
        int i, j;
        cin >> i >> j;

        bool rowMajor;
        cout << "Enter memory arrangement (1 for row-major, 0 for column-major): ";
        cin >> rowMajor;

        long long address = getAddress((char*)arr, i, j, rows, cols, rowMajor);
        cout << "Address of arr[" << i << "][" << j << "]: " << address << endl;
    }

    return 0;
}
