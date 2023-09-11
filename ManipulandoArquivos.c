//
//  ManipulandoArquivos.c
//  Projetos_C
//
//  Created by Leonardo Mota on 10/09/23.
//

#include <stdio.h>
#include <stdlib.h>

// Função para calcular a média e determinar a situação
char *calcular_situacao(float media) {
    if (media >= 7.0) {
        return "APROVADO";
    } else {
        return "REPROVADO";
    }
}

int main() {
    FILE *entrada = fopen("DadosEntrada.csv", "r");
    FILE *saida = fopen("SituacaoFinal.csv", "w");

    if (entrada == NULL || saida == NULL) {
        perror("Erro ao abrir os arquivos");
        exit(EXIT_FAILURE);
    }

    char linha[100];
    // Ler e ignorar a primeira linha de cabeçalho
    fgets(linha, sizeof(linha), entrada);

    while (fgets(linha, sizeof(linha), entrada)) {
        char nome[50];
        char telefone[15];
        char curso[50];
        float nota1, nota2;

        // Parse na linha do arquivo de entrada
        sscanf(linha, "%[^,],%[^,],%[^,],%f,%f", nome, telefone, curso, &nota1, &nota2);

        // Calcular a média das notas
        float media = (nota1 + nota2) / 2.0;

        // Calcular a situação
        char *situacao = calcular_situacao(media);

        // Escrever no arquivo de saída, formatado com duas casas decimais
        fprintf(saida, "%s, %.2f, %s\n", nome, media, situacao);
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}
