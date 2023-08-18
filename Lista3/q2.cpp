#include <iostream>

class Node{
    public:
        int key;
        Node* right;
        Node* left;

        Node(int key){
            this->key = key;
            right = left = nullptr;
        }
};

class BST{
    private:
        Node* root;
        int size;

        Node* inserthelp(Node* help, int key){
            if (help == nullptr){
                return new Node(key);
            }

            if (help->key > key){
                help->left = inserthelp(help->left, key);
            } else {
                help->right = inserthelp(help->right, key);
            }

            return help;
        }
    
    public:
        BST(){
            root = nullptr;
            size = 0;
        }

        void insert(int key){
            root = inserthelp(root, key);
            size ++;
        }


        Node* getRoot(){
            return root;
        }

        void preorder(Node* help){
            if(help == nullptr){
                return;
            }
            std::cout << " " << help->key;
            preorder(help->left);
            preorder(help->right);
        }

        void inorder(Node* help){
            if (help == nullptr){
                return;
            }
            inorder(help->left);
            std::cout << " " << help->key;
            inorder(help->right);
        }

        void posorder(Node* help){
            if (help == nullptr){
                return;
            }
            posorder(help->left);
            posorder(help->right);
            std::cout << " " << help->key;
        }

};

int main(){
    int i, n, key;

    std::cin >> n;

    BST dict;

    for (i=0; i < n; i++){
        std::cin >> key;
        dict.insert(key);
    }

    std::cout << "Pre order :";
    dict.preorder(dict.getRoot());
    std::cout << std::endl << "In order  :";
    dict.inorder(dict.getRoot());
    std::cout << std::endl << "Post order:";
    dict.posorder(dict.getRoot());
}