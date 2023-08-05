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
    node *temp,*ptr;
    ptr=new node();
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

int rev(node **head)
{
    node *temp;
    temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp->prev!=NULL)
    {
        //cout<<temp->data<<" ";
        temp=temp->prev;
    }
    //cout<<temp->data;
    temp=*head;
    //return *head;
}

void insert_beg(node **head,int item)
{
    node *temp,*ptr;
    temp=*head;
    ptr = new node();
    ptr->prev=NULL;
    ptr->data=item;
    ptr->next=NULL;
    ptr->next=temp;
    temp->prev=ptr;
    *head=ptr;
}

void insert_end(node **head,int item)
{
    node *temp,*ptr;
    ptr=new node();
    ptr->prev=NULL;
    ptr->data=item;
    ptr->next=NULL;
    temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->prev=temp;
}

void insert_pos(node **head,int item,int pos)
{
    int i=1;
    node *ptr,*temp;
    ptr=new node();
    ptr->prev=NULL;
    ptr->data=item;
    ptr->next=NULL;
    temp=*head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    ptr->prev=temp;
    ptr->next=temp->next;
    temp->next=ptr;
    ptr->next->prev=ptr;
}

void del_first(node **head)
{
    node *temp;
    temp=*head;
    *head=temp->next;
    temp->next->prev=NULL;
    delete temp;
}

void del_end(node **head)
{
    node *temp,*ptr;;
    temp=*head;
    while(temp->next!=NULL)
    {
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=NULL;
    temp->prev=NULL;
    delete temp;
}

void del_pos(node **head,int pos)
{
    int i=1;
    node *temp,*ptr;
    temp=*head;
    while(i<pos)
    {
        //ptr=temp;
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
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

int main()
{
    node *head=NULL;
    int i,n,item,pos;
    cin>>n;
    for(i=0 ; i<n ; i++)
    {
        cin>>item;
        creation(&head,item);
    }
    display(&head);
    cout<<endl;
    /*
    //rev(&head);
    cout<<"Enter data : ";
    cin>>n;
    insert_beg(&head,n);
    display(&head);
    cout<<endl;
    cout<<"Enter data : ";
    cin>>n;
    insert_end(&head,n);
    display(&head);
    cout<<endl;
    cout<<"Enter data : ";
    cin>>n;
    cout<<"Enter position : ";
    cin>>pos;
    insert_pos(&head,n,pos);
    display(&head);
    cout<<endl;
    */
    del_first(&head);
    display(&head);
    cout<<endl;
    del_end(&head);
    display(&head);
    cout<<endl;
    cout<<"Enter postion : ";
    cin>>pos;
    del_pos(&head,pos);
    display(&head);
    cout<<endl;
}