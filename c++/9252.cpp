#include <iostream>
#include <string>
using namespace std;

int map[1001][1001]={0, }; 
char res[1001];


int main() {
  string a, b;
  int n, x, y;
  cin>>a>>b;
  x=a.size(); y=b.size();
  for(int i=1; i<=x; i++) {
    for(int j=1; j<=y; j++) {
      if(a[i-1]==b[j-1]) map[i][j]=map[i-1][j-1]+1;
      else map[i][j]=((map[i-1][j]>map[i][j-1]) ? (map[i-1][j]) : (map[i][j-1]));
    }
  }
  n=map[x][y];
  for(int i=n; i>0; i--) {
    while(1) {
      if(map[x-1][y]==map[x][y]) x--;
      else if(map[x][y-1]==map[x][y]) y--;
      else break;
    }
    res[i]=a[x-1];
    x--; y--;
  }
  cout<<n<<'\n';
  for(int i=1; i<=n; i++) {
    cout<<res[i];
    if(i==n) cout<<'\n';
  }
  return 0;
}