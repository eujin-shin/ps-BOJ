#include <iostream>
#include <vector>
#define N 100000
#define L long long
using namespace std;

L arr[N]={0, };
L ans;

int Cmp(const void *a, const void *b) {
  return (int)(*(L *)a-*(L *)b);
}

int Check(L x, L n, L m) {
  L i=0, count=0;
  while(arr[i]<=x && i<n) {
    count+=x/arr[i]; i++;
    if(count>=m) return 1;
  }
  return 0;
}

void Solve(L a, L b, L n, L m) {
  L mid, left=a, right=b;
  int ret;
  while(left<=right) {
    mid=(left+right)/2;
    if(Check(mid, n, m)==1) {
      if(ans>mid) ans=mid;
      right=mid-1;
    } else {
      left=mid+1;
    }
  }
  return;
}


int main() {
  ios_base::sync_with_stdio(false);
  L n, m;
  cin>>n>>m;
  for(int i=0; i<n; i++) cin>>arr[i];
  qsort(arr, n, sizeof(L), Cmp);
  ans=m*arr[0];
  Solve(arr[0], ans, n, m);
  cout<<ans<<'\n';
  return 0;
}