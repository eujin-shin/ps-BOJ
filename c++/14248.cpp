#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

int Cnt(int x) {
  if(x<0 || x>=v.size() || v[x]==0) return 0;
  int a=v[x];
  v[x]=0;
  return 1 + Cnt(x-a) + Cnt(x+a);
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, a, s;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>a; v.push_back(a);
  }
  cin>>s; s--;
  cout<<Cnt(s)<<'\n';
  return 0;
}