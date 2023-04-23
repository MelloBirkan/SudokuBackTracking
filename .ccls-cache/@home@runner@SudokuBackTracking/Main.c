#include <stdio.h>
#include <stdlib.h>

#define N 4

// Função para imprimir a matriz do Sudoku
void Print_Matriz(int sudoku[N][N]) {
    int i, j;

    printf("---------\n");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%d ", sudoku[i][j]);
            if((j + 1) % 4  == 0){
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 4 == 0){
            printf("---------\n");
        }
    }
}

// Função para verificar se um número pode ser colocado em uma posição específica
int Valida_Posicao(int num, int sudoku[N][N], int linha, int coluna) {
    int i, j, linha_inicio, coluna_inicio;

    // verifica se o valor já existe na linha ou na coluna
    for(i = 0; i < N; i++){
        if(sudoku[linha][i] == num){
            return 0;
        }
        if(sudoku[i][coluna] == num){
            return 0;
        }
    }

    // verifica se o valor já existe no quadrante 2x2
    linha_inicio = (linha / 2) * 2;
    coluna_inicio = (coluna / 2) * 2;
    for(i = linha_inicio; i < linha_inicio + 2; i++){
        for(j = coluna_inicio; j < coluna_inicio + 2; j++){
            if(sudoku[i][j] == num){
                return 0;
            }
        }
    }
    
    return 1;
}

// Função recursiva para resolver o Sudoku
int Sudoku(int sudoku[N][N], int linha, int coluna){
    // verifica se chegou ao final do sudoku
    if(linha == N){
        return 1;
    }
    // verifica se deve mudar de linha
    if(coluna == N){
        return Sudoku(sudoku, linha + 1, 0);
    }
    // verifica se a posição já está preenchida
    if(sudoku[linha][coluna] != 0){
        return Sudoku(sudoku, linha, coluna + 1);
    }
    // tenta preencher a posição com um valor entre 1 e 4
    for(int num = 1; num <= N; num++){
        if(Valida_Posicao(num, sudoku, linha, coluna)){
            sudoku[linha][coluna] = num;
            if(Sudoku(sudoku, linha, coluna + 1)) return 1;
            sudoku[linha][coluna] = 0;
        }
    }

    return 0;
}

int main() {
    int Matriz_Sudoku[N][N] = {
        {0, 2, 4, 0},
        {1, 0, 0, 3},
        {4, 0, 0, 2},
        {0, 1, 3, 0}
    };

    printf("Sudoku inicial:\n");
    Print_Matriz(Matriz_Sudoku);

    printf("\n\nSudoku final:\n");
    if (Sudoku(Matriz_Sudoku, 0, 0)) {
        Print_Matriz(Matriz_Sudoku);
    } else {
        printf("Não há solução para este Sudoku.\n");
    }

    return 0;
}
