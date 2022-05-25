using namespace std;
#include<iostream>

template <class T>
class Arithematic
{   
    public:
        T No1;
        T No2;

        Arithematic(T a, T b )
        {
            this->No1 = a;
            this->No2 = b;
        }

        T Addition()
        {
            T ans;
            ans = No1 + No2;
            return ans;
        }

        T Substraction()
        {
            T ans;
            ans = No1 - No2;
            return ans;
        }
};




int main()
{
    
    Arithematic <int>iobj(10,11);
    
    int ret=iobj.Addition();
    cout<<"Addition :"<<ret<<"\n";

    ret=iobj.Substraction();
    cout<<"Substraction :"<<ret<<"\n";

    Arithematic <double>dobj(10.9,11.5);
    
    double dret=dobj.Addition();
    cout<<"Addition :"<<ret<<"\n";

    dret=dobj.Substraction();
    cout<<"Substraction :"<<ret<<"\n";



    return 0;
}
