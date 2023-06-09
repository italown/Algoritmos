#include <iostream>

int main(){
    int peso;

    std::cin >> peso;

    if (((peso % 2) == 0) && (peso != 2)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}