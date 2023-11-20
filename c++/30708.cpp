#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> even, odd, v;

bool Solve(int d) {
  v=vector<int>();
  int a=0, b=0, p;
  bool flag=true;
  while(a<even.size() || b<odd.size()) {
    if(d>0) {
      if(a>0 && (even[a]!=p+1 && even[a]!=p-1)) {
        return false;
      }
      v.push_back(even[a]); p=even[a++];
    } else {
      if(b>0 && (odd[b]!=p+1 && odd[b]!=p-1)) {
        return false;
      }
      v.push_back(odd[b]); p=odd[b++];
    }
    d=-d;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, t;
  bool flag=true;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x;
    if(x%2) odd.push_back(x);
    else even.push_back(x);
  }
  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());
  t=even.size()-odd.size();
  if(t==0) {
    flag=Solve(1);
    if(!flag) flag=Solve(-1);
  } else if(t>1 || t<-1) flag=false;
  else flag=Solve(t);
  if(flag) {
    for(int i=0; i<v.size(); i++) {
      if(i>0) cout<<' ';
      cout<<v[i];
    }
    cout<<'\n';
  } else {
    cout<<"-1\n";
  }
  return 0;
}