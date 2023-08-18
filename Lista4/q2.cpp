#include <iostream>
#include <vector>

class Heap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] > heap[index]) {
                std::swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int menor = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[menor]) {
            menor = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] < heap[menor]) {
            menor = rightChild;
        }

        if (menor != index) {
            std::swap(heap[index], heap[menor]);
            heapifyDown(menor);
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int top() {
        return heap[0];
    }

    void pop() {
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    size_t size() {
        return heap.size();
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    int n;
    while (std::cin >> n && n) {
        Heap pq;

        for (int i = 0; i < n; i++) {
            int num;
            std::cin >> num;
            pq.push(num);
        }

        long long int custo = 0;
        while (pq.size() > 1) {
            int soma = pq.top();
            pq.pop();
            soma += pq.top();
            pq.pop();
            custo += soma;
            pq.push(soma);
        }

        std::cout << custo << std::endl;
    }
    return 0;
}