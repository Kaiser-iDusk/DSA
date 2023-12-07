#include<bits/stdc++.h>
#include "BST.cpp"
class ListNode{
public:
    int val;
    ListNode* next; 

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
// void printList(TreeNode* head){
//     if(head==NULL){
//         return;
//     }
//     while(head!=NULL){
//         cout << head->val << " ";
//         head = head->right;
//     }
//     return;
// }
// TreeNode* headLL(TreeNode* head){
//     if(head==NULL){
//         return NULL;
//     }
//     while(head->left != NULL){
//         head = head->left;
//     }
//     return head;
// }
// TreeNode* tailLL(TreeNode* head){
//     if(head==NULL){
//         return NULL;
//     }
//     while(head->right != NULL){
//         head = head->right;
//     }
//     return head;
// }
// TreeNode* BSTtoLL(TreeNode* root){
//     if(root==NULL){
//         return NULL;
//     }
//     TreeNode* head = headLL(root->left);
//     TreeNode* leftTail = tailLL(root->left);
//     TreeNode* tail = tailLL(root->right);
//     TreeNode* rightHead = headLL(root->right);
    
//     TreeNode* mid = root;

//     if(head==NULL && tail ==NULL){
//         return root;
//     }
//     else if(head==NULL){
//         head = mid;
//         head->right = BSTtoLL(mid->right);;
//         return head;
//     }
//     else if(tail == NULL){
//         head = BSTtoLL(root->left);
//         head->left = mid;
//         return head;
//     }
//     else{
//         head = BSTtoLL(mid->left);
//         leftTail->right = mid;
//         mid->right = BSTtoLL(mid->right);
//         tail->right = NULL;
//         return head;
//     }
//     return head;
// }
using namespace std;
int main(){
    BST* tree = new BST();
    string command;
    string s = "/:BST>> ";
    while(true){
        
        cout << s;
        cin >> command;

        if(command == "exit"){
            cout << s + "Ok Bye!";
            break;
        }
        else if(command == "insert"){
            cout << s + "INSERT (val) = ";
            int x;
            cin >> x;
            tree->insert(x);
        }
        else if(command == "batch_insert"){
            int breakpoint;
            cout << s + "COMMENSE BATCH INSERT (breakpoint) = ";
            cin >> breakpoint;
            cout << endl;
            cout << s + "COMMENSE BATCH INSERT (int[])(" << breakpoint << ") = ";
            vector<int> v;
            int x;
            cin >> x;
            while(x != breakpoint){
                v.push_back(x);
                cin >> x;
            }
            for(auto i : v){
                tree->insert(i);
            }
        }
        else if(command == "print"){
            cout << s + "PRINT (BSTree) : " << endl;
            tree->printBST();
        }
        else if(command == "printLL"){
            
            if(s!="/:LL>> "){
                cout << s + "CONVERT BST TO LL (cvtBST2LL) !";
            }
            else{
                cout << s + "PRINT (SLL) : " << endl;
                tree->printList();
            }
        }
        else if(command == "cvtBST2LL"){
            cout << "/:BST->LL?>> (Y/N) ? ";
            string bl;
            cin >> bl;
            if(bl == "Y" || bl == "y"){
                s = "/:LL>> ";
                TreeNode* LL = tree->BSTtoLL(tree->getRoot());
            }
            else if(bl == "N" || bl == "n"){
                continue;
            }
            else{
                cout << s + "NOT A VALID INPUT !";
            }
        }
        cout << endl;
    }
    return 0;
}