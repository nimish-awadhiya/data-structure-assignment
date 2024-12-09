#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
long long getAddress(T* base, int i, int j, int k, int rows, int cols, int depth, bool rowMajor) {
    if (rowMajor) {
        // Row-major order
        return (long long)(base + (i * cols * depth + j * depth + k));
    } else {
        // Column-major order
        return (long long)(base + (k * rows * cols + j * rows + i));
    }
}

int main() {
    int rows, cols, depth;
    char type;
    
    // Taking type of array as input (int, float, char)
    cout << "Enter type of array (i for int, f for float, c for char): ";
    cin >> type;

    // Taking dimensions of the 3D array
    cout << "Enter number of rows, columns, and depth: ";
    cin >> rows >> cols >> depth;

    if (type == 'i') {
        int arr[rows][cols][depth];
        cout << "Enter base address: ";
        long long baseAddr;
        cin >> baseAddr;

        cout << "Enter the indices i, j, k: ";
        int i, j, k;
        cin >> i >> j >> k;

        bool rowMajor;
        cout << "Enter memory arrangement (1 for row-major, 0 for column-major): ";
        cin >> rowMajor;

        long long address = getAddress((int*)arr, i, j, k, rows, cols, depth, rowMajor);
        cout << "Address of arr[" << i << "][" << j << "][" << k << "]: " << address << endl;
    } else if (type == 'f') {
        float arr[rows][cols][depth];
        cout << "Enter base address: ";
        long long baseAddr;
        cin >> baseAddr;

        cout << "Enter the indices i, j, k: ";
        int i, j, k;
        cin >> i >> j >> k;

        bool rowMajor;
        cout << "Enter memory arrangement (1 for row-major, 0 for column-major): ";
        cin >> rowMajor;

        long long address = getAddress((float*)arr, i, j, k, rows, cols, depth, rowMajor);
        cout << "Address of arr[" << i << "][" << j << "][" << k << "]: " << address << endl;
    } else if (type == 'c') {
        char arr[rows][cols][depth];
        cout << "Enter base address: ";
        long long baseAddr;
        cin >> baseAddr;

        cout << "Enter the indices i, j, k: ";
        int i, j, k;
        cin >> i >> j >> k;

        bool rowMajor;
        cout << "Enter memory arrangement (1 for row-major, 0 for column-major): ";
        cin >> rowMajor;

        long long address = getAddress((char*)arr, i, j, k, rows, cols, depth, rowMajor);
        cout << "Address of arr[" << i << "][" << j << "][" << k << "]: " << address << endl;
    }

    return 0;
}
