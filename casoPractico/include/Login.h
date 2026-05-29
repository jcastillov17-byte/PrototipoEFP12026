#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <fstream>
#include <string>
using std::string;

class Login
{
    public:
        Login(string usuarios,string contrasena);

        string setUser(string usuarios);
        string getUser();

        string setContrasena(string contrasena);
        string getContrasena();


        bool VerificarUsuario();


    private:
        string usuarios,contrasena;
};

#endif // LOGIN_H
