#include "bodega.h"
#include "bitacora.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>


using namespace std;


void bodega::menu()
{
    int choice;
	char x;

	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION BODEGA -700 |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Bodega"<<endl;
	cout<<"\t\t\t 2. Despliegue Bodega"<<endl;
	cout<<"\t\t\t 3. Modifica Bodega"<<endl;
	cout<<"\t\t\t 4. Busca Bodega"<<endl;
	cout<<"\t\t\t 5. Borra Bodega"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insertar();
    		cout<<"\n\t\t\t Agrega otra bodega(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		desplegar();
		break;
	case 3:
		modificar();
		break;
	case 4:
		buscar();
		break;
	case 5:
		borrar();
		break;
	case 6:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
  }while(choice!= 6);
}
void bodega::insertar()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Bodega ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Bodega         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Tipo de Bodega     : ";
	cin>>tipoBodega;
	cout<<"\t\t\tIngresa Nombre   : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa Direccion   : ";
	cin>>direccion;
	cout<<"\t\t\tIngresa Estado   : ";
	cin>>estado;

	file.open("bodega.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< tipoBodega <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< estado << "\n";
	file.close();
	bitacora auditoria;
	auditoria.insertar("usuario registrado", "701", "INS");
}
void bodega::desplegar()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Bodega -------------------------"<<endl;
	file.open("bodega.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		file >> id >> tipoBodega >> nombre >> direccion >> estado;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id bodega: "<<id<<endl;
			cout<<"\t\t\t Tipo Bodega: "<<tipoBodega<<endl;
            cout<<"\t\t\t Nombre: "<<nombre<<endl;
            cout<<"\t\t\t Direccion: "<<direccion<<endl;
            cout<<"\t\t\t Estado: "<<estado<<endl;

            file >> id >> tipoBodega >> nombre >> direccion >> estado;

		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
		system("pause");
	}
	file.close();
    bitacora auditoria;
    auditoria.insertar("usuario registrado", "701", "SEL");
}
void bodega::modificar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Bodega-------------------------"<<endl;
	file.open("bodega.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la bodega que quiere modificar: ";
		cin>>participant_id;
		file1.open("bodega.txt",ios::app | ios::out);
        file >> id >> tipoBodega >> nombre >> direccion >> estado;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< tipoBodega <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< estado << "\n";
			}
			else
			{
				cout<<"\t\t\tIngresa Id Bodega         : ";
                cin>>id;
                cout<<"\t\t\tIngresa Tipo de Bodega     : ";
                cin>>tipoBodega;
                cout<<"\t\t\tIngresa Nombre   : ";
                cin>>nombre;
                cout<<"\t\t\tIngresa Direccion   : ";
                cin>>direccion;
                cout<<"\t\t\tIngresa Estado   : ";
                cin>>estado;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< tipoBodega <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< estado << "\n";
				found++;
			}
            file >> id >> tipoBodega >> nombre >> direccion >> estado;


		}
		file1.close();
		file.close();
		remove("bodega.txt");
		rename("temporal.txt","vendedores.txt");
        bitacora auditoria;
        auditoria.insertar("usuario registrado", "701", "UPD");
	}
}
void bodega::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("bodega.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la bodega buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos de la bodega buscado------------------------"<<endl;
		cout<<"\nIngrese Id de la bodega que quiere buscar: ";
		cin>>participant_id;
        file >> id >> tipoBodega >> nombre >> direccion >> estado;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id bodega: "<<id<<endl;
                cout<<"\t\t\t Tipo Bodega: "<<tipoBodega<<endl;
                cout<<"\t\t\t Nombre: "<<nombre<<endl;
                cout<<"\t\t\t Direccion: "<<direccion<<endl;
                cout<<"\t\t\t Estado: "<<estado<<endl;
				found++;
			}
            file >> id >> tipoBodega >> nombre >> direccion >> estado;

		}
		if(found==0)
		{
			cout<<"\n\t\t\t Bodega no encontrada...";
		}
		file.close();
        bitacora auditoria;
        auditoria.insertar("usuario registrado", "701", "SEL");
	}
}
void bodega::borrar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles de la bodega a Borrar-------------------------"<<endl;
	file.open("bodega.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del bodega que quiere borrar: ";
		cin>>participant_id;
		file1.open("temporal.txt",ios::app | ios::out);
        file >> id >> tipoBodega >> nombre >> direccion >> estado;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< tipoBodega <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< estado << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
            file >> id >> tipoBodega >> nombre >> direccion >> estado;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id no encontrado...";
		}
		file1.close();
		file.close();
		remove("bodega.txt");
		rename("temporal.txt","bodega.txt");
        bitacora auditoria;
        auditoria.insertar("usuario registrado", "701", "DEL");
	}
}




