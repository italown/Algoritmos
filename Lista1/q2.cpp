#include <iostream>

void merge(int arr[], int inicio, int meio, int fim){
    int tL = meio - inicio + 1;
    int tR = fim - meio;

    int arrL[tL];
    int arrR[tR];

    int i, j, k;

    for (i = 0; i < tL; i++){
        arrL[i] = arr[inicio+i];
    }

    for (i = 0; i< tR; i++){
        arrR[i] = arr[meio+i + 1];
    }

    i=0, j=0;
    k = inicio;

    while (i < tL && j < tR){
        if (arrL[i] <= arrR[j]){
            arr[k] = arrL[i];
            i++;
        } else {
            arr[k] = arrR[j];
            j++;
        }
        k++;
    }

    while (i < tL){
        arr[k] = arrL[i];
        i++;
        k++;
    }

    while (j < tR){
        arr[k] = arrR[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int inicio, int fim){
    if (inicio < fim){
        int meio = inicio + (fim-inicio)/2;

        mergesort(arr, inicio, meio);
        mergesort(arr, meio+1, fim);
        merge(arr, inicio, meio, fim);
    }
}

bool buscaBinaria(int arr[], int item, int inicio, int fim){
    if (inicio <= fim){
        int meio = inicio + (fim-inicio)/2;

        if (arr[meio] == item){
            return true;
        }

        if (arr[meio] < item){
            return buscaBinaria(arr, item, meio+1, fim);
        } else {
            return buscaBinaria(arr, item, inicio, meio-1);
        }
    }
    return false;
}


int main(){
    int n, k, i, contador;

    std::cin >> n;

    std::cin >> k;

    int arr[n];

    for (i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    mergesort(arr, 0, n-1);

    // for (i=0;i<n;i++){
    //     std::cout<< arr[i] << " ";
    // }
    
    for (i = 0; i < n; i++){
        if (buscaBinaria(arr, ((arr[i]) + k), i, n-1)){
            contador++;
        }
    }

    std::cout << contador;

    return 0;
}