//Nivel Mestre
#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.

// Enum com os atributos numéricos que podem ser comparados
typedef enum {
    POPULACAO,
    AREA,
    PIB,
    DENSIDADE_POPULACIONAL,
    PIB_PER_CAPITA
} Atributo;

// Escolha fixa do atributo para comparação (mudar aqui para comparar outro atributo)
// Opções: POPULACAO, AREA, PIB, DENSIDADE_POPULACIONAL, PIB_PER_CAPITA
#define ATTRIBUTE_CHOICE DENSIDADE_POPULACIONAL

int main() {
    // Variáveis separadas para cada atributo da cidade.
    // Atributos: estado, código da carta (), nome da cidade, população, área, PIB, número de pontos turísticos.

    char estado1,estado2; //uma letra, de A a H, respresentando um dos oito estados 
    char codigo_carta1[4]; //letra do estado seguida de um número de 01 a 04 (ex: A01, B03)
    char codigo_carta2[4]; //letra do estado seguida de um número de 01 a 04 (ex: A01, B03)
    char nome_cidade1[50], nome_cidade2[50]; //nome da cidade, até 50 caracteres
    int populacao1,populacao2; //população da cidade, um número inteiro 
    float area1,area2; //área da cidade em km², um número real
    float pib1,pib2; //PIB da cidade em milhões de reais, um número real
    int numero_pontos_turisticos1,numero_pontos_turisticos2; //número de pontos turísticos da cidade, um número inteiro
    float densi_pop1,densi_pop2; //densidade populacional da cidade, um número real
    float pib_per_capita1,pib_per_capita2; //PIB per capita da cidade, um número real

    // Cadastro das Cartas:
    //Carta 1: Solicitar ao usuário que insira as informações de uma cidade.
    // Solicitar ao usuário que insira as informações de cada cidade
    printf("Digite o estado utilizando uma letra maiúscula entre A e H:\n");
    scanf(" %c", &estado1);
    printf("Digite o código da carta (letra do estado seguida de um número de 01 a 04):\n");
    scanf("%3s", codigo_carta1);
    printf("Digite o nome da cidade (até 50 caracteres):\n");
    scanf(" %[^\n]", nome_cidade1); // Lê até 50 caracteres, incluindo espaços
    printf("Digite a população da cidade (número inteiro):\n");
    scanf("%d", &populacao1);
    printf("Digite a área da cidade em km² (número real):\n");
    scanf("%f", &area1);
    printf("Digite o PIB da cidade em milhões de reais (número real):\n");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turísticos da cidade (número inteiro):\n");
    scanf("%d", &numero_pontos_turisticos1);

    //Carta 2: Repetir o processo para uma segunda cidade, utilizando as mesmas variáveis.
    printf("\nDigite novamente as informações de outra cidade:\n");
    printf("Digite o estado utilizando uma letra maiúscula entre A e H:\n");
    scanf(" %c", &estado2);
    printf("Digite o código da carta (letra do estado, maiúscula, seguida de um número de 01 a 04):\n");
    scanf("%3s", codigo_carta2);
    printf("Digite o nome da cidade (até 50 caracteres):\n");
    scanf(" %[^\n]", nome_cidade2); // Lê até 50 caracteres, incluindo espaços
    printf("Digite a população da cidade (número inteiro):\n");
    scanf("%d", &populacao2);
    printf("Digite a área da cidade em km² (número real):\n");
    scanf("%f", &area2);
    printf("Digite o PIB da cidade em milhões de reais (número real):\n");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos da cidade (número inteiro):\n");
    scanf("%d", &numero_pontos_turisticos2); 

    // Calcular densidade e PIB per capita para uso posterior
    densi_pop1 = populacao1 / area1;
    densi_pop2 = populacao2 / area2;
    pib_per_capita1 = (pib1 * 1000.0f) / populacao1; // em milhares de reais
    pib_per_capita2 = (pib2 * 1000.0f) / populacao2; // em milhares de reais

    // Exibição dos Dados das Cartas:
    // Exibindo os valores inseridos para cada atributo da cidade, um por linha.
    printf("\nDados da Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código da Carta: %s\n", codigo_carta1);
    printf("Nome da Cidade: %s\n", nome_cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f milhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", numero_pontos_turisticos1); 
    printf("Densidade Populacional: %.2f habitantes/km²\n", densi_pop1);
    printf("PIB per Capita: %.2f mil reais\n", pib_per_capita1); 

    printf("\nDados da Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código da Carta: %s\n", codigo_carta2);
    printf("Nome da Cidade: %s\n", nome_cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f milhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", numero_pontos_turisticos2); 
    printf("Densidade Populacional: %.2f habitantes/km²\n", densi_pop2);
    printf("PIB per Capita: %.2f mil reais\n", pib_per_capita2);

    // Comparar apenas o atributo escolhido em código
    printf("\nComparando atributo fixo definido em código: ");
    switch (ATTRIBUTE_CHOICE) {
        case POPULACAO:
            printf("População\n");
            if (populacao1 > populacao2) printf("Carta 1 vence pela população.\n");
            else if (populacao2 > populacao1) printf("Carta 2 vence pela população.\n");
            else printf("Empate na população.\n");
            break;
        case AREA:
            printf("Área\n");
            if (area1 > area2) printf("Carta 1 vence pela área.\n");
            else if (area2 > area1) printf("Carta 2 vence pela área.\n");
            else printf("Empate na área.\n");
            break;
        case PIB:
            printf("PIB\n");
            if (pib1 > pib2) printf("Carta 1 vence pelo PIB.\n");
            else if (pib2 > pib1) printf("Carta 2 vence pelo PIB.\n");
            else printf("Empate no PIB.\n");
            break;
        case DENSIDADE_POPULACIONAL:
            printf("Densidade Populacional\n");
            if (densi_pop1 > densi_pop2) printf("Carta 1 vence pela densidade populacional.\n");
            else if (densi_pop2 > densi_pop1) printf("Carta 2 vence pela densidade populacional.\n");
            else printf("Empate na densidade populacional.\n");
            break;
        case PIB_PER_CAPITA:
            printf("PIB per Capita\n");
            if (pib_per_capita1 > pib_per_capita2) printf("Carta 1 vence pelo PIB per capita.\n");
            else if (pib_per_capita2 > pib_per_capita1) printf("Carta 2 vence pelo PIB per capita.\n");
            else printf("Empate no PIB per capita.\n");
            break;
        default:
            printf("Atributo desconhecido.\n");
    }

    return 0;
}