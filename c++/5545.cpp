#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int main() {
  ios_base::sync_with_stdio(false);
  int n, a, b, c, d;
  cin>>n>>a>>b>>c;
  for(int i=0; i<n; i++) {
    cin>>d; v.push_back(d);
  }
  sort(v.begin(), v.end());
  int price=a, cal=c, cur, tmp;
  for(int i=n-1; i>-1; i--) {
    cur=cal/price; tmp=(cal+v[i])/(price+b);
    if(cur>tmp) break;
    cal+=v[i]; price+=b;
  }
  cout<<cal/price<<'\n';
  return 0;
}