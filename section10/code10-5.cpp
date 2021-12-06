//ヒープの実装
/*
  〜二分木が持つキーについて〜
  親、弟、兄の三つのポインタを持つ
  ポインタをそれぞれswapすることで、swapが可能になる
  〜ヒープについて〜
  ヒープは強平衡ニ分木(バランスの取れた二分木)
  子の添字は2k+1,2k+2であり、親の添字は[k-1/2](小数点切り捨て)で求められる
  >挿入
  一番後ろに付け加える→親と比較してswapを繰り返す
  >最大値の削除
  根を削除→末尾を根に持ってくる→子の大きい方とswapを繰り返す
  交換しているキーが葉まで到達したら処理が終了する
*/

/*
  配列について
  vec.empty() → 空かを判断
  vec.back()　→ 最後のデータを返す
  vec.size()　→ 配列の大きさ
  vec.push_back()　→ 最後に追加
  vec.pop_back()　→ 最後を削除
  sort(vec.begin(), vec.end())　→ 小さい順にソート
  reverse(vec.begin(), vec.end())　→ 逆順に
*/

#include <bits/stdc++.h>
using namespace std;

struct Heap {
  vector<int> heap;
  Heap(){} //初期値は定義なし

  //挿入
  void push(int x) {
    heap.push_back(x);//最後に挿入
    int i = (int)heap.size() - 1; ///挿入された頂点番号
    while(i>0) {
      int p = (i - 1) / 2; //親の頂点番号(親の添字は[k-1/2]で切り捨て)
      if(heap[p] >= x) { //逆転が無ければ終了
        break;
      }
      heap[i] = heap[p]; //自分の値を親の値に
      i = p; //自分は上に行く
    }
    heap[i] = x; //最終的なxの位置
  }

  //最大値を求める
  int top() {
    if(!heap.empty()) {
      return heap[0];
    } else {
      return 0;
    }
  }

  //最大値を削除
  void pop() {
    if(heap.empty()) {
      return;
    }
    int x = heap.back();//最後の要素を返す（頂点に持っていく）
    heap.pop_back();
    int i = 0;
    //一番下にくるまで
    while(i*2+1 < (int)heap.size()) {
      int child1 = i*2+1, child2 = i * 2 + 2;
      //子同士を比較して、大きい方をchild1にする
      if(child2 < (int)heap.size() && heap[child2] > heap[child1]) {
        child1 = child2;
      }
      //逆転が無ければ終了
      if(heap[child1] <= x) {
        break;
      }
      heap[i] = heap[child1]; //自分の値を子頂点の値にする
      i = child1; //自分は下に行く
    }
    //最終的なxの位置
    heap[i] = x;
  }
};

int main() {
  Heap h;
  h.push(5);
  h.push(3);
  h.push(7);
  h.push(1);

  cout << h.top() << endl; // 7
  h.pop(); //最大値を削除
  cout << h.top() << endl; // 5

  h.push(11);
  cout << h.top() << endl; //11
}
