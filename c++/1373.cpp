#include <iostream>
#include <string>
#define MAX 400000
using namespace std;

int main() {
  string input;
  int ans[MAX];
  int len, alen, b=1, index, temp=0;
  cin>>input;
  len=input.size();
  alen=len/3; if(len%3==0) alen--;
  index=alen;
  for(int i=len-1; i>=0; i--) {
    if(input[i]=='1') temp+=b;
    b*=2;
    if(b==8) {
      ans[index]=temp; index--;
      temp=0; b=1;
    }
  }
  if(b!=1) ans[index]=temp;
  for(int i=0; i<=alen; i++) {
    cout<<ans[i];
    if(i==alen) cout<<'\n';
  }
  return 0;
}