// n >= 1
#include <iostream> //singkatan dari Input/Output Stream

// Baris ini memindahkan semua fitur C++ (termasuk cout dan endl)
// agar bisa langsung dipanggil
using namespace std;
int main()
{
    int n = 5;
    int arr[] = {10, 20, 30, 40, 50};

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i > j; j++)
        {
            sum += arr[i] + arr[j];
        }
    }

    cout << "Nilai sum akhir adalah: " << sum << endl;

    return 0;
}
