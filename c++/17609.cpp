#include <iostream>
#include <string>
using namespace std;

int Check(int flag, string s, int l, int r) {
  int len=s.length(), a=l, b=r, ret;
  while(a<b) {
    if(s[a]==s[b]) {
      a++; b--;
    } else {
      if(flag==0) {
        ret=Check(1, s, a+1, b);
        if(ret==2) ret=Check(1, s, a, b-1);
        return ret;
      }
      return 2;
    }
  }
  return flag;
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  string input;
  cin>>t;
  for(int i=0; i<t; i++) {
    cin>>input;
    cout<<Check(0, input, 0, input.length()-1)<<'\n';
  }
  return 0;
}