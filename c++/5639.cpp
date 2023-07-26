#include <iostream>
using namespace std;

typedef struct NODE {
  NODE *left, *right;
  int key;
} Node;

NODE *MakeTree(NODE *root, int key) {
  if(root==NULL) {
    root=new NODE;
    root->key=key; root->left=NULL; root->right=NULL;
  } else {
    if(root->key<=key) root->right=MakeTree(root->right, key);
    else root->left=MakeTree(root->left, key);
  }
  return root;
}

void Postfix(NODE *root) {
  if(root==NULL) return;
  Postfix(root->left);
  Postfix(root->right);
  cout<<root->key<<'\n';
  return;
} 

int main() {
  ios_base::sync_with_stdio(false);
  int temp; 
  NODE *root=NULL;
  while(cin>>temp) root=MakeTree(root, temp);
  Postfix(root);
  return 0;
}