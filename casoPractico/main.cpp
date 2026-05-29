#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "usuarios.h"
#include "Login.h"

using namespace std;

void menuGeneral();
void catalogos();
void reportes();
void procesos();
void ayuda();
void seguridad();
string codigoPrograma="1";
Bitacora Auditoria;
string user, contrasena;

int main()
{
        // Llamamos al objeto e ingresamos los parametros
    Login ingreso(user, contrasena);

    // Creamos un bool que verifique y despliegue el metodo VerificarUsuario
    bool UsuarioCorrecto = ingreso.VerificarUsuario();

    // Luego de ingresar con usuario y contrasenia se nos despliega otro menu
    if (UsuarioCorrecto)
    {
        menuGeneral();
    }

    return 0;
}

void menuGeneral()
{
    int choice;


    do
    {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG     |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Catalogos" << endl;
        cout << "\t\t\t 2. Procesos" << endl;
        cout << "\t\t\t 3. Seguridad" << endl;
        cout << "\t\t\t 4. Salir del Sistema" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3/4]  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            catalogos();
            break;
        case 2:
            procesos();
            break;
        case 3:
            seguridad();
            break;
        case 4:
            Auditoria.ingresoBitacora(user,codigoPrograma,"LGO"); //llamada para registrar la bitacora de seguridad
            exit(0);
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 4);
}

void catalogos()
{
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG - CATALOGOS      |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Alumnos" << endl;
        cout << "\t\t\t 2. Maestros" << endl;
        cout << "\t\t\t 3. Usuarios del sistema" << endl;
        cout << "\t\t\t 4. Carreras" << endl;
        cout << "\t\t\t 5. Facultades" << endl;
        cout << "\t\t\t 6. Cursos" << endl;
        cout << "\t\t\t 7. Jornadas" << endl;
        cout << "\t\t\t 8. Aulas" << endl;
        cout << "\t\t\t 9. Secciones" << endl;
        cout << "\t\t\t 10. Sedes" << endl;
        cout << "\t\t\t 11. Horarios" << endl;
        cout << "\t\t\t 12. Retornar menu anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1-12]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Implementacion para Alumnos
            break;
        case 2:
            // Implementacion para Maestros
            break;
        case 3:
        {
            usuarios usuario;
            usuario.menuUsuarios();
            break;
        }
        case 4:
            // Implementacion para Carreras
            break;
        case 5:
            // Implementacion para Facultades
            break;
        case 6:
            // Implementacion para Cursos
            break;
        case 7:
            // Implementacio para Jornadas
            break;
        case 8:
            // Implementacion para Aulas
            break;
        case 9:
            // Implementacion para Secciones
            break;
        case 10:
            // Implementacion para Sedes
            break;
        case 11:
            // Implementacion para Horarios
            break;
        case 12:
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 12);
}

void procesos()
{
    // Implementacion de procesos
}

void reportes()
{
    // Implementacion de reportes
}

void ayuda()
{
    // Implementacion de ayuda
}

void seguridad()
{
    // Implementacion de seguridad
    Bitacora Auditoria;
    Auditoria.visualizarBitacora();
}

