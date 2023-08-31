#include <iostream>
#include <vector>
#include <stack>

class Graph{
    private:
        std::vector<std::vector<int>> matrix;
        int size;
        bool* mark;
    
    public:
        Graph(int size){
            this->size = size;
            this->matrix.resize(size);
            this->mark = new bool[size];
        }

        void add(int i, int j){
            if (find(i, j)){
                matrix[i].push_back(j);
            }
        }

        bool find(int i, int j){
            for (int k = 0; k < matrix[i].size(); k++){
                if (matrix[i][k] == j){
                    return false;
                }
            }
            return true;
        }

        void print(){
            for (int i=0; i < size; i++){
                std::cout << i << ": ";
                for (int j=0; j < matrix[i].size(); j++){
                    std::cout << matrix[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

        int first(int i){
            for (int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] != 0){
                    return j;
                }
            }
            return size;
        }

        int next(int i, int j){
            for (int k = j+1; k < matrix[i].size(); k++){
                if (matrix[i][k] != 0){
                    return k;
                }
            }
            return size;
        }

        void toposort(int v, std::stack<int> s){

        std::vector<int> in_degree(V, 0);
    
        for (int u = 0; u < V; u++) {
            list<int>::iterator itr;
            for (itr = adj[u].begin();
                itr != adj[u].end(); itr++)
                in_degree[*itr]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (in_degree[i] == 0)
                q.push(i);

        int cnt = 0;
    
        vector<int> top_order;
    
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            top_order.push_back(u);
    
            list<int>::iterator itr;
            for (itr = adj[u].begin();
                itr != adj[u].end(); itr++)

                if (--in_degree[*itr] == 0)
                    q.push(*itr);
    
            cnt++;
        }
    
        // Check if there was a cycle
        if (cnt != V) {
            cout << "There exists a cycle in the graph\n";
            return;
        }
    
        // Print topological order
        for (int i = 0; i < top_order.size(); i++)
            cout << top_order[i] << " ";
        cout << endl;
}
        
};

int main(){
    Graph grafo(7);

    grafo.add(0, 1);
    grafo.add(0, 2);
    grafo.add(1, 5);
    grafo.add(1, 3);
    grafo.add(2, 3);
    grafo.add(3, 4);
    grafo.add(1, 4);
    grafo.add(4, 6);

    std::stack<int> s;
    grafo.toposort(0, s);
}