#include<bits/stdc++.h>
using namespace std;
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
class Solution {
public:
    TreeNode* makeTree(vector<int>& nums, int s, int e){
        // if(s>e){
        //     TreeNode* node = NULL; 
        //     return node;     
        // }
        // int len = e-s+1;
        // int pvt = len/2;
        // cout << len << " || " << pvt << endl;
        // TreeNode* node = new TreeNode(nums[pvt]);
        // TreeNode* leftS = makeTree(nums, s, pvt-1);
        // TreeNode* rightS = makeTree(nums, pvt+1, e);
        // node->left = leftS;
        // node->right = rightS;
        // return node;
        if(s > e){
            return NULL;
        }
        
        int mid = (s+e)/2;
        int rootData = nums[mid];
        TreeNode* root = new TreeNode(rootData);
        root->left = makeTree(nums, s , mid-1);
        root->right = makeTree(nums, mid+1 , e);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        return makeTree(nums, 0, n-1);
    }
    void printBST(TreeNode* root){
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
};
    double champagneTower(int poured, int query_row, int query_glass) {
        int i = 1;
        double ans;
        while(i*(i+1)<=2*poured){
            i++;
        }
        i = i-1;
        cout << i << endl;
        int rem = poured - (i*(i+1)/2);
        if(query_row < i){
            return (double) 1;
        }
        if(rem == 0 && (query_row > i)){
            return (double) 0;
        }
        if(rem != 0){
            double eq = rem / i, fglass = eq / 2, rglass = eq;
            cout << rem << " " << (double) rem/i << " " << fglass << " " << rglass << endl;
            if(query_row == i){
                if(query_glass == 0 || query_glass == i){
                    return (double) fglass;
                }
                else{
                    return (double) rglass;
                }
            }
            else if(query_row>i){
                return 0;
            }
        }
        return 0;
    }
int main(){

    int p, qr, qg;
    cin >> p >> qr >> qg;
    cout << champagneTower(p, qr, qg) << endl;
    // Solution s;
    // vector<int> nums;
    // int n;
    // cin >> n;
    // for(int i = 0; i< n; i++){
    //     int x;
    //     cin >> x;
    //     nums.push_back(x);
    // }
    // TreeNode* root = s.sortedArrayToBST(nums);
    // s.printBST(root);
    // return 0;

    // BST* tree = new BST();
    // string command;

    // while(true){
    //     cout << "/BST>>";
    //     cin >> command;
    //     cout << endl;

    //     if(command == "exit"){
    //         cout << "/BST>> Ok Bye!" << endl;
    //         break;
    //     }
    //     else if(command == "insert"){
    //         cout << "/BST>> INSERT (val) = ";
    //         int x;
    //         cin >> x;
    //         tree->insert();
    //     }
    //     else if(command == "print"){
    //         cout << "/BST>> PRINT (BSTree) : ";
    //         cout << endl;
    //         tree->printBST();
    //     }
    // }
    // return 0;
}