#include <iostream>
using namespace std;

// 이차원 배열로 각 노드의 자식 노드 개수, 부모 노드 정보, 자식 노드 정보를 저장
// 입력 과정에서 자식 노드 개수가 0인 노드를 파악하여 리프 노드 개수 산출
// 삭제할 노드 번호를 입력 받고 깊이 우선 탐색 방식으로 해당 노드를 루트로 하는 트리의 리프 노드 개수 파악
// 기존 리프 노드 - 삭제할 리프 노드
// 노드를 삭제한 뒤 그 노드의 부모 노드가 리프 노드가 되는 경우를 반영

int tree[52][52] = {0, };

int DFS(int nod) {
  int k = 0;
  if(tree[nod][0]==0) {
    k = 1;
  } else {
    for(int i=1; i<=tree[nod][0]; i++) {
      k += DFS(tree[nod][i]);
    }
  }
  return k;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, parent, target, leaf, leaf_del;
  cin>>n; leaf = n;
  for(int i=1; i<=n; i++) {
    cin>>parent; parent++;
    tree[0][i] = parent;
    if (parent==0) continue;
    if(tree[parent][0]==0) leaf--;
    tree[parent][0] = tree[parent][0] + 1;
    tree[parent][tree[parent][0]] = i;
  }
  cin>>target; target++;
  leaf_del = DFS(target);
  leaf -= leaf_del;
  parent = tree[0][target];
  if(tree[parent][0]==1) {
    leaf++;
  }
  cout<<leaf<<'\n';
  return 0;
}