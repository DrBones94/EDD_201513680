#include <QCoreApplication>
#include "lista_d.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    listaDoble = (struct lista *)malloc(sizeof(struct lista));
    listaDoble->primero = NULL;
    listaDoble->ultimo = NULL;
    menu();
    return a.exec();
}

void menu(){
    int opcion = 0;
    printf("1. Insertar dato a la lista \n");
    printf("2. Eliminar elemento de la lista (primero) \n");
    printf("3. Eliminar elemento de la lista (ultimo) \n");
    printf("4. Eliminar elemento de la lista (valor) \n");
    printf("5. Mostrar lista \n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);
    printf("\n\n");

    switch (opcion) {
    case 1:
        int val;
        printf("Ingrese el valor que desea agregar: ");
        scanf("%d", &val);
        insertar(listaDoble, val);
        menu();
        break;
    case 2:
        printf("Se a eliminado el nodo del inicio \n");
        eliminarI(listaDoble);
        menu();
        break;
    case 3:
        printf("Se a eliminado el nodo del final \n");
        eliminarF(listaDoble);
        menu();
        break;
    case 4:
        int val2;
        printf("Ingrese el valor que desea eliminar: ");
        scanf("%d", &val2);
        eliminarB(listaDoble, val2);
        menu();
        break;
    case 5:
        mostrar(listaDoble);
        menu();
        break;
        break;
    case 6:
        exit(0);
        break;
    default:

        break;
    }
}

void insertar(lista *listaD, int val){
    nuevo = (struct nodo *)malloc(sizeof(struct nodo));
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    nuevo->valor = val;

    if(listaD->primero == NULL){
        listaD->primero = nuevo;
        listaD->ultimo = nuevo;
    }
    else{
        listaD->ultimo->siguiente = nuevo;
        nuevo->anterior = listaD->ultimo;
        listaD->ultimo = nuevo;
    }
}

void mostrar(lista *listaD){
    nodo *aux = (struct nodo *)malloc(sizeof(struct nodo));

    if(listaD->primero == NULL){
        printf("La lista esta vacia \n");
    }
    else{
        aux = listaD->primero;
        while(aux != NULL){
            printf("Dato: %d \n", aux->valor);
            aux = aux->siguiente;
        }
    }
}

void eliminarI(lista *listaD){
    nodo *aux = (struct nodo *)malloc(sizeof(struct nodo));

    if(listaD->primero == NULL){
        printf("La lista esta vacia");
    }
    else{
        aux = listaD->primero->siguiente;
        free(listaD->primero);
        listaD->primero = aux;
    }

}

void eliminarF(lista *listaD){
    nodo *aux = (struct nodo *)malloc(sizeof(struct nodo));

    if(listaD->primero == NULL){
        printf("La lista esta vacia");
    }
    else{
        aux = listaD->ultimo->anterior;
        aux->siguiente = NULL;
        free(listaD->ultimo);
        listaD->ultimo = aux;
    }

}

void eliminarB(lista *listaD, int val){
    nodo *aux1 = (struct nodo *)malloc(sizeof(struct nodo));
    nodo *aux2 = (struct nodo *)malloc(sizeof(struct nodo));

    aux1 = listaD->primero;

    int encontrado = 0;

    while((aux1 != NULL) && (encontrado == 0)){
        if(aux1 ->valor == val){
            if(aux1->anterior == NULL){
                eliminarI(listaD);
                break;
            }
            else if(aux1->siguiente == NULL){
                eliminarF(listaD);
                break;
            }
            else{
                encontrado = 1;
                aux2 = aux1->anterior;
                aux2->siguiente = aux1->siguiente;
                aux1->siguiente->anterior = aux2;
                free(aux1);
                break;
            }

        }
        else{
            aux1 = aux1->siguiente;
        }
    }
}
