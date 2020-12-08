#ifndef PASAJERO_H
#define PASAJERO_H
#include <string>
#include <iostream>
using namespace std;

//Clase que guarda toda la información de los pasajeros que vuelan
class Pasajero
{
    private:
        string nombre;
        string correo;
    public:
        Pasajero();
        Pasajero(string nombre1,string correo1);
        string getName();
        void setName(string nombre1);
        string getCorreo();
        void setCorreo(string correo1);
};
Pasajero::Pasajero(){
    nombre="";
    correo="";
}
Pasajero::Pasajero(string nombre1,string correo1){
    nombre=nombre1;
    correo=correo1;
}
string Pasajero::getName(){
    return nombre;
}
void Pasajero::setName(string nombre1){
    nombre=nombre1;
}
string Pasajero::getCorreo(){
    return correo;
}
void Pasajero::setCorreo(string correo1){
    correo=correo1;
}
#endif // PASAJERO_H
