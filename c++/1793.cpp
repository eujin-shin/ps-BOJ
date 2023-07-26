#include <iostream>
#include <vector>
using namespace std;

vector <int> v[251];

void Sum(int a, int b, int x) {
  int i=0, c=0, s;
  bool flag=false;
  while(1) {
    s=c;
    if(v[a].size()>i) s+=v[a][i]*2;
    if(v[b].size()>i) s+=v[b][i];
    c=s/10; s%=10;
    if(c==0 && v[a].size()<=i && v[b].size()<=i) {
      if(s!=0) v[x].push_back(s);
      break;
    }
    v[x].push_back(s);
    i++;
  }
}

void Print(int x) {
  for(int i=1; i<=v[x].size(); i++) {
    cout<<v[x][v[x].size()-i];
  }
  cout<<'\n';
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, sol=1;
  v[0].push_back(1); v[1].push_back(1);
  while(cin>>n) {
    for(int i=sol+1; i<=n; i++) Sum(i-2, i-1, i);
    Print(n);
    if(sol<n) sol=n;
  }
  return 0;
}