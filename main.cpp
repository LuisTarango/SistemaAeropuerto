#include <iostream>
#include <Vuelos.h>
#include <Fecha.h>
#include <Pasajero.h>
#include <fstream>
using namespace std;

void cargarArchivos(Fecha fechas[20],Vuelos &listaVuelos[20],int numVuelos){
    ifstream archivo("vuelos.txt");
    int id;
    string aerolinea;
    string destino;
    string partida;
    string terminal;
    int dia;
    int mes;
    int hora;
    int minu;
    while(archivo>>dia>>mes>>hora>>minu>>id>>aerolinea>>partida>>destino>>terminal){
        fechas[numVuelos].setDia(dia);
        fechas[numVuelos].setMes(mes);
        fechas[numVuelos].setHora(hora);
        fechas[numVuelos].setMin(minu);
        listaVuelos[numVuelos].setId(id);
        listaVuelos[numVuelos].setAerolinea(aerolinea);
        listaVuelos[numVuelos].setPartida(partida);
        listaVuelos[numVuelos].setDestino(destino);
        listaVuelos[numVuelos].setTerminal(terminal);
        numVuelos++;
    }
}
//Te lleva al metodo del vuelo deseado donde se quiere a�adir pasajeros
void agregarPasajeros(Vuelos listaVuelos[20],int numVuelos){
    cout<<"Ingrese el ID del vuelo al que quiere ingresar pasajeros"<<endl;
    int nume;
    int id;
    cin>>id;
    bool findid;
    findid=false;
    for (int i=0;i<numVuelos;i++){
            int num;
            num=listaVuelos[i].getID();
        if (num==id){
            findid=true;
            nume=i;
            break;
        }else{continue;}
    }
    if (findid==true){
        listaVuelos[nume].llenarVuelos();
    }else{cout<<"Vuelo no fue encontrado"<<endl;}
}
//Funci�n que agrega un nuevo vuelo, incluyendo fecha y hora
void agregarVuelo(Fecha fechas[20],Vuelos listaVuelos[20],int &numVuelos){
    int id;
    string aerolinea;
    string destino;
    string partida;
    string terminal;
    int dia;
    int mes;
    int hora;
    int minu;
    cout<<"Ingrese un ID para el vuelo"<<endl;
    cin>>id;
    listaVuelos[numVuelos].setId(id);
    cout<<"Ingrese el nombre de la aerol�nea"<<endl;
    cin>>aerolinea;
    listaVuelos[numVuelos].setAerolinea(aerolinea);
    cout<<"Ingrese el lugar de procedencia"<<endl;
    cin>>partida;
    listaVuelos[numVuelos].setPartida(partida);
    cout<<"Ingrese el destino"<<endl;
    cin>>destino;
    listaVuelos[numVuelos].setDestino(destino);
    cout<<"Ingrese la terminal del Vuelo"<<endl;
    cin>>terminal;
    listaVuelos[numVuelos].setTerminal(terminal);
    bool fval=false;
    bool hval=false;
    while (fval==false){
        cout<<"Ingrese dia del vuelo"<<endl;
        cin>>dia;
        cout<<"Ingrese el mes del vuelo"<<endl;
        cin>>mes;
        if (fechas[numVuelos].validarFecha(dia, mes)==true){fval=true;}else{
                cout<<"Error datos invalidos"<<endl;
                continue;}
    }
    while (hval==false){
        cout<<"Ingrese la hora del vuelo"<<endl;
        cin>>hora;
        cout<<"Ingrese el minuto del vuelo"<<endl;
        cin>>minu;
        if (fechas[numVuelos].validaHora(hora, minu)==true){hval=true;}else{
                cout<<"Error datos invalidos"<<endl;
                continue;}
    }
    listaVuelos[numVuelos].iniciarPasajeros();
    numVuelos++;
}
//Despliego los asientos del vuelo con el id seleccionado
void desplegarAsientos(Vuelos listaVuelos[20],int numVuelos){
    cout<<"Ingrese el ID del vuelo"<<endl;
    int nume;
    int id;
    cin>>id;
    bool findid;
    findid=false;
    for (int i=0;i<numVuelos;i++){
            int num;
            num=listaVuelos[i].getID();
        if (num==id){
            findid=true;
            nume=i;
            break;
        }else{continue;}
    }
    if (findid==true){
        listaVuelos[nume].imprimirAsientos();
    }else{cout<<"Vuelo no fue encontrado"<<endl;}
}
//Imprime todos los vuelos registrados
void desplegarVuelos(Fecha fechas[20],Vuelos listaVuelos[20],int numVuelos){
    for (int i=0;i<numVuelos;i++){
        fechas[i].imprimeHora();
        cout<<" ";
        fechas[i].imprimeFecha();
        cout<<" ";
        listaVuelos[i].desplegarVuelos();
        cout<<endl;
    }
}

int main()
{
    int numVuelos;
    numVuelos=0;

    int opcion;
    Vuelos listaVuelos[20];
    Fecha fechas[20];
    cargarArchivos(fechas,listaVuelos,numVuelos);
    do{
            cout<<endl;
            cout << "Menu" << endl;
            cout << "1) Agregar pasajero con vuelo" << endl;
            cout << "2) Agregar vuelo" << endl;
            cout << "3) Desplegar asientos de cierto vuelo" << endl;
            cout << "4) Desplegar lista de vuelos" << endl;
            cout << "5) Obtener el total de ventas" << endl;
            cout << "6) Salir" << endl;
            cout<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:{
                agregarPasajeros(listaVuelos,numVuelos);
                break;
            }
            case 2:{
                agregarVuelo(fechas,listaVuelos,numVuelos);
                break;
            }
            case 3:{
                desplegarAsientos(listaVuelos,numVuelos);
                break;
            }
            case 4:{
                desplegarVuelos(fechas,listaVuelos,numVuelos);
                break;
            }
            //Despliega el total de dinero recuperado por la aerolinea en todos sus vuelos
            case 5:{
                int precio;
                precio=5000;
                int boletos;
                boletos=0;
                for (int i=0; i<numVuelos;i++){
                    int num;
                    num=listaVuelos[i].getPasajeros();
                    boletos=boletos+num;
                }
                int ingresos=boletos*precio;
                cout<<"Los ingresos son $"<<ingresos<<endl;
                break;
            }
            case 6:{
                break;
            }
        }
    }while (opcion != 6);
    return 0;
}
