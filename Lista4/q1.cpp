#include <iostream>

class Node{
    public:
        int key;
        Node* R;
        Node* L;
        int leftF;
        int rightF;
        int height;

       Node(int key){
            this->key = key;
            this->L = nullptr;
            this->R = nullptr;
            leftF = 0;
            rightF = 0;
            height = 0;
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
                leaf->leftF ++;
            } else{
                leaf->R = insertHelp(leaf->R, key);
                leaf->rightF ++;
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

            leaf->leftF = find_f(leaf->L);
            leaf->rightF = find_f(leaf->R);

            L->rightF = find_f(L->R);
            L->leftF = find_f(L->L);

            return L;
        }

        Node* leftRotate(Node* leaf){
            Node* R = leaf->R;
            Node* Rl = R->L;

            R->L = leaf;
            leaf->R = Rl;

            leaf->height = max(h(leaf->L), h(leaf->R)) + 1;
            R->height = max(h(R->L), h(R->R)) + 1;

            //Ajuste do tamanho do filho
            leaf->leftF = find_f(leaf->L);
            leaf->rightF = find_f(leaf->R);

            R->leftF = find_f(R->L);
            R->rightF = find_f(R->R);

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

        int find_f(Node* leaf){
            if (leaf == nullptr)
            {
                return 0;
            }
            return 1 + leaf->leftF + leaf->rightF;
        }

        int findhelp(Node* leaf, int key){
            if (leaf == nullptr){
                return -13023002;
            }
            if (leaf->key > key){
                return findhelp(leaf->L, key);
            }
            else if (leaf->key == key){
                return 1 + leaf->leftF;
            }
            else{
                return 1 + leaf->leftF + findhelp(leaf->R, key);
            }
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
            std::cout<< leaf->key << std::endl;
            preorder(leaf->L);
            preorder(leaf->R);
        }

        Node* getRoot(){
            return root;
        }

        int find(int key){ 
            return findhelp(root, key); 
        }
 
};

int main()
{
    int cases, i;

    scanf("%d", &cases);

    AVL tree;
    for (i = 0; i < cases; i++){
        int operador, valor, resposta;

        scanf("%d", &operador);
        scanf("%d", &valor);

        if (operador == 1){
            tree.insert(valor);
        }
        else {
            resposta = tree.find(valor);
            if (resposta < 0){ 
                printf("Data tidak ada\n");
            }
            else{
                printf("%d\n", resposta);
            }
        }
    }
}