#include <iostream>
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    cout<<"Hola mundo";
    listaDoble = (struct lista *)malloc(sizeof(struct lista));
    listaDoble ->primero = NULL;
    listaDoble ->ultimo = NULL;
    menu();
    return 0;
}


void menu(){
    int opcion;

    printf("1. Ingresar dato a la lista \n");
    printf("2. Eliminar dato de la lista \n");
    printf("3. Mostrar Lista \n");
    printf("Ingrese una opcion : ");
    scanf("%d", opcion);

    switch(opcion){
        case 1:
            int val;
            printf("Ingrese el valor deseado : ");
            scanf("%d", val);
            insertar(listaDoble, val);
            break;
    }
}

void insertar(lista *listaDoble, int val){
    nuevo = (struct nodo *)malloc(sizeof(struct nodo));
    nuevo ->anterior = NULL;
    nuevo ->siguiente = NULL;
    nuevo ->valor = val;

    if(listaDoble -> primero == NULL){
        listaDoble ->primero = nuevo;
        listaDoble ->ultimo = nuevo;
    }
    else{
        listaDoble->ultimo->siguiente = nuevo;
        nuevo->anterior = listaDoble ->ultimo;
        listaDoble->ultimo = nuevo;
    }
}
