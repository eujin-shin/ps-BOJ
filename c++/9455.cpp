#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

int main() {
  ios_base::sync_with_stdio(false);
  int t, m, n, sum, b;
  int map[100][100]={0, };
  cin>>t;
  while (t--) {
    sum=0;
    cin>>m>>n;
    for(int i=0; i<m; i++) {
      for(int j=0; j<n; j++) cin>>map[i][j];
    }
    for(int j=0; j<n; j++) {
      b=1;
      for(int i=1; i<=m; i++) {
        if(map[m-i][j]==1) {
          sum+=i-b; b++;
        }
      }
    }
    v.push_back(sum);
  }
  for(int i=0; i<v.size(); i++) {
    cout<<v[i];
    if(i<v.size()-1) cout<<' ';
  }
  cout<<'\n';
  return 0;
}