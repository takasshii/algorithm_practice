#include <bits/stdc++.h>
using namespace std;

//Union-Find
struct UnionFind
{
  vector<int> par, siz;

  //初期化
  UnionFind(int n): par(n,-1), siz(n,1) {}

  //値を求める
  int root(int x)
  {
    if(par[x] == -1) {
      return x; //根の場合は返す
    }
    else {
      return par[x] = root(par[x]); //経路圧縮
    }
  }
  //同じグループに属するか
  bool issame(int x, int y) {
    return root(x) == root(y);
  }
  //併合
  bool unite (int x, int y) {
    //それぞれの根を求める
    int rx = root(x);
    int ry = root(y);
    //同じグループの場合は何もしない
    if(rx == ry)
      return false;
    //union by rank
    if(siz[rx] < siz[ry]){
      //小さい方の根を大きい方の根とする
      swap(rx, ry);
    }
    //yをxの子にする
    par[ry] = rx;
    // sizを変更する
    siz[rx] += siz[ry];
    return true;
  }

  // xを含むグループのサイズを求める
  int size(int x)
  {
    return siz[root(x)];
  }
};

int main()
{
  int N, M;
  cin >> N >> M;

  //要素数NのUnion-Findを用意する
  UnionFind uf(N);

  //M回の併合クエリ
  for (int i = 0; i < M; i++) {
    //aとbの入力
    int a, b;
    cin >> a >> b;

    //aとbが同じグループか
    if(uf.issame(a,b)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    uf.unite(a, b);
  }
}