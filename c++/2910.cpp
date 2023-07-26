#include <iostream>
#include <vector>
using namespace std;

vector <int> v[1001];
int arr[1000]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, c, count, max=0, flag=0;
  cin>>n>>c;
  for(int i=0; i<n; i++) cin>>arr[i];
  for(int i=0; i<n; i++) {
    if(arr[i]<0) continue;
    count=1;
    for(int j=i+1; j<n; j++) {
      if(arr[j]==arr[i]) {
        count++; arr[j]=-1;
      }
    }
    v[count].push_back(arr[i]);
    if(max<count) max=count;
  }
  for(int i=max; i>0; i--) {
    for(int j=0; j<v[i].size(); j++) {
      for(int h=0; h<i; h++) {
        if(flag==0) flag=1;
        else cout<<' ';
        cout<<v[i][j];
        
      }
    }
  }
  cout<<'\n';
  return 0;
}