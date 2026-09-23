#include <iostream>
#include <cstring>
#include <fstream>

//prueba clase 2026-2

using namespace std;


struct est {
    int codigo;
    char nombre[30];
    float nota;
};

// otro comentario

class Estudiante{
    
    public:
    
        int codigo;
        char nombre[30];
        float nota;
        
        Estudiante();
        Estudiante(int codigo_, string nombre_, float nota_);
        Estudiante(string path);
        void Mostrar();
    
};

Estudiante::Estudiante(int codigo_, string nombre_, float nota_){
    
    codigo = codigo_;
    strcpy(nombre, nombre_.c_str());
    nota = nota_;
    
}

Estudiante::Estudiante(){
    
    codigo = 0;
    nota = 0;
    
}

Estudiante::Estudiante(string path){
    
    ifstream temporal(path, ios::binary);

    //if (!temporal) {
    //   cout << "Error al abrir el archivo." << endl;
    //    return 1;
    //}
    
    est estudiante;
    
    temporal.read((char*)&estudiante, sizeof(Estudiante));

    codigo = estudiante.codigo;
    memcpy(  &this->nombre ,&estudiante.nombre, sizeof(nombre));
    nota = estudiante.nota;
    
    temporal.close();
}

void Estudiante::Mostrar(){
    
    cout << "codigo = " << codigo << endl;
    cout << "nombre = " << nombre << endl;
    cout << "nota = " << nota << endl;
    
}

int main() {

    // -------------------------------
    // 1. ESCRIBIR EN ARCHIVO BINARIO
    // -------------------------------

    Estudiante e1(101, "Juan Perez", 4.2);
    Estudiante e2(102, "Maria Gomez", 4.5);
    Estudiante e3(103, "Carlos Lopez", 3.8);
    
    
    //Estudiante e1 = {101, "Juan Perez", 4.2};
    //Estudiante e2 = {102, "Maria Gomez", 4.5};
    //Estudiante e3 = {103, "Carlos Lopez", 3.8};
    
    ofstream archivo("estudiantes.dat", ios::binary);

    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }
    

    archivo.write((char*)&e1, sizeof(Estudiante));
    //archivo.write((char*)&e2, sizeof(Estudiante));
    //archivo.write((char*)&e3, sizeof(Estudiante));

    archivo.close();
    
    Estudiante nuevoEst("estudiantes.dat");
    
    nuevoEst.Mostrar();
   

    // -------------------------------
    // 2. LEER ARCHIVO BINARIO
    // -------------------------------
/*
    ifstream lectura("estudiantes.dat", ios::binary);

    if (!lectura) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    Estudiante estudiante;

    while (lectura.read((char*)&estudiante, sizeof(Estudiante))) {

        estudiante.Mostrar();
    }

    lectura.close();
    */

    return 0;
}

