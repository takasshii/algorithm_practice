//スタックの実装

#include <bits/stdc++.h>
using namespace std;
//スタックの最大サイズ
const int MAX = 100000;

int st[MAX]; //スタックを表す配列
int top = 0;

// 初期化 
void init()
{
  top = 0; 
}

bool isEmpty() {
  //スタックサイズが0かどうか
  return(top == 0);
}

bool isFull() {
  return (top == MAX);
}

//push
void push(int x) {
  if(isFull()) {
    cout << "error: stack is full." << endl;
    return;
  }
  st[top] = x;// xを格納
  ++top;//topを進める
}

//pop
int pop() {
   if(isEmpty()) {
     cout << "error: stack is empty." << endl;
     return -1;
   }
   --top; //topをデクリメント
   return st[top]; //topの位置にある要素を返す
}

int main()
{
  //初期化
  init();

  push(3); //{} -> {3}
  push(5); //{3} -> {3, 5}
  push(7); //{3, 5} -> {3, 5, 7}

  cout << pop() << endl; //{3, 5, 7} -> {3, 5}で7が出力
  cout << pop() << endl; //{3, 5} -> {3}で5が出力

  push(9); //{3} -> {3, 9}
}