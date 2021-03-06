#include <stdio.h>
#include <stdlib.h>
#include "Identificador.h"
typedef struct Vertice{
   
    //Dados iniciais da encomenda de um livro
    int id; //identificador
    char * nome_aluno;
    int matricula;
    char * descricao;
    
    //mecanismo p/ unir nos!
    struct Vertice * esq;
    struct Vertice * dir;
}VERTICE;

VERTICE * raiz = NULL;



void insert_dados(){
    
    printf("gerando id:\n");
    int id_gerado = id();
    printf("Digite o nome do aluno:\n");
    char * nome = malloc(sizeof(char));
    scanf(" %[^\n]s", nome);
    //... matricula e descricao..*/
    printf("matricula: \n");
    int *matricula = malloc(sizeof(int));
    scanf("%d", &matricula);
    printf("Descrição: \n");
    char * descricao = malloc(sizeof(char));
    scanf(" %[^\n]s", descricao);
    
    add_abb(id_gerado,nome,matricula,descricao);

}


VERTICE* buscar(int id, VERTICE *aux){
    
    if(aux != NULL){
        if(aux->id == id){
            return aux;
        }else if(id < aux->id){
            if(aux->esq != NULL){
                return buscar(id, aux->esq);
            }else{
                return aux;
            }
        }else if(id > aux->id){
            if(aux->dir != NULL){
                return buscar(id, aux->dir);
            }else{
                return aux;
            }
        }
    }else{
        return NULL;
    }
}


void add_abb(int id, char *nome_aluno, int matricula, char *descricao){

    VERTICE* aux = buscar(id, raiz);
    
    if(aux != NULL && aux->id == id){
        printf("Insercao invalida!\n");
    }else{
        
        VERTICE* novo = malloc(sizeof(VERTICE));
        novo->id = id;
        novo->nome_aluno = nome_aluno;
        novo->matricula = matricula;
        novo->descricao = descricao;
        novo->esq = NULL;
        novo->dir = NULL;
        
        if(aux == NULL){//arvore esta vazia
            raiz = novo;
        }else{
            if(id < aux->id){
                aux->esq = novo;
            }else{
                aux->dir = novo;
            }
        }
    }
}


void in_ordem(VERTICE *aux){
    
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("%d\n", aux->id);
    printf("%s\n", aux->nome_aluno);
    printf("%d\n", aux->matricula);
    printf("%s\n", aux->descricao);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
        }
}

/*void remover(int id, VERTICE * aux){
    
    if(aux != NULL && aux->id == id){
        raiz->dir->esq=raiz->esq;
        raiz->esq->dir=raiz->dir;
        free(raiz);
    }else{
        
        if(aux == NULL){//arvore esta vazia
            printf("Remocao invalida!\nPedido nao existente!");
        }else{
            if(id < aux->id){
                remover(id, raiz->esq);
            }else{
                remover(id, raiz->dir);
            }
        }
    }

}*/
void remover_abb(int id, VERTICE * raiz){
    
    if(raiz != NULL){
        if(raiz->id == id){///Encontrou o pacote
           raiz->dir->esq=raiz->esq;
            raiz->esq->dir=raiz->dir;
            free(raiz);
        }else if(id < raiz->id){///O pacote procurado é menor
            if(raiz->esq != NULL){
                remover_abb(id, raiz->esq);
            }else{
                printf("Remocao invalida!\nPedido nao existente!");
            }
        }else if(id > raiz->id){///O pacote procurado é maior
            if(raiz->dir != NULL){
                remover_abb(id, raiz->dir);
            }else{
                printf("\nRemocao invalida!Pedido nao existente!");
            }
        }
    }else{///A arvore está vazia
        printf("Remocao invalida!\nArvore vazia");
    }

}





