#include <fstream>

#include "cmake-build-debug/Heap.cpp"

#define newLine "\n";

ifstream fin("data.in");
ofstream fout("data.out");

using namespace std;

Heap heap;

int n, k, x, ans;

int main() {
    fin >> n >> k;

    while (n--) {
        fin >> x;
        heap.insert(x);
    }

    while (k--) {
        ans = heap.getMaximum();
    }

    fout << ans;
}
