#include <iostream>
#include "minumAiFunction.hpp"
#define RED "\033[0;31m"
#define BLACK "\033[0;30m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

using namespace std;

int main(){
    int a[][2] =  {{1,1},{2,2},{1,2},{3,1},{2,1}};
    int b[][2] = {{1,1},{2,2},{1,2},{3,1},{2,1},{3,3},{1,3}};
    int c[][2] = {{1,2}, {2,1}, {2,2},{1,1},{2,3},{3,1}};
    int d[][2] = {{1,1},{2,1},{2,2},{1,3},{3,3}};
    MiniMax  * prova = new MiniMax(a, 5);
    prova->updatePosition(b,7);
    prova->updatePosition(c, 6);
    prova->updatePosition(d, 5);
    delete prova;
    
    return 0;
}