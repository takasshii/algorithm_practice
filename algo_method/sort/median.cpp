//中央値を求める
//sortを用いることがポイント

#include <bits/stdc++.h>

using namespace std;


int main()
{
  int N;
  cin >> N;
  vector<double> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];

  //sort
  sort(A.begin(), A.end());

  double result;
  //奇数偶数で場合分け
  if(N%2 == 0) {
    result = (A[N / 2] + A[(N / 2) - 1])/2;
  } else {
    result = A[(N - 1) / 2];
  }
  
  // 浮動小数出力に対応する (小数点以下 2 桁まで出す)
  cout << fixed << setprecision(2);
  cout << result << endl;

  return 0;
}