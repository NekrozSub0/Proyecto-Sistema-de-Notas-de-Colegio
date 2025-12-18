#include <iostream>
#include <fstream>
using namespace std;

class Persona
{
	protected:
		int dni;
		string nombres;
		string apellidos;
	public:
		Persona (int, string, string);
		
};

Persona::Persona (int d, string n, string ap)
{
	dni=d;
	nombres=n;
	apellidos=ap;
}

class Estudiante:public Persona
{
	private:
		string codigo;
		string anio;
	public:
		Estudiante (int, string, string, string, string);
		void verCodigo();
		void verAnio();
};

Estudiante::Estudiante (int d, string n, string ap, string cd, string an) : Persona(d, n, ap)
{
	codigo=cd;
	anio=an;
}

void Estudiante::verCodigo() 
{ 
	cout<<"Codigo del estudiante: "<<codigo<<endl; 
}
void Estudiante::verAnio() 
{ 
	cout<<"Año cursando: "<<anio<<endl;
}

class Profesor:public Persona
{
	private:
		string curso;
	public:
		Profesor (int, string, string, string);
		void verCurso();
};

Profesor::Profesor(int d, string n, string ap, string c) : Persona(d, n, ap)
{
    curso = c;
}

void Profesor::verCurso() 
{
    cout<<"Curso: "<<curso<<endl;
}

class Materia
{
	private:
		int idCurso;
		
};

class Bimestre 
{
	private:
	    int numero;
	    bool abierto;
	public:
	    Bimestre(int);
	    void Cerrar();
	    void EstadoBim(bool, int);
};

Bimestre::Bimestre(int num)
{
	numero=num;
	abierto=true;
}

void Bimestre::Cerrar() 
{ 
	abierto = false; 
}

void EstadoBim(bool abierto, int numero)
{
	if (abierto==true)
	{
		cout<<"El bimestre N° "<<numero<<"esta abierto";
	}
	else
	{
		cout<<"El bimestre N° "<<numero<<"esta cerrado";
	}	
}

class Asistencia
{
	private:
		Estudiante estudiante;
		Materia materia;
		Bimestre bimestre;
};

int main ()
{
	return 0;
}