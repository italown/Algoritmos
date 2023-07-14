#include <iostream>

class Link{
    private:
        int element;
        Link* next;
    
    public:
        Link(int value, Link* next_node){
            element = value;
            next = next_node;
        }

        Link(Link* next_node){
            next = next_node;
        }

        Link* getNext(){
            return next;
        }

        int getElement(){
            return element;
        }

        Link* setNext(Link* newNext){
            return next = newNext;
        }

        int setElement(int value){
            return element = value;
        }
};

class Queue{
    private:
        Link* front;
        Link* back;
        int size;

        void init(){
            front = back = new Link(nullptr);
            size = 0;
        }

    public:
        Queue(){
            init();
        }

        void insert(int value){
            back->setNext(new Link(value, nullptr));
            back = back->getNext();
            size++;
        }

        void remove(){
            if (size == 0){
                return;
            }

            Link* temp = front->getNext();

            front->setNext(front->getNext()->getNext());

            if (front->getNext() == nullptr){
                back = front;
            }

            delete temp;

            size--;
        }

        void clear(){
            Link* temp = front;

            while (temp->getNext() != nullptr){
                temp = front->getNext();
                front = front->getNext()->getNext();
                delete temp;
            }

            delete front, back;

            init();
        }

        void len(){
            std::cout << "Tamanho: " << size << std::endl;
        }

        void print(){
            if (size == 0){
                return;
            }
            Link* temp = front->getNext();
            while (temp != nullptr){
                std::cout << temp->getElement() << " ";
                temp = temp->getNext();
            }
            std::cout << std::endl;
        }
};

int main(){
    Queue list;

    list.insert(5);
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(3);
    list.insert(6);
    list.remove();
    list.remove();
    list.remove();
    list.remove();
    list.len();
    list.print();
    

}