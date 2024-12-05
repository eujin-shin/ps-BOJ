#include <iostream>
#include <stack>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin>>n>>k;
  stack <ll> a, b;
  ll sumA = 0, sumB = 0, x;
  for(int i = 0; i < n; i++) {
    cin>>x;
    a.push(x);
    sumA += x;
  }
  for(int i = 0; i < n; i++) {
    cin>>x;
    b.push(x);
    sumB += x;
  }
  for(int i = 0; i < k; i++) {
    if(sumA > sumB || (sumA == sumB && a.top() > b.top())) {
      sumA -= a.top();
      a.pop();
    } else {
      sumB -= b.top();
      b.pop();
    }
  }
  cout<<(sumA > sumB ? sumA : sumB)<<'\n';
  return 0;
}