#include <iostream>
#include <string>
#include <fstream>
#include "lib.h"

using namespace std;

int main() {

    ifstream file("/Users/apple/CLionProjects/OOP_dorogi/roads");
    Doroga *mass = new Doroga[Roads];
    char destination, arrival;

    fillind_mass(file, mass);

    for (int i = 0; i < Roads; i++) {

        cout << mass[i].destination << " " << mass[i].arrival << " " << mass[i].length << endl;
    }

    cout << "Введите пункт отправления: ";
    cin >> destination;
    cout << endl << "Введите пункт назначения: ";
    cin >> arrival;
    cout << endl;

    int result = choose_shortest(destination, arrival, mass);

    cout << "Кратчайшее расстояние из пункта " << destination << " в пункт " << arrival << ": " << result;

    return 0;
}