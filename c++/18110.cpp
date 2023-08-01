#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v;

int main() {
  ios_base::sync_with_stdio(false);
  double n, sum=0;
  int s, e, avg=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>s; v.push_back(s);
  }
  if(n>0) {
    e=round(n*0.15);
    sort(v.begin(), v.end());
    for(int i=e; i<n-e; i++) {
      sum+=v[i];
    }
    avg=round(sum/(n-e*2));
  }
  cout<<avg<<'\n';
  return 0;
}