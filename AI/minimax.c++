#include <iostream>
#include "minumAiFunction.hpp"

using namespace std;

int main(){
    int a[][2] =  {{1,1},{2,2},{1,2},{3,1},{2,1}};
    // int * b = a;
    MiniMax  * prova = new MiniMax(a, 5);
    // int a[2][2] = {{1,2}, {1,2}};
    // MiniMax * prova2 = new MiniMax(a);
    
    // delete prova2;
    delete prova;
    
    return 0;
}