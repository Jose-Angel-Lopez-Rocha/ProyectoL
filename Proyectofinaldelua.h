#ifndef PROYECTOFINALDELUA_H
#define PROYECTOFINALDELUA_H

typedef struct NodoSimple {
    int dato;
    struct NodoSimple* siguiente;
} NodoSimple;

typedef struct NodoDoble {
    int dato;
    struct NodoDoble* siguiente;      
    struct NodoDoble* anterior;
} NodoDoble;

typedef struct nodoCircular {
    int dato;
    struct nodoCircular* sig;
    struct nodoCircular* ant;
} nodoCircular;

// Funciones para la lista simple
NodoSimple* crear_NodoSimple(int dato);
void insertar_Datoinicial(NodoSimple** cabeza, int dato);
void insertar_Fin(NodoSimple** cabeza, int dato);
void insertar_Ordenado(NodoSimple** cabeza, int dato);
void Borrar(NodoSimple** cabeza, int dato);
void imprimir(NodoSimple* nodo);

// Funciones para la lista doble
NodoDoble* crear_NodoDoble(int dato);
void insertar_DatoIniciod(NodoDoble** cabeza, int dato);
void insertar_DatoFind(NodoDoble** cabeza, int dato);
void insertar_Ordenadod(NodoDoble** cabeza, int dato);
void Borrard(NodoDoble** cabeza, int dato);
void imprimir_Listad(NodoDoble* nodo);

// Funciones para la lista doble circular
nodoCircular* crear_NodoCircular(int dato);
void insertar_Nodocd(nodoCircular** primero, nodoCircular** ultimo);
void insertar_NodoFinalcd(nodoCircular** primero, nodoCircular** ultimo);
void insertar_NodoOrdenadocd(nodoCircular** primero, nodoCircular** ultimo);
void imprimir_Listacd(nodoCircular* primero);
void eliminar_Nodocd(nodoCircular** primero, nodoCircular** ultimo);

// Menus
void mostrarMenuPrincipal();
int listas_circulares();
int listas_dobles(NodoDoble** cabeza);
int listas_simples(NodoSimple** cabeza);

#endif