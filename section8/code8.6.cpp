//双方向連結リストの練習

/*メンバ初期化リストについて
  struct 構造体名 {
    型1 メンバ変数1;
    型2 メンバ変数2;
    ...(必要な分だけ書く)

    構造体名() : メンバ変数名1(初期化内容), メンバ変数名2(初期化内容), ...(必要な分だけ書く)
    {
    }
  };
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  Node *prev, *next; //次のノードのポインタ
  string name;

  //メンバ初期化子リスト
  Node(string name_ = "") : prev(NULL), next(NULL), name(name_) {}
}; //ここ;必要

//番兵を表すノード
Node *nil;

//初期化
void init()
{
  nil = new Node();
  nil->prev = nil;
  nil->next = nil;
}

//連結リストを出力
void printList()
{
  //先頭から出発
  Node *cur = nil->next;
  //最後のnilまでcurのポインタを進んでいく
  for (; cur != nil; cur = cur->next)
  {
    cout << cur->name << "->";
  }
  cout << endl;
}

// Node pの直後に Node vを挿入する
void insert(Node *v, Node *p = nil)
{
  v->next = p->next;
  // pの次だったものの前はv
  p->next->prev = v;
  // pの次はv
  p->next = v;
  // vの前はp
  v->prev = p;
}

// vを削除
void erase(Node *v)
{
  // vが番兵だったら何もしない
  if (v == nil)
    return;
  // vの前だったものは次に、vの次だったものを指す
  v->prev->next = v->next;
  // vの次だったものは前に、vの前だったものを指す
  v->next->prev = v->prev;
}

int main()
{
  //初期化
  init();
  //ノードの名前の一覧
  vector<string> names = {"yamamoto", "watanabe", "ito", "takahashi", "suzuki", "sato"};
  //リスト作成
  Node *watanabe;
  //ノードを生成して一つずつ挿入
  for (int i = 0; i < (int)names.size(); i++)
  {
    //ノードを作成
    Node *node = new Node(names[i]);
    //ノードを連結リストの先頭に挿入
    insert(node);
    //渡辺ノードの保持
    if (names[i] == "watanabe")
    {
      watanabe = node;
    }
  }

  cout << "before:";
  printList();
  erase(watanabe);
  cout << "after:";
  printList();
}