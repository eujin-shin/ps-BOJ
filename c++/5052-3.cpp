#include <iostream>
#include <string>
using namespace std;

typedef struct trie {
  bool end;
  struct trie* link[10];
} TRIE;

void initTrie(TRIE *cur) {
  cur->end=false;
  for(int i=0; i<10; i++) {
    cur->link[i]=NULL;
  }
}

bool InsertTrie(TRIE *head, string data) {
  bool ret=false;
  TRIE *cur=head;
  int x;
  for(int i=0; i<data.size(); i++) {
    x=data[i]-'0';
    if(cur->link[x]==NULL) {
      cur->link[x]=(TRIE *)malloc(sizeof(trie));
      initTrie(cur->link[x]);
      if(cur->end) {
        ret=true;
      }
    } else if(i==data.size()-1) {
      ret=true;
    }
    cur=cur->link[x];
  }
  cur->end=true;
  return ret;
}

void DelTrie(TRIE *cur) {
  for(int i=0; i<10; i++) {
    if(cur->link[i]!=NULL) {
      DelTrie(cur->link[i]);
    }
  }
  free(cur);
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  string data;
  bool flag, res;
  cin>>t;
  while(t--) {
    cin>>n;
    flag=false;
    TRIE *head=(TRIE *)malloc(sizeof(TRIE));
    initTrie(head);
    while(n--) {
      cin>>data;
      if(flag) continue;
      res=InsertTrie(head, data);
      if(res) flag=true;
    }
    if(flag) cout<<"NO\n";
    else cout<<"YES\n";
    DelTrie(head);
  }
  return 0;
}