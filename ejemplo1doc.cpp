#include <iostream>
using namespace std;

// Declaración de la clase
class persona
{
public:
    void dormir();
    void hablar();
    void contar();
    void adquirirNombre();
    void decirNombre();

private:
    char nombre[40];
};

// Declaración de funciones de la clase

void persona::dormir()
{
    cout << "zzzzzzzzz" << endl;
}

void persona::hablar()
{
    cout << "bla bla bla bla" << endl;
}

void persona::contar()
{
    cout << "1, 2, 3, 4, 5..." << endl;
}

void persona::adquirirNombre()
{
    cout << "Soy una persona. Ingrese mi nombre: ";
    cin >> nombre;
}

void persona::decirNombre()
{
    cout << "Mi nombre es: " << nombre << endl;
}

// Función principal
int main()
{
    int respuesta = 0;

    // Creando una persona y capturando su nombre
    cout << "Desea crear una persona? 1=Si, 0=No: ";
    cin >> respuesta;

    if (respuesta == 1)
    {
        persona p;

        p.adquirirNombre();

        // La persona dice su nombre
        cout << "Desea que diga mi nombre? 1=Si, 0=No: ";
        cin >> respuesta;

        if (respuesta == 1)
        {
            p.decirNombre();
        }

        // La persona habla
        cout << "Quiere escucharme hablar? 1=Si, 0=No: ";
        cin >> respuesta;

        if (respuesta == 1)
        {
            p.hablar();
        }

        // La persona duerme
        cout << "Desea que vaya a dormir? 1=Si, 0=No: ";
        cin >> respuesta;

        if (respuesta == 1)
        {
            p.dormir();
        }

        // La persona cuenta
        cout << "Desea oirme contar? 1=Si, 0=No: ";
        cin >> respuesta;

        if (respuesta == 1)
        {
            p.contar();
        }
    }
    return 0;
}