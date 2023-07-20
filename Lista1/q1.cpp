#include <iostream>
#include <stdio.h>

int particcion(int arr[], int inicio, int fim){
    int pivo = arr[inicio];

    int i = inicio - 1;
    int j = fim + 1;

    while(true){
        do{
            i++;
        } while(arr[i] < pivo);

        do{
            j--;
        } while(arr[j] > pivo);

        if (i >= j){
            return j;
        }

        std::swap(arr[i], arr[j]);
    }
}

void quicksort(int arr[], int inicio, int fim){
    if (inicio < fim){
        int pivo = particcion(arr, inicio, fim);

        quicksort(arr, inicio, pivo - 1);
        quicksort(arr, pivo + 1, fim);
    }
}

void somas(int arr[], long long sum[], int size) {
    for (int i=1; i<=size; i++) {
        sum[i] = sum[i-1] + arr[i-1];
    }
}

int main(){
    int n, q, i, x, y;

    long long arraySum[n];

    scanf("%d %d", &n, &q);

    int* arr = new int[n];

    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n-1);
    
    for (i = 0; i <= q; i++){
        scanf("%d %d", &x, &y);

        long long sum = arraySum[n - x + y] - arraySum[n - x];

        printf("%d\n", sum);
    }
    std::cout << std::endl;
}