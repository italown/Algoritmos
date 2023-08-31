#include <iostream>
#include <vector>
#include <queue>

class Node{
    public:
        int anterior;
        int atual;
        int custo;

        Node(int anterior, int atual, int custo){
            this->anterior = anterior;
            this->atual = atual;
            this->custo = custo;
        }

        Node(){
            this->anterior = 0;
            this->atual = 0;
            this->custo = 0;
        }
};

struct compare{
    bool operator() (const Node t1, const Node t2) const{
        if (t1.custo != t2.custo){
            return (t1.custo > t2.custo);
        }
        return (t1.atual > t2.atual);
    }
};


class Graph{
    private:
        int** matrix;
        bool* mark;
        int size;

    public:
        Graph(int size){
            this->size = size;

            mark = new bool[size];

            matrix = new int*[size];

            for (int i = 0; i < size; i++){
                matrix[i] = new int[size];
                for (int j = 0; j < size; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        ~Graph(){
            delete[] mark;

            for (int i = 0; i < size; i++){
                delete[] matrix[i];
            }

            delete[] matrix;
        }

        int first(int v){
            for (int i=0; i < size; i++){
                if (matrix[v][i] != 0){
                    return i;
                }
            }
            return size;
        }

        int next(int v, int w){
            for (int i = w+1 ; i < size; i++){
                if (matrix[v][i] != 0){
                    return i;
                }
            }
            return size;
        }

        void add(int i, int j, int w){
            matrix[i][j] = w;
            matrix[j][i] = w;
        }

        void dijkstra(int v){
            int D[size];
            int P[size];

            int MAX = 100000;

            for (int i = 0; i < size; i++){
                D[i] = MAX;
                P[i] = -1;
                mark[i] = false;
            }

            D[v] = 0;

            std::priority_queue<Node, std::vector<Node>, compare> pq;

            pq.push(Node(v, v, 0));

            for (int i =0; i < size; i++){
                Node temp;

                do {
                    if (pq.empty()){
                        return;
                    }
                    temp = pq.top();
                    pq.pop();
                } while (mark[temp.atual]);

                P[v] = temp.anterior;
                
                int v = temp.atual;

                mark[v] = true;

                int w = first(v);

                while (w < size){
                    if (!mark[w] && (D[w] > (D[v] + matrix[v][w]))){
                        D[w] = D[v] + matrix[v][w];
                        pq.push(Node(v, w, D[w]));
                    }
                    w = next(v, w);

                }
            }

            for (int i = 0; i < size; i++){
                if (D[i] != MAX){
                    std::cout << D[i] << " ";
                }
            }
        }
};

int main(){
    int n, m, v;

    std::cin >> n >> m >> v;

    Graph grafo(n);

    for (int i = 0; i < m; i ++){
        int x, y, z;

        std::cin >> x >> y >> z;

        grafo.add(x, y, z);
    }

    grafo.dijkstra(v);

    std::cout << std::endl;
}

