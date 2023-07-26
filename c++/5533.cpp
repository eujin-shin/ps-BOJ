#include <iostream>
#include <vector>
using namespace std;

vector <int> v[3][101];

int main() {
  int s[200]={0, }, n, tmp;
  cin>>n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<3; j++) {
      cin>>tmp;
      s[i]+=tmp;
      v[j][tmp].push_back(i);
    }
  }
  for(int i=0; i<3; i++) {
    for(int j=1; j<=100; j++) {
      if(v[i][j].size()<2) continue;
      for(int h=0; h<v[i][j].size(); h++) {
        s[v[i][j][h]]-=j;
      }
    }
  }
  for(int i=0; i<n; i++) cout<<s[i]<<'\n';
  return 0;
}