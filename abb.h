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
void insert_dados(){
    
    printf("gerando id:\n");
    int id_gerado = identificador();
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
// função para remover nós da Árvore binária
VERTICE* remover(VERTICE *raiz, int chave) {
    if(raiz == NULL){
        printf("id nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(raiz->id == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esq == NULL && raiz->dir == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esq != NULL && raiz->dir != NULL){
                    VERTICE *aux = raiz->esq;
                    while(aux->dir != NULL)
                        aux = aux->dir;
                    raiz->id = aux->id;
                    aux->id = chave;
                    printf("Elemento trocado: %d !\n", chave);
                    raiz->esq = remover(raiz->esq, chave);
                    return raiz;
                }
                else{
                    // remover nós que possuem apenas 1 filho
                    VERTICE *aux;
                    if(raiz->esq != NULL)
                        aux = raiz->esq;
                    else
                        aux = raiz->dir;
                    free(raiz);
                    printf("Elemento removido: %d !\n", chave);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->id)
                raiz->esq = remover(raiz->esq, chave);
            else
                raiz->dir = remover(raiz->dir, chave);
            return raiz;
        }
    }
}








