#ifndef BIG_REAL_LIBRARY_H
#define BIG_REAL_LIBRARY_H
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include<sstream>
#include <regex>
#pragma once
bool valid=true;
using namespace std;
class BigReal
{
private:
    char sign ='+';
    string integer,fraction,greal;
public:
    BigReal();

    BigReal(string real);
    friend ostream&operator << (ostream&output,BigReal&s)
    {
        output<<s.greal;
        return output;
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
    };
};

BigReal::BigReal()
{
    return;
}
BigReal :: BigReal(string real) {
    valid = true;
    greal = real;
    if (regex_match(real, regex("[+-]?\\d*.?\\d+"))) {
        if (real[0] == '-') {
            sign = '-';
            real[0] = '0';
            real.erase(0, 1);
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
            if (sign == '+')
                greal = integer + "." + fraction;
            else
                greal = sign + integer + "." + fraction;
        } else {
            greal = real;
        }

    } else {
        cout << "The Number is Not Valid!\n";
        valid = false;
    }
}

#endif //BIG_REAL_LIBRARY_H
