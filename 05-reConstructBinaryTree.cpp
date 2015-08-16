/********************************
 *@file:
 *@author: Pan HU
 *@data: 2015-8-16
 *@version: 0.1
 *@describe:
 ********************************/
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val; 
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
{
    if(pre.empty() || in.empty() || pre.size() != in.size())
    {
        return nullptr;
    }
    
    typedef vector<int>::const_iterator vintconit;
    vintconit preBegin = pre.begin();
    vintconit preEnd = pre.end()-1;
    vintconit inBegin = in.begin();
    vintconit inEnd = in.end()-1;
    
    struct TreeNode *root = new struct TreeNode(*preBegin);
    root->left = root->right = nullptr;
    
    if(preBegin == preEnd)
    {//如果前序和后序都只有一个节点，那么这两个节点应该相等，即这棵树只有一个根节点
        if(inBegin == inEnd && *preBegin == *preEnd)
        {
            return root;
        }
        else
        {
            throw runtime_error("input error");
            //abort();
        }
    }
    

    //find root node in inorder
    ptrdiff_t leftLen = 0;
    vintconit rootOfIn = inBegin;
    while(rootOfIn != inEnd+1 && *rootOfIn != *preBegin)
    {
        ++leftLen;
        ++rootOfIn;
    }
    
    if(rootOfIn == inEnd+1)
    {
        throw runtime_error("find root failed");
        //abort();
    }
    
    vintconit preLeftEnd = preBegin + leftLen;
    
    if(preLeftEnd > preBegin && leftLen > 0)
    {//left tree not null
        vector<int> leftpre(preBegin+1,preLeftEnd+1);
        vector<int> leftin(inBegin,rootOfIn);
        root->left = reConstructBinaryTree(leftpre,leftin);
    }
    if(preLeftEnd < preEnd)
    {//right tree not null
        vector<int> rightpre(preLeftEnd+1,preEnd+1);
        vector<int> rightin(rootOfIn+1,inEnd+1);
        root->right = reConstructBinaryTree(rightpre,rightin);
    }
    
    return root;
    
}
/*
struct TreeNode* reConstructBinaryTree(vector<int>::const_iterator preBegin,vector<int>::const_iterator preEnd,
                                       vector<int>::const_iterator inBegin, vector<int>::const_iterator inEnd)
{//前序遍历的第一个就是根节点，先创建根节点，然后分别创建左右子树。递归执行此过程！
    struct TreeNode *root = new struct TreeNode(*preBegin);
    root->left = root->right = nullptr;
    
    if(preBegin == preEnd)
    {//如果前序和后序都只有一个节点，那么这两个节点应该相等，即这棵树只有一个根节点
        if(inBegin == inEnd && *preBegin == *preEnd)
        {
            return root;
        }
        else
        {
            //throw runtime_error("input error");
            abort();
        }
    }
    
    typedef vector<int>::const_iterator vintconit;

    //find root node in inorder
    ptrdiff_t leftLen = 0;
    vintconit rootOfIn = inBegin;
    while(rootOfIn != inEnd+1 && *rootOfIn != *preBegin)
    {
        ++leftLen;
        ++rootOfIn;
    }
    
    if(rootOfIn == inEnd+1)
    {
        //throw runtime_error("find root failed");
        abort();
    }
    
    vintconit preLeftEnd = preBegin + leftLen;
    
    if(preLeftEnd > preBegin && leftLen > 0)
    {//left tree not null
        root->left = reConstructBinaryTree(preBegin+1,preLeftEnd,inBegin,rootOfIn-1);
    }
    if(preLeftEnd < preEnd)
    {//right tree not null
        root->right = reConstructBinaryTree(preLeftEnd+1,preEnd,rootOfIn+1,inEnd);
    }
    
    return root;
}
*/
int main()
{
    int pre[] = {1,2,4,7,3,5,6,8};
    int in[]  = {4,7,2,1,5,3,8,6};
    
    vector<int> preorder(pre, pre+sizeof(pre)/sizeof(*pre));
    vector<int> inorder (in, in+sizeof(in)/sizeof(*in));
    
    TreeNode * root = nullptr;
    
    try{
        root = reConstructBinaryTree(preorder,inorder);
    } catch (const runtime_error &e){
        cerr<<e.what()<<endl;
    }
    if(root != nullptr)
        cout<<root->val<<endl;
    else
        cout<<"!!!"<<endl;
    
    return 0;
}
