#include <iostream>
#include <string>
using namespace std;

int main() {
  string n;
  int l=0, r=0;
  cin>>n;
  for(int i=0; i<n.size(); i++) {
    if(i<n.size()/2) l+=n[i]-'0';
    else r+=n[i]-'0';
  }
  if(l==r) cout<<"LUCKY\n";
  else cout<<"READY\n";
  return 0;
}