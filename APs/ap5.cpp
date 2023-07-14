#include <iostream>
#include <string>

class Link{
    private:
        int element;
        Link* next;

    public:
        Link(int value, Link* nextNode){
            element = value;
            next = nextNode;
        }

        Link(Link* nextNode){
            next = nextNode;
        }

        Link* getNext(){
            return next;
        }

        Link* setNext(Link* newNext){
            return next = newNext;
        }

        int getElement(){
            return element;
        }

        int setElement(int value){
            return element = value;
        }
};

class Stack{
    private:
        Link* top;
        int size;
    
    public:
        Stack(){
            top = new Link(nullptr);
            size = 0;
        }

        void push(int value){
            top = new Link(value, top);
            size++;
        }

        void pop(int n){
            if (n > size){
                return;
            }

            int i, temp;
            
            for (i=0; i < n; i++){
                if (top == nullptr){
                    return;
                }
                Link* temp = top;

                top = top->getNext();

                delete temp;
            }
            size -= n;
        }

        void print(){
            if (size == 0){
                return;
            }
            
            Link* temp = top;

            while (temp != nullptr){
                std::cout << temp->getElement() << " ";
            }

            std::cout << std::endl;
        }

        void soma(int value){
            Link* temp = top;

            int soma, i;

            if (size >= value){
                for (i = 0; i < value; i++){
                    soma += temp->getElement();
                    temp = temp->getNext();
                }
                std::cout << "Soma: " << soma << std::endl;
            }
        }
};

int main(){
    int value, i, soma;
    std::string operacao;

    Stack list;

    while (operacao != "end"){
        std::cin >> operacao;

        if (operacao == "push"){
            std::cin >> value;
            list.push(value);
        }
        else if (operacao == "pop"){
            std::cin >> value;

            list.soma(value);
            list.pop(value);
        }
    }
}

