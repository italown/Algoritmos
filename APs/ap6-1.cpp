#include <iostream>

class Node{
    public:
        int key;
        Node* next;

        Node(int key, Node* next){
            this->key = key;
            this->next = next;
        }

        Node(int key){
            this->key = key;
            this->next = nullptr;
        }
};

class openHash{
    private:
        int maxSize;
        int size;
        Node** arr;  

        int hash(int key){
            return key%maxSize;
        }

    public:
        openHash(int size){
            maxSize = size;
            this->size = 0;
            arr = new Node*[size];

            int i;

            for (i = 0; i<size; i++){
                arr[i] = nullptr;
            }
        }

        void insert(int key){
            Node* temp = new Node(key);

            int index = hash(key);

            if (arr[index] == nullptr){
                arr[index] = temp;
                return;
            }

            Node* curr = arr[index];

            while (curr->next != nullptr){
                curr = curr->next;
            }

            curr->next = temp;
        }

        void print(){
            int i;

            for (i=0; i < maxSize; i++){
                if (arr[i] != nullptr){
                    
                    Node* temp = arr[i];

                    std::cout << i << " ";

                    while (temp != nullptr){
                        std::cout << temp->key << " ";
                        temp = temp->next;
                    }

                    std::cout << std::endl;

                }
            }
        }
};

int main(){
    int i, qtd, input;

    std::cin >> qtd;

    openHash dict(10);

    for (i=0; i < qtd; i++){
        std::cin >> input;

        dict.insert(input);
    }

    std::cout << "-----------" << std::endl;

    dict.print();
}