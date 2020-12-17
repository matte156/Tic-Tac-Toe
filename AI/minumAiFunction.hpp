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
        int avaiblePositionArray[9][2];
        int sizeAvaiblePositionArray = 0;
        int avaiblePosition(){
            cout << PURPLE << "I check avaible position..." << endl;
            for (int i = 0; i < 9; i++){
                int x = i/3+1;
                int y = i - i/3*3+1;
                bool divisible = false;
                for (int j = 0; j < sizePosition; j++){
                    if(position[j][0] == x && position[j][1] == y){
                        divisible = true;
                        break;
                    }
                }
                if (!divisible) {
                    //cout << GREEN << x << "," << y << RESET << endl;
                    avaiblePositionArray[sizeAvaiblePositionArray][0] = x;
                    avaiblePositionArray[sizeAvaiblePositionArray][1] = y;
                    sizeAvaiblePositionArray++;
                }
            }
            for(int i = 0; i < sizeAvaiblePositionArray; i++){
                cout << GREEN << avaiblePositionArray[i][0] << "," << avaiblePositionArray[i][1] << RESET << endl;
            }
            checkWinner();
            return 0;
        }
        void initialize(int size) {
            position = new int*[size];
            for (int i = 0; i < size; ++i){
                position[i] = new int[2];
            }
        }
        void setArrayPosition(int array[][2], int size) {
            for (int i = 0; i < size; i++){
                position[i][0] = array[i][0];
                position[i][1] = array[i][1];
                cout << array[i][0] << "," << array[i][1] << endl;
            }
        }
        int checkWinner(){
            
            return 0;
        }
        void clear() {
            sizeAvaiblePositionArray = 0;
        }
    public:
        void updateArrayPosition(int array[][2], int size) {
            cout << "I'm updating position..." << endl;
            sizePosition = size;
            clear();
            initialize(size);
            setArrayPosition(array, size);
            avaiblePosition();
        }
        MiniMax(){
            cout << "\033[0;31mYou must have more arguments! \033[0m" << endl;
        }
        MiniMax(int array[][2], int size){
            initialize(size);
            setArrayPosition(array, size);
            sizePosition = size;
            avaiblePosition();
        }
        
        ~MiniMax(){
            cout << "\033[1;33m" << "Tresco!" << "\033[0m" << endl;
        }
};

#endif