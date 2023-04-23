
/*
#include <stdbool.h>
#include <stdio.h>

#define N 4

int grid[N][N] = {{0, 2, 4, 0}, {1, 0, 0, 3}, {4, 0, 0, 2}, {0, 1, 3, 0}};

bool verifica_possivel(int linha, int coluna, int num) {
  for (int i = 0; i < N; i++) {
    if (grid[linha][i] == num || grid[i][coluna] == num) {
      return false;
    }
  }

  int raiz = 2;
  int x = linha - linha % raiz;
  int y = coluna - coluna % raiz;

  for (int i = 0; i < raiz; i++) {
    for (int j = 0; j < raiz; j++) {
      if (grid[i + x][j + y] == num) {
        return false;
      }
    }
  }
  return true;
}

bool resolve_sudoku() {
  int linha = -1;
  int coluna = -1;
  bool vazio = true;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == 0) {
        linha = i;
        coluna = j;
        vazio = false;
        break;
      }
    }
    if (!vazio) {
      break;
    }
  }

  if (vazio) {
    return true;
  }

  for (int num = 1; num <= N; num++) {
    if (verifica_possivel(linha, coluna, num)) {
      grid[linha][coluna] = num;
      if (resolve_sudoku()) {
        return true;
      }
      grid[linha][coluna] = 0;
    }
  }
  return false;
}

void imprime_sudoku() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

int main() {
  if (resolve_sudoku()) {
    imprime_sudoku();
  } else {
    printf("Não há solução para este Sudoku.\n");
  }
  return 0;
}
*/