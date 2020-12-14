#ifndef MINIMUMAIFUNCTION_HPP
#define MINIMUMAIFUNCTION_HPP

#include <iostream>
#include <array>

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

class MiniMax{
    private:
        int** position;
        int sizePosition;
        int avaiblePositionArray[0][2];
        int avaiblePosition(){
            for (int i = 0; i < 9; i++){
                cout << BLUE << i/3+1 << "," << i - i/3*3+1 << RESET << endl;
                int x = i/3+1;
                int y = i - i/3*3+1;
                cout << RED << x << "," << BLUE << y << RESET << endl;
                for (int j = 0; j < sizePosition; j++){

                    if(position[j][0] == x && position[j][1] == y){
                        cout << "Divisible" << endl;
                    }
                }
            }
            return 0;
        }
    public:
        MiniMax(){
            cout << "\033[0;31mYou must have more arguments! \033[0m" << endl;
        }
        MiniMax(int array[][2], int size){
            position = new int*[size];
            for (int i = 0; i < size; ++i){
                position[i] = new int[2];
            }
            for (int i = 0; i < size; i++){
                position[i][0] = array[i][0];
                position[i][1] = array[i][1];
            }
            sizePosition = size;
            avaiblePosition();
        }
        
        ~MiniMax(){
            cout << "\033[1;33m" << "Tresco!" << "\033[0m" << endl;
        }
};

#endif