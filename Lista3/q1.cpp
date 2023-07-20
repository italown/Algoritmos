#include <iostream>

class Node{
    public:
        std::string key;
        
        Node(std::string new_key){
            key = new_key;
        }
};


class Hash{
    private:
        int maxSize;
        int size;
        Node** arr;
        Node* flag;
        
        int hash(std::string key){
            int i, sum = 0;

            for (i=0; i < key.size(); i++){
                sum += (key[i] * (i+1));
            }

            return (sum*19)%101;
        }

    public:
        
        Hash(int new_size){
            maxSize = new_size;
            size = 0;

            arr = new Node*[new_size];

            int i;

            for(i=0; i < new_size; i++){
                arr[i] = nullptr;
            }

            flag = new Node("none");
        }

        void insert(std::string key){

            Node* temp = new Node(key);

            int index = hash(key);

            int j = 1;

            while (arr[index] != nullptr && arr[index]->key != "none" && arr[index]->key != key){
                index += ((j*j) + (23 * j));
                index %= 101;
                j++;
                if (j == 19){
                    return;
                }
            }

            if (arr[index] == nullptr || arr[index]->key == "none"){
                arr[index] = temp;
                size++;
            }
        }

        void remove(std::string key){
            int index = hash(key);

            int j = 0;
            while (arr[index] != nullptr){
                if (arr[index]->key == key){
                    arr[index] = flag;
                    size--;
                    return;
                }
                index += (j*j) + (23 * j);
                index %= 101;
                j++;
            }

            return;
        }

        void print(){
            int i = 0;
            
            std::cout << (size) << std::endl;

            while (i < 101){
                if (arr[i] == nullptr || arr[i]->key == "none"){
                    i++;
                    continue;
                }
                std::cout << i << ":" << arr[i]->key << std::endl;
                i++;
            }
        }

};


int main(){
    int i, j, k, cases, operations;

    std::string input, key;

    std::cin >> cases;

    for (i=0; i < cases; i++){
        std::cin >> operations;

        Hash dict(101);

        for (j= 0; j < operations; j++){
            
            std::cin >> input;

            key = "";

            for (k = 4; k < (input.size()); k++){
                    key += input[k];
            }
            if (input[0] == 'A'){
                dict.insert(key);
            }
            else{
                dict.remove(key);
            }
        }
        dict.print();
    }
}