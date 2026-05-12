#include <iostream>
using namespace std;

int main() {
    int i, n;
    bool es_primo = true;

    cout << "ingrese un numero entero positivo: ";
    cin >> n;

    if (n == 0 || n == 1) {
        es_primo = false;
    }

    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            es_primo = false;
            break;
        }
    } // ¡CIERRE DEL FOR AQUÍ!

    if (es_primo)
        cout << "es primo" << endl;
    else
        cout << "no es primo" << endl;

    return 0;
}