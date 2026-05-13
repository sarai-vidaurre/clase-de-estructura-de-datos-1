#include <iostream>
#include <cmath>
using namespace std;
//declaramos la funcion
double Raiz(double);
int main() {
  double n=125, raizcuadrada;
  //llamamos a la funcion
  raizcuadrada = Raiz(n);
  cout << "La Raiz cuadrada de n es: " << n << " = "<< raizcuadrada<< endl;
  return 0;
}
double Raiz(double n){
  return sqrt(n);
}