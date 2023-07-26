#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> a, b;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, x, y, tmp, cnt=0;
  cin>>n>>m;
  for(int i=0; i<n+m; i++) {
    cin>>tmp;
    if(i<n) a.push_back(tmp);
    else b.push_back(tmp);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  x=0; y=0;
  while(1) {
    if(x==n || y==m) break;
    else if(b[y]>a[x]) x++;
    else if(b[y]<a[x]) y++;
    else {
      cnt+=2; x++; y++;
    }
  }
  cout<<m+n-cnt<<'\n';
  return 0;
}