#ifndef MINIMUMAIFUNCTION_HPP
#define MINIMUMAIFUNCTION_HPP

#include <iostream>
#include <array>

/* I define the colour for the output, work only on linux */

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

/* Initialize the class Minimax.                *
*  I use it to implement the minimax algorithm  *
*  https://en.wikipedia.org/wiki/Minimax        */

class MiniMax{
    /*  This is the privat part of the class                                *
    *   It contain the function for check avaible position, check winner,   *
    *   to update the used position and implement the minimax algorithm     */ 
    private:
        /* "position" is an integer bydimensional pointer array *
        *   and contain all the used position of tic-tac-toe    */
        int** position;
        /* "sizePosition" is an integer variable and I use it   *
        *   to memorize the size of position array              */
        int sizePosition;
        /* "position" is an integer bydimensional array         *
        *   and contain all the avaible position of tic-tac-toe */
        int avaiblePositionArray[9][2];
        /* "sizeAvaiblePositionArray" is an integer variable and I use it   *
        *   to memorize the size of "avaiblePositionArray" array            */
        int sizeAvaiblePositionArray = 0;
        /*  "avaiblePosition" is a void used for check if a determinate     *
        *   coordinate is busy or if it's avaible. If it's avible void      *
        *   transcribes the value in "avaiblePositionArray"                 */
        void avaiblePosition(){
            /*  Repeat 9 time(for check all position avaible)               */
            for (int i = 0; i < 9; i++){
                /* I use i/3+1 because i subtract all y value               */
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
                // cout << GREEN << avaiblePositionArray[i][0] << "," << avaiblePositionArray[i][1] << RESET << endl;
            }
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
                // cout << array[i][0] << "," << array[i][1] << endl;
            }
        }
        int checkWinner(){
            int coordinateToCheck[] = {1,1};
            int horizontalCheck = 0;
            int verticalCheck = 0;
            for (int j = 0; j < 3; j++) {
                horizontalCheck = 0;
                verticalCheck = 0;
                for (int i = 0; i < sizePosition; i = i+2){
                    cout << RED << position[i][1] << "     " << coordinateToCheck[1] << RESET << endl;
                    if (position[i][1] == coordinateToCheck[1]) {
                        horizontalCheck ++;
                    }
                    cout << RED << position[i][0] << "     " << coordinateToCheck[0] << RESET << endl;
                    if (position[i][0] == coordinateToCheck[0]) {
                        verticalCheck ++;
                    }
                }
                if (horizontalCheck == 3) {
                    cout << "The winner is X" << endl;
                    break;
                }
                if (verticalCheck == 3) {
                    cout << "The winner is X" << endl;
                    break;
                }
                for (int i = 0; i < sizePosition; i = i+2){
                    if (position[i][1] == coordinateToCheck[1]) {
                        horizontalCheck ++;
                    }
                    if (position[i][0] == coordinateToCheck[0]) {
                        verticalCheck ++;
                    }
                }
                horizontalCheck = 0;
                verticalCheck = 0;
                for (int i = 1; i < sizePosition; i = i+2){
                    if (position[i][1] == coordinateToCheck[1]) {
                        horizontalCheck ++;
                    }
                    if (position[i][0] == coordinateToCheck[0]) {
                        verticalCheck ++;
                    }
                }
                if (horizontalCheck == 3) {
                    cout << "The winner is O" << endl;
                    break;
                }
                if (verticalCheck == 3) {
                    cout << "The winner is O" << endl;
                    break;
                }
                coordinateToCheck[0]++;
                coordinateToCheck[1]++;
            }
            int diagonalCheck = 0;
            for (int j = 0; j < 3; j++){
                for (int i = 0; i < sizePosition; i = i+2) {
                    if (j == position[i][0] && j == position[i][0]){
                        diagonalCheck ++;
                    }
                }
            }
            if (diagonalCheck == 3) {
                cout << "The winner is X" << endl;
            }
            diagonalCheck = 0;
            for (int j = 1; j < 3; j++){
                for (int i = 1; i < sizePosition; i = i+2) {
                    if (j == position[i][0] && j == position[i][0]){
                        diagonalCheck ++;
                    }
                }
            }
            if (diagonalCheck == 3) {
                cout << "The winner is X" << endl;
            }
            return 0;
        }
        void clear() {
            sizeAvaiblePositionArray = 0;
        }
    public:
        void updatePosition(int array[][2], int size) {
            cout << "I'm updating position... " << size<< endl;
            sizePosition = size;
            clear();
            initialize(size);
            setArrayPosition(array, size);
            avaiblePosition();
            checkWinner();
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