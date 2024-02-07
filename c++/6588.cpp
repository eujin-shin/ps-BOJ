#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

vector <int> prime;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[MAX]={0, }, x;
  for(int i=2; i<MAX; i++) {
    for(int j=i*2; j<MAX; j+=i) arr[j]=1;
  }
  for(int i=3; i<MAX/2; i++) if(arr[i]==0) prime.push_back(i);
  cin>>x;
  while(x!=0) {
    if(arr[x]==1) {
      arr[x]=-1;
      for(int i=0; prime[i]<=x/2 && i<prime.size(); i++) {
        if(arr[x-prime[i]]==0) {
          arr[x]=prime[i]; break;
        }
      }
    }
    if(arr[x]==-1) cout<<"Goldbach's conjecture is wrong.\n";
    else cout<<x<<" = "<<arr[x]<<" + "<<x-arr[x]<<"\n";
    cin>>x;
  }
  return 0;
}