#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "visor.h"

void visor()
{
    int opt, c;

    do {

        printf("|###########################|\n");
        printf("|        Player Music       |\n");
        printf("|###########################|\n");
        printf("| 1. Inserir Música         |\n");
        printf("| 2. Pesquisar Música       |\n");
        printf("| 3. listar Músicas         |\n");
        printf("| 4. Limpar Player list     |\n");
        printf("| 5. Sair                   |\n");
        printf("|###########################|\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opt);

        while ((c = getchar()) != '\n' && c != EOF){}

        switch (opt) {

        case 1:
            inserirMusica();
            getchar();
            break;

        case 2:
            localizarMusica();
            getchar();
            break;

        case 3:
            mostrarLista();
            getchar();
            break;

        case 4:
            esvaziarLista();
            getchar();
            break;

        case 5:
            printf("\nO programa foi encerrado com sucesso!!\n\n");
            getchar();
            break;

        default:
            printf("\nEscolha invalida!!\n\n");
            getchar();
            break;
        }
        system("clear");
    } while (opt != 5);
}