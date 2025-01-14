#include <iostream>
#define ll long long
#define NUM 10
using namespace std;

ll result[NUM] = {0, };
ll add[11][10] = {0, };

void addResult(int len, int num, bool exceptLast);
void updateAdd(int len, ll next);
void print();

void count(int x);

int main() {
  ll n;
  cin>>n;

  add[1][0] = 1;
  ll cur = 1, bound;
  int len;
  for(len = 1, bound = 9; bound <= n; bound = bound * 10 + 9, len++) {
    for(int num = 0; num < NUM; num++) {
      addResult(len, num, num == 0);
    }
    cur = bound + 1;
    updateAdd(len, cur);
  }

  bool startFromZero = false;
  ll size;
  for(size = bound / 10 + 1, cur--; size > 0; len--, size /= 10) {
    for(int num = (startFromZero ? 0 : 1); cur + size <= n; cur += size, num++) {
      result[num] += size;
      for(int x = 0; x < NUM; x++) {
        for(int l = 1; l < len; l++) {
          addResult(l, x, false);
        }
      }
    }
    result[(cur / size + 1) % 10] += n - cur;
    startFromZero = true;
  }

  for(int i = cur + 1; i <= n; i++) count(i);
  print();
  return 0;
}

void addResult(int len, int num, bool exceptLast) {
  for(int d = 0; d < len; d++) {
    if(d == len - 1 && exceptLast) {
      break;
    }
    result[num] += add[len][d];
  }
  return;
}

void updateAdd(int len, ll next) {
  for(int d = 0; d < len; d++) {
    add[len + 1][d] = add[len][d] * (d < len - 1 ? 10 : 9);
  }
  add[len + 1][len] = next;
  return;
}

void print() {
  for(int i = 0; i < NUM; i++) {
    if(i > 0) {
      cout<<" ";
    }
    cout<<result[i];
  }
  cout<<'\n';
}

void count(int x) {
  while(x > 0) {
    result[x % 10]++;
    x /= 10;
  }
  return;
}