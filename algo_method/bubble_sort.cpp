#include <bits/stdc++.h>

using namespace std;
// 配列の中身を表示する関数
void output(vector<int> A)
{
  for (int i = 0; i < A.size(); i++)
  {
    cout << A[i];
    if (i != A.size() - 1)
      cout << " ";
    else
      cout << endl;
  }
}

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];

  for (int lp = 0; lp < N; lp++)
  {
    // 交換があったかを管理するフラグ
    bool flag = false;
    for (int i = 0; i < N - 1; i++)
    {
      if (A[i] > A[i + 1])
      {
        flag = true;
        swap(A[i], A[i + 1]);
      }
    }

    // 交換があった場合配列の中身を出力する
    if (flag)
      output(A);
    else
      break;
  }

  return 0;
}