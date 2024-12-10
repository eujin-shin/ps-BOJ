#include <iostream>
using namespace std;

long long n, k;
int check(long long t);
int biSearch();

int main() {
  cin>>n>>k;
  cout<<biSearch()<<'\n';
  return 0;
}

int check(long long t) {
  long long count, smaller = 0, same = 0;
  for(int i = 1; i <= n; i++) {
    if((long long)i * n < t) {
      smaller += n;
    } else if(t % i == 0) {
      same++;
      smaller += t / i - 1;
    } else {
      smaller += t / i;
    }
  }
  if(same == 0) {
    if(smaller < k) {
      return -1;
    } else {
      return 1;
    }
  } else if(smaller + same < k) {
    return -1;
  } else if(smaller >= k) {
    return 1;
  } else {
    return 0;
  }
}

int biSearch() {
  long long l = 0, r = 1000000000, mid;
  int result;
  while(l <= r) {
    mid = (l + r) / 2;
    result = check(mid);
    if(result < 0) {
      l = mid + 1;
    } else if(result > 0) {
      r = mid - 1;
    } else {
      break;
    }
  }
  return mid;
}