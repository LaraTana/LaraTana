#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abb.h"


//#include "fila.h"


int main(){
    printf("\nSISTEMA DE ENCOMENDA DE LIVRO\n");
    int resp = -1;
    while(resp != 0){
        printf(" 1 - Encomendar um livro.\n");
        printf(" 2 - Remover uma encomenda de livro.\n");
        printf(" 3 - Remover um pedido de livro.\n");
        printf(" 0 - Sair do sistema!\n");
        printf("Digite a funcionalidade desejada:");
        scanf("%d", &resp);
        if(resp == 1){
            
              system("cls");
              insert_dados();
              printf("\n\n");
//-----------------------------------------------------------------------------------

       }else if(resp == 2){
            //remover uma encomenda de livro da ABB (id)
            //para remover eu preciso:
            //1 - visualizar as encomendas (in_ordem)
            
            system("cls");
            
            printf("--------------------------------\n");
            in_ordem(raiz);
            
            int x = 0;
            printf("qual id excluir: ");
            scanf("%d", &x);
            remover(raiz, x);
            
            
            //2 - verificar o usuario
            //printf(" Digite seu cpf:\n");
            //char cpf[100];
            //scanf("%s", &cpf);
            //printf(" Digite sua senha:\n");
            //char senha[100];
            //scanf("%s", &senha);
            //int retorno = verificar(cpf, senha);
            /*if(retorno == 1){
                //3 - chama a funcao remover_abb por id (CADE ESSA FUNCAO?)
                //4 - setar novos dados (faltando)
                //5 - add_fila(....);
            }else if(resp == 3){
               
                //2 - verificar o usuario
                    printf(" Digite seu cpf:\n");
                    char cpf[100];
                    scanf("%s", &cpf);
                    printf(" Digite sua senha:\n");
                    char senha[100];
                    scanf("%s", &senha);
                    //int retorno = verificar(cpf, senha);
                    if(retorno == 1){
                        //remover da fila de prioridade
                    }
            }*/
        
        }
        
    }
    
    return 0;
}