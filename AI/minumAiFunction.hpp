#ifndef MINIMUMAIFUNCTION_HPP
#define MINIMUMAIFUNCTION_HPP

#include <iostream>
#include <array>

using namespace std;

class MiniMax{
    private:
        int** position;
        int sizePosition;
        int avaiblePositionArray[0][2];
        int avaiblePosition(){
            int coordinateToCheck[] = {1,1};
            for (int i = 0; i < 9; i++){
                
            }
            return 0;
        }
    public:
        MiniMax(){
            cout << "Prova!" << endl;
        }
        MiniMax(int array[][2], int size){
            position = new int*[size];
            for (int i = 0; i < size; ++i){
                cout << i << endl;
                position[i] = new int[2];
            }
            for (int i = 0; i < size; i++){
                cout << i << endl;
                position[i][0] = array[i][0];
                position[i][1] = array[i][1];
            }
            sizePosition = size;
            avaiblePosition();
        }

        ~MiniMax(){
            cout << "Tresco!" << endl;
        }
};

#endif