#include <iostream>
#define ll long long
using namespace std;

int Cmp(const void *a, const void *b) {
  return (int)(*(ll *)a-*(ll *)b);
}

ll arr[10000]={0, };
ll ans=0;

int Check(int n, int k, ll x) {
  ll count=0;
  for(int i=0; i<k; i++) {
    count+=(arr[i]/x);
    if(count>=n) return 1;
  }
  return 0;
}

void Solve(ll l, ll r, int n, int k) {
  ll mid;
  while(l<=r) {
    mid=(l+r)/2;
    if(Check(n, k, mid)==1) {
      if(ans<mid) ans=mid; 
      l=mid+1;
    } else {
      r=mid-1;
    }
  }
  return;
}

int main() {
  int n, k;
  cin>>k>>n;
  for(int i=0; i<k; i++) cin>>arr[i];
  qsort(arr, k, sizeof(ll), Cmp);
  Solve(1, arr[k-1], n, k);
  cout<<ans<<'\n';
  return 0;
}