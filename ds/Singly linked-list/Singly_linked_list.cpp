/*program for implementation of simple singly linked-list*/
/*contributed by  #ultra_utsav */
#include<bits/stdc++.h>
using namespace std;
/*create node in linked-list which contains the data and next address of next node*/
struct node
{
    int data;                                       //data for storing value in nodes
    node *next=NULL;                                //*next pointer will store address of next node
};

typedef struct node list1;                          //type defination of node structure

/*for taking data/input from user*/
int enterdata()
{
    int x;
    cout<<"enter value:   ";
    cin>>x;
    return x;
}

list1 *first=NULL;                                  //*first pointer will point to first node of list throughout program

/*insertion in list*/

/* insertion of node at beginning of list */
void insert_begin()
{
   if(first==NULL)                                 // if list is empty
   {
       first=(list1*)malloc(sizeof(list1));
       first->data=enterdata();
       first->next=NULL;
   }
   else                                           //if list is not empty
   {
       list1 *p=NULL;
       p=(list1*)malloc(sizeof(list1));
       p->next=first;
       first=p;
       first->data=enterdata();
   }
}

/* insertion of node at end of list */
void insert_end()
{
    /*first traverse to end of list then we add node to the and of list*/
    list1 *last=first;
    if(last==NULL)                                //if list is empty
        insert_begin();
    else
    {
         while(last->next!=NULL)
            {
                last=last->next;
            }
    /* now *last pointer points to last node of the list */
        list1 *temp=(list1*)malloc(sizeof(list1));
        last->next=temp;
        temp->data=enterdata();
        temp->next=NULL;
    }
}

/* insertion of node before the given node */
void insert_before()
{
    int x;
    cout<<"enter node number before which new node will added:   ";
    cin>>x;
    list1 *temp=first,*p=NULL;
    /* here *p for insert new node and *temp for traversal and one node ahead for given node or (x-1)th node */
    if(x==1||temp==NULL)
    {
        cout<<"not enough nodes in list so node will be at beginning of list\n";
        insert_begin();
    }
    else
    {
        while(x-->2)
         {
            temp=temp->next;
            if(temp==NULL)                           //if list have not enough nodes in list
                {
                    cout<<"not enough nodes in list so new node will be added to end of list\n";
                    insert_end();
                    x=2;
                    return ;
                }
         }
        p=(list1*)malloc(sizeof(list1));
        p->next=temp->next;
        temp->next=p;
        p->data=enterdata();
    }
}

/* insertion of node after the given node */
void insert_after()
{
    int x;
    cout<<"enter node number after which new node will added:   ";
    cin>>x;
    list1 *temp=first,*p=NULL;
    if(temp==NULL)                                   //if list is empty
    {
        insert_begin();
        return ;
    }
    while(x-->1)
    {
        if(temp->next==NULL)                        //if list have not enough node
        {
            cout<<"not enough nodes in list so new node will be added to end of list\n";
            insert_end();
            x=2;
            return ;
        }
        temp=temp->next;
    }
        p=(list1*)malloc(sizeof(list1));
        p->next=temp->next;
        temp->next=p;
        p->data=enterdata();
}

/*deletion*/

/* deletion of first node of list */
void delete_first()
{
    if(first==NULL)
        cout<<"!!!not enough nodes in list\n";
    else
        first=first->next;
}
/* deletion of last node of list */
void delete_end()
{
    list1 *temp=first,*p=first;
    if(temp==NULL)
    {
        cout<<"empty list\n";
        return ;
    }
    else if(temp->next==NULL)
    {
        temp=NULL;
        first=NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            p=temp;
            temp=temp->next;
        }
        if(p==first->next)
        {
            p=NULL;
        }
        else
        {
            p->next=NULL;
        }
    }
}
/* delete a node which is before to the  given node */
void delete_node()
{
    int x;
    cout<<"enter node number of node which will deleted:   ";
    cin>>x;
    if(x==1)
    {
        delete_first();
    }
    else
    {
        list1 *temp=first,*p=NULL;
        if(temp==NULL)                                  //it simply means that list is empty
        {
            cout<<"!!!not enough nodes in list\n";
            return ;
        }
        while(x-->2)
         {
             if(temp->next==NULL)                        //if list have not enough node
             {
                cout<<"!!!not enough nodes in list\n";
                return ;
             }
             temp=temp->next;
         }
        p=temp->next;
        temp->next=p->next;
    }
}

/* display the all node of the linked-list*/
void display_list()
{
    /*we have to traverse whole list */
    list1 *temp=first;
    cout<<"------------------------------------------------------\n";
    if(temp==NULL)
    {
          cout<<"empty list\n";
    }
    else
    {
          cout<<"linked list:  ";
          while(temp->next!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<temp->data;
            cout<<endl;
    }
    cout<<"------------------------------------------------------\n";
}
int main()
{
    int ch,ch1;
    list1 *top=NULL,*start=NULL,*p=NULL;
    while(1)
    {
        cout<<"\n1.insert node\t2.delete node\t3.display list\t4.exit\n";
        cout<<"enter choice:  ";
        cin>>ch;
        switch(ch)
        {
            case 1:  cout<<"\n1.insert at beginning of list\n2.insert before node\n3.insert after node\n4.insert end of list\n";
                     cout<<"enter your choice:   ";
                     cin>>ch1;
                     switch(ch1)
                     {
                         case 1: insert_begin();break;
                         case 2: insert_before();break;
                         case 3: insert_after();break;
                         case 4: insert_end();break;
                         default: cout<<"invalid choice";
                     }
                     break;
            case 2:  cout<<"\n1.delete first node of list\n2.delete number of node\n3.delete from end of list\n";
                     cout<<"enter your choice:   ";
                     cin>>ch1;
                     switch(ch1)
                     {
                         case 1: delete_first();break;
                         case 2: delete_node();break;
                         case 3: delete_end();break;
                         default: cout<<"invalid choice";
                     }
                     break;
            case 3 : display_list();
                     break;
            case 4 : exit(0);
            default: cout<<"invalid choice";
        }
    }
    return 0;
}
