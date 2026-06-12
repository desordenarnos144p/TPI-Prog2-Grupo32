#include <cstdio>
#include "ArchivoObraSocial.h"

ArchivoObraSocial::ArchivoObraSocial(std::string nombre)
   :_nombreArchivo(nombre){
}

bool ArchivoObraSocial::guardar(ObraSocial obj) {
    FILE *pObs;
     pObs = fopen(_nombreArchivo.c_str(), "ab");

    if (pObs == nullptr){
     return false;
    }

    int escribio = fwrite(&obj, sizeof(ObraSocial), 1, pObs);
    fclose(pObs);
    return escribio;
}

ObraSocial ArchivoObraSocial::leer(int pos) {
    ObraSocial obj;
    FILE *pObs;
    pObs = fopen(_nombreArchivo.c_str(), "rb");

    if (pObs == nullptr){
     return obj;
    }

    fseek(pObs, pos * sizeof(ObraSocial), SEEK_SET);
    fread(&obj, sizeof(ObraSocial), 1, pObs);
    fclose(pObs);
    return obj;
}

int ArchivoObraSocial::cantidadRegistros() {
    FILE *pObs;
    int tamTotal;

    pObs = fopen(_nombreArchivo.c_str(), "rb");
    if (pObs == nullptr){
     return 0;
    }

    fseek(pObs, 0, SEEK_END);
    tamTotal = ftell(pObs) / sizeof(ObraSocial);
    fclose(pObs);
    return tamTotal;
}

int ArchivoObraSocial::buscar(int id) {
    int total = cantidadRegistros();
    for (int i = 0; i < total; i++) {
        ObraSocial obj = leer(i);
        if (obj.getIdObraSocial() == id && obj.getEstado() == true) {
            return i;
        }
    }
    return -1;
}

bool ArchivoObraSocial::modificar(ObraSocial obj, int pos)
{
    FILE *pObs = fopen(_nombreArchivo.c_str(), "rb+");
    if(pObs == nullptr){
        return false;
    }

    fseek(pObs, pos * sizeof(ObraSocial), SEEK_SET);

    bool ok = fwrite(&obj, sizeof(ObraSocial), 1, pObs);

    fclose(pObs);

    return ok;
}
