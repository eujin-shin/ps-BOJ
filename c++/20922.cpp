#include <iostream>
#include <vector>
using namespace std;

vector <int> v[100001];
int n, k, arr[100001]={0, };

int Update(int l, int x) {
  while(v[x][arr[x]]<l) arr[x]++;
  if(v[x].size()-arr[x]<=k) return l;
  arr[x]=v[x].size()-k;
  return v[x][arr[x]-1]+1;
}

int main() {
  ios_base::sync_with_stdio(false);
  int x, l=0, max=0;
  cin>>n>>k;
  for(int i=0; i<n; i++) {
    cin>>x; v[x].push_back(i);
    l=Update(l, x);
    max = ((max < i-l+1) ? (i-l+1) : (max));
  }
  cout<<max<<'\n';
  return 0;
}