#include <iostream>
#define MAX 500000
using namespace std;

int root[MAX] = {0, };

int find(int a);
bool unionTwo(int a, int b);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin>>n>>m;

  for(int i = 0; i < n; i++) {
    root[i] = i;
  }

  int a, b, findCycle = 0;
  for(int i = 1; i <= m; i++) {
    cin>>a>>b;
    findCycle = !unionTwo(a, b) && findCycle == 0 ? i : findCycle;
  }
  cout<<findCycle<<'\n';
  return 0;
}

int find(int a) {
  return root[a] == a ? a : root[a] = find(root[a]);
}

bool unionTwo(int a, int b) {
  int rootA = find(a);
  int rootB = find(b);
  root[rootA] = rootA > rootB ? rootB : rootA;
  root[rootB] = rootA > rootB ? rootB : rootA;
  return rootA != rootB;
}