// 差の最小値
// sortを用いることがポイント

#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  //long longで受け取る　10^9がintのmax
  vector<long long> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];

  // sort
  sort(A.begin(), A.end());

  // 差の最小値 ここが負だとあかんので適当に最大値
  long long temp = 1LL << 60;
  for (int i = 0; i < N - K + 1; i++)
    temp = min(temp, (A[i + K - 1] - A[i]));

  cout << temp << endl;
  return 0;
}