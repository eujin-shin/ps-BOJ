#include <iostream>
using namespace std;

int arr[12]={0, };
int num[4]={0, };
int amin, amax, flag=1;

void btr(int r, int n, int x) {
  if(r==n) {
    if(flag>0) {
      amin=x; amax=x; flag=-1; return;
    } 
    if(amin>x) amin=x;
    if(amax<x) amax=x;
  } else {
    int cur=arr[r+1];
    if(num[0]>0) {
      num[0]-=1; btr(r+1, n, x+cur); num[0]+=1;
    }
    if(num[1]>0) {
      num[1]-=1; btr(r+1, n, x-cur); num[1]+=1;
    }
    if(num[2]>0) {
      num[2]-=1; btr(r+1, n, x*cur); num[2]+=1;
    }
    if(num[3]>0) {
      num[3]-=1; btr(r+1, n, x/cur); num[3]+=1;
    }
    return;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i];
  for(int i=0; i<4; i++) cin>>num[i];
  btr(1, n, arr[1]);
  cout<<amax<<'\n'<<amin<<'\n';
  return 0;
}