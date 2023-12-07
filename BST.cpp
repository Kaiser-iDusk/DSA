#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
class BST{
private:
    TreeNode* root;

public:
    BST(){
        root = nullptr;
    }
    TreeNode* getRoot(){
        return this->root;
    }
    void insert(int val){
        TreeNode* node=  new TreeNode(val);
        if(root == NULL){
            root = node;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* f = stk.top();
            stk.pop();
            
            if(val == f->val){
                break;
            }
            else if(val > f->val){
                if(f->right){
                    stk.push(f->right);
                }
                else{
                    f->right = node;
                    break;
                }            
            }
            else{
                if(f->left){
                    stk.push(f->left);
                }
                else{
                    f->left = node;
                    break;
                }
            }
        }
        return;
    }
    void printBST(){
        if(!root){
            return;
        }
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* curr = qu.front();
            qu.pop();
            cout << curr->val << " : ";
            if(curr->left)
                qu.push(curr->left);
            if(curr->right)
                qu.push(curr->right);
        }
        cout << endl;
        return;
    }
    void printList(){
        TreeNode* head = root;
        if(head==NULL){
            return;
        }
        while(head!=NULL){
            cout << head->val << " ";
            head = head->right;
        }
        return;
    }
    TreeNode* headLL(TreeNode* head){
        if(head==NULL){
            return NULL;
        }
        while(head->left != NULL){
            head = head->left;
        }
        return head;
    }
    TreeNode* tailLL(TreeNode* head){
        if(head==NULL){
            return NULL;
        }
        while(head->right != NULL){
            head = head->right;
        }
        return head;
    }
    TreeNode* BSTtoLL(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        TreeNode* head = headLL(root->left);
        TreeNode* leftTail = tailLL(root->left);
        TreeNode* tail = tailLL(root->right);
        TreeNode* rightHead = headLL(root->right);
        
        TreeNode* mid = root;

        if(head==NULL && tail ==NULL){
            return root;
        }
        else if(head==NULL && tail != NULL){
            head = mid;
            head->right = BSTtoLL(mid->right);;
            return head;
        }
        else if(tail == NULL && head != NULL){
            head = BSTtoLL(root->left);
            head->left = mid;
            return head;
        }
        else{
            head = BSTtoLL(mid->left);
            leftTail->right = mid;
            mid->right = BSTtoLL(mid->right);
            tail->right = NULL;
            return head;
        }
        return head;
    }
}; 