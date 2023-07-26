#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin>>n>>m;
  if(m<3) cout<<"NEWBIE!\n";
  else if(m<=n) cout<<"OLDBIE!\n";
  else cout<<"TLE!\n";
  return 0;
}