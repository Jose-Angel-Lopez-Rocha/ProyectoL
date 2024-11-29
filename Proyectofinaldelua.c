#include <stdio.h>
#include <stdlib.h> 
#include"Proyectofinaldelua.h"

/////////////////////////////// Funciones para listas simplemente enlazadas/////////////////////////////

NodoSimple* cabezaSimple = NULL;

NodoSimple* crear_NodoSimple(int dato) {
    NodoSimple* nuevoNodo = (NodoSimple*)malloc(sizeof(NodoSimple));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void insertar_Datoinicial(NodoSimple** cabeza, int dato) {
    NodoSimple* nuevoNodo = crear_NodoSimple(dato);
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

void insertar_Fin(NodoSimple** cabeza, int dato) {
    NodoSimple* nuevoNodo = crear_NodoSimple(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;//Si esta vacia el nodo se inserta y ya 
        return;
    }
    NodoSimple* aux = *cabeza;
    while (aux->siguiente != NULL) {
        aux = aux->siguiente;//se recorre para buscar la ultima posicion 
    }
    aux->siguiente = nuevoNodo;
}

void insertar_Ordenado(NodoSimple** cabeza, int dato) {
    NodoSimple* nuevoNodo = crear_NodoSimple(dato);
    if (*cabeza == NULL || (*cabeza)->dato >= dato) { //si la lista esta vacia se inserta de una 
        nuevoNodo->siguiente = *cabeza;// ya namas se hace la comparacion de tamaños 
        *cabeza = nuevoNodo;
    } else { // se recorre la lista para buscar e insertar para que apunte de nuevo
        NodoSimple* actual = *cabeza; 
        while (actual->siguiente != NULL && actual->siguiente->dato < dato) {
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
}

void Borrar(NodoSimple** cabeza, int dato) {
    NodoSimple* aux = *cabeza;
    NodoSimple* prev = NULL;
    while (aux != NULL && aux->dato != dato) {//recorremos la lista para buscar el dato en 
        prev = aux;
        aux = aux->siguiente;
    }
    if (aux == NULL) {
        printf("Número no encontrado\n");
        return;
    }
    if (prev == NULL) {//se elimina el primero  y si no se salta para darle a otro
        *cabeza = aux->siguiente;
    } else {
        prev->siguiente = aux->siguiente;
    }
    free(aux);
}

void imprimir(NodoSimple* nodo) {
    while (nodo != NULL) {
        printf("%d -> ", nodo->dato);
        nodo = nodo->siguiente;
    }
    printf("NULL\n");
}

////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////// Funciones para listas doblemente enlazadas/////////////////////////////

NodoDoble* cabezaDoble = NULL;

NodoDoble* crear_Nododoble(int dato){
   NodoDoble* nuevoNodo = (NodoDoble*)malloc(sizeof(struct NodoDoble));
    nuevoNodo->dato=dato;
    nuevoNodo->siguiente=NULL;
    nuevoNodo->anterior=NULL;
    return nuevoNodo;
}


void insertar_DatoIniciod(NodoDoble** cabeza, int dato) {
    NodoDoble* nuevoNodo = crear_Nododoble(dato);
    nuevoNodo->siguiente = *cabeza;
    if (*cabeza != NULL) {
        (*cabeza)->anterior = nuevoNodo;
    }
    *cabeza = nuevoNodo;
}

void insertar_DatoFind(NodoDoble** cabeza, int dato) {
     NodoDoble* nuevoNodo = crear_Nododoble(dato);
    if (*cabeza == NULL) {//iinicio
        *cabeza = nuevoNodo;
        return;
    }
     NodoDoble* aux = *cabeza;
    while (aux->siguiente != NULL) {//recorre para buscar el final
        aux = aux->siguiente;
    }
    aux->siguiente = nuevoNodo;
    nuevoNodo->anterior = aux;
}

void insertar_Ordenadod(NodoDoble** cabeza, int dato) {
     NodoDoble* nuevoNodo = crear_Nododoble(dato);
    if (*cabeza == NULL || (*cabeza)->dato >= dato) {
        nuevoNodo->siguiente = *cabeza;
        if (*cabeza != NULL) {
            (*cabeza)->anterior = nuevoNodo;
        }
        *cabeza = nuevoNodo;
        nuevoNodo->anterior = NULL;
    } else {
        NodoDoble* actual = *cabeza;
        while (actual->siguiente != NULL && actual->siguiente->dato < dato) {
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = actual->siguiente;
        if (actual->siguiente != NULL) {
            actual->siguiente->anterior = nuevoNodo;
        }
        actual->siguiente = nuevoNodo;
        nuevoNodo->anterior = actual;
    }
}

void Borrard(struct NodoDoble** cabeza, int dato) {
    struct NodoDoble* aux = *cabeza;
    while (aux != NULL && aux->dato != dato) {
        aux = aux->siguiente;
    }
    if (aux == NULL) {
        printf("Número no encontrado\n");
        return;
    }
    if (aux->anterior != NULL) {
        aux->anterior->siguiente = aux->siguiente;
    } else {
        *cabeza = aux->siguiente;
    }
    if (aux->siguiente != NULL) {
        aux->siguiente->anterior = aux->anterior;
    }
    free(aux);
}

void imprimir_Listad(struct NodoDoble* nodo) {
    while (nodo != NULL) {
        printf("%d <-> ", nodo->dato);
        nodo = nodo->siguiente;
    }
    printf("NULL\n");
}
///////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////// Funciones para listas circularmente doblemente enlazadas /////////////////////////////


nodoCircular* primero = NULL;
nodoCircular* ultimo = NULL;


nodoCircular* crear_NodoCircular(int dato){
   nodoCircular*nuevoNodo = (nodoCircular*)malloc(sizeof(nodoCircular));

    nuevoNodo->dato=dato;
    nuevoNodo->sig=NULL;
    nuevoNodo->ant=NULL;
    return nuevoNodo;
}



void insertar_Nodocd(nodoCircular** primero, nodoCircular** ultimo) {
    nodoCircular* nuevo = crear_NodoCircular(0);  
    printf("Ingresa el dato: ");
    scanf("%d", &nuevo->dato);
    if (*primero == NULL) {
        *primero = nuevo;
        *ultimo = nuevo;
        (*primero)->sig = *primero; 
        (*primero)->ant = *ultimo;
    } else {
        (*ultimo)->sig = nuevo;
        nuevo->sig = *primero;
        nuevo->ant = *ultimo;
        *ultimo = nuevo;
        (*primero)->ant = *ultimo;
    }
    printf("\n Nodo ingresado\n\n");
}

void insertar_NodoFinalcd(nodoCircular** primero, nodoCircular** ultimo) {
    nodoCircular* nuevo = crear_NodoCircular(0);
    printf("Ingresa el dato: ");
    scanf("%d", &nuevo->dato);
    
    if (*primero == NULL) {
        *primero = nuevo;
        *ultimo = nuevo;
        (*primero)->sig = *primero;
        (*primero)->ant = *ultimo;
    } else {
        nuevo->sig = *primero;
        nuevo->ant = *ultimo;
        (*ultimo)->sig = nuevo;
        (*primero)->ant = nuevo;
        *ultimo = nuevo;
    }
    printf("\nNodo ingresado al final\n\n");
}

void insertar_NodoOrdenadocd(nodoCircular** primero, nodoCircular** ultimo) {
    nodoCircular* nuevo = crear_NodoCircular(0);
    printf("Ingresa el dato: ");
    scanf("%d", &nuevo->dato);
    
    if (*primero == NULL) {
        *primero = nuevo;
        *ultimo = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    } else {
        nodoCircular* actual = *primero;
        do {
            if (nuevo->dato < actual->dato) {
                nuevo->sig = actual;
                nuevo->ant = actual->ant;
                actual->ant->sig = nuevo;
                actual->ant = nuevo;
                if (actual == *primero) {
                    *primero = nuevo;
                }
                return;
            }
            actual = actual->sig;
        } while (actual != *primero);

        nuevo->sig = *primero;
        nuevo->ant = *ultimo;
        (*ultimo)->sig = nuevo;
        (*primero)->ant = nuevo;
        *ultimo = nuevo;
    }
    printf("\n Nodo ingresado\n\n");
}
void imprimir_Listacd(nodoCircular* primero) {
    nodoCircular* actual = primero;
    if (primero != NULL) {
        do {
            printf("%d ", actual->dato);
            actual = actual->sig;
        } while (actual != primero);
    } else {
        printf("Lista vacía\n\n");   
    }
}

void eliminar_Nodocd(nodoCircular** primero, nodoCircular** ultimo) {
    int nodoBuscado = 0;
    nodoCircular* actual = *primero;
    nodoCircular* anterior = NULL;

    printf("Ingresa el dato a eliminar: ");
    scanf("%d", &nodoBuscado);

    if (*primero != NULL) {
        do {
            if (actual->dato == nodoBuscado) {
                if (actual == *primero) {
                    *primero = (*primero)->sig;
                    if (*primero != NULL) {
                        (*primero)->ant = *ultimo;
                    }
                } else if (actual == *ultimo) {
                    anterior->sig = *primero;
                    *ultimo = anterior;
                } else {
                    anterior->sig = actual->sig;
                    actual->sig->ant = anterior;
                }
                free(actual);
                printf("Nodo eliminado\n");
                return;
            }
            anterior = actual;
            actual = actual->sig;
        } while (actual != *primero);
    }
    printf("Elemento no encontrado\n");
}
///////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////// Menú para listas simplemente ligadas//////////////////////////////////////////////////////////
int listas_simples(NodoSimple** cabeza) {
    int k = 0;
    do {
        printf("===== Menu Listas Simplemente Enlazadas =====\n");
        printf("1. Insertar en el inicio\n");
        printf("2. Insertar al final\n");
        printf("3. Insertar ordenado\n");
        printf("4. Borrar\n");
        printf("5. Imprimir lista\n");
        printf("6. Regresar\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &k);

        switch (k) {
            case 1: {
                int dato;
                printf("Ingresa el dato inicial: ");
                scanf("%d", &dato);
                insertar_Datoinicial(cabeza, dato);
                break;
            }
            case 2: {
                int dato;
                printf("Ingresa el dato a insertar al final: ");
                scanf("%d", &dato);
                insertar_Fin(cabeza, dato);
                break;
            }
            case 3: {
                int dato;
                printf("Ingresa el dato a insertar ordenadamente: ");
                scanf("%d", &dato);
                insertar_Ordenado(cabeza, dato);
                break;
            }
            case 4: {
                int dato;
                printf("Ingresa el dato a borrar: ");
                scanf("%d", &dato);
                Borrar(cabeza, dato);
                break;
            }
            case 5:
                imprimir(*cabeza);
                break;
            case 6:
                return 0; 
            default:
                printf("Opción incorrecta. Intente de nuevo.\n");
                break;
        }
    } while (k != 6); 
    return 0;
}
//////////////////////////////////////////////////////////// Menú para listas doblemente enlazadas//////////////////////////////////////////////////////////
int listas_dobles(struct NodoDoble** cabeza) {
    int k = 0;
    do {
        printf("=====Menu listas doblemente enlazadas=====\n");
        printf("1. Insertar inicio\n");
        printf("2. Insertar fin\n");
        printf("3. Insertar ordenado\n");
        printf("4. Borrar\n");
        printf("5. Imprimir lista\n");
        printf("6. Regresar\n");
        printf("Seleccione una opcion: ");
        scanf("%i", &k);

        switch (k) {
            case 1: {
                int dato;
                printf("Ingresa el dato inicial: ");
                scanf("%d", &dato);
                insertar_DatoIniciod(cabeza, dato);
                break;
            }
            case 2: {
                int dato;
                printf("Ingresa el dato a insertar al final: ");
                scanf("%d", &dato);
                insertar_DatoFind(cabeza, dato);
                break;
            }
            case 3: {
                int dato;
                printf("Ingresa el dato a insertar: ");
                scanf("%d", &dato);
                insertar_Ordenadod(cabeza, dato);
                break;
            }
            case 4: {
                int dato;
                printf("Ingresa el dato a borrar: ");
                scanf("%d", &dato);
                Borrard(cabeza, dato);
                break;
            }
            case 5:
                imprimir_Listad(*cabeza);
                break;
            case 6:
                return 0; 
            default:
                printf("Opción incorrecta\n");
                break;
        }
    } while (k != 11);
    return 0;
}

/////////////////////////////// Menú para listas circularmente doblemente enlazadas//////////////////////////////////////////////////////////
int listas_circulares() {
    int opc;

    do {
        printf("=====Menu listas circularmente doblemente enlazadas=====\n");
        printf("1. Insertar nodo al inicio\n");
        printf("2. Insertar nodo ordenado\n");
          printf("3. Insertar nodo al final\n");
        printf("4. Imprimir lista\n");
        printf("5. Borrar nodo\n");
        printf("6. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                insertar_Nodocd(&primero, &ultimo);
                break;  
            case 2:
                insertar_NodoOrdenadocd(&primero, &ultimo);
                break;
            case 3:
                insertar_NodoFinalcd(&primero, &ultimo);
                break;
            case 4:
                imprimir_Listacd(primero);
                break;
            case 5:
                eliminar_Nodocd(&primero, &ultimo);
                break;
                case 6:
                return 0;
                break;
            default:
                printf("Opción inválida\n");
                break;
        }
    } while (opc != 5);
    return 0;
}
///////////////////////////////////////// Menu Principal /////////////////////////////////////////

void mostrarMenuPrincipal(){
    
    int n;
    do {
        printf("====Menu principal====\n");
        printf("1. Listas simplemente ligadas\n");
        printf("2. Listas doblemente enlazadas\n");
        printf("3. Listas circularmente doblemente enlazadas\n");
        printf("4. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%i", &n);

        switch (n) {
            case 1:
                listas_simples(&cabezaSimple);
                break;
            case 2:
                listas_dobles(&cabezaDoble);
                break;
            case 3:
                listas_circulares();
                break;
            case 4:
                printf("Adiós\n");
                break;
            default:
                printf("Opción incorrecta\n");
                break;
        }
    } while (n != 4); 

    
    struct NodoSimple* actualSimple = cabezaSimple;
    struct NodoSimple* siguienteSimple;
    while (actualSimple != NULL) {
        siguienteSimple = actualSimple->siguiente;
        free(actualSimple);
        actualSimple = siguienteSimple;
    }

    
    struct NodoDoble* actualDoble = cabezaDoble;
    struct NodoDoble* siguienteDoble;
    while (actualDoble != NULL) {
        siguienteDoble = actualDoble->siguiente;
        free(actualDoble);
        actualDoble = siguienteDoble;
    }

  
    if (primero != NULL) {
    nodoCircular* actual = primero;
    nodoCircular* siguiente;
    do {
        siguiente = actual->sig;
        free(actual);
        actual = siguiente;
    } while (actual != primero);
    primero = NULL;  
    ultimo = NULL;   
}
}