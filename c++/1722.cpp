#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int input[20]={0, }, used[20]={0, };
ll num[20]={0, };

void init(int n) {
  ll k=1;
  num[n-1]=1;
  for(ll i=2; i<=n; i++) {
    num[n-i]=k; k*=i;
  }
}

void GetK(int n) {
  ll k=1;
  for(int i=0; i<n; i++) {
    for(int j=0; j<input[i]-1; j++) {
      if(used[j]!=0) continue;
      k+=num[i];
    }
    used[input[i]-1]=1;
  }
  cout<<k<<'\n';
}

void GetN(ll k, int n) {
  int c;
  for(int i=0; i<n; i++) {
    c=0;
    for(int j=0; j<n; j++) {
      if(used[j]==1) continue;
      if(num[i]<k) k-=num[i];
      else {
        cout<<j+1; used[j]=1;
        break;
      }
    }
    if(i==n-1) cout<<'\n';
    else cout<<' ';
  }
}



int main() {
  ios_base::sync_with_stdio(false);
  int n, o;
  ll k;
  cin>>n>>o;
  init(n);
  if(o==1) {
    cin>>k; GetN(k, n);
  } else {
    for(int i=0; i<n; i++) {
      cin>>input[i];
    }
    GetK(n);
  }
  return 0;
}