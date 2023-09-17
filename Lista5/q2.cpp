#include <iostream>
#include <queue>
#include <vector>

class Graph{
    private:
        std::vector<std::vector<int>> list;
        int size;
        std::vector<int> grau;
    
    public:
        Graph(int size){
            this->size = size;
            list.resize(size + 1);
            grau.resize(size + 1, 0);
        }

        void add(int i, int j){
            list[i].push_back(j);
            grau[j]++;
        }

        void toposort(){
            std::vector<int> ordem;
            std::priority_queue<int, std::vector<int>, std::greater<int>> q;;

            for (int i =1; i <= size; i++){
                if (grau[i] == 0){
                    q.push(i);
                }
            }
            while (!q.empty()){
                int c = q.top();
                q.pop();

                ordem.push_back(c);

                for (int i = 0; i < list[c].size(); i++){
                    grau[list[c][i]]--;
                    if (grau[list[c][i]] == 0){
                        q.push(list[c][i]);
                    }
                }
            }
            if (ordem.size() == size){
                for (int i = 0; i < size; i++){
                    std::cout << ordem[i] << " ";
                }
            } else{
                std::cout << "Sandro fails.";
            }
            std::cout << std::endl;
        }
};


int main(){
    int vertices, arestas;

    std::cin >> vertices >> arestas;

    Graph grafo(vertices);

    for (int j = 0; j < arestas; j++){
        int x, y;

        std::cin >> x >> y;

        grafo.add(x, y);
    }

    grafo.toposort();
}

