#include <iostream>
#include <string>
using namespace std;



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bool flag;
  int t, n, d, c;
  string in;
  cin>>t;
  while(t--) {
    cin>>in; d=0; n=in.size();
    flag=true;
    while(d<n) {
      if(in[d]=='0') {
        d++;
        if(d>=n || in[d]=='0') {
          flag=false; break;
        }
        d++;
      } else {
        d++;
        if(d>=n || in[d]=='1') {
          flag=false; break;
        }
        d++;
        if(d>=n || in[d]=='1') {
          flag=false; break;
        }
        d++;
        while(d<n && in[d]=='0') d++;
        if(d>=n) {
          flag=false; break;
        }
        d++; c=0;
        while(d<n && in[d]=='1') {
          d++; c++;
        } 
        if(d>=n) break;
        d++;
        if(d>=n) {
          flag=false; break;
        } else if(in[d]=='1') d++;
        else if(c>0) d-=2;
        else {
          flag=false; break;
        }
      }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}