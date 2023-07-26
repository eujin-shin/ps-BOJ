#include <iostream>
#include <string>
using namespace std;

void Swap(int *a, int *b) {
  int temp=*a;
  *a=*b;
  *b=temp;
  return;
}

int main() {
  string s, t;
  int len1, len2, v, x, y;
  bool ans=true;
  cin>>s>>t;
  len1=s.length(); len2=t.length();
  x=0; y=len2-1; v=1;
  for(int i=len2; i>len1; i--) {
    if(t[y]=='B') {
      y-=v; v=-v; Swap(&x, &y);
    } else y-=v;
  }
  for(int i=0; i<len1; i++) {
    if(s[i]!=t[x+(v*i)]) {
      ans=false; break;
    }
  }
  if(ans) cout<<"1\n";
  else cout<<"0\n";
  return 0;
}