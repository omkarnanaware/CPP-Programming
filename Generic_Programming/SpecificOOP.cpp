using namespace std;
#include<iostream>

class Arithematic
{   
    public:
        int No1;
        int No2;

        Arithematic(int a, int b )
        {
            this->No1 = a;
            this->No2 = b;
        }

        int Addition()
        {
            int ans = 0;
            ans = No1 + No2;
            return ans;
        }

        int Substraction()
        {
            int ans = 0;
            ans = No1 - No2;
            return ans;
        }
};




int main()
{
    Arithematic obj(10,11);
    int ret = obj.Addition();
    cout<<"Addition :"<<ret<<"\n";
    int ret = obj.Substraction();
    cout<<"Substraction :"<<ret<<"\n";
    


    return 0;
}
