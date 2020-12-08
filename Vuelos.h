#ifndef VUELOS_H
#define VUELOS_H
#include <Fecha.h>
#include <Pasajero.h>
#include <string>
#include <iostream>
using namespace std;
//Clase que guarad toda la información escencial de los vuelos
class Vuelos
{
    private:
        int id;
        string aerolinea;
        string destino;
        string partida;
        string terminal;
        int asientos[30][4];
        Pasajero personas[120];
        int pasajeros;
        int agregados;

    public:
        Vuelos();
        Vuelos(int id,string aerolinea, string destino, string partida, string terminal, int asientos[30][4], int pasajeros,int agregados);
        void setAerolinea(string aerolinea1);
        void setDestino(string destino1);
        void setPartida(string partida1);
        void setTerminal(string terminal1);
        void setId(int id1);
        string getAerolinea();
        string getDestino();
        string getPartida();
        string getTerminal();
        int getID();
        void desplegarVuelos();
        int getPasajeros();
        void setPasajeros(int pasajeros1);
        void iniciarPasajeros();
        void llenarVuelos();
        void imprimirAsientos();
};
Vuelos::Vuelos(){
    id=0;
    aerolinea="";
    destino="";
    partida="";
    terminal="";
    asientos[30][4]=0;
}
Vuelos::Vuelos(int id1,string aerolinea1, string destino1, string partida1, string terminal1, int asientos1[30][4], int pasajeros1,int agregados1){
    id=id1;
    aerolinea=aerolinea1;
    destino=destino1;
    partida=partida1;
    terminal=terminal1;
    asientos[30][4]=asientos1[30][4];
    pasajeros=pasajeros1;
    agregados=agregados1;
    }
void Vuelos::setAerolinea(string aerolinea1){
    aerolinea=aerolinea1;
}
void Vuelos::setDestino(string destino1){
    destino=destino1;
}
void Vuelos::setPartida(string partida1){
    partida=partida1;
}
void Vuelos::setTerminal(string terminal1){
    terminal=terminal1;
}
void Vuelos::setId(int id1){
    id=id1;
}
string Vuelos::getAerolinea(){
    return aerolinea;
}
string Vuelos::getDestino(){
    return aerolinea;
}
string Vuelos::getPartida(){
    return partida;
}
string Vuelos::getTerminal(){
    return terminal;

}
int Vuelos::getID(){
    return id;
}
void Vuelos::desplegarVuelos(){
    cout<<id<<" "<<aerolinea<<" "<<partida<<" "<<destino<<" "<<terminal;
}
int Vuelos::getPasajeros(){
    return pasajeros;
}
void Vuelos::setPasajeros(int pasajeros1){
    pasajeros=pasajeros1;
}
void Vuelos::iniciarPasajeros(){
    pasajeros=0;
}
//agrega pasaeros al vuelo deseado
void Vuelos::llenarVuelos(){
    cout<<"Escriba la cantidad de pasajeros que desea registrar al vuelo"<<endl;
    cin>>agregados;
    int counte;
    counte=0;
    for (int i=0;i<agregados;i++){
        int num;
        string nombre;
        string correo;
        num=pasajeros+agregados;
        cout<<"Ingrese nombre"<<endl;
        cin>>nombre;
        cout<<"Ingrese correo"<<endl;
        cin>>correo;
        personas[num].setName(nombre);
        personas[num].setCorreo(correo);
        for (int k=0; k<30; k++){
                if (counte==agregados){break;}
            for (int j=0; j<4; j++){
                    if (counte==agregados){break;}
                if (asientos [k][j]==0){
                    asientos[k][j]=1;
                    counte=counte+1;
                }else{continue;}
            }
        }
    }
    pasajeros=pasajeros+agregados;
}
//imprime los asientos en el vuelo(30 filas de 4 asientos)
void Vuelos::imprimirAsientos(){
    for (int i=0; i< 30;i++){
            cout<<endl;
        for (int j=0 ;j< 4;j++){
                if (j==2){cout<<" ";}
            cout<<asientos[i][j];
        }
    }
}
#endif // VUELOS_H
