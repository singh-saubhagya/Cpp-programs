#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

struct node{
    int data;
    node *next;
    node (int a)
    {
       data=a;
       next=nullptr;
    }
};
node *newhead;
void reverse(node* head)
{
    if ( head->next == nullptr)
    {
        newhead=head;
        return ;
    }

    reverse(head->next);

    head->next->next = head;
    head->next = nullptr;

  
}

signed main()
{
    int n;
    cin>>n;
    node *head,*prev;
    head=prev=nullptr;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        node *temp=new node(x);
        if(i==0)
        {
            head=temp;

        }
        else{
            prev->next=temp;
          
        }
        prev=temp;
    }
    reverse(head);
    
    node *temp=newhead; 
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } 

}