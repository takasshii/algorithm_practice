// S.substr(l,r): 文字列Sのl文字目からl+r-1文字目までの部分文字列を返す関数

#include <iostream>
using namespace std;

int main()
{
  // データを受け取る
  string S, T;
  cin >> S;
  cin >> T;

  // S, T の長さを取得する
  int N = S.length();
  int M = T.length();

  // 線形探索 (0 から N-M まで)
  bool flag = false;
  for (int i = 0; i < N - M + 1; ++i)
  {
    if (S.substr(i, M) == T)
    {
      flag = true;
    }
  }

  // 答えを出力する
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}