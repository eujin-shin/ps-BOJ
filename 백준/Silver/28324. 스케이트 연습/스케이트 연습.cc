#include <iostream>
#include <vector>
using namespace std;

vector <long long> v;

int main() {
  int n;
  cin>>n;
  long long r;
  for(int i = 0; i < n; i++) {
    cin>>r;
    v.push_back(r);
  }

  long long limit = 1, sum = 0;
  for(int i = 1; i <= n; i++, limit++) {
    limit = limit < v[n - i] ? limit : v[n - i];
    sum += limit;
  }
  cout<<sum<<'\n';
}