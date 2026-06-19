#include <iostream>
#include "ManagerUsuario.h"
#include <cstring>

using namespace std;

ManagerUsuario::ManagerUsuario(){}

    bool ManagerUsuario::modificarUsuario()  //FUNCIONA
{
    char usuario[50];
    cout << "Ingrese el usuario a modificar: ";
    cin.getline(usuario, 50);
    int pos = _repoUsuario.buscarUsuario(usuario);  // usamos el metodo buscar usuario para encontrar el usuario a modificar

    if(pos < 0){                                        //primero verificamos si exista caso contrario salimos
        cout << "El usuario no existe." << endl;
        return false;
    }
    Usuario reg = _repoUsuario.leer(pos);
    reg.mostrar();
    int opcion;
    cout << " MODIFICAR USUARIO " << endl;
    cout << "1. Cambiar nombre completo" << endl;
    cout << "2. Cambiar contrasenia" << endl;
    cout << "3. Cambiar rol" << endl;
    cout << "0. Cancelar" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();

    switch(opcion){
    case 1: {
        char nuevoNombre[50];
        cout << "Nuevo nombre completo: ";
        cin.getline(nuevoNombre, 50);
        reg.setNombre(nuevoNombre);
        break;
    }
    case 2:{
        char nuevaPassword[50];
        cout << "Nueva contraseña: ";
        cin.getline(nuevaPassword, 50);
        reg.setPassword(nuevaPassword);
        break;
    }
    case 3:{
        int nuevoRol;
        cout << "Nuevo  rol: ";
        //aca van listado de roles activos ? llamar a metodo que tiene listar() en Rol;
        cin >> nuevoRol;
        reg.setIdRol(nuevoRol);
        break;
    }
    case 0:
        cout << "Operacion cancelada." << endl;
        return false;
    default:
        cout << "Opcion invalida." << endl;
        return false;
    }

   if(_repoUsuario.sobreEscribirRegistro(reg, pos)){
    cout << "Usuario modificado correctamente." << endl;
    return true;
    }  cout << "No se pudo modificar." << endl;
return false;
}

bool ManagerUsuario::eliminarUsuario()  //FUNCIONA
{
    char usuario[50];
    cout << "Ingrese nombre de usuario a eliminar: ";
    cin.getline(usuario, 50);

    int pos = _repoUsuario.buscarUsuario(usuario);
    if(pos < 0){
        cout << "El usuario no existe." << endl;
        return false;
    }
    Usuario reg = _repoUsuario.leer(pos);
    if(reg.getEstado() == false){                           //consultamos el estado del registro, si esta inactivo salimos
        cout << "El usuario ya se encuentra dado de baja." << endl;
        return false;
    }
    char opcion;
    cout << "Confirma la baja del usuario? (S/N): ";
    cin >> opcion;
    if(opcion != 'S' && opcion != 's'){
        cout << "Operacion cancelada." << endl;
        return false;
    }
    reg.setEstado(false);                                           // cambiamos el estado para la baja logica
    return _repoUsuario.sobreEscribirRegistro(reg, pos);           //sobreescribimos el registro en la posicion encontrada
}

    int ManagerUsuario::getNuevoId(){
    return _repoUsuario.getCantidadRegistros() + 1;
}

bool ManagerUsuario::registrarUsuario(){  //FUNCIONA
    char usuario[50];
    cout << "REGISTRAR NUEVO USUARIO: "<<endl;
    cout << "Nuevo Usuario: ";
    cin.getline(usuario, 50);

    int pos = _repoUsuario.buscarUsuario(usuario); // busca el nombre de usuario ingresado, se lo pasamos por parametro

    if(pos >= 0){
        Usuario reg = _repoUsuario.leer(pos);   // si existe leerlo

        if(reg.getEstado()){     // si esta activo, rechazarlo e informar por pantalla
            cout << "Ese usuario ya existe." << endl;
            return false;
        }else{                 //Si existe pero no esta activo, dar posibilidad de alta logica
        char opcion;
        cout << "El usuario esta dado de baja." << endl;
        cout << "Desea reactivarlo? (S/N): ";
        cin >> opcion;

        if(opcion=='S' || opcion=='s'){
          reg.setEstado(true);  //  darle el alta nuevamente. cambia el estado del registro a true
          cout<<"El usuario fue dado de alta nuevamente."<<endl;
            return _repoUsuario.sobreEscribirRegistro(reg, pos);
            }
        }
        return false;
    }

        //cuando el usuario NO existe procede a crear uno nuevo
    Usuario reg;
    reg.ingresarDatos();          // Comienza la carga de datos
    reg.setIdUsuario(getNuevoId());
    reg.setEstado(true);        // da el alta logica

    return _repoUsuario.guardar(reg);
}

Usuario ManagerUsuario::login(){  //FUNCIONA

    Usuario nuevo;

    char usuario[50];
    char password[50];

    cout << "Usuario: ";
    cin.ignore();
    cin.getline(usuario,50);

    int pos = _repoUsuario.buscarUsuario(usuario);

    if(pos < 0){
        cout << "Usuario inexistente." << endl;      // en login solo dejamos acceder con usuario activo o inactivo
        return nuevo;
    }

    Usuario reg = _repoUsuario.leer(pos);

    bool EstadoEsActivo = reg.getEstado();  // preguntamos el estado del registro

    if(EstadoEsActivo == false){      // en caso de estar inactivo damos posibilidad de alta logica
        char opcion;
        cout << "Usuario dado de baja." << endl;
        cout << "Desea reactivarla? (S/N): ";
        cin >> opcion;

    if(opcion == 'S' || opcion == 's'){
        reg.setEstado(true);
    _repoUsuario.sobreEscribirRegistro(reg, pos);      //cambiamos el estado en la pos del reg encontrado
        cout << "Cuenta reactivada correctamente." << endl;
    }
    else{
        return nuevo;
   }
    cin.ignore();
}
    cout << "Contrasenia: ";
    cin.getline(password,50);

    // aca conecta login con el menu de Admin, Medico o Paciente
    return reg;
}

bool ManagerUsuario::reactivarUsuario(){   //FUNCIONA
    char usuarioBuscar[50];
    cout << "Ingrese nombre de usuario a reactivar: ";
    cin.getline(usuarioBuscar, 50);

    int pos = _repoUsuario.buscarUsuario(usuarioBuscar);
    if(pos < 0){
        cout << "El usuario no existe." << endl;
        return false;
    }

    Usuario reg = _repoUsuario.leer(pos);

    if(reg.getEstado() == true){
        cout << "El usuario ya se encuentra activo." << endl;
        return false;
    }

    char opcion;
    cout << "La cuenta esta dada de baja." << endl;
    cout << "Desea reactivarla? (S/N): ";
    cin >> opcion;
    if(opcion == 'S' || opcion == 's'){
        reg.setEstado(true);
        cout<<"El usuario fue dado de alta nuevamente."<<endl;
        return _repoUsuario.sobreEscribirRegistro(reg, pos);
    }
    return false;
}
