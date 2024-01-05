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

bool S[N];
int Scount = 0;                      // 頂点集合Sの要素数
int d[N];
int parent[N];                       // 最短路の親頂点を格納する配列

void add(int, bool[]);
bool remain();
int dijkstra(int);
void display(char *, int *, int);
void display_shortest_path(int *, int, int);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: ./main <node ID>\n");
    return 1;
  }

  int p = atoi(argv[1]);
  if (p < 0 || N <= p) {
    fprintf(stderr, "Node ID %d is out of range: [0, %d].\n", p, N);
    return 1;
  }

  for (int i = 0; i < N; i++)
    S[i] = false;


  dijkstra(p);              // ダイクストラ法による最短路の計算
  display("Result", d, N);  // 結果表示

  // 最短路の表示
  for (int i = 0; i < N; i++) {
    if (i == p) {
      continue;
    } else {
      display_shortest_path(parent, p, i);
      printf("(from %d to %d)\n", p, i);
    }
  }

  return 0;
}
