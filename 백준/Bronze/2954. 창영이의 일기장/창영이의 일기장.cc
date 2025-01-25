#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c);

int main() {
  string s;
  getline(cin, s);
  for(int i = 0; i < s.length(); i++) {
    cout<<s[i];
    i = isVowel(s[i]) ? i + 2 : i;
  }
  cout<<'\n';
  return 0;
}

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}