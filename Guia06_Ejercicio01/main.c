#include <stdio.h>
#include <stdlib.h>
struct nodo{
    int info;
    struct nodo *sig;
};

struct nodo *raiz=NULL;

void insertar(int x){
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->info=x;
    if(raiz==NULL){
        raiz=nuevo;
        nuevo->sig=NULL;
    } else{
        nuevo->sig=raiz;
        raiz=nuevo;
    }
}

void imprimir(){
    struct nodo *reco=raiz;
    printf("Lista completa.\n");
    while (reco!=NULL){
        printf("%i\n",reco->info);
        reco=reco->sig;
    }
    printf("\n");
}
void count(){
    int num=0;
    struct nodo *reco=raiz;
    while (reco!=NULL){
        printf("%i\n",reco->info);
        reco=reco->sig;
        num=num+1;

    }
    printf("El numero de nodos es: %i.\n",num);
}

int extraer(){
    if(raiz!=NULL){
        int informacion=raiz->info;
        struct nodo *bor=raiz;
        raiz=raiz->sig;
        free(bor);
        return informacion;
    } else{
        return -1;
    }
}

void liberar(){
    struct nodo *reco=raiz;
    struct nodo *bor;
    while (reco!=NULL){
    bor=reco;
    reco= reco->sig;
    free(bor);
    }
}
void isEmpty(){
    if (raiz==NULL){
        printf("La pila esta vacia.\n");
    } else{
        printf("La pila no esta vacia.\n");
    }
}

int main() {
    isEmpty();
    insertar(10);
    insertar(40);
    count();
    insertar(3);
    count();
    isEmpty();
    imprimir();
    printf("Extraemos de la pila:%i\n",extraer());
    count();
    imprimir();
    liberar();

    return 0;
}