#ifndef ESTRUCTURAS2_H
#define ESTRUCTURAS2_H

#include <QString>


struct Avion{
    QString tipo;           //Tipo de avion
    QString id;             //Identificador
    int cant_pasajeros;     //Cantidad de pasajeros
    int turn_d;             //Turnos de desabordaje
    int turn_m;             //Turnos de mantenimiento
    struct Avion *siguiente;
    struct Avion *anterior;
};

struct Pasajero{
    QString id;                 //Identificador
    int cant_m;             //Cantidad de maletas
    int cant_d;             //Cantidad de documentos
    int num_turn_reg;       //Turnos de registro
    struct Pasajero *siguiente;
};

struct ColaS{               //Cola simple para pasajeros
    Pasajero *primero;
    Pasajero *ultimo;
};

struct Documento{
    int id;
    struct Documento *siguiente;
};

struct Pila{                //Pila para docuementos
    Documento *primero;
    Documento *ultimo;
};

struct Escritorio{
    char letra;             //Letra de identificacion
    bool estado;            //Estado vaio o lleno
    QString cliente;            //Cliente siendo atendido
    ColaS cola;             //Cola para los pasajeros (MAX. 10)
    Pila pila;              //Pila para documentos
    int cantidad;
    struct Escritorio *siguiente;
    struct Escritorio *anaterior;
};

struct Equipaje{
    int id;
    struct Equipaje *siguiente;
    struct Equipaje *anterior;
};

struct ColaSS{
    Avion *primero;
    Avion *ultimo;
};

struct Estaciones_S{
    int avion;              //Avion en mantenimiento
    bool estado;            //Estado de la estacion
    int turn_rest;          //Turnos restantes
    ColaSS cola;            //Cola para los aviones
    struct Estaciones_S *siguiente;
};

struct ColaD{               //Cola doblemente enlazada para los aviones
    Avion *primero;
    Avion *ultimo;
};



struct ListaDO{             //Lista doblemente enlazada y ordenada para escritorios
    Escritorio *primero;
    Escritorio *ultimo;
};

struct ColaSE{              //Cola simple de escritorio para contener pasajeros(Max. 10)
    Pasajero *primero;
    Pasajero *ultimo;
};



struct ListaDC{             //Lista circular doblemente enlazada para equipaje
    Equipaje *primero;
    Equipaje *ultimo;
};

struct ListaSS{
    Estaciones_S *primero;
    Estaciones_S *ultimo;
};


//ColaD *ColaDo;
void insertarCD(ColaD *ColaDoble, QString tipo, QString id, int cant_p, int turn_d, int turn_m);
void eliminarCD(ColaD *ColaDoble);
QString mostrarCD(ColaD *ColaDoble);

//ColaS *ColaSim;
void insertarCS(ColaS *ColaSimple, QString id, int cant_p);
void eliminarCS(ColaS *ColaSimple);
QString mostrarCS(ColaS *ColaSimple);

//ListaDO *ListSimpleO;
void insertarLDO(ListaDO *ListaSimpleO, QString cliente, int turn_rest, ColaS *cola, Pila *pila, int cantidad);
void eliminarLDO(ListaDO *ListaSimpleO);
QString mostrarLDO(ListaDO *ListaSimpleO);

//ColaSE *ColaSimpleE;
//void insertarCSE(ColaSE *ColaSimpleE, );

//Pila *PilaE;
void insertarP(Pila *PilaE, int id);
void eliminarP(Pila *PilaE);
void mostrarP(Pila *PilaE);

//ListaDC *ListaDobleC;
void insertarLDC(ListaDC *ListaDobleC, int id);
void eliminar(ListaDC *ListaDobleC);
void mostrar(ListaDC *ListaDobleC);

//ListaSS *ListaSimpleS;
void insertarLSS(ListaSS *ListaSimpleS, int avion, bool estado, int turn_rest, ColaSS cola);
void eliminarLSS(ListaSS *ListaSimpleS);
void mostrarLSS(ListaSS *ListaSimpleS);

//ColaSS *ColaSimpleS;
void insertarLSS(ListaSS *ListaSimpleS, int avion, bool estado, int turn_rest, ColaSS cola);
void eliminarLSS(ListaSS *ListaSimpleS);
void mostrarLSS(ListaSS *ListaSimpleS);

int cantidadPA(int tipo);
int turnosA(int tipo);
int turnosAM(int tipo);
void generarArchivo(QString texto);



#endif // ESTRUCTURAS2_H
