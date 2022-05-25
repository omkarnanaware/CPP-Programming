#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

class SinglyCLL
{
    private:            //Characteristics
        PNODE Head;
        PNODE Tail;

    public:             //Behaviour
        SinglyCLL();


          //~SinglyCLL();

        void InsertFirst(int);
        void InserLast(int);
        void InsertAtPos(int,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos();

        void Display();
        int Count();

 
    
};


        SinglyCLL::SinglyCLL()
        {
            Head = NULL;
            Tail = NULL;
        }

        //~SinglyCLL();
        
        void SinglyCLL::InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if((Head == NULL) && (Tail == NULL) )   //if LL is empty
            {
                Head = newn;
                Tail = newn;

            }
            else    //if LL contains atleast one node
            {
                newn -> next = Head;
                Head = newn;

            }

        Tail -> next = Head;
        }
        void SinglyCLL::InserLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if((Head == NULL) && (Tail == NULL) )   //if LL is empty
            {
                Head = newn;
                Tail = newn;

            }
            else    //if LL contains atleast one node
            {
                Tail -> next = newn;
                Tail = newn;

            }

        }
        void SinglyCLL::InsertAtPos(int no,int ipos)
        {

        }


        void SinglyCLL::DeleteFirst()
        {

        }
        void SinglyCLL::DeleteLast()
        {

        }
        void SinglyCLL::DeleteAtPos()
        {

        }


        void SinglyCLL::Display()
        {
            PNODE temp = Head;

            if(Head == NULL && Tail == NULL)
            {
                return;
            }
            
            do
            {
                cout<<temp->data<<"\t";
                temp = temp -> next;
            }while(temp != Head);
            
            cout<<endl;
        }
        int SinglyCLL::Count()
        {
            int iCnt=0;

            PNODE temp = Head;

            if(Head == NULL && Tail == NULL)
            {
                return 0;
            }
            else
            {
                do
                {
                    iCnt++;
                    temp = temp ->next;
                } while (temp != Head);
            
            }



        return iCnt;
        }




int main()
{   int iRet = 0;
    SinglyCLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
 
 
    obj.InserLast(101);
    obj.InserLast(111);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are:"<<iRet<<endl;

    return 0;
}