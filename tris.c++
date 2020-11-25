#include "GL/gl.h" // File header per la libreria OpenGL
#include "GL/glut.h" // File header per la libreria GLUT
#include <stdlib.h> // File header per usare 'exit()'
#include <math.h>       /* sin */
#include <iostream>

#define PI 3.14159265

using namespace std;

bool XO = false;                                                                //Serve al metodo draw per stabilire se disegnare un cerchio o una croce
int coordinate[9][2];                                                           //Serve per memorizzare tutte le coordinate dei vari cerchi/croci
int coordinateCount = 1;                                                        //Serve a tenere memorizzato gli array già utilizzati

int checkWinner();                                                              //Metodo per stabilire se c'è ed eventualmente chi è il vincitore
bool checkIfIsFull(int x, int y){                                               //Metodo che serve per stabilire se si può disegnare una croce o x in una determinata casella oppure vedere se è occupata. Restituisce un valore boolean
    bool compatible = 0;                                                        //Variabile da restituire. Se rimane 0 si può disegnare in quella casella, altrimenti è già utilizzata
    for (int i = 0; i < coordinateCount - 1; i++){                              //Viene fatto un loop che corrisponde al numero di caselle già piene
        int coordinateX = coordinate[i][0];                                     //Per comodità si atribuiscono i valore dell'array a una variabile
        int coordinateY = coordinate[i][1];
        if (coordinateX == x && coordinateY == y){                              //Controlla se la casella richiesta è libera o occupata
            compatible = 1;                                                     //Se occupata la variabile "compatibile" diventa 1
        }
    }
    return compatible;                                                          //Restituisce la variabile compatibile
}
void gameOver(){                                                                //Una serie di comandi che servono a "Ripulire" lo spazio già usato dalle caselle.
    for (int i = 0; i < coordinateCount - 1; i++){                              //Vengono ripetuti i comandi seguenti.  Si sottrae uno alla variavile "cordinateCount" perché gli array si iniziano a contare da zero
        coordinate[i][0] = 0;                                                   //Si azzerano le coordinate X e Y in modo che il metodo draw non le disegni
        coordinate[i][1] = 0;
    }
    coordinateCount = 0;                                                        //Si azzera il contatore dell'array "coordinate"

}
void drawO(int positionX, int positionY);                                       //Metodo usato per disegnare gli O
void drawX(int positionX, int positionY);                                       //Metodo usato per disegnare le X
void backGround();                                                              //Metodo usato per disegnare lo sfondo
void draw();                                                                    //Metodo usato per gestire le parti da disegnare
void display_callback();                                                        //Viene usato per disegnare lo sfondo. Viene chiamato direttamente da glut 
void init();                                                                    //
void mouseFunction(int button, int state, int x, int y){
    // cout << x << " " << y << " " << state << " " << button << endl;
    if (x < 166 && y > 331) {
        if (state == 1){
            if (checkIfIsFull(1,1) == 0) {
                coordinate[coordinateCount -1][0] = 1;
                coordinate[coordinateCount -1][1] = 1;
                coordinateCount++;
                draw();
            }
            else {
                cout << "You can't select the same square 2 time" << endl;
            }
        }  
    }
    else if (x < 166 && y < 331 && y > 166) {
        if (state == 1){
            if (checkIfIsFull(1,2) == 0) {
                coordinate[coordinateCount -1][0] = 1;
                coordinate[coordinateCount -1][1] = 2;
                coordinateCount++;
                draw();
            }
            else {
                cout << "You can't select the same square 2 time" << endl;
            }            
        }
    }
    else if (x < 166 && y < 166) {
        if (state == 1){
            if (checkIfIsFull(1,3) == 0){
                coordinate[coordinateCount -1][0] = 1;
                coordinate[coordinateCount -1][1] = 3;
                coordinateCount++;
                draw();
            }
            else {
                cout << "You can't select the same square 2 time" << endl;
            }
        }
    }
    else if (x < 332 && x > 166 && y > 331) {
        if (state == 1){
            if (checkIfIsFull(2,1) == 0){
                coordinate[coordinateCount -1][0] = 2;
                coordinate[coordinateCount -1][1] = 1;
                coordinateCount++;
                draw();
            }
            else {
                cout << "You can't select the same square 2 time" << endl;
            }
        }
    }
    else if (x < 332 && x > 166 && y < 331 && y > 166) {
        if (state == 1){
            if (checkIfIsFull(2,2) == 0){
                coordinate[coordinateCount -1][0] = 2;
                coordinate[coordinateCount -1][1] = 2;
                coordinateCount++;
                draw();
            }
            else {
                cout << "You can't select the same square 2 time" << endl;
            }
        }
    }
    else if (x < 332 && x > 166 && y < 166) {
        if (state == 1){
            if (checkIfIsFull(2,3) == 0){
                coordinate[coordinateCount -1][0] = 2;
                coordinate[coordinateCount -1][1] = 3;
                coordinateCount++;
                draw();
            }
            else {
                cout << "You can't select the same square 2 time" << endl;
            }
        }
    }
    else if (x > 332 && y > 331) {
        if (state == 1){
            if (checkIfIsFull(3,1) == 0){
                coordinate[coordinateCount -1][0] = 3;
                coordinate[coordinateCount -1][1] = 1;
                coordinateCount++;
                draw();
            }
            else {
                cout << "You can't select the same square 2 time" << endl;
            }
        }
    }
    else if (x > 332 && y < 331 && y > 166) {
        if (state == 1){
            if (checkIfIsFull(3,2) == 0){
                coordinate[coordinateCount -1][0] = 3;
                coordinate[coordinateCount -1][1] = 2;
                coordinateCount++;
                draw();
            }
            else {
                cout << "You can't select the same square 2 time" << endl;
            }
        }
    }
    else {
        if (state == 1){
            if (checkIfIsFull(3,3) == 0){
                coordinate[coordinateCount -1][0] = 3;
                coordinate[coordinateCount -1][1] = 3;
                coordinateCount++;
                draw();
            }
            else {
                cout << "You can't select the same square 2 time" << endl;
            }
        }
    } 

}


int main(int argc, char** argv){
    cout << cos(45*PI/180) << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(498,498);
    glutCreateWindow("Tris");
    glutMouseFunc(mouseFunction);
    glutDisplayFunc(display_callback);
    init();
    //glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}

void draw(){
        glClearColor (1.0f, 1.0f, 1.0f, 1.0f); // Sfondo nero
        glClear (GL_COLOR_BUFFER_BIT);         // Cancella la scena

        // backGround();

        // glutSwapBuffers();

        backGround();

        checkWinner();

        XO = false;
        
        for (int i = 0; i < coordinateCount - 1; i++){
            int XtoDraw = coordinate[i][0];
            int YtoDraw = coordinate[i][1];
            if (XO == false){
                drawX(XtoDraw,YtoDraw);
                XO = true;
            }
            else{
                drawO(XtoDraw,YtoDraw);
                XO = false;
            }
        }



        if (coordinateCount < 10){
        
        }
        else {
            for (int i = 0; i < coordinateCount - 1; i++){
                coordinate[i][0] = 0;
                coordinate[i][1] = 0;
            }
            coordinateCount = 0;
        }

        glutSwapBuffers();        

}

void drawO(int positionX, int positionY){
        glLineWidth(4.0);
        glColor3f(0.0, 0.0, 0.0);

        glBegin(GL_LINES);
            for (int i = 0; i < 360; i++) {
                double x, y;
                int radius = 50;
                
                x = cos((i-1)*PI/180)*radius + 174 + (positionX*116 - 116 - 116);
                y = sin((i-1)*PI/180)*radius + 58 + (positionY*116 - 116);
                //cout << x << " " << y << endl;
                glVertex3f(x,y,0);
                x = cos(i*PI/180)*radius + 174 + (positionX*116 - 116 - 116);
                y = sin(i*PI/180)*radius + 58 + (positionY*116 - 116);
                glVertex3f(x,y,0);
            }
        glEnd();    
}

void drawX(int positionX, int positionY){
    glLineWidth(4.0);
    glColor3f(0.0, 0.0, 0.0);
    int position = positionX * 116 - 116;
    int position2 = positionY * 116 - 116;
    glBegin(GL_LINES);
        glVertex2f(10 + position,10 + position2);
        glVertex2f(106 + position,106 + position2);
        glVertex2f(10 + position,106 + position2);
        glVertex2f(106 + position,10 + position2);
    glEnd();
}

void init(){
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, 348,0,348, 0,1);
    //glClearColor(1.0, 1.0, 1.0, 1.0); 
}

void display_callback(){
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
    glClearColor (1.0f, 1.0f, 1.0f, 1.0f); // Sfondo nero
    glClear (GL_COLOR_BUFFER_BIT);         // Cancella la scena
    backGround();
    glutSwapBuffers();
    //draw(0,0);
}

void backGround(){
    bool color = false;

    for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                if (color == false){
                    glColor3f(1.0, 1.0, 1.0);
                    color = true;
                }
                else{
                    glColor3f(0.8, 0.8, 0.8);
                    color = false;
                }
                glBegin(GL_POLYGON_BIT);
                    //glColor3f(1.0, 0.0, 0.0);
                    glVertex2f(i*116,(j+1)*116);
                    glVertex2f((i+1)*116, (j+1)*116.0);
                    glVertex2f(i*116,j*116);
                    glVertex2f((i+1)*116,j*116);
                glEnd();
                
            }
            
        }
        //draw();
        //glutSwapBuffers ();
}

int checkWinner(){
    int coordinateX[9][2];
    int coordinateO[9][2];
    int countCoordinateX = 0;
    int countCoordinateO = 0;
    bool separateCoordinate = true;

    // cout << "Le X sono su: ";

    for (int i = 0; i < coordinateCount -1; i = i+2){
        coordinateX[countCoordinateX][0] = coordinate[i][0];
        coordinateX[countCoordinateX][1] = coordinate[i][1];
        // cout << coordinateX[countCoordinateX][0] << "," << coordinateX[countCoordinateX][1] << " ";
        countCoordinateX++;
    }

    // cout << endl;

    // cout << "Gli zeri sono su: ";

    for (int i = 1; i < coordinateCount -1; i = i+2){
        coordinateO[countCoordinateO][0] = coordinate[i][0];
        coordinateO[countCoordinateO][1] = coordinate[i][1];
        // cout << coordinateO[countCoordinateO][0] << "," << coordinateO[countCoordinateO][1] << " ";
        countCoordinateO++;
    }

    // cout << endl;

    int coordinateToCheck[] = {1, 1};
    for (int i = 0; i<6; i++){
        int horizontalAxO = 0;
        for(int j = 0; j < countCoordinateX; j++){
            if (coordinateX[countCoordinateX][1] == coordinateToCheck[1]){
                horizontalAxO ++;
            }
        }
        cout << horizontalAxO << endl;
        for(int j = 0; j < countCoordinateO; j++){
            //cout << j << endl;
        }
    }
    
    return 0;
}