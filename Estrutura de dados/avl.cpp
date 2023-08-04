#include <iostream>
#include <string>

class Node{
    public:
       int key;
       Node* R;
       Node* L;
       int height;

       Node(int key){
            this->key = key;
            L = R = nullptr;
            height = -1;
       } 
};

class AVL{
    private:
        Node* root;
        int size;

        Node* insertHelp(Node* leaf, int key){
            if (leaf == nullptr){
                return new Node(key);
            }
            if (leaf->key > key){
                leaf->L = insertHelp(leaf->L, key);
            } else{
                leaf->R = insertHelp(leaf->R, key);
            }

            leaf->height = 1 + max(h(leaf->L), h(leaf->R));

            int balance = getBalance(leaf);

            if ((balance < -1) && (key >= leaf->R->key)){
                return leftRotate(leaf);
            }
            if ((balance > 1) && (key < leaf->L->key)){
                return rightRotate(leaf);
            }
            if ((balance > 1) && (key >= leaf->L->key)){
                leaf->L = leftRotate(leaf->L);
                return rightRotate(leaf);
            }
            if ((balance < -1) && (key < leaf->R->key)){
                leaf->R = rightRotate(leaf->R);
                return leftRotate(leaf);
            }

            return leaf;
        }

        Node* rightRotate(Node* leaf){
            Node* L = leaf->L;
            Node* Lr = L->R;

            L->R = leaf;
            leaf->L = Lr;

            leaf->height = max(h(leaf->L), h(leaf->R)) + 1;
            L->height = max(h(L->L), h(L->R)) + 1;

            return L;
        }

        Node* leftRotate(Node* leaf){
            Node* R = leaf->R;
            Node* Rl = R->L;

            R->L = leaf;
            leaf->R = Rl;

            leaf->height = max(h(leaf->L), h(leaf->R)) + 1;
            R->height = max(h(R->L), h(R->R)) + 1;

            return R;
        }

        int getBalance(Node* leaf){
            return h(leaf->L) - h(leaf->R);
        }

        int max(int h1, int h2){
            if (h1 > h2){
                return h1;
            }
            return h2;
        }

        int h(Node* leaf){
            if (leaf == nullptr){
                return -1;
            }
            return leaf->height;
        }

    public:
        AVL(){
            root = nullptr;
            size = 0;
        }

        void insert(int key){
            root = insertHelp(root, key);
            size++;
        }

        void preorder(Node* leaf){
            if (leaf == nullptr){
                return;
            }
            std::cout<< leaf->key << " ";
            preorder(leaf->L);
            preorder(leaf->R);
        }

        void inorder(Node* leaf){
            if (leaf == nullptr){
                return;
            }
            inorder(leaf->L);
            std::cout << leaf->key << " ";
            inorder(leaf->R);
        }

        void posorder(Node* leaf){
            if (leaf == nullptr){
                return;
            }
            posorder(leaf->L);
            posorder(leaf->R);
            std::cout << leaf->key << " ";
        }

        Node* getRoot(){
            return root;
        }
};

int main(){
    std::string input;

    int operacoes, key, i;

    std::cin >> operacoes;

    AVL dict; 

    for (i=0; i < operacoes; i++){
        std::cin >> input;

        if (input == "insert"){
            std::cin >> key;
            dict.insert(key);
        } else if(input == "pre"){
            dict.preorder(dict.getRoot());
        } else if (input == "in"){
            dict.inorder(dict.getRoot());
        } else if (input == "post"){
            dict.posorder(dict.getRoot());
        }
    }
}

// int main(){
//     int casos, n, key, i, j, k;

//     std::cin >> casos;

//     for (i=0; i < casos; i++){
//         std::cin >> n;
        
//         AVL dict;

//         for (j=0; j < n; j++){
//             std::cin >> key;
//             dict.insert(key);
//         }
//         dict.preorder(dict.getRoot());
//     }
//     std::cout << std::endl;
// }


