//連結リストの練習

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

struct Node {
  Node* next; //次のノードのポインタ
  string name;

  //メンバ初期化子リスト
  Node(string name_ = "") : next(NULL), name(name_) {}
}; //ここ;必要

//番兵を表すノード
Node *nil;

//初期化
void init() {
  nil = new Node();
  nil->next = nil;
}

//連結リストを出力
void printList() {
  //先頭から出発
  Node *cur = nil->next;
  //最後のnilまでcurのポインタを進んでいく
  for (; cur != nil; cur = cur->next) {
    cout << cur->name << "->";
  }
  cout << endl;
}

//Node pの直後に Node vを挿入する
void insert(Node *v, Node *p = nil) {
  v->next = p->next;
  p->next = v;
}

int main() {
  //初期化
  init();
  //ノードの名前の一覧
  vector<string> names = {"yamamoto", "wtanabe", "ito", "takahashi", "suzuki", "sato"};
  //ノードを生成して一つずつ挿入
  for (int i = 0; i < (int)names.size();i++) {
    //ノードを作成
    Node *node = new Node(names[i]);
    //ノードを連結リストの先頭に挿入
    insert(node);
    //一つ挿入されたら出力
    cout << "step" << i << ":";
    printList();
  }
}