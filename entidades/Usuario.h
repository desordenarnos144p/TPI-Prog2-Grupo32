#pragma once
class Usuario {
    public:
        Usuario();
        Usuario(int idUsuario, const char* nombre, const char* usuario, const char* password, int idRol, bool estado);

        void setIdUsuario(int id);
        int getIdUsuario();

        void setNombre(const char* n);
        const char* getNombre();

        void setUsuario(const char* u);
        const char* getUsuario();

        void setPassword(const char* p);
        const char* getPassword();

        void setIdRol(int rol);
        int getIdRol();

        void setEstado (bool estado);
        bool getEstado();

        void cargar();
        void mostrar();

private:
    int _idUsuario;
    char _nombre[50];
    char _usuario[50];
    char _password[50];
    int _idRol;
    bool _estado;
};
