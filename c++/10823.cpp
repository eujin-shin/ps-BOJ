#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int tmp=0, sum=0;
  while(cin>>s) {
    for(int i=0; i<s.size(); i++) {
      if(s[i]==',') {
        sum+=tmp; tmp=0;
      } else {
        tmp*=10; tmp+=s[i]-'0';
      }
    }
  }
  cout<<sum+tmp<<'\n';
  return 0;
}