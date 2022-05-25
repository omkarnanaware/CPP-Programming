#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node * next;

};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


class Singly_LinkedList
{
    private:
        PNODE Head;

    public:
        Singly_LinkedList();
        ~Singly_LinkedList();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();

};

Singly_LinkedList::Singly_LinkedList()
{
    Head = NULL;
}

Singly_LinkedList::~Singly_LinkedList()
{
    PNODE temp,deltemp;
    temp = Head;

    while(temp != NULL)
    {   
        deltemp = temp;
        temp = temp -> next;
        free(deltemp);

    }

}



void Singly_LinkedList::InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }

    else
    {
        newn -> next = Head;
        Head = newn;
    }

}

void Singly_LinkedList::InsertLast(int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }

    else
    {
        temp = Head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        
    }
  


}

void Singly_LinkedList::InsertAtPos(int no,int pos)
{
    int iCnt = 0;
    int size = 0;

    size = Count();


    PNODE temp = NULL; 
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if(pos < 1 || pos > (size + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    else if(pos == 1)
    {
        InsertFirst(no);
    }

    else if(pos == (size + 1))
    {
        InsertLast(no);
    }

    else
    {
    temp = Head;
    for(iCnt = 1;iCnt < (pos - 1);iCnt++)
    {
        temp = temp -> next;
    }

    newn -> next = temp -> next;
    temp -> next = newn;


    }
}

void Singly_LinkedList::DeleteFirst()
{
    PNODE temp = NULL;
    temp = Head;

    Head = Head -> next;

    delete(temp);

}

void Singly_LinkedList::DeleteLast()
{
    struct node * temp = NULL;

    if(Head == NULL)
    {
        printf("LL is empty\n");
        return;
    }

    else
    {
        temp = Head;

        while(temp -> next -> next != NULL)
        {
            temp = temp ->next;
        }

        free(temp->next);
        temp -> next = NULL;


    }


}


void Singly_LinkedList::DeleteAtPos(int pos)
{
    PNODE temp1 = NULL ,temp2 = NULL;
    int iCnt = 0;
    int size = 0;

    size = Count();

    if(pos < 1 || pos > (size))
    {
        printf("Invalid Position\n");
        return;
    }

    else if(pos == 1)
    {
        DeleteFirst();
    }

    else if(pos == (size))
    {
        DeleteLast();
    }

    else
    {
        temp1 = Head;
        for(iCnt = 1;iCnt < (pos - 1);iCnt++)
        {
            temp1 = temp1 -> next;
        }
        temp2 = temp1 -> next;

       temp1 -> next = temp1-> next -> next;
       free(temp2);
    }


}



void Singly_LinkedList::Display()
{   
    PNODE temp = NULL;
    temp = Head;
    

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";

}

int Singly_LinkedList::Count()
{
    int Count = 0;
    PNODE temp = NULL;
    temp = Head;

    while(temp != NULL)
    {
        Count++;
        temp = temp -> next;
    }

    return Count;
}






int main()
{
    cout<<"Printing"<<std::endl;
    Singly_LinkedList obj;
    obj.InsertFirst(10);
    obj.InsertFirst(20);
    obj.InsertFirst(30);
    obj.InsertFirst(40);
    obj.InsertFirst(50);

    obj.Display();  

    obj.InsertLast(1000);
    obj.Display();
    obj.DeleteFirst();

    obj.Display();

    obj.DeleteLast();
    obj.Display();

    obj.InsertAtPos(400,3);
    obj.Display();

    obj.DeleteAtPos(3);
    obj.Display();



    //Dynamic object creation
    Singly_LinkedList *pobj = new Singly_LinkedList();
    cout<<sizeof(pobj);

    pobj->InsertFirst(10);
    pobj->Display();



}