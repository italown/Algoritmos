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

        int first(int v){
            if (!list[v].empty()){
                return list[v][0].second;
            }
            return size;
        }

        int next(int v, int w){
            for (int i; i < list[v].size(); i++){
                if (list[v][i].second == w ){
                    if (list[v][i].second < list[v].size()){
                        return list[v][i+1].second;
                    }
                    break;
                }
            }
            return size;
        }

        void add(int i, int j, int w){
            list[i].push_back({w, j});
            list[j].push_back({w, i});
        }

        void dijkstra(int s, int end){
            int D[size];

            const int MAX = 100000;

            for (int i = 0; i < size; i++){
                D[i] = MAX;
            }

            D[s] = 0;

            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int,int>>> pq;

            pq.push({0, s});

            while (!pq.empty()){
                int dist = pq.top().first;
                int v = pq.top().second;
                pq.pop();

                if (dist > D[v]){
                    continue;
                }

                for (int i = 0; i < list[v].size(); i++){
                    int peso = list[v][i].first;
                    int q = list[v][i].second;

                    if(D[q] > dist + peso){
                        D[q] = dist + peso;
                        pq.push({D[q], q});
                    }

                }
            }
            if (D[end] == MAX){
                std::cout << "unreachable" << std::endl;
            } else{
                std::cout << D[end] << std::endl;
            }
            
        }
};

int main(){
    int casos;
    std::cin >> casos;
    
    for (int k =0; k < casos; k++){
        std::cout << "Case #" << k+1 << ": ";
        int n, m, v, s;

        std::cin >> n >> m >> v >> s;

        Graph grafo(n);

        for (int i = 0; i < m; i ++){
            int x, y, z;

            std::cin >> x >> y >> z;

            grafo.add(x, y, z);
        }

        if (m == 0){
            std::cout << "unreachable" << std::endl;
            continue;
        }

        grafo.dijkstra(v, s);
    }
}
