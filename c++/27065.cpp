#include <iostream>
#include <vector>
using namespace std;

vector <int> v[5001];
int arr[5001]={0, };

int Find(int k) {
  if(arr[k]==0) {
    int sum=0;
    for(int i=1; i<k; i++) {
      if(k%i!=0) continue;
      v[k].push_back(i);
      sum+=i;
    }
    if(sum<=k) arr[k]=-1;
    else arr[k]=1;
  }
  return arr[k];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, flag;
  cin>>t;
  while(t--) {
    cin>>n; flag=1;
    if(Find(n)<0) {
      flag=-1;
    } else {
      for(int i=0; i<v[n].size(); i++) {
        if(Find(v[n][i])>0) flag=-1;
      }
    }
    if(flag > 0) cout<<"Good Bye\n";
    else cout<<"BOJ 2022\n";
  }
  return 0;
}