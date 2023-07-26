#include <iostream>
using namespace std;

int main() {
  int a=0, b=0, x, arr[10]={0, };
  for(int i=0; i<10; i++) cin>>arr[i];
  for(int i=0; i<10; i++) {
    cin>>x;
    if(x>arr[i]) b++;
    else if(x<arr[i]) a++;
  }
  if(a>b) cout<<"A\n";
  else if(b>a) cout<<"B\n";
  else cout<<"D\n";
  return 0;
}