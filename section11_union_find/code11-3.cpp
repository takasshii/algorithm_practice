/*
  ~関数について~
  root(x)→根を返す
  issame(x,y)→根がそれぞれ等しいかを調べる
  union(x,y)→結合する要素の片一方の根に根を子として結びつける

  工夫について
  union by size
  経路圧縮

  union by size
  サイズが大きい方の根を頂点とする
  (小さい方を大きい方に結合する)

  経路圧縮
  調べたら根に直接繋ぎ直す

  int root(int x) {
    if (par[x] == -1) {
      return x; //xが根の場合はxを直接返す
    }
    else return par[x] = root(par[x]); //xの親par[x]を根に設定する
  }

  以上を踏まえて
*/

#include <bits/stdc++.h>
using namespace std;

//Union-Find
struct UnionFind {
  vector<int> par, siz; //par: 各町店の親頂点の番号を表す　siz: 各頂点の属する根付き木の頂点数を表す
  //初期化
  UnionFind(int n) : par(n,n-1), siz(n,1) {}
  //根を求める
  //ここ再帰関数
  int root(int x)
  {
    if (par[x] == -1) return x; // xが根の場合はxを直接返す
    else return par[x] = root(par[x]); // xの親par[x]を根に設定する
  }
  //xとyが同じグループに属するかどうか(根が一致するか)
  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  //併合する
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);

    //すでに同じグループの時は何もしない
    if(x == y) return false;

    //union by size
    if(siz[x] <siz[y])
      swap(x, y);
    //yをxの子にする
    par[y] = x;
    siz[x] += siz[y];
    return true;
  }

  //xを含むグループのサイズ
  int size(int x) {
    return siz[root(x)];
  }
};

int main() {
  UnionFind uf(7); //{0},{1},{2},{3},{4},{5},{6}
  uf.unite(1,2);   //{0},{1,2},{3},{4},{5},{6}
  uf.unite(2,3);   //{0},{1,2,3},{4},{5},{6}
  uf.unite(5,6);   //{0},{1,2,3},{4},{5,6}
  cout << uf.issame(1, 3) << endl; //true
  cout << uf.issame(2, 5) << endl; //false

  uf.unite(1, 6);                 //{0},{1,2,3,5,6},{4}
  cout << uf.issame(2,5) << endl; //false
}
