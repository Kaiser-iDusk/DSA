#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    void printList(Node* n){
        while(n != NULL){
            cout << n->data << "->";
            n = n->next;
        }
        cout << endl;
    }
    struct Node* reverse(Node* head){
        Node* curr1 = NULL;
        Node* curr2 = NULL;
        Node* curr3 = NULL;

        if(head)
            curr2 = head;
        else
            return NULL;

        if(head->next)
            curr3 = head->next;
        else
            return head;

        while(curr3 != NULL){
            curr2->next = curr1;
            curr1 = curr2;
            curr2 = curr3;
            curr3 = curr3->next;
        }     

        curr2->next = curr1;
        return curr2;
    }
    struct Node * mergeResult(Node *node1, Node *node2)
    {
        // your code goes here
        struct Node* tail = NULL;
        struct Node* head = NULL;
        struct Node* tail2 = NULL;

        if(node1 && node2){
            head = (node1->data <= node2->data) ? (node1) : (node2);
            tail2 = (node1->data > node2->data) ? (node1) : (node2);
        }
        else if(node1 && !node2)
            head = node1;
        else
            head = node2;
        tail = head;

        while(tail != NULL){
            if(tail2){
                if(tail->next){
                    if(tail->next->data <= tail2->data){
                        tail = tail->next;
                    }
                    else{
                        struct Node* temp = tail->next;
                        tail->next = tail2;
                        tail2 = temp;
                    }
                }
                else{
                    tail->next = tail2;
                    tail2 = NULL;
                }
            }
            else{
                tail = tail->next;
            }
        }
        printList(head);
        head = reverse(head);
        printList(head);
        return NULL;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}