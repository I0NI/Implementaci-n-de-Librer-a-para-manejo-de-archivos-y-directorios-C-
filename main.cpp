#include <iostream>
#include <filesystem>
#include "files.h"

using namespace std;

int main()
{
    int cantidad;
    cout<<"Bienvenido a la creadora de archivos, espero que disfrute su estadia :)."<<endl;

    cout << "\nCuantos archivos quiere crear pa: \n";
    cin >> cantidad;
    crearArchivos(cantidad);
    cout << contarArchivosDeDirectorio();
    cout << endl;
    listarArchivosDeDirectorio();
    mostrarDetalles();
    cout<<"\n";
    cout<<"Si tiene curiosidad de porque no le dejo poner un texto en el primer archivo,  pos el codigo no quiso colaborar asi que no se pudo......";

    return 0;
}



