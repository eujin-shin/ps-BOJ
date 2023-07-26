#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector <int> v;
int q[8001]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double sum=0;
  int n, tmp, min=4000, max=-4000;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>tmp;
    v.push_back(tmp); sum+=tmp;
    q[tmp+4000]++;
    if(min>tmp) min=tmp;
    if(max<tmp) max=tmp;
  }
  double avr;
  int mode, mid, range;
  bool flag=true;
  avr=floor(sum/(double)n+0.5);
  sort(v.begin(), v.end());
  mid=v[n/2];
  tmp=0;
  for(int i=min+4000; i<=max+4000; i++) {
    if(q[i]==0 || q[i]<tmp) continue;
    if(q[i]==tmp && flag) {
      mode=i-4000; flag=false;
    } else if(q[i]>tmp) {
      tmp=q[i]; mode=i-4000; flag=true;
    }
  }
  range=max-min;
  cout<<avr<<'\n'<<mid<<'\n'<<mode<<'\n'<<range<<'\n';
  return 0;
}