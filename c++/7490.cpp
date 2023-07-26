#include <iostream>
using namespace std;

char arr[10];

void Print(int n) {
  cout<<'1';
  for(int i=2; i<=n; i++) {
    cout<<arr[i]<<i;
  }
  cout<<'\n';
  return;
}

void Btrack(int n, int r, int s, int c, int f) {
  int tmp=s;
  if(n==r) {
    s+=f*c;
    if(s==0) Print(n);
    return;
  }
  r+=1;
  arr[r]=' ';
  Btrack(n, r, s, c*10+r, f);
  arr[r]='+';
  Btrack(n, r, s+f*c, r, 1);
  arr[r]='-';
  Btrack(n, r, s+f*c, r, -1);
  return;
}

int main() {
  int t, n;
  cin>>t;
  for(int i=0; i<t; i++) {
    cin>>n;
    Btrack(n, 1, 0, 1, 1);
    if(i+1<t) cout<<'\n';
  }
  return 0;
}