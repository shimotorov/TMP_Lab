#include <iostream>

using namespace std;

struct Node
{
   int key;
   Node *left;
   Node *right;
};
   Node *root;
Node *Add_Node(Node *root,int value)
{
   if(!root)
   {
      root=new Node;
      root->left=root->right=NULL;
      root->key=value;
      return root;
   }
   if(value<root->key)
      root->left=Add_Node(root->left,value);
   else
       if(value>root->key)
          root->right=Add_Node(root->right,value);
       return root;
}

void CleanTree (Node **w)
//Очистка дерева.
//*w - указатель на корень дерева.
{
  if (*w!=NULL)
  { 
     CleanTree (&((**w).left));
     CleanTree (&((**w).right));
     delete *w; 
  }
}

void Print_Node(Node *root)
{
   if(!root)
      return;
   cout <<"(";
   cout<<root->key;
   Print_Node(root->left);
   Print_Node(root->right);
   cout<<")";
}

void main()
{
   
   int i,a[10]={2,5,7,1,4,3,9,12,6};
   for(i=0;i<9;i++)
       root=Add_Node(root,a[i]);
   Print_Node(root);
   system("pause");
}