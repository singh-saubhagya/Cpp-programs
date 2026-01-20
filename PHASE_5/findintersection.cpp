#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define endl '\n'
#define tab '\t'

struct node{
    int data;
    node *next;

    node(int a){
        data=a;
        next=nullptr;
    }
};
void solve()
{
  int n,m;
  cin>>n>>m;
  node *head1,*head2,*prev;
  head1=head2=prev=nullptr;

  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    node * temp= new node(x);
    if(head1==nullptr )
    {
        head1=temp;
        prev=head1;
    }
    else 
    {
        prev->next=temp;
        prev=temp;
    }
  }  
  node *prev2=nullptr;
  for(int i=0;i<m;i++)
  {
    int x;
    cin>>x;
    node * temp= new node(x);
    if(head2==nullptr)
    {
        head2=temp;
        prev2=head2;
    }
    else 
    {
        prev2->next=temp;
        prev2=temp;
    }
  }  
  
  node *temp1,*temp2;
  temp1=head1;
  temp2=head2;
  while(temp1!=nullptr)
  {
    cout<<temp1->data<<tab;
    temp1=temp1->next;
  }
  cout<<endl;
  while(temp2!=nullptr)
  {
    cout<<temp2->data<<tab;
    temp2=temp2->next;
  }



}
signed main()
{
  cin.tie(0); cout.tie(0);
  solve();
}