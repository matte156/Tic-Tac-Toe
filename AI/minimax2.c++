#include <iostream>
#include <vector>
#include <array>
#include "minimax.hpp"

using namespace std;

int main() {
    vector<int> v;
    MiniMax * prova = new MiniMax(v);
    v.push_back(1);
    for (auto i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }
    //cout << v[0];
    return 0;
}