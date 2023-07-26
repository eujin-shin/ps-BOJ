#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue <int> q;
vector <int> v[11];

void Search(int l, int k) {
  if(l<k) Search(l+1, k);
  v[l].push_back(q.front()); q.pop();
  if(l<k) Search(l+1, k);
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int k, temp;
  cin>>k;
  for(int i=1, j=1; i<=k; i++, j*=2) {
    for(int h=0; h<j; h++) {
      cin>>temp; q.push(temp);
    }
  }
  Search(1, k);
  for(int i=1; i<=k; i++) {
    for(int j=0; j<v[i].size(); j++) {
      cout<<v[i][j];
      if(j==v[i].size()-1) cout<<'\n';
      else cout<<' ';
    }
  }
}