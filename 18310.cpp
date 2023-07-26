#include <iostream>
#define ll long long
using namespace std;

int arr[100001]={0, };
ll len[100001]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, k, m=0, a=0, b=0;
  ll l=0, r=0, min=-1, ans;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>k; arr[k]++;
    if(k>m) m=k;
  }
  for(int i=0; i<m-1; i++) {
    a+=arr[1+i]; l+=a;
    if(arr[2+i]>0) len[2+i]+=l;
    b+=arr[m-i]; r+=b;
    if(arr[m-i-1]>0) len[m-i-1]+=r;
  }
  for(int i=1; i<=m; i++) {
    if(len[i]==0 && arr[i]==0) continue;
    if(len[i]<min || min<0) {
      min=len[i]; ans=i;
    }
  }
  cout<<ans<<'\n';
  return 0;
}