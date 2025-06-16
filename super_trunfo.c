#include <stdio.h>

// Estrutura para armazenar os dados de uma carta do Super Trunfo
typedef struct {
    char estado[30];
    char codigoCarta[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular a densidade populacional e PIB per capita da carta
void calcularIndicadores(Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

int main() {
    // Criando e preenchendo duas cartas pré-definidas
    Carta carta1 = {
        "SP", "C01", "São Paulo", 12300000, 1521.11, 700000000.0, 30
    };
    Carta carta2 = {
        "RJ", "C02", "Rio de Janeiro", 6000000, 1200.20, 400000000.0, 20
    };

    // Calcula os indicadores para as duas cartas
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Definindo o atributo para comparação (alterar aqui para mudar o atributo)
    // Opções: 1-População, 2-Área, 3-PIB, 4-Densidade Populacional, 5-PIB per capita
    int atributoComparacao = 1;

    // Variáveis para armazenar os valores dos atributos das cartas e o nome do atributo para exibição
    float valorCarta1, valorCarta2;
    char nomeAtributo[30];

    // Seleciona o atributo para comparar baseado no valor de atributoComparacao
    if (atributoComparacao == 1) {
        valorCarta1 = carta1.populacao;
        valorCarta2 = carta2.populacao;
        sprintf(nomeAtributo, "População");
    } else if (atributoComparacao == 2) {
        valorCarta1 = carta1.area;
        valorCarta2 = carta2.area;
        sprintf(nomeAtributo, "Área");
    } else if (atributoComparacao == 3) {
        valorCarta1 = carta1.pib;
        valorCarta2 = carta2.pib;
        sprintf(nomeAtributo, "PIB");
    } else if (atributoComparacao == 4) {
        valorCarta1 = carta1.densidadePopulacional;
        valorCarta2 = carta2.densidadePopulacional;
        sprintf(nomeAtributo, "Densidade Populacional");
    } else if (atributoComparacao == 5) {
        valorCarta1 = carta1.pibPerCapita;
        valorCarta2 = carta2.pibPerCapita;
        sprintf(nomeAtributo, "PIB per capita");
    } else {
        printf("Atributo inválido para comparação.\n");
        return 1;
    }

    // Exibe as informações das cartas e o atributo escolhido
    printf("Comparação de cartas (Atributo: %s):\n", nomeAtributo);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valorCarta1);
    printf("Carta 2 - %s (%s): %.2f\n\n", carta2.nomeCidade, carta2.estado, valorCarta2);

    // Lógica para determinar o vencedor
    // Para densidade populacional, vence a carta com menor valor
    if (atributoComparacao == 4) {
        if (valorCarta1 < valorCarta2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valorCarta2 < valorCarta1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    // Para os demais atributos, vence a carta com maior valor
    else {
        if (valorCarta1 > valorCarta2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valorCarta2 > valorCarta1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    return 0;
}
