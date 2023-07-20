#include <iostream>
#include <string>
#include <vector>

template <typename K, typename I>

class HashNode{
    public:
        K key;
        I value;

        HashNode(K new_key, I new_value){
            key = new_key;
            value = new_value;
        }
};


template <typename K, typename I>
class ClosedHash{
    private:
        HashNode<K, I>** arr;
        int maxSize;
        int size;
        HashNode<K,I>* flag;

    public:
        ClosedHash(int size){
            maxSize = size;

            this->size = 0;

            arr = new HashNode<K, I>* [size];

            int i;
            for (i = 0; i < maxSize; i++){
                arr[i] = nullptr;
            }

            flag = new HashNode<K, I>(-1, -1);    
        }

        int hashCode(K key){
            return key%maxSize;
        }

        void insertNode(K key, I value){
            HashNode<K, I>* temp = new HashNode<K, I> (key, value);

            int indexHash = hashCode(key);

            while (arr[indexHash] != nullptr && arr[indexHash]->key != key && arr[indexHash]->key != -1){
                indexHash++;
                indexHash %= maxSize;
            }

            if (arr[indexHash] == nullptr || arr[indexHash]->key == -1){
                size++;
            }

            arr[indexHash] = temp;
        }

        I deleteNode(K key){
            int indexHash = hashCode(key);

            while (arr[indexHash] != nullptr){
                if (arr[indexHash]->key == key){
                    HashNode<K, I>* temp = arr[indexHash];

                    arr[indexHash] = flag;

                    size--;

                    return temp->value;
                }

                indexHash++;
                indexHash %= maxSize;
            }

            return -1;
        }
        
        //Achar o valor da key
        I get(K key){

            int indexHash = hashCode(key);

            int count = 0;

            while (arr[indexHash] != nullptr){

                if (count >= size){
                    return -1;
                }

                if (arr[indexHash]->key == key){
                    return arr[indexHash]->value;
                }

                indexHash++;
                indexHash %= maxSize;
            }

            return -1;
        }

        void print(){
            
            int i = 0;

            while (i < maxSize){
                if (arr[i] != nullptr && arr[i]->key != -1){
                    std::cout << "Key: " << arr[i]->key << std::endl;
                    std::cout << "Value: " << arr[i]->value << std::endl;
                }
                i++;
            }
            std::cout << "------------" << std::endl;
        }

};


int main(){
    ClosedHash<int, int> dict(10);

    dict.print();
    dict.insertNode(0, 10);
    dict.insertNode(10, 10);
    dict.insertNode(0, 10);
    dict.print();
    dict.insertNode(3, 20);
    dict.print();
    dict.deleteNode(3);
    dict.print();

    std::cout << dict.get(0) << std::endl;
}