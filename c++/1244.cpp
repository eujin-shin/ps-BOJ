#include <iostream>
using namespace std;

int swt[101] = {0, };

void Boy(int x, int n) {
  for(int i=x; i<=n; i+=x) {
    swt[i] = !swt[i];
  }
}

void Girl(int c, int n) {
  int x = c, y = c;
  while(swt[x]==swt[y]) {
    swt[x] = !swt[x];
    if(x!=y) {
      swt[y] = !swt[y];
    }
    x--; y++;
    if(x<1 || y>n) {
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, type, x;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>swt[i];
  }
  cin>>m;
  for(int i=0; i<m; i++) {
    cin>>type>>x;
    if(type==1) {
      Boy(x, n);
    } else if(type==2) {
      Girl(x, n);
    }
  }
  for(int i=1; i<=n; i++) {
    cout<<swt[i];
    if(i%20==0 || i==n) {
      cout<<'\n';
    } else {
      cout<<' ';
    }
  }
  return 0;
}