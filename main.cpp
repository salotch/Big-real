#include "library.h"
using namespace std;
int main()
{char choice;
    cout<<"                    Welcome to BigReal Operations\n"<<"Enter the operation you want to do on Two-BigReal numbers\n"
    <<"+\n"<<"-\n"<<"<\n"<<">\n"<<"=\n"<<"your choice is: ";
    cin>>choice;
    string no1,no2;
    do
    {
    cout<<"please enter the first number:\n";
    cin>>no1;
    BigReal t1(no1);
    }while (!valid);
    do
    {
    cout<<"please enter the second number:\n";
    cin>>no2;
    BigReal t2(no2);
    }while (!valid);
    BigReal op2,op(no1),op1(no2);
    if(choice=='+')
    {
    op2=op+op1;
    cout<<"Summation = ";
    cout <<op2;
    }

}
