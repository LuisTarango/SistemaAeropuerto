#ifndef FECHA_H
#define FECHA_H
#include <string>
#include <iostream>
using namespace std;

//Clase que guarda toa la información escencial de la fecha de los vuelos
class Fecha
{
    private:
        int dia;
        int mes;
        int anio;
        int hora;
        int minutos;
    public:
        Fecha();
        Fecha(int dia1, int mes1, int anio1, int hora1, int minutos1);
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        int getMin();
        void setDia(int dia1);
        void setMes(int mes1);
        void setAnio(int anio1);
        void setHora(int hora1);
        void setMin(int minutos1);
        bool validarFecha(int dia1, int mes1);
        void imprimeFecha();
        void imprimeHora();
        bool validaHora(int hora1, int minutos1);
};
Fecha::Fecha(){
    dia=0;
    mes=0;
    anio=0;
    hora=0;
    minutos=0;
}
Fecha::Fecha(int dia1, int mes1, int anio1, int hora1, int minutos1){
    dia=dia1;
    mes=mes1;
    anio=anio1;
    hora=hora1;
    minutos=minutos1;
}
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAnio(){
    return anio;
}
int Fecha::getHora(){
    return hora;
}
int Fecha::getMin(){
    return minutos;
}
void Fecha::setDia(int dia1){
    dia=dia1;
}
void Fecha::setMes(int mes1){
    mes=mes1;
}
void Fecha::setAnio(int anio1){
    anio=anio1;
}
void Fecha::setHora(int hora1){
    hora=hora1;
}
void Fecha::setMin(int minutos1){
    minutos=minutos1;
}
//valida que la fecha proporcionada sea valida
bool Fecha::validarFecha(int dia1, int mes1){
    if (mes1>12){return false;}
    if (dia1>31){return false;}
    if (mes1==2 && dia1>28){return false;}
    if ((mes1==4 || mes1==6 || mes1==9 || mes1==11)&& dia1>30){return false;
    }else {mes=mes1;
    dia=dia1;
    return true;}
}
void Fecha::imprimeFecha(){
    cout<<dia<<"/"<<mes;
}
//imprume la hora en el formato estandar
void Fecha::imprimeHora(){
    if (minutos<10){
        cout<<hora<<":0"<<minutos;
    }else{cout<<hora<<":"<<minutos;}
}
//revisa que la hora proporcionada sea valida
bool Fecha::validaHora(int hora1, int minutos1){
    if (hora1>23){return false;}
    if (minutos1>59){return false;
    }else{hora=hora1;
    minutos=minutos1;
        return true;}
}
#endif // FECHA_H
