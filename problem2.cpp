// Compilation command: g++ -std=c++17 -Wall -Wextra problem2.cpp -o problem2
// Run command: ./problem2

#include <iostream>

using namespace std;

struct DynArray
{
    int *data;    // pointer to heap-allocated buffer
    int size;     // number of elements in use
    int capacity; // total allocated slots
};

// Fungsi internal (helper) untuk memperbesar kapasitas memori
// O(n)
void growArray(DynArray &a)
{
    int newCap = a.capacity * 2;
    int *newData = new int[newCap];

    // Salin data lama ke tempat baru
    for (int i = 0; i < a.size; i++)
    {
        newData[i] = a.data[i];
    }

    // Membebaskan memori lama untuk mencegah memory leak
    delete[] a.data;
    a.data = newData;
    a.capacity = newCap;
}

// 1. Inisialisasi kapasitas = 2, size = 0, alokasikan memori heap
// O(1)
void initArray(DynArray &a)
{
    a.capacity = 2;
    a.size = 0;
    a.data = new int[a.capacity];
}

// 2. Bebaskan memori dan reset ukuran
// O(1)
void freeArray(DynArray &a)
{
    delete[] a.data;
    a.data = nullptr; // Mencegah dangling pointer
    a.size = 0;
    a.capacity = 0;
}

// 3. Tambah elemen ke belakang, resize jika penuh
// Amortized O(1)
void pushBack(DynArray &a, int value)
{
    if (a.size == a.capacity)
    {
        growArray(a);
    }
    a.data[a.size++] = value;
}

// 4. Sisipkan elemen di posisi tertentu (index)
// O(n)
void insertAt(DynArray &a, int index, int value)
{
    if (index < 0 || index > a.size)
        return; // Asumsi index valid

    if (a.size == a.capacity)
    {
        growArray(a);
    }

    // Geser elemen dari kanan ke kiri (mulai dari belakang)
    // agar data tidak saling tertimpa (overwrite).
    for (int i = a.size; i > index; i--)
    {
        a.data[i] = a.data[i - 1];
    }

    a.data[index] = value;
    a.size++;
}

// 5. Hapus elemen di posisi tertentu (index)
// O(n)
void removeAt(DynArray &a, int index)
{
    if (index < 0 || index >= a.size)
        return; // Asumsi index valid

    // Geser elemen dari kiri ke kanan untuk menutupi elemen yang dihapus
    for (int i = index; i < a.size - 1; i++)
    {
        a.data[i] = a.data[i + 1];
    }
    a.size--;
}

// 6. Ambil nilai di index tertentu
// O(1)
int getAt(const DynArray &a, int index)
{
    return a.data[index];
}

// 7. Ubah nilai di index tertentu
// O(1)
void setAt(DynArray &a, int index, int value)
{
    a.data[index] = value;
}

// 8. Cetak isi array sesuai format yang diminta
// O(n)
void printDynArr(const DynArray &a)
{
    cout << "[";
    for (int i = 0; i < a.size; i++)
    {
        cout << a.data[i];
        if (i < a.size - 1)
        {
            cout << ", ";
        }
    }
    cout << "] (size=" << a.size << ", cap=" << a.capacity << ")\n";
}

int main()
{
    DynArray arr;
    initArray(arr);

    // 1. pushBack until a resize is triggered
    for (int i = 1; i <= 5; i++)
    {
        pushBack(arr, i * 10);
    }
    printDynArr(arr); // Expected: [10, 20, 30, 40, 50] (size=5, cap=8)

    // 2. insertAt
    insertAt(arr, 2, 25);
    printDynArr(arr); // Expected: [10, 20, 25, 30, 40, 50] (size=6, cap=8)

    // 3. removeAt
    removeAt(arr, 0);
    printDynArr(arr); // Expected: [20, 25, 30, 40, 50] (size=5, cap=8)

    // 4. getAt / setAt
    cout << "Element at index 2: " << getAt(arr, 2) << "\n"; // Expected: 30
    setAt(arr, 2, 99);
    printDynArr(arr); // Expected: [20, 25, 99, 40, 50] (size=5, cap=8)

    // Membebaskan memori sebelum program selesai
    freeArray(arr);

    return 0;
}