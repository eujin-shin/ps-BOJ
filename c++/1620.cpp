#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector <string> v;
vector <pair<string, int> > g;

int toInt(string s) {
  int x=0;
  for(int i=0; i<s.size(); i++) {
    x*=10;
    x+=s[i]-'0';
  }
  return x;
}

int findIdx(string s) {
  int l=0, r=v.size(), mid;
  while(l<=r) {
    mid=(l+r)/2;
    if(s.compare(g[mid].first)==0) break;
    else if(s>g[mid].first) l=mid+1;
    else r=mid-1;
  }
  return g[mid].second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  string s;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>s;
    v.push_back(s);
    g.push_back(make_pair(s, i+1));
  }
  sort(g.begin(), g.end());
  for(int i=0; i<m; i++) {
    cin>>s;
    if(s[0]>='0' && s[0]<='9') {
      cout<<v[toInt(s)-1]<<'\n';
    } else {
      cout<<findIdx(s)<<'\n';
    }
  }
  return 0;
}