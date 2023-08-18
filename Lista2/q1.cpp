#include <iostream>
#include <string>

class Link{
    private:
        char element;
        Link* next;
    
    public:
        Link(char value, Link* nextNode){
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

        char getElement(){
            return element;
        }

        char setElement(int newElement){
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

        void moveToStart(){
            curr = head;
        }

        void moveToEnd(){
            curr = tail;
        }

        void insert(int value){
            curr->setNext(new Link(value, curr->getNext()));

            if (tail == curr){
                tail = curr->getNext();
            }
            curr = curr->getNext();


            size++;
        }

        void print(){
            Link* temp = head->getNext();

            while (temp != nullptr){
                std::cout << temp->getElement();
                temp = temp->getNext();
            }

            std::cout << std::endl;
        }
};

int main(){
    std::string input;
    int i, j;


    while (std::cin >> input){
        LinkedList list;
        for (i=0; i < input.size(); i++){
            if (input[i] == '['){
                list.moveToStart();
            }
            else if (input[i] == ']'){
                list.moveToEnd();
            } else{
                list.insert(input[i]);
            }
        }
        list.print();
    }
}