#include <iostream>
#include <fstream>
#include <filesystem>
#include "windows.h"
#include "files.h"
using namespace std;

void crearArchivos(int cantidad) {
    string nombreArchivo="archivo";
    int i= cantidad;
    for(i=0; i<cantidad; i++){
        string texto;
        cout << "\nIngrese el texto para el archivo " << i << ": ";
        getline(cin,texto);
        ofstream file;
        file.open("C:/Users/IONI RODAS/Desktop/Hola papu/" + nombreArchivo + to_string(i) +".txt");
        file << texto;
        file.close();
    }
    cout<<"\n";
    cout<<"Archivos creados:"<<to_string(i)<<",";
}


void listarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;
    hFind = FindFirstFile("C:/Users/IONI RODAS/Desktop/Hola papu/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
    {
        cout << findFileData.cFileName;
        while (FindNextFile(hFind, &findFileData) != 0)
            cout << findFileData.cFileName << '\n';
    }
}

int contarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:/Users/IONI RODAS/Desktop/Hola papu/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos+=1;
        }
    return cantidadDeArchivos-1;
}

void mostrarDetalles(){
    filesystem::directory_iterator directoryIterator("C:/Users/IONI RODAS/Desktop/Hola papu");
    cout << "\n";
    cout << "Detalles:";
    cout << "\n";
    for (const auto& entry : directoryIterator) {
        if (!filesystem::is_directory(entry.status())) {
            cout << entry.path().filename() << " "<< "Peso: "<<file_size(entry.path()) <<" Kb."<<endl;
        }
    }
}

