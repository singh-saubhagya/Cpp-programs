#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void reversell(ListNode *head, ListNode *tail)
{
   if(head==tail)
   return ;
   reversell(head->next,tail);
   head->next->next=head;
   head->next=nullptr;
}

ListNode* reverseList(ListNode* head, int k) {
    ListNode * it=head;
    ListNode *ans=nullptr;
    ListNode *pt=nullptr;
    while(it!=nullptr)  
    {

        ListNode * a=it;
        ListNode * b=a;
        int ct=1;
        while(ct!=k)
        {
            ct++;
            b=b->next;
        }
        ListNode * nh=b->next;
        reversell(a,b);
        if(pt!=nullptr)
        {
            pt->next=b;

        }
        else {
            ans=b;
        }
        pt=a;
        it=nh;
    }
    return ans;
}


ListNode* GetList(vector<int> &num) {
    ListNode* head = nullptr;

    if(num.empty()) {
        return head;
    }

    ListNode* cur = head;
    
    for(int i  = 0; i < (int)num.size(); i++) {
        ListNode* temp = new ListNode(num[i]);
        if(!cur) {
            cur = temp;
            head = cur;
        }
        else {
            cur->next = temp;
            cur = temp;
        }
    }
    
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> num;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }

    int K;
    cin >> K;

    ListNode* head = GetList(num);

    head = reverseList(head, K);

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
    
    return 0;
}