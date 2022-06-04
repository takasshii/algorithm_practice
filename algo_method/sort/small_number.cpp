// Xk番目に小さい数を求める
// sortを用いることがポイント

#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  vector<int> X(M);
  for (int i = 0; i < N; i++)
    cin >> A[i];

  for (int i = 0; i < M; i++)
    cin >> X[i];

  // sort
  sort(A.begin(), A.end());

  // 配列を一つずつ代入
  for (auto x: X)
    cout << A[x] << endl;

    return 0;
}