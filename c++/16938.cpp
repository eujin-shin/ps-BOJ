#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int n, l, r, x, e, c=0;

void Solve(int k, int m, int sum, int max, int min) {
  if(k==e) {
    if(sum>=l && sum<=r && max-min>=x) c++;
    return;
  }
  for(int i=m; i<=n-e+k; i++) {
    if(k==0) min=v[i];
    Solve(k+1, i+1, sum+v[i], v[i], min);
  }
  return;
}

int main() {
  int tmp;
  cin>>n>>l>>r>>x;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  for(int i=1; i<=n; i++) {
    e=i;
    Solve(0, 0, 0, 0, 0);
  }
  cout<<c<<'\n';
  return 0;
}