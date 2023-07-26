#include <iostream>
#include <vector>
using namespace std;

vector <int> v, s;
int stat[3001]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, d, k, c, tmp, cur, max=0;
  cin>>n>>d>>k>>c;
  stat[c]=1; cur=1;
  for(int i=0; i<n+k-1; i++) {
    if(i<n) cin>>tmp;
    else tmp=s[i-n];
    v.push_back(tmp);
    if(s.size()<k-1) s.push_back(tmp);
    if(stat[tmp]==0) cur++;
    stat[tmp]++;
    if(v.size()<k) continue;
    else if(v.size()>k) {
      if(v[0]!=c) {
        stat[v[0]]--; 
        if(stat[v[0]]==0) cur--;
      }
      v.erase(v.begin());
    }
    if(cur>max) max=cur;
  }
  cout<<max<<'\n';
  return 0;
}