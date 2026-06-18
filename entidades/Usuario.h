#pragma once
class Usuario {
    public:
        Usuario();
        Usuario(int idUsuario,
                const char* nombre,
                const char* usuario,
                const char* password,
                int idRol,
                bool estado);

        void setIdUsuario(int idUsusario);
        int getIdUsuario();

        void setNombre(const char* nombre);
        const char* getNombre();

        void setUsuario(const char* usuario);
        const char* getUsuario();

        void setPassword(const char* password);
        const char* getPassword();

        void setIdRol(int idRol);
        int getIdRol();

        void setEstado (bool estado);
        bool getEstado();

        void ingresarDatos();
        void mostrar();

private:
    int _idUsuario;
    char _nombre[50];
    char _usuario[50];
    char _password[50];
    int _idRol;
    bool _estado;
};
