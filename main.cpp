#include "library.h"
using namespace std;
int main()
{string no1,no2;
    string choice;
    cout<<"                    Welcome to BigReal Operations\n"<<"Enter the operation you want to do on Two-BigReal numbers\n"
    <<"+\n"<<"-\n"<<"<\n"<<">\n"<<"==\n"<<"your choice is: ";
    cin>>choice;
    do
    {
    cout<<"please enter the first number: ";
    cin.ignore();
    getline(cin,no1);
    BigReal t1(no1);
    }while (!valid);
    do
    {
        cout<<"please enter the second number: ";
        getline(cin,no2);
        BigReal t2(no2);
    }while (!valid);
    BigReal op2,op(no1),op1(no2);
    if(choice=="+")
    {
        op2 = op + op1;
        cout << "Summation = ";
        cout << op2;
    }
    else if(choice==">")
    {
       if(op.sign==op1.sign&&op.sign=='-')
           cout<<((op > op1)? "No" : "Yes");
       else
        cout<<((op > op1)? "Yes" : "No");
    }
    else if(choice=="<")
    {
        if(op.sign==op1.sign&&op.sign=='-')
            cout<<((op < op1)? "No" : "Yes");
        else
            cout<<((op < op1)? "Yes" : "No");
    }
    else if(choice=="-")
    {
        op2 = op - op1;
        cout << "Difference = ";
        cout << op2;
    }
    else if(choice=="==")
    {
        cout<<((op == op1)? "Yes" : "No");
    }
}
