#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    Node* child[26];
    bool isTerminal;

    Node(char ch){
        data = ch;
        isTerminal = false;
        for(int i = 0; i< 26; i++)
            child[i] = NULL;
    }
};

class Trie{
    Node* root;

public:
    Trie(){
        root = new Node('\0');
    }

    void insertUtil(Node* root, string& s){
        if(s.length()==0){
            root->isTerminal = true;
            return;
        }
        if(root->child[s[0] - 'a'] == NULL){
            root->child[s[0] - 'a'] = new Node(s[0]);
        }
        string str = s.substr(1);
        insertUtil(root->child[s[0] - 'a'], str);
    }
    
    void insert(string s){
        insertUtil(root, s);
    }

    Node* search(Node* root, string& s){
        if(s.length()==0){
            return root;
        }
        if(root->child[s[0] - 'a'] != NULL){
            string tmp = s.substr(1);
            return search(root->child[s[0] - 'a'], tmp);
        }
        return NULL;
    }

    void fill(Node* root, string& query, vector<string>& ans){
        if(root == NULL){
            return;
        }
        if(root->isTerminal){
            ans.push_back(query);
        }
        queue<Node*> q;
        for(int i = 0; i< 26; i++){
            if(root->child[i]){
                q.push(root->child[i]);
            }
        }
        while(!q.empty()){
            Node* top = q.front();
            q.pop();
            string cur = query + top->data;
            fill(top, cur, ans);
        }
    }

    vector<string> find(string query){
        vector<string> ans;

        Node* terminal = search(root, query);
        if(terminal == NULL){
            return ans;
        }

        fill(terminal, query, ans);
        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie tr;
    int n = contactList.size();
    for(int i = 0; i< n; i++){
        tr.insert(contactList[i]);
    }
    vector<vector<string> > ans;
    for(int i = 0; i< queryStr.length(); i++){
        vector<string> temp;
        string subs = queryStr.substr(0, (i+1));
        temp = tr.find(subs);
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    string query = "gklwj";
    vector<string> v({"llcfd", "jryqe", "aplon", "kwnuj", "bxuuf"});
    vector<vector<string>> ans;
    ans = phoneDirectory(v, query);

    for(int i = 0; i< ans.size(); i++){
        if(ans[i].size() == 0){
            cout << "Not found" << endl;
        }
        else{
            for(int j = 0; j< ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}