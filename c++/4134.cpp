#include <iostream>
#include <math.h>
using namespace std;

int main() {
  long long t, n;
  bool flag;
  cin>>t;
  while(t--) {
    cin>>n;
    if(n<2) {
      cout<<"2\n"; continue;
    }
    while(1) {
      flag=true;
      for(int i=2; i<=sqrt(n); i++) {
        if(n%i==0) {
          flag=false; break;
        }
      } 
      if(flag) {
        cout<<n<<'\n'; break;
      }
      n++;     
    }
  }
  return 0;
}