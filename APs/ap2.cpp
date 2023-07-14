#include <iostream>

int particcion(int arr[], int inicio, int fim){
    int pivo = arr[fim];

    int j = inicio - 1;
    int i;

    for (i = inicio; i < fim; i++){
        if (arr[i] < pivo){
            j++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[j+1], arr[fim]);
    
    return j + 1;
}

void Quicksort(int arr[], int inicio, int fim){
    if (inicio < fim){
        int pivo = particcion(arr, inicio, fim);

        Quicksort(arr, inicio, pivo -1);
        Quicksort(arr, pivo + 1, fim);
    }
}

int main(){
    int tamanho, i;
    
    std::cin >> tamanho;

    int arr[tamanho];

    for (i=0; i < tamanho; i++){
        std::cin >> arr[i];
    }

    Quicksort(arr, 0, tamanho-1);

    for (i = 0; i < tamanho; i++){
        std::cout << arr[i] << " ";
    }

    return 0;
}