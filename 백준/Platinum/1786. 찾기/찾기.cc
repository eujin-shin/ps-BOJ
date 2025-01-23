#include <iostream>
#include <string>
#include <vector>
#define MAX 1000000
using namespace std;

vector <int> targets, answer;

int main() {
  string t, p;
  getline(cin, t);
  getline(cin, p);

  int target = 0;
  targets.push_back(0);
  for(int i = 1; i < p.length(); i++) {
    while(target > 0 && p[i] != p[target]) {
      target = targets[target - 1];
    }
    if(p[target] == p[i]) {
      target++;
    }
    targets.push_back(target);
  }

  target = 0;
  for(int i = 0; i < t.length(); i++) {
    while(target > 0 && t[i] != p[target]) {
      target = targets[target - 1];
    }
    if(p[target] == t[i]) {
      target++;
    }
    if(target == p.length()) {
      answer.push_back(i - p.length() + 2);
      target = targets[target - 1];
    }
  }

  cout<<answer.size();
  for(int i = 0; i < answer.size(); i++) {
    cout<<(i > 0 ? ' ' : '\n');
    cout<<answer[i];
  }
  cout<<'\n';
  return 0;
}