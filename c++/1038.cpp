#include <iostream>
using namespace std;

int n, c=0;
int num[10]={0, };
bool flag=false;

void Btrack(int r, int k, int x) {
  if(k==r) {
    c++;
    if(n!=c) return;
    flag=true;
    for(int i=0; i<k; i++) {
      cout<<num[i];
    }
    cout<<'\n';
    return;
  }
  for(int i=r-k-1; i<x; i++) {
    if(i==0 && k==0) continue;
    num[k]=i;
    Btrack(r, k+1, i);
    if(flag) break;
  }
  return;
}

int main() {
  cin>>n;
  if(n==0) {
    cout<<"0\n";
    return 0;
  }
  for(int i=1; i<=10; i++) {
    Btrack(i, 0, 10);
    if(flag) break;
  }
  if(!flag) cout<<"-1\n";
  return 0;
}