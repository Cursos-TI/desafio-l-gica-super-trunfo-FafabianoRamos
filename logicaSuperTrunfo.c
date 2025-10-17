//Nivel Mestre
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

// --- Helpers globais ---
const char* nomeAtributo(Atributo a) {
    switch (a) {
        case POPULACAO: return "População";
        case AREA: return "Área";
        case PIB: return "PIB";
        case DENSIDADE_POPULACIONAL: return "Densidade Populacional";
        case PIB_PER_CAPITA: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

double get_valor_card1(Atributo a, int populacao1, float area1, float pib1, double densi_pop1, double pib_per_capita1) {
    switch (a) {
        case POPULACAO: return (double) populacao1;
        case AREA: return (double) area1;
        case PIB: return (double) pib1;
        case DENSIDADE_POPULACIONAL: return densi_pop1;
        case PIB_PER_CAPITA: return pib_per_capita1;
        default: return 0.0;
    }
}

double get_valor_card2(Atributo a, int populacao2, float area2, float pib2, double densi_pop2, double pib_per_capita2) {
    switch (a) {
        case POPULACAO: return (double) populacao2;
        case AREA: return (double) area2;
        case PIB: return (double) pib2;
        case DENSIDADE_POPULACIONAL: return densi_pop2;
        case PIB_PER_CAPITA: return pib_per_capita2;
        default: return 0.0;
    }
}

int comparaValores(double v1, double v2) {
    return (v1 > v2) ? 1 : ((v2 > v1) ? -1 : 0);
}

// compara considerando regra especial: para DENSIDADE_POPULACIONAL menor é melhor
int comparaPorAtributo(Atributo a, double v1, double v2) {
    if (a == DENSIDADE_POPULACIONAL) {
        return (v1 < v2) ? 1 : ((v2 < v1) ? -1 : 0);
    }
    return comparaValores(v1, v2);
}

// Se desejar manter escolha fixa, defina FIXED_ATTRIBUTE to 1 e ajuste FIXED_CHOICE
// Ex: #define FIXED_ATTRIBUTE 1 e #define FIXED_CHOICE PIB
// Caso contrário, o atributo será escolhido aleatoriamente em tempo de execução.
#define FIXED_ATTRIBUTE 0
#define FIXED_CHOICE DENSIDADE_POPULACIONAL

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

    // Checagens básicas para evitar divisão por zero
    if (area1 <= 0.0f || area2 <= 0.0f) {
        printf("Erro: área deve ser maior que 0 para calcular densidade.\n");
        return 1;
    }
    if (populacao1 <= 0 || populacao2 <= 0) {
        printf("Erro: população deve ser maior que 0 para calcular PIB per capita.\n");
        return 1;
    }

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
    

    // Agora: permitir que o jogador escolha dois atributos distintos (ou opção 0 = aleatório)
    Atributo escolhido1, escolhido2;
    if (FIXED_ATTRIBUTE) {
        escolhido1 = FIXED_CHOICE;
        // escolher segundo aleatório distinto
        srand((unsigned) time(NULL));
        do { escolhido2 = (Atributo) (rand() % 5); } while (escolhido2 == escolhido1);
        printf("\nAtributos escolhidos automaticamente: %s e %s\n", nomeAtributo(escolhido1), nomeAtributo(escolhido2));
    } else {
        int opc = -1;
        int valid = 0;
        // primeiro atributo
        while (!valid) {
            printf("\nEscolha o primeiro atributo (digite o número):\n");
            for (int i = 0; i < 5; ++i) printf("%d - %s\n", i+1, nomeAtributo((Atributo)i));
            printf("0 - Aleatório\n");
            if (scanf(" %d", &opc) != 1) { int c; while ((c = getchar()) != '\n' && c != EOF); printf("Entrada inválida. Tente novamente.\n"); continue; }
            if (opc == 0) { srand((unsigned) time(NULL)); escolhido1 = (Atributo) (rand() % 5); valid = 1; }
            else if (opc >= 1 && opc <= 5) { escolhido1 = (Atributo)(opc - 1); valid = 1; }
            else printf("Opção inválida.\n");
        }

        // segundo atributo (deve ser distinto do primeiro) - menu dinâmico usando switch para não mostrar o escolhido
        valid = 0;
        while (!valid) {
            printf("\nEscolha o segundo atributo (digite o número) - deve ser diferente do primeiro:\n");
            switch (escolhido1) {
                case POPULACAO:
                    printf("2 - Área\n3 - PIB\n4 - Densidade Populacional\n5 - PIB per Capita\n"); break;
                case AREA:
                    printf("1 - População\n3 - PIB\n4 - Densidade Populacional\n5 - PIB per Capita\n"); break;
                case PIB:
                    printf("1 - População\n2 - Área\n4 - Densidade Populacional\n5 - PIB per Capita\n"); break;
                case DENSIDADE_POPULACIONAL:
                    printf("1 - População\n2 - Área\n3 - PIB\n5 - PIB per Capita\n"); break;
                case PIB_PER_CAPITA:
                    printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Populacional\n"); break;
                default:
                    for (int i = 0; i < 5; ++i) printf("%d - %s\n", i+1, nomeAtributo((Atributo)i));
            }
            printf("0 - Aleatório\n");
            if (scanf(" %d", &opc) != 1) { int c; while ((c = getchar()) != '\n' && c != EOF); printf("Entrada inválida. Tente novamente.\n"); continue; }
            if (opc == 0) { srand((unsigned) time(NULL)); escolhido2 = (Atributo) (rand() % 5); if (escolhido2 == escolhido1) continue; valid = 1; }
            else if (opc >= 1 && opc <= 5) { escolhido2 = (Atributo)(opc - 1); if (escolhido2 == escolhido1) { printf("Escolha deve ser diferente do primeiro atributo.\n"); continue; } valid = 1; }
            else printf("Opção inválida.\n");
        }

        printf("\nAtributos escolhidos: %s e %s\n", nomeAtributo(escolhido1), nomeAtributo(escolhido2));
    }

    // Comparar individualmente (regra especial para densidade) e somar os valores
    double v1a = get_valor_card1(escolhido1, populacao1, area1, pib1, densi_pop1, pib_per_capita1);
    double v2a = get_valor_card2(escolhido1, populacao2, area2, pib2, densi_pop2, pib_per_capita2);
    int r1 = comparaPorAtributo(escolhido1, v1a, v2a);
    printf("\nComparação por atributo 1 (%s):\n", nomeAtributo(escolhido1));
    printf("%s: %.2f\n", nome_cidade1, v1a);
    printf("%s: %.2f\n", nome_cidade2, v2a);
    printf("Vencedor do atributo 1: %s\n", (r1==1)?nome_cidade1:((r1==-1)?nome_cidade2:"Empate"));

    double v1b = get_valor_card1(escolhido2, populacao1, area1, pib1, densi_pop1, pib_per_capita1);
    double v2b = get_valor_card2(escolhido2, populacao2, area2, pib2, densi_pop2, pib_per_capita2);
    int r2 = comparaPorAtributo(escolhido2, v1b, v2b);
    printf("\nComparação por atributo 2 (%s):\n", nomeAtributo(escolhido2));
    printf("%s: %.2f\n", nome_cidade1, v1b);
    printf("%s: %.2f\n", nome_cidade2, v2b);
    printf("Vencedor do atributo 2: %s\n", (r2==1)?nome_cidade1:((r2==-1)?nome_cidade2:"Empate"));

    // Soma dos atributos (valores numéricos) - maior soma vence
    double soma1 = v1a + v1b;
    double soma2 = v2a + v2b;
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", nome_cidade1, soma1);
    printf("%s: %.2f\n", nome_cidade2, soma2);

    if (soma1 > soma2) printf("\nResultado: %s vence pela maior soma.\n", nome_cidade1);
    else if (soma2 > soma1) printf("\nResultado: %s vence pela maior soma.\n", nome_cidade2);
    else printf("\nEmpate!\n");

    return 0;
}