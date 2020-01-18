#include "lib.h"


void fillind_mass(ifstream &file, Doroga *mass) {

    string a;

    for (int i = 0; i < Roads; i++) {

        getline(file, a);
        mass[i].destination = a[0];

        a = a.erase(0, 2);
        mass[i].arrival = a[0];

        a = a.erase(0, 2);
        int len = atoi(a.c_str());
        mass[i].length = len;

    }
}

int choose_shortest(char destination, char arrival, Doroga *mass) {

    int result = 0, points_val = 1;
    int dest = 0, arr = 0;

    for (int i = 1; i < Roads; i++) {
        if (mass[i - 1].destination != mass[i].destination) {
            points_val++;       //Выясняем сколько у нас всего точек
        }
    }

    char *points = new char[points_val];
    points[0] = 'A';
    int koeef = 1;
    for (int i = 1; i < Roads; i++) {
        if (mass[i - 1].destination != mass[i].destination) {
            points[koeef] = mass[i].destination;        //Заполняем массив в котором все точки
            koeef++;
        }
    }

    for (int i = 0; i < points_val; i++) {      //Выесняем строку и столбец искомого элемента в матрице
        if (points[i] == destination) {
            dest = i;
        } else if (points[i] == arrival) {
            arr = i;
        }
    }

    /*int **matrix = new int *[points_val];       //Заводим матрицу весов
    for (int i = 0; i < points_val; i++) {
        matrix[i] = new int[points_val];
    }*/
    int matrix[points_val][points_val];
    int koef = 0;

    for (int i = 0; i < points_val; i++) {      //Заполняем первую матрицу
        for (int j = 0; j < points_val; j++) {

            if (i == j) {
                matrix[i][j] = 0;
            } else if (points[i] == mass[koef].destination && points[j] == mass[koef].arrival) {
                matrix[i][j] = mass[koef].length;
            } else {
                matrix[i][j] = INT_MAX;
            }
            koef++;
        }
    }

    for(int k = 0; k<points_val; k++){
        for(int i = 0; i<points_val; i++){
            for(int j = 0; j<points_val; j++){

                if(matrix[i][k]+matrix[k][j]<matrix[i][j]){

                    matrix[i][j] = matrix[i][k]+matrix[k][j];
                }
            }
        }
    }

    result = matrix[dest][arr];

    return result;
}