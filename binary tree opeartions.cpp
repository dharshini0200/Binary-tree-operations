#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct binarytree
{
    int data;
    struct binarytree *left;
    struct binarytree *right;
}*root;
binarytree* newnode(int data)
{
    struct binarytree* current=root;;
    current= new binarytree;
    current->data=data;
    current->left=NULL;
    current->right=NULL;
    return current;
}
int size(struct binarytree* root)
{
    if (root == NULL)
        return 0;
    else
        return(size(root->left) + 1 + size(root->right));
}
int findmax(struct binarytree* root)
{
    if (root == NULL)
        return INT_MIN;
    int res = root->data;
    int lres = findmax(root->left);
    int rres = findmax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}
int findmin(struct binarytree* root)
{
    if (root == NULL)
      return INT_MAX;
    int res = root->data;
    int lres = findmin(root->left);
    int rres = findmin(root->right);
    if (lres < res)
      res = lres;
    if (rres < res)
      res = rres;
    return res;
}
int add(binarytree* root)
{
    if (root == NULL)
        return 0;
    return (root->data + add(root->left) + add(root->right));
}

int main()
{
    int ch;
    root=newnode(1);
    root->left=newnode(2);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right=newnode(3);
    while(1){
    cout<<endl;
    cout<<" 1.SIZE IF THE BINARY TREE: "<<endl;
    cout<<" 2.MAX ELMENT IN BINARY TREE:"<<endl;
    cout<<" 3.MIN ELMENT IN BINARY TREE:"<<endl;
    cout<<" 4.SUM OF ALL ELMENT IN BINARY TREE:"<<endl;
    cout<<"Enter the choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"size:";
        cout<<size(root);
        break;
    case 2:
        cout<<" max element:";
        cout<<findmax(root);
        break;
    case 3:
        cout<<" min element:";
        cout<<findmin(root);
        break;
    case 4:
        cout<<" sum of all elements:";
        cout<<add(root);
         break;

      }
      }
      }
