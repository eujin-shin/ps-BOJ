#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct NUM {
  int len, sum;
  string s;
} num;

int Cmp(const void *a, const void *b) {
  num x=*(num *)a, y=*(num *)b;
  int ret=x.len-y.len, sx=0, sy=0, tx, ty;
  if(ret!=0) return ret;
  for(int i=0; i<x.len; i++) {
    tx=x.s[i]-'0'; ty=y.s[i]-'0';
    if(tx>0 && tx<10) sx+=tx;
    if(ty>0 && ty<10) sy+=ty;
  }
  x.sum=sx; y.sum=sy;
  ret=sx-sy;
  if(ret!=0) return ret;
  for(int i=0; i<x.len; i++) {
    ret=x.s[i]-y.s[i];
    if(ret!=0) return ret;
  }
  return ret;
}

num arr[50];

int main() {
  ios_base::sync_with_stdio(false);
  string input;
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i].s;
    arr[i].len=arr[i].s.size();
  }
  sort(arr, arr+n, Cmp);
  for(int i=0; i<n; i++) cout<<arr[i].s<<'\n';
  return 0;
}