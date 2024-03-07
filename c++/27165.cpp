#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

int main() {
  int n, cnt=0, x, a, s=-1, tmp;
  cin>>n;
  for(int i=0; i<=n; i++) {
    cin>>a; v.push_back(a);
    if(a==1) cnt++;
  }
  cin>>x;
  if(cnt>2) {
    cout<<"NO\n"; return 0;
  }
  for(int i=0; i<=n-x; i++) {
    if(v[i]==0 || v[i]==2) continue;
    tmp=0;
    if(v[i]==1) tmp++;
    if(v[i+x]==1) tmp++;
    if(v[i+x]==0) tmp--;
    if(tmp==cnt) {
      s=i; break;
    }
  }
  if(s<0) {
    cout<<"NO\n";
  } else {
    cout<<"YES\n";
    cout<<s<<' '<<s+x<<'\n';
  }
  return 0;
}