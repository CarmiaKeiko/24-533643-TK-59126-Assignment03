// Compilation command: g++ -std=c++17 -Wall -Wextra problem3.cpp -o problem3
// Run command: ./problem3

#include <iostream>

using namespace std;

// 1. Linear Search
// Mengembalikan indeks elemen jika ditemukan, atau -1 jika tidak ditemukan.
int linearSearch(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Ditemukan
        }
    }
    return -1; // Tidak ditemukan
}

// 2. Binary Search (Hanya bekerja pada array yang sudah terurut)
// Mengembalikan indeks elemen jika ditemukan, atau -1 jika tidak ditemukan.
int binarySearch(int *arr, int n, int target)
{
    int lo = 0;
    int hi = n - 1;

    while (lo <= hi)
    {
        // Menggunakan rumus ini untuk mencegah integer overflow
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target)
        {
            return mid; // Ditemukan di tengah
        }
        else if (arr[mid] < target)
        {
            lo = mid + 1; // Cari di setengah kanan
        }
        else
        {
            hi = mid - 1; // Cari di setengah kiri
        }
    }
    return -1; // Tidak ditemukan
}

// 3. Generate Sorted Array
// Membuat array terurut berisi bilangan genap {0, 2, 4, ..., 2(n-1)}
int *generateSortedArray(int n)
{
    int *arr = new int[n]; // Alokasi memori dinamis di heap
    for (int i = 0; i < n; i++)
    {
        arr[i] = i * 2;
    }
    return arr;
}

int main()
{
    // Demonstrasi pada array dengan ukuran n = 10, 100, 1000
    int sizes[] = {10, 100, 1000};

    for (int n : sizes)
    {
        cout << "========================================\n";
        cout << "Testing with array size n = " << n << "\n";

        // Buat array terurut
        int *arr = generateSortedArray(n);

        // Kasus 1: Mencari nilai yang ADA (elemen di titik tengah)
        int targetExists = arr[n / 2];
        cout << "\n[Case 1] Searching for EXISTING target: " << targetExists << "\n";

        int linIndex1 = linearSearch(arr, n, targetExists);
        int binIndex1 = binarySearch(arr, n, targetExists);

        cout << "Linear Search returned index : " << linIndex1 << "\n";
        cout << "Binary Search returned index : " << binIndex1 << "\n";

        if (linIndex1 == binIndex1)
        {
            cout << "-> SUCCESS: Both algorithms agree!\n";
        }
        else
        {
            cout << "-> ERROR: Algorithms returned different indices!\n";
        }

        // Kasus 2: Mencari nilai yang TIDAK ADA
        // Karena array isinya genap non-negatif, kita cari angka ganjil (misal: 3)
        int targetMissing = 3;
        cout << "\n[Case 2] Searching for MISSING target: " << targetMissing << "\n";

        int linIndex2 = linearSearch(arr, n, targetMissing);
        int binIndex2 = binarySearch(arr, n, targetMissing);

        cout << "Linear Search returned index : " << linIndex2 << "\n";
        cout << "Binary Search returned index : " << binIndex2 << "\n";

        if (linIndex2 == binIndex2)
        {
            cout << "-> SUCCESS: Both algorithms agree!\n";
        }
        else
        {
            cout << "-> ERROR: Algorithms returned different indices!\n";
        }

        // Membebaskan memori yang dialokasikan oleh generateSortedArray
        delete[] arr;
        arr = nullptr;
    }

    cout << "========================================\n";
    return 0;
}