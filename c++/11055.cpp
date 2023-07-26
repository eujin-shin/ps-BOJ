#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int arr[1001]={0, }, sum[1001]={0, };
  int n, max, j, temp;
  cin>>n;
  cin>>arr[1];
  sum[1]=max=arr[1];
  for(int i=2; i<=n; i++) {
    cin>>arr[i]; temp=0;
    for(j=1; j<i; j++) {
      if(arr[j]<arr[i] && sum[j]>temp) temp=sum[j];
    }
    sum[i]=arr[i]+temp;
    if(sum[i]>max) max=sum[i];
  }
  cout<<max<<'\n';
  return 0;
}