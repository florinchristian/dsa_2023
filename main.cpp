#include <fstream>
#include "cmake-build-debug/Heap.cpp"

#define newLine "\n";

using namespace std;

ifstream fin("data.in");
ofstream fout("data.out");

int n, k, x;
Heap heap;

int main() {
    fin >> n >> k;

    while (n--) {
        fin >> x;
        heap.insert(x);
    }

    while (k--) {
        fout << heap.getMaximum() << newLine;
    }
}
