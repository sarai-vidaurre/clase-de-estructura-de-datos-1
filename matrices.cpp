//Matrices
#include <iostream>
using namespace std;

int main(){
    int notas [5];
    cout << "Ingrese 5 numeros: "<< endl;
    
    for (int i=0; i < 5; ++i)
        cin >> notas[i];
        cout << "los numeros ingresados al arreglo son: \n"<< endl;
        for (int i=0; i < 5; ++i)
            cout << notas[i] << "\n  "<< endl;
    return 0;
}