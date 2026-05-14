// Potencia
#include <iostream>
using namespace std;
int calcularpotencia (int, int);
int main(){
    int base,potencia,resultado;
    cout << "Ingrese un numero base: ";
    cin >> base;
    cout << "Ingrese un numero potencia: ";
    cin >> potencia;
    resultado = calcularpotencia(base,potencia);
    cout << base << "^" << potencia << " = " << resultado;
    return 0;
}
int calcularpotencia(int base, int potencia){
    
    if (potencia !=0){
        return base * calcularpotencia(base, potencia-1);
        
    }
    else{
        return 1;
    }
}