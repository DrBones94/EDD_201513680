#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

struct nodo{
    int valor;
    struct nodo *siguiente;
    struct nodo *anterior;
};

struct lista{
    nodo *primero;
    nodo *ultimo;
};

lista *listaDoble;
nodo *nuevo;
void inicio();
void menu();
void insertar(lista *listaDoble, int valor);
void eliminar(lista *listaDoble, int valor);

#endif // LISTA_H_INCLUDED
