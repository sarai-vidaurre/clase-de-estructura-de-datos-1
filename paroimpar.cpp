#include <iostream>
using namespace std;

int main() {
    int numero;

    // Pedir el número al usuario
    cout << "Ingrese un número entero: ";
    cin >> numero;

    // Verificar si es par o impar
    if (numero % 2 == 0) {
        cout << numero << " es PAR" << endl;
    } else {
        cout << numero << " es IMPAR" << endl;
    }

    return 0;
}