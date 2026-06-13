#include <iostream>
#include "entidades/Paciente.h"

using namespace std;

int main(){

    Paciente p;

    p.cargar();

    cout << endl;

    p.mostrar();

    return 0;
}
