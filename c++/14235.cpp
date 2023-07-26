#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

void BinSearch(int k, int l) {
  int r=v.size(), mid;
  while(l+1<r) {
    mid=(l+r)/2;
    if(v[mid]<k) r=mid;
    else l=mid;
  }
  v.insert(v.begin()+r, k);
  return;
}

int Print(int l) {
  if(v.empty() || v.size()==l) cout<<"-1\n";
  else {
    cout<<v[l]<<'\n';
    return l+1;
  }
  return l;
}

int main() {
  int n, a, x, l=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>a;
    if(a==0) l=Print(l);
    else {
      for(int i=0; i<a; i++) {
        cin>>x;
        BinSearch(x, l-1);
      }
    }
  }
  return 0;
}