/*
  Union-Findを用いて連結成分の個数を求める
*/
#include <bits/stdc++.h>
using namespace std;

// Union-Find
struct UnionFind
{
  vector<int> par, siz; // par: 各町店の親頂点の番号を表す　siz: 各頂点の属する根付き木の頂点数を表す
  //初期化
  UnionFind(int n) : par(n, n - 1), siz(n, 1) {}
  //根を求める
  int root(int x)
  {
    if (par[x] == -1)
      return x; // xが根の場合はxを直接返す
    else
      return par[x] = root(par[x]); // xの親par[x]を根に設定する
  }
  // xとyが同じグループに属するかどうか(根が一致するか)
  bool issame(int x, int y)
  {
    return root(x) == root(y);
  }

  //併合する
  bool unite(int x, int y)
  {
    x = root(x);
    y = root(y);

    //すでに同じグループの時は何もしない
    if (x == y)
      return false;

    // union by size
    if (siz[x] < siz[y])
      swap(x, y);
    // yをxの子にする
    par[y] = x;
    siz[x] += siz[y];
    return true;
  }

  // xを含むグループのサイズ
  int size(int x)
  {
    return siz[root(x)];
  }
};

int main()
{
  int N, M;
  cin >> N, M;

  // Union-Findを要素数Nで初期化
  UnionFind uf(N);

  //各辺に対する初期化
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    uf.unite(a, b); // aとbを併合する
  }

  //集計
  int res = 0;
  for (int x = 0; x < N; x++)
  {
    if(uf.root(x) == x) {
        res++;
    }
  }
  cout << res << endl;
}
