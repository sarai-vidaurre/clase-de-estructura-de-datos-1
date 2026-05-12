#include <iostream>
#include <cstdlib>  // Para system("cls") o system("clear")
using namespace std;

int main() {
    int numero;
    int opcion;
    char continuar;

    do {
        cout << "   CALCULADORA DE TABLAS DEL 1 AL 10" << endl;
        // Pedir el número
        cout << "Ingrese un número del 1 al 10: ";
        cin >> numero;
        // Validar que el número esté en el rango correcto
        if(numero < 1 || numero > 10) {
            cout << "El número debe estar entre 1 y 10." << endl;
        } else {
            // Menú de operaciones
            cout << "--- ¿Qué operación deseas ver? ---" << endl;
            cout << "1. SUMA" << endl;
            cout << "2. RESTA" << endl;
            cout << "3. MULTIPLICACIÓN" << endl;
            cout << "4. DIVISIÓN" << endl;
            cout << "5. TODAS LAS OPERACIONES" << endl;
            cout << "Opción: ";
            cin >> opcion;
            cout << "------------------------" << endl;
            // Realizar la operación seleccionada
            switch(opcion) {
                case 1: // SUMA
                    cout << "TABLA DE SUMAR DEL " << numero << ":" << endl;
                    cout << "------------------------" << endl;
                    for(int i = 1; i <= 10; i++) {
                        cout << numero << " + " << i << " = " << numero + i << endl;
                    }
                    break;

                case 2: // RESTA
                    cout << "TABLA DE RESTAR DEL " << numero << ":" << endl;
                    cout << "------------------------" << endl;
                    for(int i = 1; i <= 10; i++) {
                        cout << numero << " - " << i << " = " << numero - i << endl;
                    }
                    break;

                case 3: // MULTIPLICACIÓN
                    cout << "TABLA DE MULTIPLICAR DEL " << numero << ":" << endl;
                    cout << "-----------------------------" << endl;
                    for(int i = 1; i <= 10; i++) {
                        cout << numero << " x " << i << " = " << numero * i << endl;
                    }
                    break;

                case 4: // DIVISIÓN
                    cout << "TABLA DE DIVIDIR DEL " << numero << ":" << endl;
                    cout << "-------------------------" << endl;
                    for(int i = 1; i <= 10; i++) {
                        cout << numero << " / " << i << " = " << (float)numero / i << endl;
                    }
                    break;

                case 5: // TODAS LAS OPERACIONES
                    cout << "=== TODAS LAS OPERACIONES PARA EL " << numero << " ===" << endl;

                    cout << "--- SUMA ---" << endl;
                    for(int i = 1; i <= 10; i++) {
                        cout << numero << " + " << i << " = " << numero + i << endl;
                    }

                    cout << "--- RESTA ---" << endl;
                    for(int i = 1; i <= 10; i++) {
                        cout << numero << " - " << i << " = " << numero - i << endl;
                    }

                    cout << "--- MULTIPLICACIÓN ---" << endl;
                    for(int i = 1; i <= 10; i++) {
                        cout << numero << " x " << i << " = " << numero * i << endl;
                    }

                    cout << "--- DIVISIÓN ---" << endl;
                    for(int i = 1; i <= 10; i++) {
                        cout << numero << " / " << i << " = " << (float)numero / i << endl;
                    }
                    break;

                default:
                    cout << "Opción no válida. Por favor, elige 1, 2, 3, 4 o 5." << endl;
            }
        }

        // Preguntar si quiere continuar
        cout << "¿Quieres realizar otra operación? (s/n): ";
        cin >> continuar;

    } while(continuar == 's' || continuar == 'S');

    cout << "¡Gracias por usar la calculadora! Hasta luego." << endl;

    return 0;
}