#include "estructuras2.h"
#include <QMessageBox>
#include <iostream>
#include <QString>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <cstdio>
#include <cctype>

int cant_a;

//**********CARACTERISTICAS DEL AVION(PASAJEROS)**********
int cantidadPA(int tipo){

    int cantidadp;

    switch (tipo) {
    case 0:
        cantidadp = 5 + rand() %(10 - 5);
        break;
    case 1:
        cantidadp = 15 + rand() %(25 - 15);
        break;
    case 2:
        cantidadp = 30 + rand() %(40 - 30);
        break;
    default:
        break;
    }

    return cantidadp;
}

int turnosA(int tipo){

    int desabordaje;

    switch (tipo) {
    case 0:
        desabordaje = 1;
        break;
    case 1:
        desabordaje = 2;
        break;
    case 2:
        desabordaje = 3;
        break;
    default:
        break;
    }

    return desabordaje;
}

int turnosAM(int tipo){

    int turnos;

    switch (tipo) {
    case 0:
        turnos = 1 + rand() %(4-1);
        break;
    case 1:
        turnos = 2 + rand() %(4-2);
        break;
    case 2:
        turnos = 3 + rand() %(6-3);
        break;
    default:
        break;
    }

    return turnos;
}



//*********INSERTAR COLA DOBLE************
void insertarCD(ColaD *ColaDoble, QString tipo, QString id, int cant_p, int turn_d, int turn_m){
    Avion *nuevo = new Avion(); //(struct Avion *)malloc(sizeof(struct Avion));
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    nuevo->tipo = tipo;
    nuevo->id = id;
    nuevo->cant_pasajeros = cant_p;
    nuevo->turn_d = turn_d;
    nuevo->turn_m = turn_m;

    if(ColaDoble->primero == NULL){
        ColaDoble->primero = nuevo;
        ColaDoble->ultimo = nuevo;
    }
    else{
        ColaDoble->ultimo->siguiente = nuevo;
        nuevo->anterior = ColaDoble->ultimo;
        ColaDoble->ultimo = nuevo;
    }
}


//**********ELIMINAR COLA DOBLE**********
void eliminarCD(ColaD *ColaDoble){
    Avion *aux = (struct Avion *)malloc(sizeof(struct Avion));
    aux->anterior = NULL;
    aux->siguiente = NULL;

    if(ColaDoble->primero == NULL){
        QMessageBox msgBox;
        msgBox.setText("La cola de aviones esta vacia");
        msgBox.exec();
    }
    else{
        aux = ColaDoble->primero->siguiente;
        free(ColaDoble->primero);
        ColaDoble->primero = aux;
        ColaDoble->primero->anterior = NULL;
    }
}


//**********MOSTRAR COLA DOBLE**********
QString mostrarCD(ColaD *ColaDoble){
    QString graph;
    Avion *aux = (struct Avion *)malloc(sizeof(struct Avion));
    aux->anterior = NULL;
    aux->siguiente = NULL;

    graph.append("subgraph cluster_Aviones { \n node [shape= box]; \n");

    if(ColaDoble->primero == NULL){
        QMessageBox msgBox;
        msgBox.setText("La Cola de Aviones esta vacia");
        msgBox.exec();
    }
    else{

        aux = ColaDoble->primero;

        while(aux != NULL){

            if((aux->anterior == NULL) && (aux->siguiente == NULL)){
                graph.append(aux->id);
                graph.append(";\n");
            }
            else if((aux->siguiente == NULL) && (aux->anterior != NULL)){
                //graph.append(aux->id);
                //graph.append(" -> ");
                //graph.append(aux->anterior->id);
                //graph.append(";\n");
            }
            else{
                graph.append(aux->id);
                graph.append(" -> ");
                graph.append(aux->siguiente->id);
                graph.append(";\n");
                graph.append(aux->siguiente->id);
                graph.append(" -> ");
                graph.append(aux->siguiente->anterior->id);
                graph.append(";\n");
            }

            aux = aux->siguiente;
        }
    }

    graph.append("} \n " );

    return graph;
}

//**********INSERTAR COLA SIMPLE**********
void insertarCS(ColaS *ColaSimple, QString id, int cant_i){
    for(int i = 0; i < cant_i; i++){
        Pasajero *nuevo = new Pasajero();
        nuevo->siguiente = NULL;
        nuevo->id = id + QString::number(i);
        nuevo->cant_m = 1 + rand()%(4-1);
        nuevo->cant_d = 1 + rand()%(10-1);
        nuevo->num_turn_reg = 1 + rand()%(3-1);

        if(ColaSimple->primero == NULL){
            ColaSimple->primero = nuevo;
            ColaSimple->ultimo = nuevo;
        }
        else{
            ColaSimple->ultimo->siguiente = nuevo;
            ColaSimple->ultimo = nuevo;
        }
    }
}

//**********ELIMINAR COLA SIMPLE**********
void eliminarCS(ColaS *ColaSimple){
    Pasajero *aux = new Pasajero();
    aux->siguiente = NULL;

    if(ColaSimple->primero == NULL){
        QMessageBox msgBox;
        msgBox.setText("La cola de pasajeros esta vacia");
        msgBox.exec();
    }
    else{
        aux = ColaSimple->primero->siguiente;
        free(ColaSimple->primero);
        ColaSimple->primero = aux;
    }

}

//**********MOSTRAR COLA SIMPLE**********
QString mostrarCS(ColaS *ColaSimple){
    QString graph;
    Pasajero *aux = new Pasajero();
    aux->siguiente = NULL;

    graph.append("subgraph cluster_Pasajeros { \n node [shape=box]; \n");

    if(ColaSimple->primero == NULL){
        QMessageBox msgBox;
        msgBox.setText("La cola de Pasajeros esta vacia");
        msgBox.exec();
    }
    else{

        aux = ColaSimple->primero;

        while(aux != NULL){
            if(aux->siguiente != NULL){
                graph.append(aux->id);
                graph.append(" -> ");
                graph.append(aux->siguiente->id);
                graph.append("; \n");
            }
            else{
                graph.append(aux->id);
                graph.append("; \n");
            }

            aux = aux->siguiente;
        }
    }

    graph.append("} \n");

    return graph;

}

//**********INSERTAR LISTA DOBLE**********
void insertarLDO(ListaDO *ListaDoble, QString cliente,int turn_rest , ColaS *cola, Pila *pila, int cantidad){
    for(int i = 0; i < cantidad; i++){
        Escritorio *nuevo = new Escritorio();
        nuevo->siguiente = NULL;
        nuevo->anaterior = NULL;
        nuevo->letra = (65 + i);
        nuevo->estado = false;
        nuevo->cliente = cliente;
        nuevo->cola = *cola;
        nuevo->pila = *pila;
        nuevo->cantidad = turn_rest;

        Escritorio *aux = new Escritorio();
        aux->anaterior = NULL;
        aux->siguiente = NULL;

        if(ListaDoble->primero == NULL){
            ListaDoble->primero = nuevo;
            ListaDoble->ultimo = nuevo;
        }
        else{
            ListaDoble->ultimo->siguiente = nuevo;
            nuevo->anaterior = ListaDoble->ultimo;
            ListaDoble->ultimo = nuevo;
        }
    }
}

//**********MOSTRAR LISTA DOBLE**********
QString mostrarLDO(ListaDO *ListaDoble){
    QString graph;
    Escritorio *aux = new Escritorio();
    aux->anaterior = NULL;
    aux->siguiente = NULL;

    graph.append("subgraph cluster_Escritorios { \n node [shape=box]; \n");

    if(ListaDoble->primero == NULL){
        QMessageBox msgBox;
        msgBox.setText("La lista de Escritorios esta vacia");
        msgBox.exec();
    }
    else{

        aux = ListaDoble->primero;

        while(aux != NULL){

            if((aux->anaterior == NULL) && (aux->siguiente == NULL)){
                graph.append(aux->letra);
                graph.append(";\n");
            }
            else if((aux->siguiente == NULL) && (aux->anaterior != NULL)){
                //graph.append(aux->id);
                //graph.append(" -> ");
                //graph.append(aux->anterior->id);
                //graph.append(";\n");
            }
            else{
                graph.append(aux->letra);
                graph.append(" -> ");
                graph.append(aux->siguiente->letra);
                graph.append(";\n");
                graph.append(aux->siguiente->letra);
                graph.append(" -> ");
                graph.append(aux->siguiente->anaterior->letra);
                graph.append(";\n");
            }

            aux = aux->siguiente;
        }
    }

    graph.append("}");

    return graph;
}

void generarArchivo(QString texto){
    QString text;
    QFile archivo("/home/drbones/archivo.dot");
    archivo.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream text_stream_for_writing(&archivo);

    text = texto;

    text_stream_for_writing << text;

    archivo.close();

    text.clear();

    system("dot -Tpng /home/drbones/archivo.dot -o /home/drbones/grafo.png"); // Generar el grafo
    system("nohup display /home/drbones/grafo.png &");  //Desplegar grafo.

}
