#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    cout << "================================================" << endl;
    cout << "         TABLA ASCII DEL 0 AL 200" << endl;
    cout << "================================================" << endl;
    cout << "  Dec  |  Char  |  Dec  |  Char  |  Dec  |  Char" << endl;
    cout << "------+--------+-------+--------+-------+-------" << endl;

    // Mostrar en columnas de 3
    for(int i = 0; i <= 200; i += 3) {
        // Primera columna
        cout << setw(4) << i << "   |   ";
        if(i >= 32 && i <= 126) {
            cout << "  " << char(i) << "    |   ";
        } else if(i == 10) {
            cout << " \\n   |   ";  // Nueva línea
        } else if(i == 13) {
            cout << " \\r   |   ";  // Retorno de carro
        } else if(i == 9) {
            cout << " \\t   |   ";  // Tabulador
        } else {
            cout << "  ?    |   ";
        }

        // Segunda columna
        if(i + 1 <= 200) {
            cout << setw(4) << i + 1 << "   |   ";
            if(i + 1 >= 32 && i + 1 <= 126) {
                cout << "  " << char(i + 1) << "    |   ";
            } else if(i + 1 == 10) {
                cout << " \\n   |   ";
            } else if(i + 1 == 13) {
                cout << " \\r   |   ";
            } else if(i + 1 == 9) {
                cout << " \\t   |   ";
            } else {
                cout << "  ?    |   ";
            }
        } else {
            cout << "           |       ";
        }

        // Tercera columna
        if(i + 2 <= 200) {
            cout << setw(4) << i + 2 << "   |   ";
            if(i + 2 >= 32 && i + 2 <= 126) {
                cout << "  " << char(i + 2) << endl;
            } else if(i + 2 == 10) {
                cout << " \\n" << endl;
            } else if(i + 2 == 13) {
                cout << " \\r" << endl;
            } else if(i + 2 == 9) {
                cout << " \\t" << endl;
            } else {
                cout << "  ?" << endl;
            }
        } else {
            cout << endl;
        }
    }

    return 0;
}