#include <iostream>

#include <vector>

using namespace std;

#ifndef MINIMAX_HPP
#define MINIMAX_HPP

class MiniMax {
    private:
        vector<int> * prova = new vector<int>;
        void echoProva();
    public:
    MiniMax (vector<int> &positions);
    ~MiniMax(){
    }
};

MiniMax::MiniMax(vector<int> &positions){
    
}

void MiniMax::echoProva() {
    
}

#endif