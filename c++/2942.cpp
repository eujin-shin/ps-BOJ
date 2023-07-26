#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int GCS(int a, int b) {
  if(a<b) {
    int tmp=b; b=a; a=tmp;
  }
  if(a%b==0) return b;
  return GCS(b, a-b);
}

int main() {
  vector <int> v;
  int r, g, x;
  cin>>r>>g;
  x=GCS(r, g);
  for(int i=1; i<=sqrt(x); i++) {
    if(x%i!=0) continue; 
    v.push_back(i);
    if(i!=sqrt(x)) v.push_back(x/i);
  }
  sort(v.begin(), v.end());
  for(int i=0; i<v.size(); i++) {
    cout<<v[i]<<' '<<r/v[i]<<' '<<g/v[i]<<'\n';
  }
  return 0;
}