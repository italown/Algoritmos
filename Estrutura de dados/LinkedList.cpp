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

        Link* setNext(Link* new_next){
            return next = new_next;
        }

        int getElement(){
            return element;
        }

        int setElement(int value){
            return element = value;
        }
};

class LinkedList{
    private:
        Link* head;
        Link* tail;
        Link* curr;
        int size;

    public:
        LinkedList(){
            head = tail = curr = new Link(nullptr);
            size = 0;
        }

        void insert(int value){
            curr->setNext(new Link(value, curr->getNext()));

            if (tail == curr){
                tail = curr->getNext();
            }

            size++;
        }

        void moveToStart(){
            curr = head;
        }

        void next(){
            if (curr == tail){
                return;
            }

            curr = curr->getNext();
        }

        void prev(){
            if (curr == head){
                return;
            }

            Link* temp = head;

            while (temp->getNext() != curr){
                temp = temp->getNext();
            }

            curr = temp;
        }

        void clear(){
            Link* temp = head;

            while (temp != nullptr){
                Link* trash = temp ->getNext();
                delete temp;
                temp = trash;
            }

            delete head;

            head = curr = tail = new Link(nullptr);
            size = 0;
        }

        void remove(){
            if (curr == tail){
                return;
            }

            if (tail == curr->getNext()){
                tail = curr;
            }

            Link* temp = curr->getNext();

            curr->setNext(curr->getNext()->getNext());
            
            size--;

            delete temp;
        }

        void print(){
            Link* temp = head->getNext();

            while (temp != nullptr){
                std::cout << temp->getElement() << " ";
                temp = temp->getNext();
            }

            std::cout << std::endl;
        }
};

int main(){
    LinkedList list;

    list.insert(3);
    list.print();

    list.insert(5);
    list.print();

    list.next();
    list.insert(10);
    list.print();

    list.prev();
    list.remove();
    list.print();

    list.prev();
    list.remove();
    list.print();

    list.next();
    list.remove();
    list.print();

    list.insert(1);
    list.insert(1);
    list.insert(3);

    list.print();

    list.clear();

    list.print();

    return -1;
}