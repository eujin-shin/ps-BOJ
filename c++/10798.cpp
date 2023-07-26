#include <iostream>
#include <string>
using namespace std;

int main() {
  string ip[5];
  int l=0;
  for(int i=0; i<5; i++) {
    cin>>ip[i];
    if(ip[i].size()>l) l=ip[i].size();
  }
  for(int i=0; i<l; i++) {
    for(int j=0; j<5; j++) {
      if(ip[j].size()<=i) continue;
      cout<<ip[j][i];
    }
  }
  cout<<'\n';
  return 0;
}