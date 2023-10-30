#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v, h;

int Max(vector<int> vec) {
  int max=0, x;
  sort(vec.begin(), vec.end());
  for(int i=0; i<vec.size(); i++) {
    x=(i==0 ? vec[0] : vec[i]-vec[i-1]);
    if(x>max) max=x;
  }
  return max;
}

int main() {
  int n, m, k, d, x;
  cin>>n>>m>>k;
  h.push_back(m); v.push_back(n);
  for(int i=0; i<k; i++) {
    cin>>d>>x;
    if(d==0) h.push_back(x);
    else v.push_back(x);
  }
  m=Max(h);
  n=Max(v);
  cout<<m*n<<'\n';
  return 0;
}