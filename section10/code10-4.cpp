//重み付きグラフ
//最短路問題で扱う

/*メンバ初期化リストについて
  struct 構造体名 {
    型1 メンバ変数1;
    型2 メンバ変数2;
    ...(必要な分だけ書く)

    構造体名() : メンバ変数名1(初期化内容), メンバ変数名2(初期化内容), ...(必要な分だけ書く)
    {
    }
  };
*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to; //隣接頂点番号
  long long w;
  Edge(int to, long long w) :to(to), w(w) {}
};

using Graph = vector<vector<Edge>>; //グラフ型

int main()
{
  int N, M;
  cin >> N >> M;

  Graph G(N);
  for (int i = 0; i < M; i++)
  {
    int a, b;
    long long w;
    cin >> a >> b >> w;
    //有向グラフ
    G[a].push_back(Edge(b,w));

    //無向グラフならさらに
    // G[b].push_back(Edge(a,w);
  }
}
