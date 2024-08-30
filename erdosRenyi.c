#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarGrafoErdosRenyi(int n, double p, int orientado, const char* nomeArquivo) {
    int i, j;
    int **grafo;
    FILE *arquivo;

    // Alocando memória para a matriz de adjacência
    grafo = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        grafo[i] = (int*)malloc(n * sizeof(int));
    }

    // Inicializando a matriz de adjacência
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            grafo[i][j] = 0;
        }
    }

    // Preenchendo a matriz de adjacência
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            double rand_val = (double)rand() / RAND_MAX;
            if (rand_val < p) {
                grafo[i][j] = 1;
                if (!orientado) {
                    grafo[j][i] = 1;
                }
            }
        }
    }

    // Abrindo o arquivo para escrita
    arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Escrevendo a matriz de adjacência no arquivo
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fprintf(arquivo, "%d ", grafo[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    // Fechando o arquivo
    fclose(arquivo);

    // Liberando a memória alocada
    for (i = 0; i < n; i++) {
        free(grafo[i]);
    }
    free(grafo);
}

int main() {
    int n;
    double p;
    int orientado;
    char nomeArquivo[100];

    // Inicializando o gerador de números aleatórios
    srand(time(NULL));

    // Entrada do usuário
    printf("Digite o número de nós: ");
    scanf("%d", &n);
    printf("Digite a probabilidade (p) para as arestas (entre 0 e 1): ");
    scanf("%lf", &p);
    printf("Digite 1 para grafo orientado ou 0 para não orientado: ");
    scanf("%d", &orientado);
    printf("Digite o nome do arquivo para salvar o grafo: ");
    scanf("%s", nomeArquivo);

    // Gerar e salvar o grafo
    gerarGrafoErdosRenyi(n, p, orientado, nomeArquivo);

    printf("Grafo gerado e salvo em %s\n", nomeArquivo);

    return 0;
}
