#include <iostream>
using namespace std;

int main() {
  int n, axis, a, b, c, d, x, y;
  cin>>n;
  axis=a=b=c=d=0;
  for(int i=0; i<n; i++) {
    cin>>x>>y;
    if(x==0 || y==0) axis++;
    else if(x>0 && y>0) a++;
    else if(x<0 && y>0) b++;
    else if(x<0 && y<0) c++;
    else d++;
  }
  cout<<"Q1: "<<a<<'\n';
  cout<<"Q2: "<<b<<'\n';
  cout<<"Q3: "<<c<<'\n';
  cout<<"Q4: "<<d<<'\n';
  cout<<"AXIS: "<<axis<<'\n';
  return 0;
}