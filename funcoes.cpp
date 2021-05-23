#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

struct Lista {
    char musica[40], cantor[40];
    float duracao;
    Lista *prox;
};
Lista *inicio, *fim, *aux;

void inserirMusica() { //Função de inserção na lista.

    int c;
    Lista *novo = (struct Lista *)malloc(sizeof(struct Lista));

    printf("\nDigite o nome da música: ");
    fgets(novo->musica, 39, stdin);
    printf("Nome do cantor ou banda: ");
    fgets(novo->cantor, 39, stdin);
    printf("Duração da música: ");
    scanf("%f", &novo->duracao);

    while ((c = getchar()) != '\n' && c != EOF){}

    novo->prox = NULL;

    if (inicio == NULL) {
        inicio = fim = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }
    printf("\nMusica inserida com sucesso!!\n\n");
}

void esvaziarLista() { //Função para excluir toda a lista.

    char ch;

    if (inicio == NULL) {
        printf("\nA fila está vazia!\n\n");
    } else {

        printf("\nTem certeza que deseja esvaziar toda a lista (s/n): ");

        ch = getchar();

        if (ch == 's' || ch == 'S') {
            while (inicio != NULL) {
                aux = inicio;
                inicio = inicio->prox;
                free(aux);
            }
            printf("\nA lista foi esvaziada com sucesso!!\n\n");
        } else {
            printf("\nA lista nao foi esvaziada!!\n\n");
        }
    }
}

void mostrarLista() {//Função para exibir a lista na tela do usuário.

    aux = inicio;

    if (inicio == NULL) {
        printf("\nA lista está vazia!");
    } else {

        while (aux != NULL) {
            printf("\n");
            printf("Música: %s", aux->musica);
            printf("Cantor: %s", aux->cantor);
            printf("Duração: %.2f\n", aux->duracao);
            aux = aux->prox;
        }
    }
    printf("\n\n");
}

void localizarMusica() {//Função para pesquisar uma música na lista.

    aux = inicio;

    if (inicio == NULL) {
        printf("\nA lista está vazia!!!! :(");
    } else {

        char musica[40];
        printf("\n");
        printf("Digite o nome da música a ser buscada: ");
        fgets(musica, 39, stdin);

        while (aux->musica != NULL) {
            if (strcmp(aux->musica, musica) == 0) {
                printf("\n");
                printf("Música: %s", aux->musica);
                printf("Cantor: %s", aux->cantor);
                printf("Duração: %.2f\n", aux->duracao);
                return;
            } else {
                aux = aux->prox;
            }
        }

        if (aux->musica == NULL) {
            printf("\nMúsica %s não localizada!\n", musica);
        }
    }
    printf("\n\n");
}