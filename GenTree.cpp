#include<bits/stdc++.h>
using namespace std;
template<typename T> class treeNode{
    public:
        T data;
        vector<treeNode<T>*> children;

        treeNode(T data){
            this->data = data;
        }
        ~treeNode(){
            for(int i = 0; i< children.size(); i++){
                delete children[i];
            }
        }
};
template<typename T> class Tree{
private:
    treeNode<T>* root;
    int levels = 0;

public:
    Tree(){
        cout << "Generating the Tree." << endl;
        root = NULL;
    }
    treeNode<T>* input(){
        queue<treeNode<T>*> qu;
        treeNode<T>* parent;
        if(levels == 0){
            cout << "Constructing root of tree." << endl;
            T data;
            cin >> data;
            root = new treeNode<T>(data);
            qu.push(root);
        }
        while(!qu.empty()){
            parent = qu.front();
            int nChild;
            cout << "Enter number of Children for " << parent->data << " of level " << levels << endl;
            cin >> nChild;
            if(nChild > 0){
                levels++;
            }
            for(int i = 0; i< nChild; i++){
                int data;
                cout << "Enter data for " << i+1 << "th child " << " of parent " << parent->data << " of level " << levels-1 << endl;
                cin >> data;
                treeNode<T>* node = new treeNode<T>(data);
                parent->children.push_back(node);
                qu.push(node);
            }
            qu.pop();
        }
        return root;
    }
    void print(){
        treeNode<T>* it = root;
        queue<treeNode<T>*> qu;
        qu.push(it);
        while(!qu.empty()){
            it = qu.front();
            qu.pop();
            cout << it->data << " : ";
            for(int i = 0; i< it->children.size(); i++){
                cout << it->children[i]->data << " "; 
                qu.push(it->children[i]);
            }
            cout << endl;
        }
    }
    void numNodes(treeNode<T>* rt, int& cnt){
        if(rt->children.size()==0){
            return;
        }
        cnt += rt->children.size();
        for(int i = 0; i< rt->children.size(); i++){
            numNodes(rt->children[i], cnt);
        }
    }
    int height(treeNode<T>* rt){
        int max_ans = 0, ans = 1;
        if(rt->children.size()==0){
            return 1;
        }
        for(int i = 0; i< rt->children.size(); i++){
            max_ans = max(max_ans, height(rt->children[i]));
        }
        return ans + max_ans;
    }
    void printAtK(treeNode<T>* rt, int k){
        if(!rt){
            return;
        }
        if(k==0){
            cout << rt->data << endl;
        }
        for(int i = 0; i< rt->children.size(); i++){
            printAtK(rt->children[i], k-1);
        }
        return;
    }
    int leafNodes(treeNode<T>* rt){
        if(!rt){
            return -1;
        }
        int cnt = 0;
        if(rt->children.size()==0){
            cnt++;
        }
        for(int i = 0; i< rt->children.size(); i++){
            cnt += leafNodes(rt->children[i]);
        }
        return cnt;
    }
    void deleteTree(treeNode<T>* rt){
        if(!rt){
            return;
        }
        for(int i = 0; i< rt->children.size(); i++){
            deleteTree(rt->children[i]);
        }
        delete rt;
    }
};
template<typename T> class BTNode{
public:
    T data;
    BTNode<T>* left;
    BTNode<T>* right;

    BTNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
template<typename T> class BinaryTree{
private:
    BTNode<T>* root = NULL;
    int nodes = 0;
public:
    BTNode<T>* input(){
        T rootData;
        cout<<"Enter root data"<<endl;
        cin>>rootData;
        root = new BTNode<T>(rootData);
        queue<BTNode<int>*> q;
        q.push(root);
        nodes++;
        while(!q.empty()){
            BTNode<T>* f = q.front();
            q.pop();

            cout<<"Enter left child of "<<f->data<<endl;
            T leftChildData;
            cin>>leftChildData;
            if(leftChildData != -1){
                BTNode<T>* child = new BTNode<T>(leftChildData);
                q.push(child);
                f->left = child;
                nodes++;
            }
            cout<<"Enter right child of "<<f->data<<endl;
            T rightChildData;
            cin>>rightChildData;
            if(rightChildData != -1){
                BTNode<T>* child = new BTNode<T>(rightChildData);
                q.push(child);
                f->right = child;
                nodes++;
            }
        }
        return root;
    }
    int numNodes(){
        return nodes;
    }
    bool findNode(BTNode<int>* root, int key){
        if(!root){
            return false;
        }
        if(root->data==key){
            return true;
        }
        return findNode(root->left, key)||findNode(root->right, key);
    }
    int minValue(BTNode<int>* root){
        if(!root){return INT_MAX;}
        int mini = root->data;
        return min(mini, min(minValue(root->left), minValue(root->right)));
    }
    int maxValue(BTNode<int>* root){
        if(!root){return INT_MIN;}
        int maxi = root->data;
        return max(maxi, max(maxValue(root->left), maxValue(root->right)));
    }
    int helper(BTNode<T>* node, int num){
        if(node->left == NULL && node->right == NULL){
            num++;
            return num;
        }
        return helper(node->left, num) + helper(node->right, num);
    }
    int leafNodes(BTNode<int>* root){
        if(!root){
            return 0;
        }
        
        return helper(root, 0);
    }
    BTNode<int>* Tree(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE){
        if(inS>inE){
            return NULL;
        }

        int rootData = preorder[preS];

        int lps = preS+1;
        int lpe;
        int rps;
        int rpe = preorder.size()-1;
        int lis = 0;
        int lie;
        int ris;
        int rie = inorder.size()-1;

        for(int i = 0; i< preorder.size(); i++){
            if(inorder[i]==rootData){
                lie = i - 1;
                ris = i + 1;
                break;
            }
        }

        lpe = lie - lis + lps;
        rps = rpe - rie + ris;

        BTNode<int>* root = new BTNode<int>(rootData); 

        BTNode<int>* leftS = Tree(preorder, inorder, lps, lpe, lis, lie);
        BTNode<int>* rightS = Tree(preorder, inorder, rps, rpe, ris, rie);

        root->left = leftS;
        root->right = rightS;

        return root;
    }
    BTNode<int>* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==1){
            BTNode<int>* node = new BTNode<int>(preorder[0]);
            return node;
        }

        return Tree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
int main(){
    BinaryTree<int>* tree = new BinaryTree<int>();
    BTNode<int>* node = tree->input();
    vector<int> in, pre;
    int n;
    cin >> n;
    for(int i = 0; i< n; i++){
        int x, y;
        cin >> x >> y;
        in.push_back(x);
        pre.push_back(y);
    }
    BTNode<int>* root = tree->buildTree(pre, in);

    // int key;
    // cout << "Enter key : " << endl;
    // cin >> key;
    // cout << tree->findNode(node, key) << endl;

    // cout << "Min Value: " << tree->minValue(node) << endl;
    // cout << "Number of leaf nodes : " << tree->leafNodes(node) << endl;
    // Tree<int>* tree = new Tree<int>();
    // treeNode<int>* node = tree->input();
    // tree->print();
    // int cnt = 1;
    // tree->numNodes(node, cnt);
    // cout << "Number of Nodes: " << cnt << endl;
    // cout << "Height of Tree: " << tree->height(node) << endl;
    // int k;
    // cout << "Enter value of k : " << endl;
    // cin >> k;
    // tree->printAtK(node, k);
    // cout << "Number of leaf Nodes: " << tree->leafNodes(node) << endl;
    // //tree->deleteTree(node);
    // delete node;
    // if(!node){
    //     cout << "Successfully deleted tree!" << endl;
    // }
    // else{
    //     cout << "Not deleted successfully!" << endl;
    // }
    // tree->print();
    return 0;
}