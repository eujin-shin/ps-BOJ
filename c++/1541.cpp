#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  int len, num=0, x, sum=0, flag=1;
  cin>>input;
  len=input.length();
  for(int i=0; i<len; i++) {
    x=input[i]-'0';
    if(x>=0 && x<10) {
      num=num*10+x;
    } else {
      sum+=num*flag; num=0;
      if(input[i]=='-') flag=-1;
    }
  }
  sum+=num*flag;
  cout<<sum<<'\n';
  return 0;
}