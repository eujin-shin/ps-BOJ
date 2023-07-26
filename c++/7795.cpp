#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> a;
vector <int> b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, m, tmp, count, idx;
  cin>>t;
  while(t--) {
    count=0;
    a=vector <int>();
    b=vector <int>();
    cin>>n>>m;
    for(int i=0; i<n; i++) {
      cin>>tmp; a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    for(int i=0; i<m; i++) {
      cin>>tmp; b.push_back(tmp);
    }
    sort(b.begin(), b.end());
    idx=-1;
    for(int i=0; i<a.size(); i++) {
      while(idx+1<b.size() && a[i]>b[idx+1]) idx++;
      count+=idx+1;
    }
    cout<<count<<'\n';
  }
  return 0;
}