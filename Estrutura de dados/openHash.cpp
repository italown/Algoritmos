#include <iostream>

class Node{
    public:
        int key;
        int value;

        Node(int new_key, int new_value){
            key = new_key;
            value = new_value;
        }
};

class Hash{
    private:
        int maxSize;
        int size;
        Node** arr;
        
    public:
        
}