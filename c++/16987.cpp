#include <iostream>
using namespace std;

int n, m=0, s[8]={0, }, w[8]={0, };

void Break(int r, int c) {
  if(r==n) {
    if(c>m) m=c;
    return;
  }
  if(s[r]<=0 || c>n-2) {
    Break(r+1, c);
    return;
  }
  int a=s[r], b, tmp;
  for(int i=0; i<n; i++) {
    if(i==r || s[i]<=0) continue;
    tmp=c;
    b=s[i];
    s[r]-=w[i]; s[i]-=w[r];
    if(s[r]<=0) tmp++;
    if(s[i]<=0) tmp++;
    Break(r+1, tmp);
    s[r]=a; s[i]=b;
  }
  return;
}

int main() {
  cin>>n;
  for(int i=0; i<n; i++) cin>>s[i]>>w[i];
  Break(0, 0);
  cout<<m<<'\n';
  return 0;
}