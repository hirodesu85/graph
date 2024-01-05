#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "common.h"

int w[N][N] = {
  { 0, M,  M, 8, 15, M},
  {10, 0, 24, M,  8, M},
  { M, M,  0, M,  M, 6},
  { M, M,  M, 0,  5, M},
  { M, M, 12, M,  0, 7},
  { M, M,  3, M,  M, 0}};

// サイズが同じで異なるグラフ
// int w[N][N] = {
//   { 0, 80,  M, 30,  M,  M},
//   { M,  0, 30,  M,  M,  M},
//   { M,  M,  0,  M,  M, 20},
//   { M, 50,  M,  0, 10,  M},
//   { M, 20, 40,  M,  0, 15},
//   { M, 25,  M,  M,  M,  0}};

int d[N][N];
int p[N][N];

void floyd();
void display(char *, int[N][N], int);
void print_path(int, int);
void shortest_path(int, int);

int main(int argc, char *argv[]) {
  floyd();
  display("Result", d, N);

  // 最短路の表示
  for (int i = 0; i < N; i++) {
    printf("Shortest path from %d:\n", i);
    for (int j = 0; j < N; j++) {
      if (i == j) {
        continue;
      } else {
        shortest_path(i, j);
        printf("(from %d to %d)\n", i, j);
      }
    }
    printf("\n");
  }
}