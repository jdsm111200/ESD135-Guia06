#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int info;
    struct nodo *sig;
};


struct nodo *raiz=NULL;


void insertar(int x){
    struct nodo *nuevo;
    nuevo = malloc(sizeof (struct nodo));
    nuevo->info = x;
    if (raiz == NULL) {
        raiz=nuevo;
        nuevo->sig=NULL;
    }else{
        nuevo->sig = raiz;
        raiz=nuevo;
    }
}


void imprimir(){
    struct nodo *reco=raiz;
    while(reco!=NULL){
        printf("%i ", reco->info);
        reco=reco->sig;
    }
    printf("\n");
}


void reemplazar(struct nodo *pila, int viejo, int nuevo ){
    if(pila != NULL){
        while(pila!=NULL){
            if(pila->info == viejo){
                pila->info = nuevo;
            }
            pila = pila->sig;
        }
    }else{
        printf("No se encontro coincidencia con la pila\n");
    }
}

int main(){
    int viejo,nuevo;

    insertar(10);
    insertar(40);
    insertar(3);
    insertar(7);
    insertar(3);

    printf("\nLista inicial de la pila :\n");
    imprimir();
    printf("Ingrese el numero viejo:\n");
    scanf("%d", &viejo);
    printf("Ingrese el numero nuevo:\n");
    scanf("%d", &nuevo);
    reemplazar(raiz,viejo, nuevo);
    printf("\nSe sustituyó el valor viejo = %d por el valor nuevo ingresado = %d",viejo,nuevo);
    printf("\nLa lista queda:\n");
    printf("\nLista final de la pila :\n");
    imprimir();

    return 0;
}