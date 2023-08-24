#include <iostream>
#include <string>
using namespace std;

int lcs[102][102][102]={0, };

int main() {
  string a, b, c;
  int max;
  cin>>a>>b>>c;
  for(int x=1; x<=a.size(); x++) {
    for(int y=1; y<=b.size(); y++) {
      for(int z=1; z<=c.size(); z++) {
        if(a[x-1]==b[y-1] && b[y-1]==c[z-1]) {
         lcs[x][y][z]=lcs[x-1][y-1][z-1]+1; 
        } else {
          max=lcs[x-1][y][z];
          if(lcs[x][y-1][z]>max) max=lcs[x][y-1][z];
          if(lcs[x][y][z-1]>max) max=lcs[x][y][z-1];
          lcs[x][y][z]=max;
        }
      }
    }
  }
  cout<<lcs[a.size()][b.size()][c.size()]<<'\n';
  return 0;
}