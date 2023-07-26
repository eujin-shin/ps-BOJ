#include <iostream>
using namespace std;

int main() {
  int n, m, k;
  cin>>n>>m>>k;
  if(m-k<0) n+=m-k;
  else n+=k-m;
  cout<<n<<'\n';
  return 0;
}