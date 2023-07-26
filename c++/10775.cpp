#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector <int> plane;
set <int> s;

int main() {
  ios_base::sync_with_stdio(false);
  int g, p, k, count=0, ans=-1;
  cin>>g>>p;
  for(int i=1; i<=g; i++) s.insert(i);
  set <int>::iterator it;
  for(int i=0; i<p; i++) {
    cin>>k;
    if(ans>=0) continue;
    it=s.upper_bound(k); 
    if(it==s.begin()) ans=i;
    else s.erase(--it);
  }
  if(ans<0) ans=p;
  cout<<ans<<'\n';
  return 0;
}