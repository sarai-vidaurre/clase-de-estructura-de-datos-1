#include <iostream>
using namespace std;

int main() {
    double num1, num2, num3, mayor;

    cout << "=== ENCONTRAR EL NÚMERO MÁS ALTO ===" << endl;
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;
    cout << "Ingrese el tercer número: ";
    cin >> num3;

    // Comparar para encontrar el mayor
    if (num1 >= num2 && num1 >= num3) {
        mayor = num1;
    } else if (num2 >= num1 && num2 >= num3) {
        mayor = num2;
    } else {
        mayor = num3;
    }

    cout << "\nEl número más alto es: " << mayor << endl;

    return 0;
}