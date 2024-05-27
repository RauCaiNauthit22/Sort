#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n - i - 1; j++) {
            
            if(a[j] > a[j + 1]) {
                swap (a[j], a[j + 1]);
            }
        }
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int point = i - 1;

        while (point > 0 && x < point) {
            a[point + 1] = a[point];
            --point;
        }
        a[point + 1] = x;
    }
}

// Trộn 2 dãy con: Dãy 1 từ left -> middle; Dãy 2 từ middle + 1 -> right.
void Merge(int a[], int left, int middle, int right) {
    vector<int> l(a + left, a + middle + 1); // Sao chép phần tử từ left -> middle vào l.
    vector<int> r(a + middle + 1,a + right + 1); // Sao chép phần tử từ left -> middle vào r.
    int i = 0, j = 0;

    while (i < l.size() && j < r.size()) {
        if (l[i] < r[j]) {
            a[left] = l[i]; ++left; ++i;
        } else {
            a[left] = r[j]; ++left; ++j;
        }
    }

    while (i < l.size()) {
        a[left] = l[i]; ++left; ++i;
    }

    while (j < l.size()) {
        a[left] = r[j]; ++left; ++j;
    }
}

void MergeSort(int a[], int left, int right) {
    if (left >= right) return;
    int middle = (left + right) / 2;
    MergeSort(a, left, middle);
    MergeSort(a, middle + 1, right);
    Merge(a, left, middle, right);
}

// Phân hoạch Lomuto.
// Phân hoạch đoạn từ left -> right.
int partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    ++i;
    swap(a[i], a[r]);
    return i;
}

// Phân hoạch Hoare.
int partition2(int a[], int l, int r) {
    int pivot = a[l];
    int i = l - 1;
    int j = j + 1;
    while (1) {
        do {
            ++i;

        } while (a[i] < pivot);

        do {
            --j;
        } while (a[j] > pivot);
        if (i < j) {
            swap(a[i], a[j]);
        } else {
            return j;
        }
    }
}

void QuickSort(int a[], int l, int r) {
    if (l >= r) return;
    int p = partition(a, l ,r);
    QuickSort(a, l, p - 1);
    QuickSort(a, p + 1, r);
}

void QuickSort2(int a[], int l, int r) {
    if (l >= r) return;
    int p = partition(a, l ,r);
    QuickSort(a, l, p);
    QuickSort(a, p + 1, r);
}

void Heapify(int a[], int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = 1;
    if (l < n && a[l] > a[largest]) {
        largest = l;
    }

    if (r < n && a[r] > a[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        Heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(a[i], a[0]);
        Heapify(a, i, 0);
    }
}

int main() {
    int n;
    int a[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    selectionSort(a, n);
    bubbleSort(a, n);
    insertionSort(a, n);
    MergeSort(a, 0, n -1);
    QuickSort(a, 0, n -1);
    QuickSort2(a, 0, n - 1);
    HeapSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << endl;
    }
    return 0;
}