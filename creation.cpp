#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *prev;
    node *next;
};
void creation(node **head,int item)
{
    node *ptr=new node();
    node *temp;
    ptr->prev=NULL;
    ptr->data=item;
    ptr->next=NULL;
    if(*head==NULL)
    {
        *head=temp=ptr;
    }
    else
    {
        temp->next=ptr;
        ptr->prev=temp;
        temp=ptr;
    }
}
void display(node **head)
{
    node *temp;
    temp=*head;
    while(temp->next!=NULL)
    {
        cout<<temp->data<<" "; 
        temp=temp->next;
    }
     cout<<temp->data;
}
void reverse(node **head)
{
    node *temp;
    temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<temp->data;
}
int main()
{
    int n,i,item;
    node *head=NULL;
    cin>>n;
    for(i=0 ; i<n ; i++)
    {
        cin>>item;
        creation(&head,item);
    }
    display(&head);
    cout<<endl;
    reverse(&head);
}