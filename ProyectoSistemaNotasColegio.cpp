#include <iostream>
#include <fstream>
using namespace std;

//CLASE BASE
class Persona{
	protected:
		string dni;
		string nombres;
		string apellidos;
	public:
		Persona();
		Persona(string, string, string);
		virtual void mostrarDatos();
		void setdni(string);
		void setnombres(string);
		void setapellidos(string);
		string getdni();
		string getnombres();
		string getapellidos();
};
Persona::Persona(){
	dni="Sin registro";
	nombres="Sin registro";
	apellidos="Sin registro";
}
Persona::Persona (string d, string n, string ap){
	dni=d;
	nombres=n;
	apellidos=ap;
}
void Persona::setdni(string d){
	dni=d;
}
void Persona::setnombres(string n){
	nombres=n;
}
void Persona::setapellidos(string ap){
	apellidos=ap;
}
string Persona::getdni(){
	return dni;
}
string Persona::getnombres(){
    return nombres;
}
string Persona::getapellidos(){
    return apellidos;
}
void Persona::mostrarDatos(){
	cout<<"DNI: "<<dni<<endl;
    cout<<"Nombres: "<<nombres<<endl;
    cout<<"Apellidos: "<<apellidos<<endl;
}

//Clase derivada de Persona
class Estudiante:public Persona{
	private:
		string codigo;
		string anio;
	public:
		Estudiante();
		Estudiante(string, string, string, string, string);
		string getcodigo();
		string getanio();
		void setcodigo(string);
		void setanio(string);
		void mostrarDatos();
};
Estudiante::Estudiante():Persona(){
	codigo="Sin registro";
	anio="Sin registro";
}
Estudiante::Estudiante (string d, string n, string ap, string cd, string an) : Persona(d, n, ap){
	codigo=cd;
	anio=an;
}
string Estudiante::getcodigo(){
	return codigo;
}
string Estudiante::getanio(){
	return anio;
}
void Estudiante::setcodigo(string c){
	codigo=c;
}
void Estudiante::setanio(string a){
	anio=a;
}
void Estudiante::mostrarDatos(){
	Persona::mostrarDatos();
	cout<<"Codigo: "<<codigo<<endl;
    cout<<"Año: "<<anio<<endl;
}

//Clase derivada Profesor
class Profesor:public Persona{
	private:
		string curso;
	public:
		Profesor();
		Profesor(string, string, string, string);
		string getcurso();
		void setcurso(string);		
		void mostrarDatos();
};
Profesor::Profesor():Persona(){
	curso="Sin registro";
}
Profesor::Profesor(string d, string n, string ap, string c) : Persona(d, n, ap){
    curso = c;
}
string Profesor::getcurso(){
	return curso;
}
void Profesor::setcurso(string c){
	curso=c;
}
void Profesor::mostrarDatos(){
	Persona::mostrarDatos();
    cout<<"Curso: "<<curso<<endl;
}

//Clase Materia
class Materia{
	private:
		int idCurso;
		
};

//Clase Bimestre
class Bimestre{
	private:
	    int numero;
	    bool abierto;
	public:
	    Bimestre(int);
	    void Cerrar();
	    void EstadoBim(bool, int);
};
Bimestre::Bimestre(int num){
	numero=num;
	abierto=true;
}
void Bimestre::Cerrar(){ 
	abierto = false; 
}
void EstadoBim(bool abierto, int numero){
	if (abierto==true){
		cout<<"El bimestre N° "<<numero<<"esta abierto";
	}
	else{
		cout<<"El bimestre N° "<<numero<<"esta cerrado";
	}	
}

//Clase Asistencia
class Asistencia{
	private:
		Estudiante estudiante;
		Materia materia;
		Bimestre bimestre;
};

//Funciones para menus
void menuestudiante();
void loginestudiante(){
	
	menuestudiante();
}
void menuestudiante(){
	char opcionestudiante;
	do{
        cout<<"--- SISTEMA DE NOTAS DE COLEGIO ---"<<endl;
        cout<<"Ingrese opción de usuario: "<<endl;
        cout<<"A. Ver datos: "<<endl;
        cout<<"B. Ver asistencia: "<<endl;
        cout<<"C. Ver notas: "<<endl;
        cout<<"D. Sacar reporte: "<<endl;
        cout<<"X. Salir"<<endl;;
        cin>>opcionestudiante;
        opcionestudiante=toupper(opcionestudiante);
        switch(opcionestudiante){
            case 'A':
                cout<<"Datos de estudiante"<<endl;
                //Estudiante::mostrarDatos();
                break;
            case 'B':
                cout<<"Asistencia de estudiante: "<<endl;
                
                break;
            case 'C':
                cout<<"Notas de estudiante: "<<endl;
                
                break; 
			 case 'D':
                cout<<"Reporte de estudiante: "<<endl;
                
                break;    
            case 'X':
                cout<<"Cerrando programa..."<<endl;
                break;
            default:
                cout<<"ERROR. Opcion ingresada no disponible"<<endl;
        }
    }while(opcionestudiante!='X');	
}

void menuprofesor();
void loginprofesor(){
	
	menuprofesor();
}
void menuprofesor(){
	char opcionprofesor;
    do{
        cout<<"\n--- MENU DOCENTE ---"<<endl;
        cout<<"A. Ver mis datos"<<endl;
        cout<<"B. Ver curso asignado"<<endl;
        cout<<"C. Ingresar notas (Simulado)"<<endl;
        cout<<"X. Regresar"<<endl;
        cout<<"Opcion: "<<endl;
        cin>>opcionprofesor;
        opcionprofesor=toupper(opcionprofesor);
        switch(opcionprofesor){
            case 'A':
                cout<<"Datos del profesor"<<endl;
                
                break;
            case 'B':
                cout<<"Curso asignado"<<endl;
                
                break;
            case 'C':
                cout<<"Ingresar notas..."<<endl;
                
                break;
            case 'X':
                cout<<"Saliendo del menu profesor"<<endl;
                break;
            default:
                cout<<"ERROR. Opcion no valida"<<endl;
        }
    }while(opcionprofesor!='X');
}

void menuprincipal(){
	char opcionmenu;
	do{
        cout<<"--- SISTEMA DE NOTAS DE COLEGIO ---"<<endl;
        cout<<"Ingrese opción de usuario: "<<endl;
        cout<<"A. Ingresar como estudiante"<<endl;
        cout<<"B. Ingresar como profesor"<<endl;
        cout<<"X. Salir"<<endl;;
        cin>>opcionmenu;
        opcionmenu=toupper(opcionmenu);
        switch(opcionmenu){
            case 'A':
                cout<<"Ingrese sus credenciales de estudiante"<<endl;
                loginestudiante();
                break;
            case 'B':
                cout<<"Ingrese sus credenciales de profesor"<<endl;
                loginprofesor();
                break;
            case 'X':
                cout<<"Cerrando programa..."<<endl;
                break;
            default:
                cout<<"ERROR. Opcion ingresada no disponible"<<endl;
        }
    }while(opcionmenu!='X');	
}

int main (){
	Estudiante estudiante1("77777777", "Juan", "Perez", "U2024", "5to");
    Profesor profesor1("12345678", "Alberto", "Einstein", "Fisica Cuantica");
	menuprincipal();
	
	return 0;
}