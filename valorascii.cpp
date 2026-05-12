#include <iostream>
using namespace std;
int main(){
    char c;
    cout << "Ingrese un caracter: ";
    cin >> c;
    cout << "El valor ASCII de " << c << " es " << int(c) << endl;
    return 0;
}