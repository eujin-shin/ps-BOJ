#include <iostream>
using namespace std;

int arr[50]={0, };

int main() {
  int a, b, c, k=0, x=1;
  cin>>a>>b>>c;
  c%=2;
  while(x*2<=a) {
    x*=2; k++;
  }
  while(a>0) {
    arr[k]=1;
    a-=x;
    while(a>0 && a<x) {
      x/=2; k--;
    }
  }
  k=0; x=1;
  
}