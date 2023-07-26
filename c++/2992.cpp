#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string in;
  int l=-1, r;
  char tmp;
  cin>>in;
  for(int i=in.size()-1; i>0; i--) {
    if(in[i-1]<in[i]) {
      l=i-1; break;
    }
  }
  if(l<0) {
    cout<<"0\n"; return 0;
  }
  for(r=l+1; r+1<in.size(); r++) {
    if(in[r+1]<=in[l]) break;
  }
  tmp=in[l]; in[l]=in[r]; in[r]=tmp;
  for(int i=1; l+i<in.size()-i; i++) {
    tmp=in[l+i]; in[l+i]=in[in.size()-i]; in[in.size()-i]=tmp;
  }
  for(int i=0; i<in.size(); i++) cout<<in[i];
  cout<<'\n';
  return 0;
}