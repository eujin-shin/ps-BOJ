#include <iostream>
#include <stack>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  stack <int> s;
  long long sum=0;
  int n, x;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x;
    while(!s.empty() && s.top()<=x) {
      s.pop();
    }
    sum+=s.size(); s.push(x);
  }
  cout<<sum<<'\n';
  return 0;
}