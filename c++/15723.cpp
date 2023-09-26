#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <int> v[26];
int map[26][26]={0, };

void Search(int start, int cur) {
  int tmp;
  for(int i=0; i<v[cur].size(); i++) {
    tmp=v[cur][i];
    if(map[start][tmp]==0) {
      map[start][tmp]=1;
      Search(start, tmp);
    }
  }
  return;
}

int main() {
  string s;
  char x, y;
  int n, m, cur;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x>>s>>y;
    v[x-'a'].push_back(y-'a');
    map[x-'a'][y-'a']=1;
  }
  for(int i=0; i<26; i++) {
    for(int j=0; j<v[i].size(); j++) {
      Search(i, v[i][j]);
    }
  }
  cin>>m;
  for(int i=0; i<m; i++) {
    cin>>x>>s>>y;
    if(map[x-'a'][y-'a']==1) cout<<"T\n";
    else cout<<"F\n";
  }
  return 0;
}