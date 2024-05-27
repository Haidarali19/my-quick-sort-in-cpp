#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void inputArray(int arr[], int n) {
    cout << "Masukkan elemen-elemen array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[n];
    inputArray(arr, n);

    quicksort(arr, 0, n - 1);

    cout << "Array yang diurutkan: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

