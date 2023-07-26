#include <iostream>
#include <vector>
#include <algorithm>
#define max 100000
using namespace std;

vector <int> v[5001];

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, y, c=0, sum, min;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x>>y;
    v[y].push_back(x);
    if(y>c) c=y;
  }
  sum=0;
  for(int i=1; i<=c; i++) {
    if(v[i].size()==0) continue;
    sort(v[i].begin(), v[i].end());
    for(int j=0; j<v[i].size(); j++) {
      min=max;
      if(j!=0 && v[i][j]-v[i][j-1]<min) min=v[i][j]-v[i][j-1];
      if(j!=v[i].size()-1 && v[i][j+1]-v[i][j]<min) min=v[i][j+1]-v[i][j];
      sum+=min;
    }
  }
  cout<<sum<<'\n';
  return 0;
}