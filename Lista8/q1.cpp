#include <iostream>
#include <vector>

int max(int i, int j){
    if (i > j){
        return i;
    }
    return j;
}

void dp(int s, int n, std::vector<int> tamanhos, std::vector<int> pesos){
    std::vector<std::vector<int>> matrix(n+1, std::vector<int>(s+1, 0));

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= s; j++){
            if (tamanhos[i-1] <= j){
                matrix[i][j] = max(matrix[i-1][j], matrix[i-1][j-tamanhos[i-1]] + pesos[i-1]);
            } else{
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }
    std::cout << matrix[n][s];
}

int main(){
    int s, n;

    std::cin >> s >> n;

    std::vector<int> tamanhos(n);
    std::vector<int> pesos(n);

    for (int i = 0; i < n; i++){
        std::cin >> tamanhos[i] >> pesos[i];
    }

    dp(s, n, tamanhos, pesos);
}
