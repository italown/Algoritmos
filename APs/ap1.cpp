#include <iostream>

void Merge(int arr[], int inicio, int meio, int fim) {
    int l1 = meio - inicio + 1;
    int l2 = fim - meio;

    int esquerda[l1];
    int direita[l2];

    int i, j, k;
    
    for (i=0; i < l1; i++) {
        esquerda[i] = arr[inicio + i];
    }

    for (i=0; i < l2; i++) {
        direita[i] = arr[meio + i + 1];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < l1 && j < l2){
        if (esquerda[i] <= direita[j]){
            arr[k] = esquerda[i];
            i++;
        }
        else {
            arr[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < l1){
        arr[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < l2){
        arr[k] = direita[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim-inicio) / 2;

        MergeSort(arr, inicio, meio);
        MergeSort(arr, meio + 1, fim);

        Merge(arr, inicio, meio, fim);
    }
}

int main() {

    int tamanho, i;
    
    std::cin >> tamanho;

    int arr[tamanho];

    for (i = 0; i < tamanho; i++ ){
        std::cin >> arr[i];
    }

    MergeSort(arr, 0, tamanho - 1);

    for (i = 0; i < tamanho; i++){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}