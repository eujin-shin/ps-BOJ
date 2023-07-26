#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  double kg=0.4536, lb=2.2046, l=3.7854, g=0.2642, x;
  string s;
  cin>>t;
  for(int i=0; i<t; i++) {
    cin>>x>>s;
    cout<<fixed;
    cout.precision(4);
    if(s.compare("kg")==0) cout<<lb*x<<" lb\n";
    else if(s.compare("lb")==0) cout<<kg*x<<" kg\n";
    else if(s.compare("l")==0) cout<<g*x<<" g\n";
    else if(s.compare("g")==0) cout<<l*x<<" l\n";
  }
  return 0;
}