#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> mv;
vector <int> pv;
int x, y, cur;
bool flag=false;

int GetDis(int a, int b) {
  int r=a+b;
  if(r<0) return -r;
  return r;
}

void Update(int a, int b) {
  int r=GetDis(a, b);
  if(cur<r && flag) return;
  cur=r; x=a; y=b; flag=true;
  return;
}

int UpperBound(int k) {
  int l=0, r=pv.size()-1, mid, idx=r;
  while(l<=r) {
    mid=(l+r)/2;
    if(pv[mid]<k) {
      l=mid+1;
    } else {
      r=mid-1; idx=mid;
    }
  }
  return idx;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, tmp, a, b;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>tmp;
    if(tmp<0) mv.push_back(tmp);
    else pv.push_back(tmp);
  }
  sort(mv.begin(), mv.end()); 
  reverse(mv.begin(), mv.end());
  sort(pv.begin(), pv.end());
  if(mv.size()>1) Update(mv[0], mv[1]);
  if(pv.size()>1) Update(pv[0], pv[1]);
  for(int i=0; i<mv.size(); i++) {
    if(pv.size()==0) break;
    tmp=UpperBound(-mv[i]);
    Update(mv[i], pv[tmp]);
    if(tmp>0) Update(mv[i], pv[tmp-1]);
  }
  if(x>y) {
    tmp=y; y=x; x=tmp;
  }
  cout<<x<<' '<<y<<'\n';
  return 0;
}