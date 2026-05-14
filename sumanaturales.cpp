// Calcular la suma de numeros naturales
#include <iostream>
using namespace std;
int suma (int n);
int main(){
    int n;
    cout << "Ingrese un numero positivo: ";
    cin >> n;
    cout << "La suma es igual a: "<< suma(n);
    return 0;
}
int suma(int n){
    if (n != 0){
        return n + suma(n-1);
    }
    else{
        return 1;
    }
}