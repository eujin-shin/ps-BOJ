#include <iostream>
#include <vector>
using namespace std;

vector <pair<int, int> > ans;
vector <int> cnt[101];

void Move(int s, int v, int e, int k) {
  if(k==1) {
    ans.push_back(make_pair(s, e));
  } else {
    Move(s, e, v, k-1);
    ans.push_back(make_pair(s, e));
    Move(v, s, e, k-1);
  }
  return;
}

void Dp(int k) {
  if(cnt[k].size()>0) return;
  int c=1, t;
  Dp(k-1);
  for(int i=0; i<cnt[k-1].size(); i++) {
    t=cnt[k-1][i]*2+c;
    c=t/10; t%=10; cnt[k].push_back(t);
  }
  if(c!=0) cnt[k].push_back(c);
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  if(n<21) {
    Move(1, 2, 3, n);
    cout<<ans.size()<<'\n';
    for(int i=0; i<ans.size(); i++) cout<<ans[i].first<<' '<<ans[i].second<<'\n';
  } else {
    cnt[1].push_back(1);
    Dp(n);
    for(int i=cnt[n].size()-1; i>-1; i--) cout<<cnt[n][i];
    cout<<'\n';
  }
  return 0;
}