#ifndef LISTA_D
#define LISTA_D

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
void menu();
void insertar(lista *listaDoble, int valor);
void eliminarI(lista *listaDoble);
void eliminarF(lista *listaDoble);
void eliminarB(lista *listaDoble, int val);
void mostrar(lista *listaDoble);

#endif // LISTA_D

