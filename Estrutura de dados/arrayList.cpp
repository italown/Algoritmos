#include <iostream>

template <typename E>

class ArrayList {

    private:
        int maxSize;
        int cursor;
        int size;
        int* arr;
    
    public:
        ArrayList(int value){ //Cria a lista
            maxSize = value;
            cursor = size = 0;
            arr = new int [value];
        }

        int getValue(int value){ //Retorna o indice do valor
            int i;
            for (i = 0; i < maxSize; i++){
                if (arr[i] == value){
                    return i;
                }
            }
            return -1;
        }

        void clear(){
            cursor = 0;
        }

        void insert(E value){ //Adiciona um valor na posição do cursor
            if (size > maxSize){
                return;
            }

            int i;

            for (i=size; i > cursor; i--){
                arr[i] = arr[i-1];
            }
            arr[cursor] = value;
            size++;
        }  

        void moveToStart(){
            cursor = 0;
        }

        void moveToEnd(){
            cursor = size;
        }

        void prev(){
            if ((cursor-1) >= 0){
                cursor--;
            }
        }

        void next(){
            if ((cursor + 1) <= size){
                cursor++;
            }
        }


        E remove(){ //Remove um valor na posição do cursor

            if ((cursor < 0 ) && (cursor >= size)){
                return -1;
            }
            
            E value = arr[cursor];

            int i;
            for (i=cursor; i < size; i++){
                arr[i] = arr[i+1];
            }

            size--;
            return value;
        }  
        
        void append(E value){
            if (size == maxSize-1){
                return;
            }
            arr[size++] = value;
        }

        int tamanho(){
            return size;
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
    ArrayList<int> list(10);

    list.append(5);
    list.print();
    list.append(10);
    list.print();
    list.insert(0);
    list.print();
    list.remove();
    list.print();
    std::cout << list.tamanho() << std::endl;
    list.insert(5);

    

    std::cout << "fim" << std::endl;
}