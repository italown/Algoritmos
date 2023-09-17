#include <iostream>
#include <vector>

int abs(int i){
    if (i < 0){
        return -i;
    }
    return i;
}

int max(int i, int j){
    if (i > j){
        return i;
    }
    return j;
}

int min(int i, int j){
    if (i > j){
        return j;
    }
    return i;
}

void min_custo(int n, std::vector<long long>& h, int k){
    std::vector <long long> dp(n+1, 0); //inicia tudo com zeros

    for (int i = 2; i <= n; i++){
        dp[i] = 1230412121;
        for (int j =  i-1; j >= max(i - k, 1); j--){
            dp[i] = min(dp[i], dp[j] + abs(h[i-1] - h[j-1]));
        }
    }
    std::cout << dp[n];
}

int main(){
    int n, k;

    std::cin >> n >> k;

    std::vector<long long> h(n);

    for (int i = 0; i < n; i++){
        std::cin >> h[i];
    }

    min_custo(n, h, k);
}