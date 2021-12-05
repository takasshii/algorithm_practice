//キューの実装
//リンクバッファ（環状）での実装

#include <bits/stdc++.h>
using namespace std;
//スタックの最大サイズ
const int MAX = 100000;

int qu[MAX]; //キューを表す配列
int head = 0, tail = 0; //始め、終わりを表す

// 初期化
void init()
{
  head = tail = 0;
}

bool isEmpty()
{
  //スタックサイズが0かどうか
  return (head == tail);
}

bool isFull()
{
  return (head == (tail+1)%MAX); //head == (MAX+1)%MAX → 円なので
}

// enqueue
void enqueue(int x)
{
  if (isFull())
  {
    cout << "error: stack is full." << endl;
    return;
  }
  qu[tail] = x; //終端に代入
  ++tail; //tailを進める
  if(tail == MAX) {
    tail = 0;
  } // リンクバッファなので、端に来たら0に
}

// dequeue
int dequeue()
{
  if (isEmpty())
  {
    cout << "error: stack is empty." << endl;
    return -1;
  }
  int res = qu[head]; //
  ++head; //headを進める
  if(head == MAX) {
    head = 0; //リンクバッファの終端に来たら0に
  }
  return res; // topの位置にある要素を返す
}

int main()
{
  //初期化
  init();

  enqueue(3); //{} -> {3}
  enqueue(5); //{3} -> {3, 5}
  enqueue(7); //{3, 5} -> {3, 5, 7}

  cout << dequeue() << endl; //{3, 5, 7} -> {3, 5}で7が出力
  cout << dequeue() << endl; //{3, 5} -> {3}で5が出力

  enqueue(9); //{3} -> {3, 9}
}