#include <iostream>
#include <memory.h>
#define MAX 100000
using namespace std;

long long mem[MAX];
long long p, q;

long long solve(long long n) {
  if(n==0) return 1;
  if(n>=MAX) return solve(n/p)+solve(n/q);
  if(mem[n]==-1) mem[n]=solve(n/p)+solve(n/q);
  return mem[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin>>n>>p>>q;
  memset(mem, -1, sizeof(mem));
  cout<<solve(n)<<'\n';
  return 0;
}