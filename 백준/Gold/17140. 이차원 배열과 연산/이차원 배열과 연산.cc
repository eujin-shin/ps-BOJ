#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100][100] = {0, };

int rowCalc(int rSize, int cSize);
int rowSort(int r, int cSize);
int columnCalc(int rSize, int cSize);
int columnSort(int c, int rSize);

int main() {
  int targetY, targetX, k;
  cin>>targetY>>targetX>>k;

  int rSize = 3, cSize = 3;
  for(int y = 0; y < rSize; y++) {
    for(int x = 0; x < cSize; x++) {
      cin>>arr[y][x];
    }
  }

  int ans = -1, count = 0;
  while(count <= 100) {
    if(arr[targetY - 1][targetX - 1] == k) {
      ans = count;
      break;
    }

    if(rSize < cSize) {
      rSize = columnCalc(rSize, cSize);
    } else {
      cSize = rowCalc(rSize, cSize);
    }
    count++;
  }
  cout<<ans<<'\n';
  return 0;
}

int rowCalc(int rSize, int cSize) {
  int max = 0, size;
  for(int y = 0; y < rSize; y++) {
    size = rowSort(y, cSize);
    if(size > max) {
      max = size;
    }
  }
  return max;
}

int rowSort(int r, int cSize) {
  int count[101] = {0, };
  for(int x = 0; x < cSize; x++) {
    count[arr[r][x]]++;
    arr[r][x] = 0;
  }

  vector<pair<int, int> > v;
  for(int i = 1; i <= 100; i++) {
    if(count[i] != 0) {
      v.push_back(make_pair(count[i], i));
    }
  }
  sort(v.begin(), v.end());
  
  int index = 0;
  for(int i = 0; i < v.size() && index < 100; i++, index += 2) {
    arr[r][index] = v[i].second;
    arr[r][index + 1] = v[i].first;
  }
  return index;
}

int columnCalc(int rSize, int cSize) {
  int max = 0, size;
  for(int x = 0; x < cSize; x++) {
    size = columnSort(x, rSize);
    if(size > max) {
      max = size;
    }
  }
  return max;
}

int columnSort(int c, int rSize) {
  int count[101] = {0, };
  for(int y = 0; y < rSize; y++) {
    count[arr[y][c]]++;
    arr[y][c] = 0;
  }

  vector<pair<int, int> > v;
  for(int i = 1; i <= 100; i++) {
    if(count[i] != 0) {
      v.push_back(make_pair(count[i], i));
    }
  }
  sort(v.begin(), v.end());
  
  int index = 0;
  for(int i = 0; i < v.size() && index < 100; i++, index += 2) {
    arr[index][c] = v[i].second;
    arr[index + 1][c] = v[i].first;
  }
  return index;
}