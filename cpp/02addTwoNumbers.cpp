/**
 * Definition for singly-linked list.*/
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>   
#include<conio.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=-1;//和        
        int flag=0;//进位
        int val1=-1,val2=-1;
        ListNode* l3;
        ListNode* head=new ListNode(0);
        l3=head;
        
        while(l1!=NULL || l2!=NULL)
        {
            ListNode* p=new ListNode(0);
            if(l1)
            {
                val1=l1->val;
                l1=l1->next;
            }
            else val1=0;
            if(l2)
            {
                val2=l2->val;
                l2=l2->next;
            }
            else val2=0;
            sum=(val1+val2+flag)%10;
            flag=(val1+val2+flag)/10;
            p->val=sum;
            p->next=NULL;        
            l3->next=p;
            l3=l3->next;
        }
                
        if(l1==NULL && l2==NULL && flag==1)
        {          
            ListNode* p=new ListNode(0);
            p->val=1;
            p->next=NULL;
            l3->next=p;
            l3=l3->next;
        }
            
    return head->next;
    }

};
ListNode* initial1(vector<int>&a)
{
    int i=0;
    ListNode* an=new ListNode(0);
    ListNode* p1;
    p1=an;
    for(i=0;i<a.size();i++)
    {
        ListNode* p=new ListNode(0);
        p->val=a[i];
        p->next=NULL;
        p1->next=p;
        p1=p1->next;
    }
    return an->next;
}
void print1(ListNode* l1)
{
    while(l1!=NULL)
    {
        cout<<l1->val<<',';
        l1=l1->next;
    }
}
int main()
{
    vector<int>a={9,8};
    vector<int>b={1};
    Solution A;
    print1(A.addTwoNumbers(initial1(a),initial1(b)));
    system("pause");
    return 0;    
}
