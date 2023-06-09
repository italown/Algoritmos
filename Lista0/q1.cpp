#include <iostream>

long quantidadePisos(long numerador, long denominador) {
    long resultado = numerador / denominador;

    if ((numerador % denominador) != 0) {
        resultado++;
    }

    return resultado;
}

int main() {
    long long x, y, lado;

    std::cin >> x >> y >> lado;

    long long ladoX = quantidadePisos(x, lado);
    long long ladoY = quantidadePisos(y, lado);

    long long resultado = ladoX * ladoY;

    std::cout << resultado << std::endl;

    return 0;
}