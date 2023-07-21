#include <iostream>

class Node{
    public:
        int key;
        int value;
        Node* next;
        Node(int key, int value, Node* next){
            this->key = key;
            this->value = value;
            this->next = next;
        }
        
        Node(int key, int value){
            this->key = key;
            this->value = value;
            this->next = nullptr;
        }
};

class Hash{
    private:
        int maxSize;
        int size;
        Node** arr;

        int hash(int key){
            return key%maxSize;
        }
    
    public:
        Hash(int size){
            maxSize = size;
            this->size = 0;
            arr = new Node*[size];
            
            int i;
            for (i=0; i < size; i++){
                arr[i] = nullptr;
            }
        }

        void insert(int key, int value){
            int index = hash(key);

            Node* temp = new Node(key, value);

            if (arr[index] == nullptr){
                arr[index] = temp;
            }
            else { 
                temp->next = arr[index];
                arr[index] = temp;
            }
        }

        void remove(int key){
            int index = hash(key);

            Node* prev = nullptr;
            Node* temp = arr[index];

            while (temp != nullptr){
                if (temp->key == key){
                    if (temp == arr[index]){
                        arr[index] = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                }
                prev = temp;
                temp = temp->next;
            }
        }

        void print(){
            int i;
            for (i = 0; i < maxSize; i++){
                if (arr[i] != nullptr){
                    Node* temp = arr[i];

                    while (temp != nullptr){
                        std::cout << "Key: " << temp->key << std::endl;
                        std::cout << "Value: " << temp->value << std::endl;
                        temp = temp->next;
                    }
                }
            }
        }
};

int main(){
    Hash dict(10);

    dict.insert(1, 12);
    dict.insert(11, 13);
    dict.remove(11);
    dict.print();
}