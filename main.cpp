#include <fstream>
#include "cmake-build-debug/Heap.cpp"

#define newLine "\n";

using namespace std;

ifstream fin("data.in");
ofstream fout("data.out");

Heap heap;

int listCount;
int n, k, x;

int main() {
    fin >> listCount;

    while (listCount--) {
        fin >> n;

        while (n--) {
            fin >> x;
            heap.insert(x);
        }
    }

    while (!heap.isEmpty()) {
        fout << heap.getMinimum() << " ";
    }
}
