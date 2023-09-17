#include <stdio.h>
#include <string.h>

// Função para fazer a troca de duas strings no vetor
void fazerTroca(char *array[], int i, int j){ 
    char *auxiliar = array[i]; // aux recebe o array na posicao i
    array[i] = array[j]; // o que estava no i vai receber o que estava no j
    array[j] = auxiliar; // o que estava no j vai receber o que estava no i
}

// Função que encontra a chave e particiona o vetor
int particionarVetor(char *array[], int baixo, int alto, int *numTrocas, int *numComparacoes){
    char *chave = array[alto]; //elemento chave é o último elemento do vetor
    int i = baixo - 1; // inicializando um indice para a posição da chave

    // loop para percorrer o vetor da posicao baixo até alto-1
    for (int j = baixo; j < alto; j++){
        (*numComparacoes)++;
        if (strcmp(array[j], chave) < 0) { // compara a PALAVRA ATUAL (array[j]) com a chave
            i++; // se for menor que a chave, incrementa i
            fazerTroca(array, i, j); // troca a palavra atual (array[j]) com a palavra em i
            (*numTrocas)++; // incrementa o numero de trocas feitas
        }
    }

    //Após o loop, a chave tem que voltar para a posição certa
    fazerTroca(array, i+1, alto); // troca a chave (array[alto]) com a palavra na posição (i+1)
    (*numTrocas)++; // incrementa o numero de trocas feitas

    //retornando o indice onde a chave está agora
    return i+1;
}

// Função que faz o QuickSort
void quickSort(char *array[], int baixo, int alto, int *numTrocas, int *numComparacoes) {
    if (baixo < alto) { // verifica se há mais de um elemento no vetor
        int indiceChave = particionarVetor(array, baixo, alto, numTrocas, numComparacoes); // encontra o indice onde a chave deve estar

        // Aplicando o quicksort usando RECURSIVIDADE 
        quickSort(array, baixo, indiceChave - 1, numTrocas, numComparacoes); // ESQUERDA DA CHAVE
        quickSort(array, indiceChave + 1, alto, numTrocas, numComparacoes); // DIREITA DA CHAVE
    }
}


int main(){
    char *array[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi", "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int n = sizeof(array) / sizeof(array[0]); // tamanho do vetor
    int comparacoes = 0, trocas = 0;

    // ORDENANDO O VETOR USANDO QUICKSORT
    quickSort(array, 0, n - 1, &trocas, &comparacoes); // de 0 até o ultimo elemento 

    // Exibindo o vetor ordenado
    printf("Vetor ordenado: \n");
    for (int i = 0; i < n; i++){
        printf("%s - ", array[i]);
    }

    // Gerando um arquivo de saída
    FILE *arquivoSaida = fopen("saidaQuickSort.txt", "w");
        if (arquivoSaida == NULL) {
            printf("Erro ao criar o arquivo de saida.");
            return 1;
        }
        
        for (int i = 0; i < n; i++){
            fprintf(arquivoSaida, "%s\n", array[i]);
        }

        fclose(arquivoSaida);

        //CALCULANDO MEDIANA
        char *mediana = array[n / 2];
        printf("\n\nMediana: %s\n", mediana);

        printf("\nNumero de comparacoes feitas: %d\n", comparacoes);
        printf("\nNumero de trocas feitas: %d\n", trocas);

        return 0;
    

}
