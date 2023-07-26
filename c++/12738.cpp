#include <iostream>
#define M 1000000
using namespace std;

int arr[M]={0, };
int lis[M+1]={0, };

int LowerBound(int n, int k) {
  int l=1, r=n, c;
  while(l<r) {
    c=(l+r)/2;
    if(lis[c]>=k) r=c;
    else l=c+1;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, count=1, low;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  lis[1]=arr[0];
  for(int i=1; i<n; i++) {
    if(lis[count]<arr[i]) lis[++count]=arr[i];
    else if(lis[1]>=arr[i]) lis[1]=arr[i];
    else {
      low=LowerBound(count, arr[i]);
      if(lis[low]>arr[i]) lis[low]=arr[i];
    }
  }
  cout<<count<<'\n';
  return 0;
}