#ifndef MINIMUMAIFUNCTION_HPP
#define MINIMUMAIFUNCTION_HPP

#include <iostream>

using namespace std;

class MiniMax{
    private:
        int coordinateX[5][2];
        int coordinateO[4][2];
        int coordinateCount;
        // bool checkIfIsFull(int x, int y){
        //     bool compatible = 0;
        //     for (int i = 0; i < coordinateCount - 1; i++){
        //         int coordinateX = coordinateX[i][0];
        //         int coordinateY = coordinate[i][1];
        //         if (coordinateX == x && coordinateY == y){
        //             compatible = 1;
        //         }
        //     }
        //     return compatible;
        // }
        void oneParameter(){
        }
        void twoParameter(){
        }
        void threeParameter(){
        }
        void fourParameter(){
        }
        void fiveParameter(){
        }
        int sixParameter(){
            return 0;
        }
        int sevenParameter(){
            return 0;
        }
        int eightParameter(){
            return 0;
        }
    public:
        MiniMax(){
            cout << "Prova!" << endl;
        }
        MiniMax(int array[2][2], int size){
            
        }

        ~MiniMax(){
            cout << "Tresco!" << endl;
        }
};

#endif