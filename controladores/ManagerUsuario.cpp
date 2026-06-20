#include <iostream>
#include "ManagerUsuario.h"
#include <cstring>

using namespace std;

ManagerUsuario::ManagerUsuario() {}

bool ManagerUsuario::modificarUsuario()  //FUNCIONA
{
    char usuario[50];
    cout<< "Ingrese el usuario a modificar: ";
    cin.getline(usuario, 50);
    int pos = _repoUsuario.buscarUsuario(usuario);  // usamos el metodo buscar usuario para encontrar el usuario a modificar

    if(pos < 0)                                         //primero verificamos si exista caso contrario salimos
    {
        cout<<"El usuario no existe."<<endl;
        return false;
    }
    Usuario reg = _repoUsuario.leer(pos);
    reg.mostrar();
    int opcion;
    cout<<" MODIFICAR USUARIO " <<endl;
    cout<<"1. Cambiar nombre completo"<<endl;
    cout<<"2. Cambiar contrasenia"<<endl;
    cout<<"3. Cambiar rol"<<endl;
    cout<<"0. Cancelar"<<endl;
    cout<< "Opcion: ";
    cin>>opcion;
    cin.ignore();

    switch(opcion)
    {
    case 1:
    {
        char nuevoNombre[50];
        cout<<"Nuevo nombre completo: ";
        cin.getline(nuevoNombre, 50);
        reg.setNombre(nuevoNombre);
        break;
    }
    case 2:
    {
        char nuevaPassword[50];
        cout<<"Nueva contrasenia: ";
        cin.getline(nuevaPassword, 50);
        reg.setPassword(nuevaPassword);
        break;
    }
    case 3:
    {
        int nuevoRol;
        cout<<"Nuevo  rol: ";
        //aca van listado de roles activos ? llamar a metodo que tiene listar() en Rol;
        cin>>nuevoRol;
        cin.ignore();
        reg.setIdRol(nuevoRol);
        break;
    }
    case 0:
        cout<<"Operacion cancelada."<<endl;
        return false;
    default:
        cout<<"Opcion invalida."<<endl;
        return false;
    }

    if(_repoUsuario.sobreEscribirRegistro(reg, pos))
    {
        cout << "Usuario modificado correctamente."<<endl;
        return true;
    }
    cout<<"No se pudo modificar."<<endl;
    return false;
}

bool ManagerUsuario::eliminarUsuario()  //FUNCIONA
{
    char usuario[50];
    cout<<"Ingrese nombre de usuario a eliminar: ";
    cin.getline(usuario, 50);

    int pos = _repoUsuario.buscarUsuario(usuario);
    if(pos < 0)
    {
        cout<<"El usuario no existe."<<endl;
        return false;
    }
    Usuario reg = _repoUsuario.leer(pos);
    if(reg.getEstado() == false)                            //consultamos el estado del registro, si esta inactivo salimos
    {
        cout<<"El usuario ya se encuentra dado de baja."<<endl;
        return false;
    }
    char opcion;
    cout<<"Confirma la baja del usuario? (presione 'S' o 's' para confirmar la baja, presione cualquier otra tecla para salir): ";
    cin>>opcion;
    cin.ignore();
    if(opcion != 'S' && opcion != 's')
    {
        cout<<"Operacion cancelada."<<endl;
        return false;
    }
    cout <<"El usuario fue dado de baja."<<endl;
    return _repoUsuario.bajaLogicaUsuario(usuario);            //damos la baja logica llamando a su metodo
}

bool ManagerUsuario::registrarUsuario()   //FUNCIONA
{
    char usuario[50];
    cout<<"REGISTRAR NUEVO USUARIO: "<<endl;
    cout<<"Nuevo Usuario: ";
    cin.getline(usuario, 50);

    int pos = _repoUsuario.buscarUsuario(usuario); // busca el nombre de usuario ingresado, se lo pasamos por parametro

    if(pos >= 0)
    {
        Usuario reg = _repoUsuario.leer(pos);   // si existe leerlo

        if(reg.getEstado())      // si esta activo, rechazarlo e informar por pantalla
        {
            cout<< "Ese usuario ya existe."<<endl;
            return false;
        }
        else                   //Si existe pero no esta activo, dar posibilidad de alta logica
        {
            char opcion;
            cout<<"El usuario esta dado de baja."<<endl;
            cout<<"Desea reactivarlo? (presione 'S' o 's' para reactivar, presione cualquier otra tecla para salir): ";
            cin>>opcion;
            cin.ignore();

            if(opcion=='S' || opcion=='s')
            {
                bool exito = _repoUsuario.altaLogicaUsuario(usuario); //  darle el alta nuevamente. cambia el estado del registro a true

                if(exito)
                {
                    cout<<"El usuario fue dado de alta nuevamente."<<endl;
                }
                else
                {
                    cout<<"Error al intentar reactivar el usuario."<<endl;
                }
                return exito;
            }
        }
        return false;
    }

    //cuando el usuario NO existe procede a crear uno nuevo
    Usuario reg;
    reg.ingresarDatos();          // Comienza la carga de datos
    reg.setUsuario(usuario);
    reg.setEstado(true);

    return _repoUsuario.guardar(reg);
}

Usuario ManagerUsuario::login()   //FUNCIONA
{
    char usuario[50];
    char password[50];

    cout<<"Usuario: ";
    cin.getline(usuario,50);
    system("pause");
    system("cls");
    int pos = _repoUsuario.buscarUsuario(usuario);  //buscamos la pos del usuario en Usuarios.dat con el metodo buscarUsuario

    if(pos < 0)
    {
        cout<<"Usuario inexistente."<<endl;
        system("pause");
        system("cls");
        return Usuario();
    }

    Usuario reg = _repoUsuario.leer(pos);    // se encontro, procedemos a leer el usuario en su pos

                                                                            // preguntamos el estado del registro

    if(reg.getEstado() == false)       // controlar si el usuario esta de baja
    {
        char opcion;
        cout<<"Usuario dado de baja."<<endl;
        cout<<"Desea reactivarla? (presione 'S' o 's' para reactivar, presione cualquier otra tecla para salir): ";
        cin>>opcion;
        cin.ignore();
        system("pause");
        system("cls");

        if(opcion == 'S' || opcion == 's')
        {
            bool exito = _repoUsuario.altaLogicaUsuario(usuario);   //si hubo exito en dar la logica informamos, tambien si hubo un error
            if(exito)
            {
                cout<<"Cuenta reactivada nuevamente."<<endl;
                reg= _repoUsuario.leer(pos);

            }
        else
        {
            cout<<"Se cancelo el proceso de reactivacion de la cuenta, volviendo..."<<endl;
            return Usuario();      // sale del proceso sino presiono 's' o 'S'
        }
    }
    cout<<"Contrasenia: ";
    cin.getline(password,50);       //ACA SERIA LA VERIFICACION DE CONTRASEÑA
    system("pause");
    system("cls");

    cout<<"Ingreso exitoso. Bienvenido/a!"<<endl;
    return reg;
  }
}
bool ManagerUsuario::reactivarUsuario()    //FUNCIONA
{
    char usuarioBuscar[50];
    cout<<"Ingrese nombre de usuario a reactivar: ";
    cin.getline(usuarioBuscar, 50);

    int pos = _repoUsuario.buscarUsuario(usuarioBuscar);
    if(pos < 0)
    {
        cout<<"El usuario no existe."<<endl;
        return false;
    }

    Usuario reg = _repoUsuario.leer(pos);

    if(reg.getEstado() == true)
    {
        cout<<"El usuario ya se encuentra activo."<<endl;
        return false;
    }

    char opcion;
    cout<<"La cuenta esta dada de baja."<<endl;
    cout<<"Desea reactivarla? (presione 'S' o 's' para reactivar, presione cualquier otra tecla para salir): ";
    cin>>opcion;
    cin.ignore();

    if(opcion == 'S' || opcion == 's')
    {
        // Delegamos el alta al repositorio, él cambia el estado y sobrescribe
        bool exito = _repoUsuario.altaLogicaUsuario(usuarioBuscar);

        if(exito)
        {
            cout<<"El usuario fue dado de alta nuevamente."<<endl;
        }
        else
        {
            cout<<"Error al intentar reactivar el archivo."<<endl;
        }
        return exito;
    }
    cout<< "Operacion cancelada."<<endl;
    return false;
}

