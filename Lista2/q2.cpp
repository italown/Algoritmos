#include <iostream>

class Node {
    public:
        int value;
        Node* next;

        Node(int element, Node* next = nullptr) {
            value = element;
            this->next = next;
        }
        Node(Node* next = nullptr) {
            this->next = next;
        }
};

class Stack {
    private:
        Node* top;
        int size;

    public:
        Stack() {
            top = nullptr;
            size = 0;
        }


        void push(int value) {
            top = new Node(value, top);
            size++;
        }

        void pop() {
            if (top != NULL) {
                int value = top->value;
                Node* temp = top->next;

                delete top;
                top = temp;
                
                size--;
            }
        }

        int topValue() {
            if (top != 0) {
                return top->value;
            }
        }

        int lenght() {
            return size;
        }
};


int main() {
    int tamanho, vagao, cur, i;
    bool valido;
    int size;

    while (std::cin >> tamanho && tamanho) {
        Stack pilha;
        
        while (std::cin >> vagao && vagao) {
            cur = 1;
            valido = true;

            size = pilha.lenght();

            while(size != 0) {
                pilha.pop();
                size--;
            }

            for (i = 1; i < tamanho; i++) {
                for (; cur <= vagao; cur++) {
                    pilha.push(cur);
                }

                if (pilha.topValue() != vagao) {
                    valido = false;
                }
                
                pilha.pop();
                
                std::cin >> vagao;
            }


            if (valido) {
                std::cout << "Yes" << std::endl;
            }
            else {
                std::cout << "No" << std::endl;
            }


        }
        std::cout << std::endl;
    }
}