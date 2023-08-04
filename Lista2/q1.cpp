#include <iostream>
#include <string>

class Link{
    private:
        char element;
        Link* next;
        Link* prev;
    
    public:
        Link(char value, Link* new_prev, Link* next_node){
            element = value;
            prev = new_prev;
            next = next_node;
        }

        Link(Link* new_prev, Link* next_node){
            next = next_node;
            prev = new_prev;
        }

        Link* getNext(){
            return next;
        }

        Link* setPrev(Link* new_prev){
            return prev = new_prev;
        }
        Link* getPrev(){
            return prev;
        }

        Link* setNext(Link* new_next){
            return next = new_next;
        }

        char getElement(){
            return element;
        }

        char setElement(char value){
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
            head = tail = curr = new Link(nullptr, nullptr);
            size = 0;
        }

        void insert(char value){
            curr->setPrev(new Link(value, curr->getPrev(), curr));

            if (head == curr){
                head = curr->getPrev()->getPrev();
            }

            size++;
        }

        void moveToStart(){
            curr = head;
        }

        void moveToEnd(){
            curr = tail;
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
    int i;

    while (!std::cin.eof()){
        std::cin >> input;
        LinkedList list;

        if (!std::cin.eof()){
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

}