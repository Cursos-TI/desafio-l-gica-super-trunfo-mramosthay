#include <stdio.h>
#include <stdlib.h>

int main() {
    char estado1[50], estado2[50], cidade1[50], cidade2[50];
    int populacao1, populacao2, pontosTuristicos1, pontosTuristicos2;
    float area1, area2, pib1, pib2;
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;

    // Exibir tutorial inicial
    printf("\n*** Bem-vindo ao jogo Super Trunfo de Cidades! ***\n");
    printf("Cada jogador escolherá uma cidade e inserirá seus atributos.\n");
    printf("Você escolherá dois atributos para comparar e o jogo determinará a cidade vencedora.\n");
    printf("\n");
    printf("Atributos: \n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Demográfica\n5 - PIB per capita\n6 - Pontos Turísticos\n");
    printf("Boa sorte!\n\n");

    // Exibição das cartas 1 e 2
    printf("Cidade 1:\n");
    printf("Estado: ");
    scanf("%s", estado1);
    printf("Cidade: ");
    scanf("%s", cidade1);
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões): ");
    scanf("%f", &pib1);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    //Cálculo densidade demografica e pib per capita
    densidade1 = (area1 > 0) ? populacao1 / area1 : 0;
    pibPerCapita1 = (populacao1 > 0) ? pib1 / populacao1 : 0;

    printf("\nCidade 2:\n");
    printf("Estado: ");
    scanf("%s", estado2);
    printf("Cidade: ");
    scanf("%s", cidade2);
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões): ");
    scanf("%f", &pib2);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);
    
    densidade2 = (area2 > 0) ? populacao2 / area2 : 0;
    pibPerCapita2 = (populacao2 > 0) ? pib2 / populacao2 : 0;

    // Escolha dos atributos
    int atributo1, atributo2;
    printf("\n *** Vamos jogar Super Trunfo! ***\n");
    
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 6) {
        printf("Atributo inválido! Reinicie o jogo.\n");
        return 1;
    }
    
    printf("Escolha o segundo atributo (diferente do primeiro): ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1) {
        printf("Atributo inválido! Reinicie o jogo.\n");
        return 1;
    }
    
    float valor1_1 = 0, valor2_1 = 0, valor1_2 = 0, valor2_2 = 0;
    
    switch (atributo1) {
        case 1: 
            valor1_1 = populacao1; valor2_1 = populacao2; 
            break;

        case 2: 
            valor1_1 = area1; valor2_1 = area2; 
            break;

        case 3: 
            valor1_1 = pib1; valor2_1 = pib2; 
            break;

        case 4: 
            valor1_1 = densidade1; valor2_1 = densidade2; 
            break;

        case 5: 
            valor1_1 = pibPerCapita1; valor2_1 = pibPerCapita2; 
            break;

        case 6: 
            valor1_1 = pontosTuristicos1; valor2_1 = pontosTuristicos2; 
            break;

        default: printf("Erro inesperado!\n"); return 1;
    }

    switch (atributo2) {
        case 1: 
            valor1_2 = populacao1; valor2_2 = populacao2; 
            break;
        case 2: 
            valor1_2 = area1; valor2_2 = area2; 
            break;
        case 3: 
            valor1_2 = pib1; valor2_2 = pib2; 
            break;
        case 4: 
            valor1_2 = densidade1; valor2_2 = densidade2; 
            break;
        case 5: 
            valor1_2 = pibPerCapita1; valor2_2 = pibPerCapita2; 
            break;
        case 6: 
            valor1_2 = pontosTuristicos1; valor2_2 = pontosTuristicos2; 
            break;

        default: printf("Erro inesperado!\n"); return 1;
    }

    float soma1 = valor1_1 + valor1_2;
    float soma2 = valor2_1 + valor2_2;
    int vencedorFinal = (soma1 > soma2) ? 1 : (soma1 < soma2) ? 2 : 0;

    printf("\n================= RESULTADO DA COMPARAÇÃO =================\n");
    printf("Cidade 1: %s (%s)\n", cidade1, estado1);
    printf("Cidade 2: %s (%s)\n\n", cidade2, estado2);
    printf("Atributos escolhidos:\n");
    printf("1º Atributo: %.2f vs %.2f\n", valor1_1, valor2_1);
    printf("2º Atributo: %.2f vs %.2f\n\n", valor1_2, valor2_2);
    printf("Soma dos atributos:\n");
    printf("   - %s: %.2f\n", cidade1, soma1);
    printf("   - %s: %.2f\n", cidade2, soma2);
    
    if (vencedorFinal == 1) {
        printf("\nCidade vencedora: %s\n", cidade1);

    } else if (vencedorFinal == 2) {
        printf("\nCidade vencedora: %s\n", cidade2);
        
    } else {
        printf("\nEmpate! Nenhuma cidade venceu.\n");
    }
    printf("===========================================================\n");
    
    return 0;
}
