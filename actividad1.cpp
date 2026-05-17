#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// ============================================================
//  Nombre del archivo de persistencia
// ============================================================
const string ARCHIVO = "inventario.json";

// ============================================================
//  Estructura principal
// ============================================================
struct Videojuego {
    int    codigo;
    string nombre;
    string plataforma;
    string genero;
    float  precio;
    int    stock;
};

// ============================================================
//  Prototipos de funciones
// ============================================================
void  registrar        (Videojuego juegos[], int &n);
void  mostrar          (Videojuego juegos[], int  n);
void  buscar           (Videojuego juegos[], int  n);
void  stockBajo        (Videojuego juegos[], int  n);
void  masCaro          (Videojuego juegos[], int  n);
float calcularInventario(Videojuego juegos[], int n);
void  eliminar         (Videojuego juegos[], int &n);
void  mostrarMenu      ();
bool  codigoExiste     (Videojuego juegos[], int n, int codigo);
void  guardarJSON      (Videojuego juegos[], int  n);
void  cargarJSON       (Videojuego juegos[], int &n);
// Helpers internos para parsear JSON sin librerías externas
string extraerValorStr (const string &linea);
int    extraerValorInt (const string &linea);
float  extraerValorFloat(const string &linea);

// ============================================================
//  Función principal
// ============================================================
int main() {
    Videojuego juegos[100];
    int n = 0;        // cantidad de juegos registrados
    int opcion;

    // Cargar datos guardados al iniciar
    cargarJSON(juegos, n);

    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin  >> opcion;

        switch (opcion) {
            case 1: registrar(juegos, n); guardarJSON(juegos, n); break;
            case 2: mostrar(juegos, n);                           break;
            case 3: buscar(juegos, n);                            break;
            case 4: stockBajo(juegos, n);                         break;
            case 5: masCaro(juegos, n);                           break;
            case 6: {
                float total = calcularInventario(juegos, n);
                cout << fixed << setprecision(2);
                cout << "\n  Valor total del inventario: " << total << " Bs.\n\n";
                break;
            }
            case 7: eliminar(juegos, n); guardarJSON(juegos, n);  break;
            case 8: cout << "\n  Saliendo del sistema. Hasta luego!\n\n"; break;
            default: cout << "\n  Opcion invalida. Intente de nuevo.\n\n";
        }

    } while (opcion != 8);

    return 0;
}

// ============================================================
//  Muestra el menú principal
// ============================================================
void mostrarMenu() {
    cout << "\n===== INVENTARIO DE VIDEOJUEGOS =====\n";
    cout << "1. Registrar videojuego\n";
    cout << "2. Mostrar todos los videojuegos\n";
    cout << "3. Buscar videojuego por codigo\n";
    cout << "4. Mostrar videojuegos con stock bajo (menor a 5)\n";
    cout << "5. Mostrar el videojuego mas caro\n";
    cout << "6. Calcular valor total del inventario\n";
    cout << "7. Eliminar videojuego\n";
    cout << "8. Salir\n";
    cout << "=====================================\n";
}

// ============================================================
//  Verifica si un código ya existe en el arreglo
// ============================================================
bool codigoExiste(Videojuego juegos[], int n, int codigo) {
    for (int i = 0; i < n; i++) {
        if (juegos[i].codigo == codigo) return true;
    }
    return false;
}

// ============================================================
//  1. Registrar un videojuego
// ============================================================
void registrar(Videojuego juegos[], int &n) {
    if (n >= 100) {
        cout << "\n  El inventario esta lleno (maximo 100 juegos).\n";
        return;
    }

    Videojuego nuevo;

    // --- Código (único y positivo) ---
    do {
        cout << "\n  Codigo (numero entero positivo): ";
        cin  >> nuevo.codigo;
        if (nuevo.codigo <= 0)
            cout << "  Error: el codigo debe ser un numero positivo.\n";
        else if (codigoExiste(juegos, n, nuevo.codigo))
            cout << "  Error: ese codigo ya existe en el inventario.\n";
        else
            break;
    } while (true);

    cin.ignore();   // limpiar buffer antes de getline

    // --- Nombre ---
    cout << "  Nombre del videojuego: ";
    getline(cin, nuevo.nombre);

    // --- Plataforma ---
    cout << "  Plataforma (PS5, Xbox, PC, Switch, etc.): ";
    getline(cin, nuevo.plataforma);

    // --- Género ---
    cout << "  Genero (Accion, RPG, Deportes, etc.): ";
    getline(cin, nuevo.genero);

    // --- Precio (no negativo) ---
    do {
        cout << "  Precio (Bs.): ";
        cin  >> nuevo.precio;
        if (nuevo.precio < 0)
            cout << "  Error: el precio no puede ser negativo.\n";
    } while (nuevo.precio < 0);

    // --- Stock (no negativo) ---
    do {
        cout << "  Stock disponible: ";
        cin  >> nuevo.stock;
        if (nuevo.stock < 0)
            cout << "  Error: el stock no puede ser negativo.\n";
    } while (nuevo.stock < 0);

    juegos[n] = nuevo;
    n++;

    cout << "  Videojuego registrado exitosamente!\n";
}

// ============================================================
//  2. Mostrar todos los videojuegos
// ============================================================
void mostrar(Videojuego juegos[], int n) {
    if (n == 0) {
        cout << "\n  No hay videojuegos registrados.\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << "\n--------------------------------------------------------------------------------\n";
    cout << left
         << setw(6)  << "Cod"
         << setw(22) << "Nombre"
         << setw(12) << "Plataforma"
         << setw(12) << "Genero"
         << setw(12) << "Precio (Bs.)"
         << setw(6)  << "Stock"
         << "\n";
    cout << "--------------------------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left
             << setw(6)  << juegos[i].codigo
             << setw(22) << juegos[i].nombre
             << setw(12) << juegos[i].plataforma
             << setw(12) << juegos[i].genero
             << setw(12) << juegos[i].precio
             << setw(6)  << juegos[i].stock
             << "\n";
    }
    cout << "--------------------------------------------------------------------------------\n";
}

// ============================================================
//  3. Buscar videojuego por código
// ============================================================
void buscar(Videojuego juegos[], int n) {
    if (n == 0) {
        cout << "\n  No hay videojuegos registrados.\n";
        return;
    }

    int codigo;
    cout << "\n  Ingrese el codigo a buscar: ";
    cin  >> codigo;

    for (int i = 0; i < n; i++) {
        if (juegos[i].codigo == codigo) {
            cout << fixed << setprecision(2);
            cout << "\n  --- Videojuego encontrado ---\n";
            cout << "  Codigo    : " << juegos[i].codigo     << "\n";
            cout << "  Nombre    : " << juegos[i].nombre     << "\n";
            cout << "  Plataforma: " << juegos[i].plataforma << "\n";
            cout << "  Genero    : " << juegos[i].genero     << "\n";
            cout << "  Precio    : " << juegos[i].precio << " Bs.\n";
            cout << "  Stock     : " << juegos[i].stock      << "\n";
            return;
        }
    }
    cout << "\n  Videojuego con codigo " << codigo << " no encontrado.\n";
}

// ============================================================
//  4. Mostrar videojuegos con stock bajo (< 5)
// ============================================================
void stockBajo(Videojuego juegos[], int n) {
    if (n == 0) {
        cout << "\n  No hay videojuegos registrados.\n";
        return;
    }

    cout << "\n  --- Videojuegos con stock bajo (menos de 5 unidades) ---\n";
    bool hayAlguno = false;

    for (int i = 0; i < n; i++) {
        if (juegos[i].stock < 5) {
            cout << "  [" << juegos[i].codigo << "] "
                 << juegos[i].nombre << " — Stock: " << juegos[i].stock << "\n";
            hayAlguno = true;
        }
    }

    if (!hayAlguno)
        cout << "  Todos los videojuegos tienen stock suficiente.\n";
}

// ============================================================
//  5. Mostrar el videojuego más caro
// ============================================================
void masCaro(Videojuego juegos[], int n) {
    if (n == 0) {
        cout << "\n  No hay videojuegos registrados.\n";
        return;
    }

    int indice = 0;
    for (int i = 1; i < n; i++) {
        if (juegos[i].precio > juegos[indice].precio)
            indice = i;
    }

    cout << fixed << setprecision(2);
    cout << "\n  --- Videojuego mas caro ---\n";
    cout << "  Codigo    : " << juegos[indice].codigo     << "\n";
    cout << "  Nombre    : " << juegos[indice].nombre     << "\n";
    cout << "  Plataforma: " << juegos[indice].plataforma << "\n";
    cout << "  Genero    : " << juegos[indice].genero     << "\n";
    cout << "  Precio    : " << juegos[indice].precio << " Bs.\n";
    cout << "  Stock     : " << juegos[indice].stock      << "\n";
}

// ============================================================
//  6. Calcular el valor total del inventario
//     (suma de precio * stock de cada juego)
// ============================================================
float calcularInventario(Videojuego juegos[], int n) {
    float total = 0.0f;
    for (int i = 0; i < n; i++) {
        total += juegos[i].precio * juegos[i].stock;
    }
    return total;
}

// ============================================================
//  7. Eliminar videojuego por código
//     Desplaza los elementos del arreglo para tapar el hueco
// ============================================================
void eliminar(Videojuego juegos[], int &n) {
    if (n == 0) {
        cout << "\n  No hay videojuegos registrados.\n";
        return;
    }

    int codigo;
    cout << "\n  Ingrese el codigo del videojuego a eliminar: ";
    cin  >> codigo;

    int indice = -1;
    for (int i = 0; i < n; i++) {
        if (juegos[i].codigo == codigo) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "  Videojuego con codigo " << codigo << " no encontrado.\n";
        return;
    }

    // Confirmar antes de borrar
    cout << "  Videojuego a eliminar: " << juegos[indice].nombre
         << " (" << juegos[indice].plataforma << ")\n";
    cout << "  Confirmar eliminacion? (1 = Si / 0 = No): ";
    int confirm;
    cin >> confirm;
    if (confirm != 1) {
        cout << "  Eliminacion cancelada.\n";
        return;
    }

    // Desplazar elementos hacia la izquierda
    for (int i = indice; i < n - 1; i++) {
        juegos[i] = juegos[i + 1];
    }
    n--;

    cout << "  Videojuego eliminado correctamente.\n";
}

// ============================================================
//  Helpers: extraer valores de una línea JSON del estilo
//  "  \"clave\": valor"
// ============================================================
string extraerValorStr(const string &linea) {
    // Busca el segundo ':' y devuelve el texto entre comillas que le sigue
    size_t dos_puntos = linea.find(':');
    if (dos_puntos == string::npos) return "";
    size_t inicio = linea.find('"', dos_puntos);
    if (inicio == string::npos) return "";
    size_t fin = linea.find('"', inicio + 1);
    if (fin == string::npos) return "";
    return linea.substr(inicio + 1, fin - inicio - 1);
}

int extraerValorInt(const string &linea) {
    size_t dos_puntos = linea.find(':');
    if (dos_puntos == string::npos) return 0;
    // Extraer solo la parte numérica (ignorar "Bs" si existe)
    string valor = linea.substr(dos_puntos + 1);
    size_t bs = valor.find("Bs");
    if (bs != string::npos) valor = valor.substr(0, bs);
    return stoi(valor);
}

float extraerValorFloat(const string &linea) {
    size_t dos_puntos = linea.find(':');
    if (dos_puntos == string::npos) return 0.0f;
    // Extraer solo la parte numérica (ignorar "Bs" si existe)
    string valor = linea.substr(dos_puntos + 1);
    size_t bs = valor.find("Bs");
    if (bs != string::npos) valor = valor.substr(0, bs);
    return stof(valor);
}

// ============================================================
//  Guardar inventario en inventario.json
// ============================================================
void guardarJSON(Videojuego juegos[], int n) {
    ofstream archivo(ARCHIVO);
    if (!archivo.is_open()) {
        cout << "  Advertencia: no se pudo guardar el archivo " << ARCHIVO << "\n";
        return;
    }

    archivo << "[\n";
    for (int i = 0; i < n; i++) {
        archivo << "  {\n";
        archivo << "    \"codigo\": " << juegos[i].codigo << ",\n";
        archivo << "    \"nombre\": \"" << juegos[i].nombre << "\",\n";
        archivo << "    \"plataforma\": \"" << juegos[i].plataforma << "\",\n";
        archivo << "    \"genero\": \"" << juegos[i].genero << "\",\n";
        archivo << fixed << setprecision(2);
        archivo << "    \"precio\": " << juegos[i].precio << ",\n";
        archivo << "    \"stock\": " << juegos[i].stock << "\n";
        archivo << "  }";
        if (i < n - 1) archivo << ",";
        archivo << "\n";
    }
    archivo << "]\n";
    archivo.close();
}

// ============================================================
//  Cargar inventario desde inventario.json al iniciar
// ============================================================
void cargarJSON(Videojuego juegos[], int &n) {
    ifstream archivo(ARCHIVO);
    if (!archivo.is_open()) {
        // Primera vez: el archivo aún no existe, no es un error
        return;
    }

    n = 0;
    string linea;
    Videojuego actual;
    bool dentroObjeto = false;

    while (getline(archivo, linea) && n < 100) {
        // Detectar inicio de un objeto
        if (linea.find('{') != string::npos) {
            dentroObjeto = true;
            actual = Videojuego();  // resetear
            continue;
        }
        // Detectar fin de objeto
        if (linea.find('}') != string::npos && dentroObjeto) {
            juegos[n] = actual;
            n++;
            dentroObjeto = false;
            continue;
        }

        if (!dentroObjeto) continue;

        // Leer cada campo según la clave que aparezca en la línea
        if (linea.find("\"codigo\"") != string::npos) 
            actual.codigo = extraerValorInt(linea);
        else if (linea.find("\"nombre\"") != string::npos) 
            actual.nombre = extraerValorStr(linea);
        else if (linea.find("\"plataforma\"") != string::npos) 
            actual.plataforma = extraerValorStr(linea);
        else if (linea.find("\"genero\"") != string::npos) 
            actual.genero = extraerValorStr(linea);
        else if (linea.find("\"precio\"") != string::npos) 
            actual.precio = extraerValorFloat(linea);
        else if (linea.find("\"stock\"") != string::npos) 
            actual.stock = extraerValorInt(linea);
    }

    archivo.close();

    if (n > 0)
        cout << "\n  [" << n << " videojuego(s) cargado(s) desde  "\n";
}