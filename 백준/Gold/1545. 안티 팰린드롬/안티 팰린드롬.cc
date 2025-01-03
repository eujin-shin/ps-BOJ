#include <iostream>
#include <string>
using namespace std;

int counts[26] = {0, };

void print(int length, int half);

int main() {
  string s;
  int length, half;
  cin>>s;
  length = s.length();
  half = (length % 2 == 0 ? length / 2 : (length + 1) / 2);
  
  bool isAble = true;
  for(int i = 0; i < length && isAble; i++) {
    counts[s[i] - 'a']++;
    if(counts[s[i] - 'a'] > half) {
      isAble = false;
    }
  }

  if(isAble) {
    print(length, half);
  } else { 
    cout<<"-1\n";
  }
  return 0;
}

void print(int length, int half) {
  int cur = 1, holdIndex = -1, stopHold = -1;
  for(int i = 0; i < 26; i++) {
    for(int n = 0; n < counts[i]; n++) {
      if(cur == stopHold) {
        for(int temp = 0; temp < counts[holdIndex]; temp++) {
          cout<<(char)('a' + holdIndex);
          cur++;
        }
        stopHold = -1;
      }

      cout<<(char)('a' + i);
      if(cur++ == half) {
        holdIndex = i;
        stopHold = (length % 2 == 0 ? half + n + 2 : half + n + 1);
        counts[i] -= n + 1;
        break;
      }
    }
    if(cur == stopHold) {
      for(int temp = 0; temp < counts[holdIndex]; temp++) {
        cout<<(char)('a' + holdIndex);
        cur++;
      }
      stopHold = -1;
    }
  }
  cout<<'\n';
  return;
}