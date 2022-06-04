//to_string()で文字列に変えれる
//size()で配列の大きさとれる

#include <iostream>
using namespace std;

int main() {
  // データを受け取る
  int L, R; 
  cin >> L >> R;

  // 配列の全探索
  int count = 0;
  for (int x=L; x<=R; ++x) {
    // x が回文数かを調べる
    string S = to_string(x);
    bool flag = true;
    int N = S.size();
    for (int i=0; i<N; ++i) {
      if (S[i] != S[(N-1)-i]) {
        flag = false;
      }
    }
    //  x が回文数ならば 1 を足す
    if (flag) count++;
  }

  // 答えを出力する
  cout << count << endl;
  return 0;
}