#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <int> v[51];
int map[51][51]={0, };
int num[51]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  string s;
  int n, cur, max=0;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>s;
    for(int j=1; j<=n; j++) {
      if(s[j-1]=='N') continue;
      v[i].push_back(j);
      map[i][j]=1; num[i]+=1;
    }
  }
  for(int i=1; i<=n; i++) {
    for(int j=0; j<v[i].size(); j++) {
      cur=v[i][j];
      for(int h=0; h<v[cur].size(); h++) {
        if(v[cur][h]==i || map[i][v[cur][h]]==1) continue;
        map[i][v[cur][h]]=1; num[i]+=1;
      }
    }
  }
  for(int i=1; i<=n; i++) {
    if(num[i]>max) max=num[i];
  }
  cout<<max<<'\n';
  return 0;
}