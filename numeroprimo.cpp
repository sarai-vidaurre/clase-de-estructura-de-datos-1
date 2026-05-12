#include <iostream>
using namespace std;

int main() {
    int numero;
    bool primo = true;
    cout << "Ingrese un número para saber si es primo: ";
    cin >> numero;

    if (numero <= 1) {
        primo = false;
    }
    else {
        for (int divisor = 2; divisor < numero; divisor++) {
            if (numero % divisor == 0) { 
                primo = false;  
                break;  
            }
        }
    }

    if (primo == true) {
        cout <<"El "<< numero << " SÍ es un número primo." << endl;
    } else {
        cout <<"El "<< numero << " NO es un número primo." << endl;
    }

    return 0;
}