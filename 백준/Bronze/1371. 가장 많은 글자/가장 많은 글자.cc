#include <iostream>
#include <string>
using namespace std;

int counts[26] = {0, };

int main() {
  string s;
  int max = 0, cur;
  while(cin>>s) {
    for(int i = 0; i < s.length(); i++) {
      cur = s[i] - 'a';
      if(cur >= 0 && cur < 26) {
        counts[cur]++;
      }
    }
  }

  for(int i = 0; i < 26; i++) {
    if(counts[i] > max) {
      max = counts[i];
    }
  }

  for(int i = 0; i < 26; i++) {
    if(counts[i] == max) {
      cout<<(char)(i + 'a');
    }
  }
  cout<<'\n';
  return 0;
}