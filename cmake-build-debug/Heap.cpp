//
// Created by Cristi on 07.11.2023.
//

#include <vector>
#include <map>

using namespace std;

class Heap {
private:
    vector<int> heap;
    map<int, int> frequency;

    void keepUp(int index) {
        int parent = (index - 1) / 2;

        while (index > 0 && this->frequency[this->heap[index]] > this->frequency[this->heap[parent]]) {
            swap(this->heap[index], this->heap[parent]);

            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void keepDown(int index) {
        int highest = index;

        int leftChild = index * 2 + 1;
        int rightChild = index * 2 + 2;

        if (leftChild < this->heap.size()
            && this->frequency[this->heap[leftChild]] > this->frequency[this->heap[highest]]
                ) {
            highest = leftChild;
        }

        if (rightChild < this->heap.size()
            && this->frequency[this->heap[rightChild]] > this->frequency[this->heap[highest]]
                ) {
            highest = rightChild;
        }

        if (highest != index) {
            swap(this->heap[highest], this->heap[index]);
            this->keepDown(highest);
        }
    }

public:
    void insert(int x) {
        if (this->frequency[x] > 0) {
            this->frequency[x]++;

            int index = 0;

            for (int i = 0; i < this->heap.size(); ++i) {
                if (this->heap[i] == x) {
                    index = i;
                    break;
                }
            }

            this->keepUp(index);

            return;
        }

        this->heap.push_back(x);

        this->frequency[x] = 1;

        int index = (int) this->heap.size() - 1;

        this->keepUp(index);
    }

    int getMaximum() {
        if (this->heap.empty()) {
            throw out_of_range("Heap is empty.");
        }

        int result = this->heap[0];

        this->heap[0] = this->heap.back();
        this->heap.pop_back();

        this->frequency[result] = -1;

        this->keepDown(0);

        return result;
    }
};