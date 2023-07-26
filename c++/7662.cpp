#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

void Solve(int x) {
  int cur=x*x%10;
  v = vector <int>();
  v.push_back(x);
  while(cur!=x) {
    v.push_back(cur);
    cur=cur*x%10;
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, a, b, i;
  cin>>t;
  while(t--) {
    cin>>a>>b;
    Solve(a%10);
    i=b%v.size();
    if(i==0) i=v.size();
    i=v[--i];
    if(i==0) i=10;
    cout<<i<<'\n';
  }
  return 0;
}
