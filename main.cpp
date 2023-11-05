#include <iostream>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <vector>
#include <string>
#include<sstream>
using namespace std;
class BigReal
{
private:
    string integer,fraction;
public:
    BigReal()
    {
        return;
    }
    BigReal(string a)
    {
        integer=a;
    }
    BigReal operator+(BigReal c2) {
        BigReal s3;
        string s0;
        int ch=0;
        int i1 =integer.find(".");
        int i2=c2.integer.find(".");
        if(i1>0&&i2<0)
        {
            int no_after=integer.size()-(i1+1);
            c2.integer=c2.integer+".";
            for(int i=0;i<no_after;i++)
            {
                c2.integer=c2.integer+"0";
            }
        }
        else if(i1<0&&i2>0)
        {
            int no_after=c2.integer.size()-(i2+1);
            integer=integer+".";
            for(int i=0;i<no_after;i++)
            {
                integer=integer+"0";
            }
        }
        else if(i1>0&&i2>0)
        {
            int no_after=c2.integer.size()-(i2+1);
            int no_after1=integer.size()-(i2+1);
            if(no_after>no_after1)
                for(int i=0;i<no_after-no_after1;i++)
                {
                    integer=integer+"0";
                }
            else
                for(int i=0;i<no_after1-no_after;i++)
                {
                    c2.integer=c2.integer+"0";
                }
        }
        if(integer[0]=='-'&&c2.integer[0]=='-')
        {
            integer.erase(0,1);
            c2.integer.erase(0,1);
            ch=1;
        }

        if(c2.integer.size()>integer.size())
        {
            int size =c2.integer.size()-integer.size();
            string zero;
            for(int i=0;i<size;i++)
                zero=zero+"0";
            integer=zero+integer;
        }
        else if(c2.integer.size()<integer.size())
        {
            int size =integer.size()-c2.integer.size();
            string zero;
            for(int i=0;i<size;i++)
                zero=zero+"0";
            c2.integer=zero+c2.integer;

        }
        int x,carry=0,n;
        for(int i=integer.size()-1;i>=0;--i)
        {
            if(integer[i]=='.') {
                --i;
                s3.integer += ".";
            }
            if(i!=0) {
                if(carry==1) {
                    x = ((integer[i] - '0') + (c2.integer[i] - '0')+1);
                    carry=0;
                }
                else if(carry==0)
                {
                    x= ((integer[i] - '0') + (c2.integer[i] - '0'));
                }

                if (x < 10)
                    s3.integer += to_string(x);
                else {
                    x = x % 10;
                    s3.integer += to_string(x);
                    carry=1;
                }
            }
            else if (i==0 && integer[i]!='-'&&c2.integer[i]!='-')
            {
//                if(carry==1)
                x = ((integer[i] - '0') + (c2.integer[i] - '0'));
                if(carry==1) {
                    x = x + 1;
                    carry=0;
                }
                s0=to_string(x);
                reverse(s0.begin(),s0.end());
                s3.integer += s0;
            }

        }
        if(ch==1)
            s3.integer+="-";
        reverse(s3.integer.begin(),s3.integer.end());
        return s3.integer;
//
   }
    friend ostream&operator << (ostream&output,BigReal&s)
    {
        output<<s.integer;
        return output;
    }
};

int main()
{
    string no1,no2;
    cin>>no1>>no2;
   BigReal op(no1),op1(no2),op2;
   op2=op+op1;
   cout <<op2;




}



