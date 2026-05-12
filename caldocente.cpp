#include <iostream>
using namespace std;

int main() {
    double n;
    char op;
    cout <<"Ingrese el operador de la tabla "<< " +,-,*,/ ";
    cin >> op;
    cout <<"Ingrese un numero del 1 al 10 ";
    cin >> n;
    switch (op){
        case '+':
            for (int i=1; i<=10; i++){
                cout << n << "+" << i << "=" << n+i << endl;
            }
            break;
        case '-':
            for (int i=1; i<=10; i++){
                cout << n << "-" << i << "=" << n-i << endl;
            }
            break;
        case '*':
            for (int i=1; i<=10; i++){
                cout << n << "*" << i << "=" << n*i << endl;
            }
            break;
        case '/':
            for (int i=1; i<=10; i++)
                 cout << n << "/" << i << "=" << n/i << endl;   
            break;
        default:
            cout << "Operador no válido" << endl;
            break;
    }
     return 0;
}