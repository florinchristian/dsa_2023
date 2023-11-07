#include <vector>

using namespace std;

class Heap {
private:
    vector<int> heap;

    void keepUp(int index) {
        int parent = (index - 1) / 2;

        while (index > 0 && this->heap[index] < this->heap[parent]) {
            swap(this->heap[index], this->heap[parent]);

            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void keepDown(int index) {
        int smallest = index;

        int leftChild = index * 2 + 1;
        int rightChild = index * 2 + 2;

        if (leftChild < this->heap.size() && this->heap[leftChild] < this->heap[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < this->heap.size() && this->heap[rightChild] < this->heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(this->heap[smallest], this->heap[index]);
            this->keepDown(smallest);
        }
    }
public:
    void insert(int x) {

        this->heap.push_back(x);

        int index = (int) this->heap.size() - 1;

        this->keepUp(index);
    }

    int getMinimum() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty.");
        }

        int result = this->heap[0];

        heap[0] = this->heap.back();
        this->heap.pop_back();

        this->keepDown(0);

        return result;
    }
};