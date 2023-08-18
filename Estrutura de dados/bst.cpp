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

        int findhelp(Node* help, int key){
            if (help == nullptr){
                return -1;
            }

            if (key > help->key){
                return findhelp(help, key);
            } else if (key == help->key){
                return help->key;
            } else{
                return findhelp(help, key);
            }
        }

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

        Node* removehelp(Node* help, int key){
            if (help == nullptr){
                return nullptr;
            } else if (help->key > key){
                help->left = removehelp(help->left, key);
            } else if (help->key < key){
                help->right = removehelp(help->right, key);
            } else{
                if (help->left == nullptr){
                    return help->right;
                } else if (help->right == nullptr){
                    return help->left;
                } else{
                    Node* temp = getmin(help->right);
                    help->key = temp->key;
                    help->right = deletemin(help->right);
                }

            }

            return help;
        }

        Node* getmin(Node* help){
            if (help->left == nullptr){
                return help;
            }
            return getmin(help->left);
        }

        Node* deletemin(Node* help){
            if (help->left == nullptr){
                help->left = deletemin(help->left);
            }
            return help;
        }
    
    public:
        BST(){
            root = nullptr;
            size = 0;
        }

        int find(int key){
            return findhelp(root, key);
        }

        void insert(int key){
            root = inserthelp(root, key);
            size ++;
        }

        void remove(int key){
            int temp = findhelp(root, key);

            if (temp == -1){
                return;
            }

            root = removehelp(root, key);
            size--;
        }

        Node* getRoot(){
            return root;
        }

        void inorder(Node* help){
            if (help == nullptr){
                return;
            }
            inorder(help->left);
            std::cout << " " << help->key;
            inorder(help->right);
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
}