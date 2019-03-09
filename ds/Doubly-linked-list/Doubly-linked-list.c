#include<stdio.h>
#include<conio.h>


struct node
{
    struct node *blink; //TO LINK THE NODE THAT IS BEFORE THE CURRENT NODE
    int data;
    struct node *link;  //TO LINK THE NODE THAT IS BEFORE THE CURRENT NODE

};

struct node* root=NULL,*current;
//DEFINE THE ROOT NODE,AND INITIALIZE THE POINTER OF NODE THAT POINTS TO CURRENT NODE


void addatlast()
{
    //TO ADD THE NEW NODE AND LINK IT TO LINK_LIST

    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));    //ALLOCATE THE MEMORY TO NEW NODE

    printf("\nEnter node data:");   //SCAN THE DATA FOR NODE
    scanf("%d",&temp->data);

    temp->link=NULL;
    if(root==NULL)
    {
         //IF THERE IS NO NODE IN LINKED_LIST, MAKE THIS NODE ROOT NODE AND POINTS CURRENT TO THIS NODE
         //BACKLINK AND LINK OF NODE IS SET TO NULL SINCE THERE IS ONLY ONE NODE
        root=temp;
        root->blink=NULL;
        root->link=NULL;
        current=root;
    }
    else
    {
        //SET THE NODE AFTER THE CURRENT NODE AND MAKE CURRENT POINTS TO NEW NODE
        struct node *p;
        p=root;
        if(p->link==NULL)
            temp->blink=root;

        while(p->link!=NULL)
        {
            p=p->link;
        }
        temp->blink=p;
        p->link=temp;
        current=temp;
    }
}

void addatbegin()
{

    // ADD THE NODE AT BEGIN AND MAKE THAT NODE ROOT NODE
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));


    printf("Enter node data\n");
    scanf("%d",&temp->data);


    temp->link=root;  //SET LINK OF NEW ROOT NODE TO OUR OLD ROOT NODE
    root->blink=temp; //SET BACKLINK OF THE ROOT NODE TO OUR NEW ROOT NODE

    root=temp;       //ROOT WILL POINT TO THE NEW NODE NOW
    temp->blink=NULL; //BACKLINK OF ROOT NODE IS SET TO THE NULL
}

void addafter(int x)
{

    if(x==1)
    {
        addatbegin();
        return;
    }

    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter node data: ");
    scanf("%d",&temp->data);

    if(root==NULL)
    {
        temp->blink=NULL;
        temp->link=NULL;
        root=temp;
        current=root;
        printf("\nNo node present so,Node is added as root node..\n");
    }
    else
    {
        int i=2;  //SINCE P IS POINTING ONE NODE AFTER SO I IS KEPT 2 INSTEAD OF 1
        struct node *p;
        p=root;
        while(i<x)  //i IS COUNTER THAT COUNT THE NODE UPTO GIVEN NODE
        {
            if(p->link==NULL)
            {
                //IF THERE IS NOT ENOUGH NODE THEN PROGRAME WILL BE CRASH
                //THIS CONDITION CHEACK FOR THAT AND ADD THE NODE AFTER THE LAST NODE
                //WE CAN ALSO SET THE COUNTER FOR ADDING AND DELETING THE NODE SO WE CAN DIRECTLY GET THE NUMBER OF NODE PRESENT
                printf("\nNot enough node so,added after current node..\n");
                break;
            }
            p=p->link;
            i++;
        }
        temp->link=p->link;
        temp->blink=p;
        p->link=temp;
        current=temp;
    }
}

void display()
{
    //IT CAN DISPLAY IN BOTH DIRECTION AS USER DEMAND
    int t;  //t IS FOR USER CHOICE
    printf("Enter a no 1 for printing in forward direction and 0 for printing in reverse direction:\n");
    scanf("%d",&t);
    printf("\n");

    if(root==NULL)
    {
        printf("\nNOTHING TO DISPLAY!!!\n");
        return;
    }


    if(t==1)
    {
        //PRINT IN FORWARD DIRECTION
        struct node *temp;
        temp=root;
        while(temp->link!=NULL)
        {
            printf("%d --> ",temp->data);
            temp=temp->link;
        }
        printf("%d\n",temp->data);
    }



    else if(t==0)
    {
        //PRINT IN BACKWARD DIRECTION
        struct node *temp;
        temp=current;
        while(temp->blink!=NULL)
        {
            printf("%d  <-- ",temp->data);
            temp=temp->blink;
        }
        printf("%d\n",temp->data);
    }


}


void deletefirst()
{
    //DELETE THE ROOT NODE AND MAKE ROOT NODE UPCOMING NODE
    struct node *x;
    x=root;

    if(root==NULL)
    {
        printf("Nothing to delete\n");
        return;
    }

    root=root->link;
    root->blink=NULL;

    //IF THERE WILL ONLY ONE NODE MEANS current WILL BE POINTING TO THE ROOT NODE
    //SO WE HAVE TO MAKE current POINTS TO THE ROOT WHICH WILL BE NULL
    if(current==x)
        current=root;


    printf("Node with given data is deleted!!\n");
    free(x);
}

void delete_given(int x)
{

    //THIS FUNCTION WILL DELETE THE NODE WITH DATA GIVEN BY USER
    //ONLY FISRT OCCURENCE OF GIBEN DATA WILL BE DELETED

    struct node *temp,*p;
    int flag=0;
    temp=root;

    if(root==NULL)
    {
        printf("Nothing to delete\n");
        return;
    }
    if(root->data==x)
    {
        //IF GIVEN DATA IS SITUATED AT ROOT NODE
        //THEN WE SIMPLY DELETE THAT CALL OUR FUNCTION THAT DELETE THE ROOT NODE
        deletefirst();
        return;
    }

    while(temp->link!=NULL)
    {
        if(temp->data==x)
        {
            //WHEN THE DATA MATCH TO THE NODE
            //BACKLINK OF UPCOMING NODE AND LINK OF THE PREVIOUS NODE SHOULD POINTS EACHOTHER
            p->link=temp->link;
            temp->link->blink=p;
            flag=1;    //SHOWS THAT NODE IS DELETED
            free(temp); //MEMORY ASSIGNED TO THAT NODE SHOLUD BE CLEARED NOW
            break;
        }
        p=temp;          //p LINKS TO PREVIOUS NODE OF temp FOR EVERY ITERATION
        temp=temp->link;
    }
    if(flag==1)
        printf("Node with given data is deleted!!\n");
    else if(temp->data==x)
    {
            //IF USER WANT TO DELETE THE LAST NODE POINTED BY current
            //NODE PREVIOUS OF current NODE IS NOW WILL BE current
            p->link=NULL;
            current=p;
            printf("Node with given data is deleted!!\n");
            free(temp);
    }
    else
        printf("There is no node with given data!!\n");

}
int length()
{
    //TO MEASURE THE LENGTH OF LINKED_LIST
    struct node *temp;
    int c=0;   //COUNTER COUNTING THE NODES
    temp=root;
    if(root==NULL)
        return 0;
    while(temp->link!=NULL)
    {
        c++;
        temp=temp->link;
    }
    return (c+1);
}

int main()
{
    int k,x;
    while(1)
    {
        //USER CHOICE MENU OF FUNCTIONALITY THAT OUR LINKED LIST IS PROVIDING

        printf("\nDoubly linked list operations\n");
        printf("*****************************\n");
        printf("1.Add at last\n");
        printf("2.Add at begin\n");
        printf("3.Add at given number of node\n");
        printf("4.Display linked_list\n");
        printf("5.Delete fist node\n");
        printf("6.Delete node with given data\n");
        printf("7.Length of linked_list\n");
        printf("8.Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d",&k);

        switch(k)
        {
            case 1: addatlast();
                    break;
            case 2: addatbegin();
                    break;
            case 3: printf("\nAt what position do you want to add node..\n");
                    scanf("%d",&x);
                    addafter(x);
                    break;
            case 4: display();
                    break;
            case 5: deletefirst();
                    break;
            case 6: printf("\nEnter the node data to delete that node..\n");
                    scanf("%d",&x);
                    delete_given(x);
                    break;
            case 7: printf("\nThere are %d node in linked list..\n",length());
                    break;
            case 8: return 0;
                    break;
            default:
                printf("\nInvalid number :( \n");
        }
    }
    return 0;
}
