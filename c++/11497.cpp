#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int t, n, l, a, b, max;
  cin>>t;
  while(t--) {
    cin>>n; max=0;
    vector <int> v;
    for(int i=0; i<n; i++) {
      cin>>l; v.push_back(l);
    }
    sort(v.begin(), v.end());
    a=b=v[0];
    for(int i=1; i<v.size(); i+=2) {
      if(v[i]-a>max) max=v[i]-a;
      a=v[i];
      if(i+1<v.size()) {
        if(v[i+1]-b>max) max=v[i+1]-b;
        b=v[i+1];
      } else {
        if(a-b>max) max=a-b;
        b=a;
      }
    }
    if(b-a>max) max=b-a;
    cout<<max<<'\n';
  }
  return 0;
}