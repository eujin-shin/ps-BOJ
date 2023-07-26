#include <iostream>
#include <string>
using namespace std;

int pos[15][2]={0, };
string s;

int main() {
  int k=0, tmp;
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      pos[k][0]=i; pos[k][1]=j; k++;
    }
  }
  k=0;
  for(int i=0; i<4; i++) {
    cin>>s;
    for(int j=0; j<4; j++) {
      if(s[j]=='.') continue;
      else tmp=s[j]-'A';
      k += (i>pos[tmp][0]) ? (i-pos[tmp][0]) : (pos[tmp][0]-i);
      k += (j>pos[tmp][1]) ? (j-pos[tmp][1]) : (pos[tmp][1]-j);
    }
  }
  cout<<k<<'\n';
  return 0;
}