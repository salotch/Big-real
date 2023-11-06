#ifndef BIG_REAL_LIBRARY_H
#define BIG_REAL_LIBRARY_H
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include<sstream>
#include <regex>
# pragma once
bool valid=true;
using namespace std;
class BigReal
{
private:
    string integer,fraction,greal;
public:
    char sign ='+';
    BigReal();//empty constructor
    BigReal(string real);//parameterize constructor to check if the number valid
    friend ostream&operator << (ostream&output,BigReal&s)
    {
        output<<s.greal;
        return output;
    }
    bool operator<(const BigReal& c2) {
        int x,y;
        int len1=integer.size();
        int len2=c2.integer.size();
        if (integer[0]=='-'&&c2.integer[0]!='-'){return true;}
        if (c2.integer[0]=='-'&&integer[0]!='-')return false;
        int count=0;
        if(len1<len2)
        {
            return true;
        }
        else if (len1==len2)
        {
            for(int i =0;i<integer.size();i++)
            {
                if (integer[i]<c2.integer[i])
                {
                    return true;
                    break;
                }
                else if (integer[i]<c2.integer[i])
                {
                    return false;
                    break;
                }
                else
                    count++;
            }
            if(count==integer.size())
            {count=0;
                for (int i =0;i<fraction.size();i++)
                { if (fraction[i]<c2.fraction[i])
                    {
                        return true;
                        break;
                    }
                    else if (fraction[i]>c2.fraction[i])
                    {
                        return false;
                        break;
                    }
                    else
                        count++;
                }
                if(count==fraction.size())
                    return false;
            }
        }
        return false;
    }
    bool operator>(const BigReal& c2) {
        int x,y;
        int len1=integer.size();
        int len2=c2.integer.size();
        if (integer[0]=='-'&&c2.integer[0]!='-'){return false;}
        if (c2.integer[0]=='-'&&integer[0]!='-')return true;
        int count=0;
        if(len1>len2)
        {
            return true;
        }
        else if (len1==len2)
        {
            for(int i =0;i<integer.size();i++)
            {
                if (integer[i]>c2.integer[i])
                {
                    return true;
                    break;
                }
                else if (integer[i]<c2.integer[i])
                {
                    return false;
                    break;
                }
                else
                    count++;
            }
            if(count==integer.size())
            {count=0;
                for (int i =0;i<fraction.size();i++)
                { if (fraction[i]>c2.fraction[i])
                    {
                        return true;
                        break;
                    }
                    else if (fraction[i]<c2.fraction[i])
                    {
                        return false;
                        break;
                    }
                    else
                        count++;
                }
                if(count==fraction.size())
                    return false;
            }
        }
        return false;
    }
    BigReal operator+(BigReal c2) {
        BigReal s3;
        string s0;
        int ch = 0;
        int i1 = greal.find(".");
        int i2 = c2.greal.find(".");
        if (i1 > 0 && i2 < 0) {
            int no_after = greal.size() - (i1 + 1);
            c2.greal = c2.greal + ".";
            for (int i = 0; i < no_after; i++) {
                c2.greal = c2.greal + "0";
            }
        } else if (i1 < 0 && i2 > 0) {
            int no_after = c2.greal.size() - (i2 + 1);
            greal = greal + ".";
            for (int i = 0; i < no_after; i++) {
                greal = greal + "0";
            }
        } else if (i1 > 0 && i2 > 0) {
            int no_after = c2.greal.size() - (i2 + 1);
            int no_after1 = greal.size() - (i2 + 1);
            if (no_after > no_after1)
                for (int i = 0; i < no_after - no_after1; i++) {
                    greal = greal + "0";
                }
            else
                for (int i = 0; i < no_after1 - no_after; i++) {
                    c2.greal = c2.greal + "0";
                }
        }
        if (greal[0] == '-' && c2.greal[0] == '-') {
            greal.erase(0, 1);
            c2.greal.erase(0, 1);
            ch = 1;
        }

        if (c2.greal.size() > greal.size()) {
            int size = c2.greal.size() - greal.size();
            string zero;
            for (int i = 0; i < size; i++)
                zero = zero + "0";
            greal = zero + greal;
        } else if (c2.greal.size() < greal.size()) {
            int size = greal.size() - c2.greal.size();
            string zero;
            for (int i = 0; i < size; i++)
                zero = zero + "0";
            c2.greal = zero + c2.greal;

        }
        int x, carry = 0, n;
        for (int i = greal.size() - 1; i >= 0; --i) {
            if (greal[i] == '.') {
                --i;
                s3.greal += ".";
            }
            if (i != 0) {
                if (carry == 1) {
                    x = ((greal[i] - '0') + (c2.greal[i] - '0') + 1);
                    carry = 0;
                } else if (carry == 0) {
                    x = ((greal[i] - '0') + (c2.greal[i] - '0'));
                }

                if (x < 10)
                    s3.greal += to_string(x);
                else {
                    x = x % 10;
                    s3.greal += to_string(x);
                    carry = 1;
                }
            } else if (i == 0 && greal[i] != '-' && c2.greal[i] != '-') {
//                if(carry==1)
                x = ((greal[i] - '0') + (c2.greal[i] - '0'));
                if (carry == 1) {
                    x = x + 1;
                    carry = 0;
                }
                s0 = to_string(x);
                reverse(s0.begin(), s0.end());
                s3.greal += s0;
            }

        }
        if (ch == 1)
            s3.greal += "-";
        reverse(s3.greal.begin(), s3.greal.end());
        return s3.greal;
//
    }
    BigReal operator-(BigReal c2) {
        BigReal s3;
        string s0;
        int ch=0;
        if(integer[0]!='-'&&c2.integer[0]=='-')
        {
            c2.integer.erase(0,1);
            s3=operator+(c2);
            return s3;
        }
        else if(integer[0]=='-'&&c2.integer[0]!='-')
        {
            c2.integer='-'+c2.integer;
            s3=operator+(c2);
            return s3;
        }
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
            string swap;
            integer.erase(0,1);
            c2.integer.erase(0,1);
            c2.integer.swap(integer);
        }
//
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
        for(int i=0;i<integer.size();i++)
        {
            if(integer[i]=='.')
                ++i;
            if(integer[i]-'0'<c2.integer[i]-'0')
            {
                ch=1;
                c2.integer.swap(integer);
            }
        }
        int x,borrow=0,n;
        for(int i=integer.size()-1;i>=0;--i) {
            if (integer[i] == '.') {
                --i;
                s3.integer += ".";
            }
            if(integer[i]<c2.integer[i])
            {
                if(borrow==1) {
                    x = (10 + (integer[i] - '0') - (c2.integer[i] - '0')-1);
                    borrow=0;
                }
                else {
                    x = (10 + (integer[i] - '0') - (c2.integer[i] - '0'));
                }
                s3.integer+=to_string(x);
                borrow=1;

            }
            else
            {
                if(borrow==1)
                {
                    x=((integer[i]-'0')-(c2.integer[i]-'0')-1);
                    borrow=0;

                }
                else
                    x=((integer[i]-'0')-(c2.integer[i]-'0'));
                s3.integer+=to_string(x);
            }
        }
        if(ch==1)
            s3.integer+="-";
        reverse(s3.integer.begin(),s3.integer.end());
        return s3.integer;
    }
    bool operator==(const BigReal& c2) {
        int x,y;
        int len1=integer.size();
        int len2=c2.integer.size();
        if (integer[0]=='-'&&c2.integer[0]!='-'){return false;}//if the signs is different the numbers is different
        if (c2.integer[0]=='-'&&integer[0]!='-')return false;
        int count=0;
        if(len1>len2)
        {
            return false;
        }
        else if (len1==len2)
        {
            for(int i =0;i<integer.size();i++)
            {
                if (integer[i]>c2.integer[i])
                {
                    return false;
                    break;
                }
                else if (integer[i]<c2.integer[i])
                {
                    return false;
                    break;
                }
                else
                    count++;
            }
            if(count==integer.size())
            {count=0;
                for (int i =0;i<fraction.size();i++)
                { if (fraction[i]>c2.fraction[i])
                    {
                        return false;
                        break;
                    }
                    else if (fraction[i]<c2.fraction[i])
                    {
                        return false;
                        break;
                    }
                    else
                        count++;
                }
                if(count==fraction.size())
                    return true;
            }
        }
        return false;
    }
};

BigReal::BigReal()
{
    return;
}
BigReal :: BigReal(string real) {
    valid = true;//to check if the number is valid or not
    if (regex_match(real, regex("[+-]?\\d*.?\\d+"))) //using regular expression i have to check tht the first index have +or-or neither after that digits after that have at most dot after that digits
        {
        if (real[0] == '-') {
            sign = '-';//here to split the real
        } else if (real[0] == '+') {
            sign = '+';
            real[0] = '0';
            real.erase(0, 1);
        }
        if (real.find('.') != -1) {
            integer = real.substr(0, real.find('.'));
            fraction = real.substr(real.find('.') + 1, real.size());
            if (fraction.size() == 0)
                fraction = "0";
            if (integer.size() == 0)
                integer = "0";
            greal = integer + "." + fraction;//to save the big real after make it suitable

        } else {
            greal = real;//if the number does not have dot
            integer=real;
        }

    }
    else//if the number not valid
    {
        cout << "The Number is Not Valid!\n";
        valid = false;
    }
}

#endif //BIG_REAL_LIBRARY_H
