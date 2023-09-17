#include <iostream>
#include <vector>
#include <queue>

class Graph{
    private:
        std::vector<std::vector<std::pair<int,int>>> list;
        int size;

    public:
        Graph(int size){
            this->size = size;
            list.resize(size);
        }

        void add(int i, int j, int w){
            list[i].push_back({w, j});
            list[j].push_back({w, i});
        }

        void dijkstra(int s, int end) {
        int D[size];
        int max = 0; // Variável para rastrear o peso da maior aresta no menor caminho

        const int MAX = 100000;

        for (int i = 0; i < size; i++) {
            D[i] = MAX;
        }

        D[s] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        pq.push({0, s});

        while (!pq.empty()) {
            int dist = pq.top().first;
            int v = pq.top().second;
            pq.pop();

            if (dist > D[v]) {
                continue;
            }

            for (int i = 0; i < list[v].size(); i++) {
                int peso = list[v][i].first;
                int q = list[v][i].second;

                if (D[q] > dist + peso) {
                    D[q] = dist + peso;
                    pq.push({D[q], q});
                    if (peso > max) {
                        max = peso;
                    }
                }
            }
        }
        
        if (D[end] == MAX) {
            std::cout << "IMPOSSIBLE" << std::endl;
        } else {
            std::cout << max << std::endl; 
        }
    }

};

int main() {
    int vertices, arestas, x, y, z, i, start, end;

    std::cin >> vertices >> arestas;

    Graph grafo(vertices);

    for (i = 0; i < arestas; i++) {
        std::cin >> x >> y >> z;
        grafo.add(x, y, z);
    }

    while (true) {
        std::cin >> start >> end;

        if (start == 0 && end == 0) {
            std::cout << "IMPOSSIBLE";
            break;
        }

        grafo.dijkstra(start, end);
    }

    return 0;
}