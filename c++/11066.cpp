#include <iostream>
#include <queue>
#include <vector>
#define M 10001
using namespace std;

int main() {
  int t, n, x, y, tmp, sum, idx, max;
  vector <int> v;
  cin>>t;
  while(t--) {
    sum=0;
    cin>>n;
    for(int i=0; i<n; i++) {
      cin>>tmp; v.push_back(tmp);
    }
    while(v.size()>1) {
      max=M; idx=-1;
      for(int i=1; i<v.size(); i++) {
        if(v[i]+v[i-1]<max) {
          idx=i; max=v[i]+v[i-1];
        }
      }
      v[idx-1]+=v[idx]; 
      cout<<v[idx-1]<<'\n';
      sum+=v[idx-1];
      v.erase(v.begin()+idx);
    }
    v.erase(v.begin());
    cout<<sum<<'\n';
  }
  return 0;
}