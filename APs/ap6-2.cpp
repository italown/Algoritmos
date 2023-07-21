#include <iostream>
#include <string>

class Node{
    public:
        std::string key;

        Node(std::string key){
            this->key = key;
        }
};

class ClosedHash{
    private:
        int maxSize;
        int size;
        Node** arr;
        Node* flag;
        
        int hash(std::string key){
            int i, sum;

            sum = 0;

            for (i=0; i < key.size(); i++){
                sum += key[i];
            }
            return sum%maxSize;
        }

    public:
        ClosedHash(int size){
            maxSize = size;
            this->size = 0;
            arr = new Node*[size];

            flag = new Node("none");

            int i;

            for (i=0; i<size; i++){
                arr[i] = nullptr;
            }
        }

        void insert(std::string key){
            if (size >= (maxSize-1)){
                return;
            }

            Node* temp = new Node(key);

            int index = hash(key);
            
            while (arr[index] != nullptr && arr[index]->key != "none" && arr[index]->key != key){
                index ++;
                index %= maxSize;
            }
            
            if (arr[index] == nullptr || arr[index]->key == "none"){
                size++;
            }

            arr[index] = temp;
        }

        void remove(std::string key){
            int index = hash(key);

            while (arr[index] != nullptr){
                if (arr[index]->key == key){
                    arr[index] = flag;
                    size--;
                    return;
                }
                index++;
                index %= maxSize;
            }
        }

        void find(std::string key){
            int index = hash(key);
            
            int count = 0;

            while (arr[index] != nullptr && count <= size){
                if (arr[index]->key == key){
                    std::cout << arr[index]->key << " " << index << std::endl;
                    return;
                }
                count++;
                index++;
                index %= maxSize;
            }
            std::cout << key << " " << -1 << std::endl;
        }
};

int main(){
    int size;

    std::string operador, input;

    std::cin >> size;

    ClosedHash dict(size);

    while (operador != "fim"){
        std::cin >> operador;

        if (operador == "add"){
            std::cin >> input;
            dict.insert(input);
        } else if (operador == "rmv"){
            std::cin >> input;
            dict.remove(input);
        } else if (operador == "sch"){
            std::cin >> input;
            dict.find(input);
        }
    }
}