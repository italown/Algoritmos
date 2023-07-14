#include <iostream>
#include <string>

class ArrayList{
    private:
        int maxSize;
        int size;
        int curr;
        int* arr;
    
    public:
        ArrayList(int value){
            maxSize = value;
            size = curr = 0;
            arr = new int [value];
        }

        void insert(int value){
            if (size >= maxSize){
                return;
            }

            int i;
            for (i = size; i > curr; i--){
                arr[i] = arr[i-1];
            }

            arr[curr] = value;
            size ++;
        }

        void remove(){
            if ((curr < 0) || (curr >= size)){
                return;
            }

            int i;

            for (i=curr; i < size; i++){
                arr[i] = arr[i+1];
            }

            size --;
        }

        void next(){
            if (curr < size){
                curr++;
            }
        }

        void prev(){
            if (curr != 0){
                curr --;
            }
        }

        void count(int value){
            int i, count;

            for (i=0; i < size; i++){
                if (arr[i] == value){
                    count++;
                }
            }
            std::cout << count << std::endl;
        }

        void print(){
            int i;

            for (i=0; i < size; i++){
                std::cout << arr[i] << " ";
            }

            std::cout << std::endl;
        }
};

int main(){

    int qtd_casos, casos, valor, i, j;

    std::string operador;
    
    std::cin >> qtd_casos;

    for (i = 0; i < qtd_casos; i++){

        std::cout << "Caso " << i+1 << ":" << std::endl;

        std::cin >> casos;

        ArrayList list(casos);

        for (j=0; j < casos; j++){
            std::cin >> operador;

            if (operador == "insert"){
                std::cin >> valor;
                list.insert(valor);
            }
            else if (operador == "remove"){
                list.remove();
            }
            else if (operador == "count"){
                std::cin >> valor;
                list.count(valor);
            }
            else if (operador == "next"){
                list.next();
            }
            else if (operador == "prev"){
                list.prev();
            }
        }
    }
}