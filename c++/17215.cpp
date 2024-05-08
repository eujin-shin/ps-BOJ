#include <iostream>
#include <string>
using namespace std;

int arr[30]={0, };

int main() {
  string st;
  int ans=0, s=0, b=0, p, f=1, t=1;
  bool d, n;
  cin>>st;
  for(int i=0; i<st.length(); i++) {
    n=false;

    if(st[i]=='S') {
      if(f<10) {
        arr[i+1]++; arr[i+2]++;
      }
      s=10; n=true; 
    } else if(st[i]=='P') {
      if(f<10) {
        arr[i+1]++;
      }
      s=10-p; n=true;
    } else {
      if(st[i]=='-') s=0;
      else s=st[i]-'0';
      t++;
      if(t>2) n=true;
    } 
    p=s;
    ans+=s+s*arr[i];
    if(n) {
      f++; t=1;
    }
  }
  cout<<ans<<'\n';
}