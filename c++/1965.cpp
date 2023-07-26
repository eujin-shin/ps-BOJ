#include <iostream>
using namespace std;

int lis[1001]={0, };
int box[1000]={0, };

int UpperBound(int count, int x) {
  int l=0, r=count, c; 
  while(l<r) {
    c=(l+r)/2;
    if(lis[c]>=x) r=c;
    else l=c+1;
  }
  return l;
}

int main() {
  int n, count=0, pos, x;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x;
    if(lis[count]<x){
      count++;
      lis[count]=x;
    } else {
      pos=UpperBound(count, x);
      lis[pos]=x;
    }
  }
  cout<<count<<'\n';
  return 0;
}