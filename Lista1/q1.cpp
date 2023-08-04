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

        quicksort(arr, inicio, pivo);
        quicksort(arr, pivo + 1, fim);
    }
}

void sum(int arr[], long long sum[], int size) {
    for (int i=1; i<=size; i++) {
        sum[i] = sum[i-1] + arr[i-1];
    }
}

int main(){
    int n, q, i, soma;

    std::cin >> n >> q;

    int arr[n];

    for (i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    long long arr_sum[n];

    quicksort(arr, 0, n-1);

    sum(arr, arr_sum, n);
    
    for (i = q; i > 0; i--){
        int x, y;
        std::cin >> x >> y;

        long long sum;
        sum = arr_sum[n - x + y] - arr_sum[n - x];

        std::cout << sum << std::endl;
    }

}