#include <iostream>

int partition (int array[], int begin, int end) {
    int pivot = array[begin];
    int i = begin;
    int j = end;

    while (i < j) {
        while (array[i] <= pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i < j)
            std::swap(array[i], array[j]);
    }

    std::swap(array[j], array[begin]);
    return j;
}

void quickSort(int array[], int begin, int end) {
    if (begin < end) {
        int p = partition(array, begin, end);

        quickSort(array, begin, p-1);
        quickSort(array, p+1, end);
    }
}

void somas(int arr[], long long sum[], int size) {
    for (int i=1; i<=size; i++) {
        sum[i] = sum[i-1] + arr[i-1];
    }
}

int main(){
    int n, q, x, y, sum; // n- intems, q - consultas
    std::cin >> n >> q;
    int array[n];

    for (int i=0; i<n; i++) {
        std::cin >> array[i];
    }
    long long arraySum[n];
    quickSort(array, 0, n-1);
    somas(array, arraySum, n);
    
    while(q>0) {
        std::cin >> x >> y;

        long long sum = arraySum[n - x + y] - arraySum[n - x];
        std::cout << sum << std::endl;
        q--;
    }

    return 0;
}