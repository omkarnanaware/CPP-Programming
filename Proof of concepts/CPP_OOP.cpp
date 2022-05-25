#include <iostream>
using namespace std;

class Number
{   

    private:
    int iNo;
    int iFact;
    
    public:
    void Accept()       //Getter
    {
        cout<<"Enter the no\n";
        cin>>iNo;
    }

    void Display()      //Setter
    {

        cout<<"Value is :"<<this->iNo<<"\n";


    }


    int Factorial()
    {

        int iFact = 1;
        int iCnt = 0;

        for(iCnt = 1;iCnt <= iNo;iCnt++)
        {

            iFact *=iCnt;   //iFact = iFact * iCnt;

        }

        return iFact;

    }


};


int main()
{   
    int iRet = 0;
    Number nobj;

    nobj.Accept();
    nobj.Display();

    iRet = nobj.Factorial();

    cout<<"Factorial:"<<iRet;


}