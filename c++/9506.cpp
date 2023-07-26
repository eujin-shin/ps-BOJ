#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, sum;
  cin>>n;
  while(n>0) {
    vector<int> v; sum=0;
    for(int i=1; i<n; i++) {
      if(n%i!=0) continue;
      v.push_back(i); sum+=i;
    }
    if(sum==n) {
      cout<<n<<" = ";
      for(int i=0; i<v.size(); i++) {
        cout<<v[i];
        if(i+1<v.size()) cout<<" + ";
      }
      cout<<'\n';
    } else {
      cout<<n<<" is NOT perfect.\n";
    }
    cin>>n;
  }
  return 0;
}