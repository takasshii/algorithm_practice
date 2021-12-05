//グラフの受け取り

#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; //グラフ型

int main() {
  int N, M;
  cin >> N >> M;

  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a,b;
    cin >> a >> b;
    //有向グラフ
    G[a].push_back(b);

    //無向グラフならさらに
    // G[b].push_back(a);
  }
}
