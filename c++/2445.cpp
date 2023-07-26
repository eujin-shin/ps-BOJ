#include <iostream>
using namespace std;

void Print(int x, int a) {
  char out;
  if(a) out='*';
  else out=' ';
  for(int i=0; i<x; i++) cout<<out;
}

int main() {
  int n, i=1, f=1;
  cin>>n;
  for(int c=1; c<n*2; c++) {
    Print(i, 1); Print(n*2-i*2, 0); Print(i, 1);
    cout<<'\n';
    if(i==n) f=-1;
    i+=f;
  }
  return 0;
}