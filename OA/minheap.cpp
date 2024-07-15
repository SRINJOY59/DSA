#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MinHeap {
public:
    vector<int> heap;

    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(&heap[i], &heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            heapify(smallest);
        }
    }

    void buildHeap(const vector<int>& arr) {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    void levelOrderTraversal() {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }

private:
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    void swap(int* x, int* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
};

int main() {
    MinHeap minHeap;
    vector<int> arr = {85,12,36,96,88,14,75,36,99,10};
    
    minHeap.buildHeap(arr);

    cout << "Level order traversal of the min heap: ";
    minHeap.levelOrderTraversal();

    return 0;
}
