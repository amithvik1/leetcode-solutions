#include <stdbool.h>
#include <stdlib.h>

void insertionSort(int* arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int n, int i, int start) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[start + l] > arr[start + largest]) largest = l;
    if (r < n && arr[start + r] > arr[start + largest]) largest = r;

    if (largest != i) {
        swap(&arr[start + i], &arr[start + largest]);
        heapify(arr, n, largest, start);
    }
}

void heapSort(int* arr, int left, int right) {
    int n = right - left + 1;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, left);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[left], &arr[left + i]);
        heapify(arr, i, 0, left);
    }
}

int partition(int* arr, int left, int right) {
    int mid = left + (right - left) / 2;
    
    if (arr[mid] < arr[left]) swap(&arr[mid], &arr[left]);
    if (arr[right] < arr[left]) swap(&arr[right], &arr[left]);
    if (arr[mid] < arr[right]) swap(&arr[mid], &arr[right]);
    
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void introsortUtil(int* arr, int left, int right, int depthLimit) {
    if (right - left < 16) {
        return;
    }

    if (depthLimit == 0) {
        heapSort(arr, left, right);
        return;
    }

    int p = partition(arr, left, right);
    introsortUtil(arr, left, p - 1, depthLimit - 1);
    introsortUtil(arr, p + 1, right, depthLimit - 1);
}

void introsort(int* arr, int size) {
    int depthLimit = 0;
    for (int temp = size; temp > 1; temp >>= 1) {
        depthLimit++;
    }
    depthLimit *= 2;

    introsortUtil(arr, 0, size - 1, depthLimit);
    insertionSort(arr, 0, size - 1);
}

bool asteroidsDestroyed(int mass, int* asteroids, int size) {
    introsort(asteroids, size);

    long long c = mass; 
    for(int i = 0; i < size; i++){
        if(asteroids[i] > c) return false; 
        c += asteroids[i]; 
    }
    return true;
}

