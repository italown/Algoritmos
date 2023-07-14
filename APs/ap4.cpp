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

        int setElement(int newElement){
            return element = newElement;
        }
};

class LinkedList{
    private:
        Link* head;
        Link* tail;
        Link* curr;
        int size;

        void init(){
            curr = tail = head = new Link(nullptr);
            size = 0;
        }

        void deleteAll(){
            curr = head;

            while (curr != nullptr){
                head = curr;
                curr = curr->getNext();
                delete head;
            }
        }

    public:
        LinkedList(){
            init();
        }

        void next(){
            if (curr != tail){
                curr = curr->getNext();
            }
        }

        void prev(){
            if (curr == head){
                return;
            }

            Link* temp = head;

            while (temp != curr){
                temp = temp->getNext();
            }
            curr = temp;
        }

        void insert(int value){
            curr->setNext(new Link(value, curr->getNext()));

            if (curr == tail){
                tail = curr->getNext();
            }

            size++;
        }

        void remove(){
            if (curr == tail){
                return;
            }

            if (curr->getNext() == tail){
                tail = curr;
            }
            Link* temp = curr->getNext();

            curr->setNext(curr->getNext()->getNext());

            size--;

            delete temp;
        }

        void count(int value){
            
            int count = 0 ;

            Link* temp = head;

            while (temp != nullptr){
                if (temp->getElement() == value){
                    count++;
                }
                temp = temp->getNext();
            }
            std::cout << count << std::endl;

            delete temp;
        }

        void print(){
            Link* temp = head->getNext();

            while (temp != nullptr){
                std::cout << temp->getElement() << ", ";
                temp = temp->getNext();
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

        LinkedList list;

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