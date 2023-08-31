#include <iostream>
#include <queue>
#include <stack>
#include <vector>
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

        void toposort(int v){
            std::stack<int> stack;
            help_toposort(v, stack);
        }

        void help_toposort(int v, std::stack<int> s){
            for (int i=0; i < size; i++){
                mark[i] = false;
            }
            mark[v] = true;
            int w = first(v);

            while(w < size){
                if (!mark[w]){
                    help_toposort(w, s);
                }
                w = next(v, w);
            }
            std::cout << v << " ";
        }

};


int main(){
    int vertices, arestas;

    std::cin >> vertices >> arestas;

    Graph grafo(vertices);

    for (int j = 0; j < arestas; j++){
        int x, y;

        std::cin >> x >> y;

        grafo.setEdge(x, y);
    }

    grafo.toposort(1);

}

