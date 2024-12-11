#include <iostream>
#include <vector>
#include <queue>
#define pnt pair<int, int>
#define ppnt pair<int, pnt>
using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
  return 0;
}

void solve() {
  int intersects, roads, targets, start, x, y, watched;
  cin>>intersects>>roads>>targets>>start>>x>>y;

  vector <pair<int, int> > map[2001];
  int a, b, distance;
  for(int i = 0; i < roads; i++) {
    cin>>a>>b>>distance;
    map[a].push_back(make_pair(distance, b));
    map[b].push_back(make_pair(distance, a));
    if((a == x && b == y) || (a == y && b == x)) {
      watched = distance;
    }
  }

  int ends[2001] = {0, }, target;
  for(int i = 0; i < targets; i++) {
    cin>>target;
    ends[target] = 1;
  }

  priority_queue <ppnt, vector<ppnt>, greater<ppnt> > pq;
  int distances[2001] = {0, };
  int current;
  for(int i = 0; i < 2001; i++) {
    distances[i] = 3000000;
  }
  distances[start] = 0;
  pq.push(make_pair(0, make_pair(0, start)));

  int nextIntersect, nextDistance;
  while(!pq.empty()) {
    distance = pq.top().first;
    a = pq.top().second.first;
    b = pq.top().second.second;
    pq.pop();

    current = b;
    for(int i = 0; i < map[current].size(); i++) {
      nextDistance = map[current][i].first + distance;
      nextIntersect = map[current][i].second;
      if(distances[nextIntersect] > nextDistance) {
        distances[nextIntersect] = nextDistance;
        pq.push(make_pair(nextDistance, make_pair(current, nextIntersect)));
      }
    }
  }

  int passedDistances[2][2001] = {0, };
  for(int i = 0; i < 2001; i++) {
    passedDistances[0][i] = 3000000;
    passedDistances[1][i] = 3000000;
  }

  passedDistances[0][x] = 0;
  pq.push(make_pair(0, make_pair(0, x)));
  while(!pq.empty()) {
    distance = pq.top().first;
    a = pq.top().second.first;
    b = pq.top().second.second;
    pq.pop();

    current = b;
    for(int i = 0; i < map[current].size(); i++) {
      nextDistance = map[current][i].first + distance;
      nextIntersect = map[current][i].second;
      if(passedDistances[0][nextIntersect] > nextDistance) {
        passedDistances[0][nextIntersect] = nextDistance;
        pq.push(make_pair(nextDistance, make_pair(current, nextIntersect)));
      }
    }
  }

  passedDistances[1][y] = 0;
  pq.push(make_pair(0, make_pair(0, y)));
  while(!pq.empty()) {
    distance = pq.top().first;
    a = pq.top().second.first;
    b = pq.top().second.second;
    pq.pop();

    current = b;
    for(int i = 0; i < map[current].size(); i++) {
      nextDistance = map[current][i].first + distance;
      nextIntersect = map[current][i].second;
      if(passedDistances[1][nextIntersect] > nextDistance) {
        passedDistances[1][nextIntersect] = nextDistance;
        pq.push(make_pair(nextDistance, make_pair(current, nextIntersect)));
      }
    }
  }

  bool isFirst = true;
  int distanceA, distanceB;
  for(int i = 1; i <= 2000; i++) {
    if(ends[i] == 0) {
      continue;
    }
    distanceA = watched + passedDistances[0][start] + passedDistances[1][i];
    distanceB = watched + passedDistances[0][i] + passedDistances[1][start];
    if(distanceA == distances[i] || distanceB == distances[i]) {
      if(isFirst) {
        isFirst = false;
      } else {
        cout<<' ';
      }
      cout<<i;
    }
  }
  cout<<'\n';
  
  return;
}