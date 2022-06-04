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
  {
    cin >> A[i];
  }
  for (int i = 0; i < N - 1; i++)
  {
    int temp = i;
    int flag = false;
    for (int j = i; j < N - 1; j++)
    {
      if (A[temp] > A[j + 1])
      {
        temp = j + 1;
        flag = true;
      }
    }

    if (flag)
    {
      swap(A[i], A[temp]);
    }
    output(A);
  }

  return 0;
}