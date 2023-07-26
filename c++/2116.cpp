#include <iostream>
using namespace std;

int p[6]={5, 3, 4, 1, 2, 0}, a[6]={0, };
int map[7][10001]={0, };

int main() { 
  ios_base::sync_with_stdio(false);
  int n, max=0, sum, tmp, b, u;
  cin>>n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<6; j++) cin>>map[j][i];
  }
  for(int i=0; i<6; i++) {
    b=i; sum=0;
    for(int j=0; j<n; j++) {
      tmp=0;
      for(int h=0; h<6; h++) {
        if(h!=b && h!=p[b] && map[h][j]>tmp) tmp=map[h][j];
        if(map[h][j+1]==map[p[b]][j]) u=h;
      }
      sum+=tmp;
      b=u;
    }
    if(sum>max) max=sum;
  }
  cout<<max<<'\n';
  return 0;
}