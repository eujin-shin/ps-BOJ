#include <iostream>
#include <vector>
using namespace std;

vector <int> v[5];
int arr[6]={0, };

int main() {
  int k, d, x, y, a;
  cin>>k;
  for(int i=0; i<6; i++) {
    cin>>d>>arr[i];
    v[d].push_back(i);
  }
  for(int i=1; i<=4; i++) {
    if(v[i].size()!=1) continue;
    if(i<3) x=v[i][0];
    else y=v[i][0];
  }
  a=arr[x]*arr[y];
  for(int i=-1; i<2; i++) {
    if(x+i<0) arr[5]=0;
    else if(x+i>5) arr[0]=0;
    else arr[x+i]=0;
    if(y+i<0) arr[5]=0;
    else if(y+i>5) arr[0]=0;
    else arr[y+i]=0;
  }
  x=-1;
  for(int i=0; i<6; i++) {
    if(arr[i]==0) continue;
    if(x<0) x=i;
    else y=i;
  }
  a=a-(arr[x]*arr[y]);
  cout<<a*k<<'\n';
  return 0;
}