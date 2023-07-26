#include <iostream>
#include <string>
using namespace std;

string in[100];

int main() {
  ios_base::sync_with_stdio(false);
  int n, v, h, c;
  cin>>n;
  for(int i=0; i<n; i++) cin>>in[i];
  v=0; h=0;
  for(int y=0; y<n; y++) {
    c=0;
    for(int x=0; x<n; x++) {
      if(in[y][x]=='X') {
        if(c>1) h++;
        c=0;
      } else {
        c++;
      }
    }
    if(c>1) h++;
  }
  for(int x=0; x<n; x++) {
    c=0;
    for(int y=0; y<n; y++) {
      if(in[y][x]=='X') {
        if(c>1) v++;
        c=0;
      } else {
        c++;
      }
    }
    if(c>1) v++;
  }
  cout<<h<<' '<<v<<'\n';
  return 0;
}