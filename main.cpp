#include <iostream>
#include <chrono>
#include "dynamic_array.h"
using namespace std;

int josephus(DynamicArray& warriors, int step) {
    int num_warriors = warriors.size();
    int index = step - 1;
    while (num_warriors > 1) {
        warriors.removeAt(index);
        num_warriors--;
        index = (index + step - 1) % num_warriors;
    }
    return warriors[0];
}

int main() {
    setlocale(LC_ALL, "Ru");
    int n = 10000;
    int k = 2;
    DynamicArray warriors;
    warriors.reserve(n);
    for (int i = 1; i <= n; ++i) {
        warriors.append(i);
    }

    auto start = chrono::high_resolution_clock::now();
    int last_survivor = josephus(warriors, k);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_time = end - start;

    cout << "Last survivor: " << last_survivor << '\t' << elapsed_time.count() << " seconds" << endl;

    return 0;
}
