#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector <int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  while(1) {
    cin>>n;
    if(n==0) break;
    v=vector<int>(); x=n;
    for(int i=2; i<=n; i++) {
      if(v.empty() && i>sqrt(n)) break;
      if(i>x) break;
      if(x%i==0) v.push_back(i);
      while(x%i==0) x/=i;
    }
    if(v.empty()) {
      cout<<n-1<<'\n'; continue;
    }
    for(int i=0; i<v.size(); i++) {
      n=n/(v[i])*(v[i]-1);
    }
    cout<<n<<'\n';
  }
  return 0;
}