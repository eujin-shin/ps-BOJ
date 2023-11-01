#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define snt pair<string, int>
using namespace std;

vector <snt> res;
vector <string> v[11];


int Comp(snt a, snt b) {
  int t=0;
  if(a.second<b.second) t=1;
  else if(a.second==b.second) {
    if(a.first.length()<b.first.length()) t=1;
    else if(a.first.length()==b.first.length()) {
      if(a.first>b.first) t=1;
    }
  }
  return t;
}

void Merge(int x, int mid, int y) {
  vector <snt> tmp;
  int l=x, r=mid, t;
  while(l<mid || r<=y) {
    if(r>y) t=l++;
    else if(l>=mid) t=r++;
    else t=((Comp(res[r], res[l])==1) ? (l++) : (r++));
    tmp.push_back(res[t]);
  }
  for(int i=0; i<tmp.size(); i++) res[x+i]=tmp[i];
}

void Sort(int l, int r) {
  if(l>=r) return;
  int mid=(l+r)/2;
  Sort(l, mid);
  Sort(mid+1, r);
  Merge(l, mid+1, r);
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  int n, m, start;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>s;
    if(s.size()<m) continue;
    v[s.size()].push_back(s); 
  }
  for(int i=m; i<11; i++) {
    sort(v[i].begin(), v[i].end());
    start=-1;
    for(int j=0; j<v[i].size(); j++) {
      if(j==0) {
        start=0;
      } else if(v[i][j]!=v[i][j-1]) {
        res.push_back(make_pair(v[i][start], j-start));
        start=j;
      }
    }
    if(start>=0) {
      res.push_back(make_pair(v[i][start], v[i].size()-start));
    }
  }
  Sort(0, res.size()-1);
  for(int i=0; i<res.size(); i++) cout<<res[i].first<<'\n';
  return 0;
}
