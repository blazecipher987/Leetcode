#include<bits/stdc++.h>
using namespace std;


class Node{

public:

    int val;
    Node *next;

    void traverseList(){
        
        Node *curr = this;

        while(curr!=nullptr){
            cout<<curr->val<<"->";
            curr = curr->next;
        }
        cout<<endl;
    }

    Node(int value, Node* nextt){
        this->val = value;
        this->next = nextt;
    }

    Node(Node *h){
        this->next = h;
    }

    Node(){

    }

    Node* setNext(Node *t){
        this->next = t;
        return this->next;
    }





};


int main(){

    Node *head;
    head = new Node(10, nullptr);

    Node *temp= head;

    for(int i=0;i<6; i++){
        int t;
        cin>>t;
        temp = temp->setNext(new Node(t,nullptr)); 
    }




    
    head->traverseList();

}