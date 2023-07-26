#include <iostream>
#include <string>
using namespace std;

int main() {
  string s="UCPC", input, ans="I hate UCPC";
  int idx=0;
  getline(cin, input);
  for(int i=0; i<input.size(); i++) {
    if(s[idx]==input[i]) {
      idx++;
      if(idx==4) {
        ans="I love UCPC"; break;
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}