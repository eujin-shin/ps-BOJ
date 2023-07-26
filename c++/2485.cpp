#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, min, c;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x; v.push_back(x);
  }
  min=v[1]-v[0];
  for(int i=2; i<n; i++) {
    if(v[i]-v[i-1]<min) min=v[i]-v[i-1];
  }
  for(int i=1; i<=min; i++) {
    if(min%i!=0) continue;
    x=min/i; c=0;
    for(int j=1; j<n; j++) {
      if((v[j]-v[j-1])%x!=0) {
        c=-1; break;
      }
      c+=(v[j]-v[j-1])/x-1;
    }
    if(c>0) break;
  }
  cout<<c<<'\n';
  return 0;
}