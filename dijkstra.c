#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // stdbool.hヘッダーファイルをインクルード
#include <limits.h>
#include "common.h"

extern int w[N][N];
extern bool S[N];
extern int Scount;                      // 頂点集合Sの要素数
extern int d[N];

/**
 * 頂点集合 S に頂点 u を追加する．
 * @param u 追加する頂点
 * @param S 頂点集合
 * @return なし
 */
void add(int u, bool S[]) {
  S[u] = true;
  Scount++;
}

/**
 * 頂点集合のうち S に追加されていない頂点があるかどうか確認する．
 * @return S に追加されていない頂点が存在すれば true，それ以外は false
 */
static bool remain() {
  if (Scount < N)
    return true;
  else
    return false;
}

/**
 * p からの最短距離が確定していない頂点のうち，d[] が最小の頂点を
 * 返す．
 * @param なし
 * @return 未確定の d[] が最小の頂点
 */
int select_min() {
  int min_val = M;
  int min_idx = -1;
  for (int i = 0; i < N; i++) {
    if (!S[i] && d[i] < min_val) {
      min_val = d[i];
      min_idx = i;
    }
  } 
  return min_idx;
}

/**
 * 頂点 u から頂点 x に接続する辺が存在すれば true, それ以外は
 * false を返す.
 * @param u 頂点
 * @param x 頂点
 * @return 辺が存在すれば true, それ以外は false
 */
bool member(int u, int x) {
  if (w[u][x] != M)
    return true;
  else
    return false;
}

/**
 * ダイクストラ法で，頂点 p から各頂点への最短路の重みを計算する．
 * @param p 開始点
 * @return なし
 */
void dijkstra(int p) {
  add(p, S);

  for (int i = 0; i < N; i++) {
    d[i] = w[p][i];
    // (A)
  }

  while (remain()) {
    int u = select_min();
    if (u == -1)
      break;
    else
      add(u, S);

    for (int x = 0; x < N; x++) {
      if (member(u, x)) {
        int k = d[u] + w[u][x];
        // (B)
        if (d[x] == M)
          d[x] = k;
        else if (k < d[x])
          d[x] = k;
      }
    }
  }
}

/**
 * 配列の中身を標準出力に表示．結果出力およびデバッグ用．
 * @param name ラベル（変数名など）
 * @param ary 配列
 * @return なし
 */
void display(char* name, int* ary, int length) {
  printf("%s: [", name);
  for (int i = 0; i < length; i++) {
    if (ary[i] == M)
      printf(" M");
    else
      printf(" %d", ary[i]);
  }
  printf(" ]\n");
}
