#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // stdbool.hヘッダーファイルをインクルード
#include <limits.h>
#include "common.h"

extern int w[N][N];
extern int d[N][N];
extern int p[N][N];

void floyd() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      d[i][j] = w[i][j];
      p[i][j] = i;
    }
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if ((d[i][k] == M) || (d[k][j] == M)) {
          continue;
        }
        int can = d[i][k] + d[k][j];
        if (can < d[i][j]) {
          d[i][j] = can;
          p[i][j] = p[k][j];
        }
      }
    }
  }
}

void display(char* name, int ary[N][N], int size) {
  printf("%s:\n", name);
  for (int i = 0; i < size; i++) {
    printf(" [");
    for (int j = 0; j < size; j++) {
      if (ary[i][j] == M) {
        printf(" M");
      } else {
        printf(" %d", ary[i][j]);
      }
    }
    printf(" ]\n");
  }
}

void print_path(int m, int n) {
  if (n != m) {
    print_path(m, p[m][n]);
    printf(" -> ");
  }
  printf("%d", n);
}

void shortest_path(int m, int n) {
  if (d[m][n] == M) {
    printf("No path");
  } else {
    print_path(m, n);
  }
}