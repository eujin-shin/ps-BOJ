#include <iostream>
using namespace std;

int main() {
  int a[1000], b[1000];
  int n, front=0, top=-1;
  bool flag=true;
  cin>>n;
  for(int i=0; i<n; i++) cin>>a[i];
  for(int i=1; i<=n; i++) {
    if(top>=0 && b[top]==i) {
      top--;
    } else {
      while(front<n && a[front]!=i) b[++top]=a[front++];
      if(a[front]==i) front++;
      else {
        flag=false; break;
      }
    }
  }
  if(flag) cout<<"Nice\n";
  else cout<<"Sad\n";
  return 0;
}