#include<bits/stdc++.h>
using namespace std;

class tree{
    public:
    int data;
    tree* left;
    tree* right;
};

int main(){
    tree* root = new tree();
    root->data = 1;
    root->left = new tree();
    root->left->data = 2;
    root->right = new tree();
    root->right->data = 3;
    root->left->left = new tree();
    root->left->left->data = 4;
    root->left->right = new tree();
    root->left->right->data = 5;
    root->right->left = new tree();
    root->right->left->data = 6;
    root->right->right = new tree();
    root->right->right->data = 7;
    root->right->right->right = new tree();
    root->right->right->right->data = 8;
    root->right->right->right->right = new tree();
    root->right->right->right->right->data = 9;
    root->right->right->right->right->right = new tree();
    root->right->right->right->right->right->data = 10;
    root->right->right->right->right->right->right = new tree();
    root->right->right->right->right->right->right->data = 11;
    root->right->right->right->right->right->right->right = new tree();
    root->right->right->right->right->right->right->right->data = 12;
    root->right->right->right->right->right->right->right->right = new tree();
    root->right->right->right->right->right->right->right->right->data = 13;
    root->right->right->right->right->right->right->right->right->right = new tree();
    root->right->right->right->right->right->right->right->right->right->data = 14;
    root->right->right->right->right->right->right->right->right->right->right = new tree();
    root->right->right->right->right->right->right->right->right->right->right->data = 15;
    root->right->right->right->right->right->right->right->right->right->right->right = new tree();
    root->right->right->right->right->right->right->right->right->right->right->right->data = 16;

    cout<<root->right->right->right->right->right->right->right->right->right->right->right->data<<endl;
}