#include <iostream>
#include <string>
using namespace std;

void print(int d, int x, int s) {
  if(x>0 && d==1) cout<<"|";
  else cout<<' ';
  for(int i=0; i<s; i++) if(d==0) cout<<"-"; else cout<<" ";
  if(x<2 && d==1) cout<<"|";
  else cout<<' ';
  return;
}

int main() {
  string x;
  int s, n, k, arr[10]={0, };
  cin>>s>>x; n=x.length();
  for(int i=0; i<n; i++) arr[i]=x[i]-'0';
  for(int i=0; i<n; i++) {
    if(i>0) cout<<' ';
    k=arr[i];
    if(k==1 || k==4) print(-1, 0, s);
    else print(0, 0, s);
  }
  for(int i=0; i<s; i++) {
    cout<<'\n';
    for(int j=0; j<n; j++) {
      if(j>0) cout<<' ';
      k=arr[j];
      if(k==0 || k==4 || k>7) print(1, 1, s);
      else if(k<4 || k==7) print(1, 0, s);
      else print(1, 2, s);
    }
  }
  cout<<'\n';
  for(int i=0; i<n; i++) {
    if(i>0) cout<<' ';
    k=arr[i];
    if(k==1 || k==7 || k==0) print(-1, 0, s);
    else print(0, 0, s);
  }
  for(int i=0; i<s; i++) {
    cout<<'\n';
    for(int j=0; j<n; j++) {
      if(j>0) cout<<' ';
      k=arr[j];
      if(k==6 || k==8 || k==0) print(1, 1, s);
      else if(k==2) print(1, 2, s);
      else print(1, 0, s);
    }
  }
  cout<<'\n';
  for(int i=0; i<n; i++) {
    if(i>0) cout<<' ';
    k=arr[i];
    if(k==1 || k==4 || k==7) print(-1, 0, s);
    else print(0, 0, s);
  }
  cout<<'\n';
  return 0;
}