// 部分和の最大化
// sortを用いることがポイント

#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];

  // sort
  sort(A.begin(), A.end());

  // 部分和の最大化
  int result = 0;
  for (int i = 0; i < K; i++)
    result += A[N - i - 1];

  cout << result << endl;
  return 0;
}