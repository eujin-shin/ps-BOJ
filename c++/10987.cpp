#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  char tmp;
  int cnt=0;
  cin>>input;
  for(int i=0; i<input.size(); i++) {
    tmp = input[i];
    if(tmp=='a' || tmp=='e' || tmp=='i' || tmp=='o' || tmp=='u') cnt++;
  }
  cout<<cnt<<'\n';
  return 0;
}