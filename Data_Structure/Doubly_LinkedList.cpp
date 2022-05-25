#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
    struct node * prev;

};



typedef struct node NODE ;
typedef struct node * PNODE;


class Doubly_LinkedList
{
    private:
        PNODE Head;
    
    public:
        Doubly_LinkdeList();
        ~Doubly_LinkedList();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};


Doubly_LinkedList::Doubly_LinkdeList()
{
    Head = NULL;
}

Doubly_LinkedList:: ~Doubly_LinkedList()
{
    PNODE temp = NULL, dtemp = NULL;

    temp = Head;

    while(temp != NULL)
    {
        dtemp = temp;
        temp = temp -> next;
        delete dtemp;
    }


}


void Doubly_LinkedList::InsertFirst(int no)
{
    PNODE newn = NULL;
    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;


    if(Head == NULL)
    {
        Head = newn;
    }

    else
    {
        newn -> next = Head;
        Head -> prev = newn;
        Head = newn;

    }
}


void Doubly_LinkedList::InsertLast(int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;


    if(Head == NULL)
    {
        Head = newn;
    }

    else
    {
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete(temp -> next);
        temp -> next = NULL;

    }


}


void Doubly_LinkedList::DeleteFirst()
{
    PNODE temp = NULL;
    temp = Head;
    if(Head == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }

    Head = Head -> next;
    Head -> prev = NULL;
    delete temp;

}

void Doubly_LinkedList::DeleteLast()
{
    PNODE temp = NULL;
    
    if(Head == NULL)
    {
        cout<<"Empty LL\n";
        return;
    }
    
    
    else
    {
        temp = Head;

        while (temp ->next ->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
        
    }

}


void Doubly_LinkedList::InsertAtPos(int no,int pos)
{   
    int iCnt = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    if(pos < 1 || pos > (size + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    else if(pos == 1)
    {
        InsertFirst(no);
    }

    else if(pos == (size+1))
    {
        InsertLast(no);
    }

    else
    {
        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        for(iCnt = 1; iCnt < (pos -1);iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        newn -> prev = temp;
        temp -> next = newn;

    }



}


void Doubly_LinkedList::DeleteAtPos(int pos)
{
     int iCnt = 0;

    PNODE temp = NULL;

    if(pos < 1 || pos > (size))
    {
        cout<<"Invalid position\n";
        return;
    }

    else if(pos == 1)
    {
        InsertFirst(no);
    }

    else if(pos == (size+1))
    {
        InsertLast(no);
    }

    else
    {
        for(iCnt = 1; iCnt < (pos -1);iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp ->next -> prev = temp;



    }


}


void Doubly_LinkedList::Display()
{
    PNODE temp = NULL;

    temp = Head;
    while(temp != NULL)
    {
        cout << temp -> data;
        temp = temp -> next;
    }



}


int Doubly_LinkedList::Count()
{
    PNODE temp = NULL;
    int iCnt = 0;

    temp = Head;
    while (temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    return iCnt;
}

int main()
{
    Doubly_LinkedList obj;

    obj.InsertFirst(50);
    obj.InsertFirst(40);
    obj.InsertFirst(30);
    obj.InsertFirst(20);
    obj.InsertFirst(10);

    obj.Display();

    return 0;
}