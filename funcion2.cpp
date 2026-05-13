#include <iostream>
#include <cmath>
using namespace std;
//declaramos la funcion
void mostrar(char='*',int=3);

int main() {
  int contador =5;
  cout << "sin pasos de argumentos: ";
  mostrar();
  cout << "paso primer argumento: ";
  mostrar('$');
  cout << "paso ambos argumentoS: ";
  mostrar('#', 6);
  return 0;
}
void mostrar(char c, int num){
  for (int i=1; i<=num; i++){
    cout << c <<endl;
  }
}