#include <iostream>
#include <queue>
#include <string>

class Graph{
    private: 
        int** matrix;
        int numEdge;
        int size;
        bool* mark;

    public:
        Graph(int size){
            mark = new bool[size];
            numEdge = 0;
            this->size = size;
            
            matrix = new int* [size];

            for (int i = 0; i < size; i++){
                matrix[i] = new int[size];
                for (int j = 0; j < size; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        void clear(){
            delete[] mark;
            
            for (int i = 0; i < size; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        int first(int v){
            for (int j = 0; j < size; j++){
                if (matrix[v][j] != 0){
                    return j;
                }
            }
            return size;
        }

        int next(int v, int w){
            for(int j = w+1; j < size; j++){
                if (matrix[v][j] != 0){
                    return j;
                }
            }
            return size;
        }

        void setEdge(int i, int j){
            matrix[i][j] = 1;
        }

        void delEdge(int i, int j){
            matrix[i][j] = 0;
            matrix[j][i] = 0;
        }

        void graphTraverse(){
            for (int v = 0; v < size; v++){
                mark[v] = 0;
            }
            for (int v = 0; v < size; v++){
                if (mark[v] == 0){
                    DFS(v);
                }
            }
            std::cout << std::endl;
        }

        void DFS(int v){
            std::cout << v << " ";
            mark[v] = true;
            int w = first(v);

            while (w < size){
                if (mark[w] == false){
                    DFS(w);
                }
                w = next(v, w);
            }
        }

        void BFS(int start){
            std::queue <int> Q;
            Q.push(start);
            
            mark[start] = true;

            while (Q.size() > 0){
                int v = Q.front();
                Q.pop();

                std::cout << v << " ";

                int w = first(v);

                while (w < size){
                    if (!mark[w]){
                        mark[w] = true;
                        Q.push(w);
                    }
                    w = next(v, w);
                }
            }
        }

        void menor_caminho(int start, int end){
            std::queue <int> Q;

            Q.push(start);

            mark[start] = true;

            int dist[size];
            for (int i = 0; i < size; i++){
                dist[i] = -1;
            }
            dist[start] = 0;

            while (!Q.empty()){
                int v = Q.front();
                Q.pop();

                if (v== end){
                    std::cout << dist[end] << std::endl;
                    return;
                }

                int w = first(v);

                while (w < size){
                    if (!mark[w]){
                        mark[w] = true;
                        Q.push(w);
                        dist[w] = dist[v] + 1;
                    }
                    w = next(v, w);
                }
            }

            std::cout << -1 << std::endl;
            return;
        }

};


int main(){
    int casos;

    std::cin >> casos;

    for (int i = 0; i < casos; i++){
        int vertices, arestas;

        std::cin >> vertices >> arestas;

        Graph grafo(vertices);

        for (int j = 0; j < arestas; j++){
            int x, y;

            std::cin >> x >> y;

            grafo.setEdge(x, y);
        }

        int consultas;
        std::cin >> consultas;

        for (int j = 0; j < consultas; j++){
            int x,y;

            std::cin >> x >> y;

            grafo.menor_caminho(x, y);
        }
    }
}
