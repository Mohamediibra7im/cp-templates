// @brief: This code provides a way to read and print large integers using __int128 in C++.

#include<bits/stdc++.h>
using namespace std;

__int128 read()
{
    __int128 x = 0;
    int f = 1;
    char ch = getchar();

    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
    {
        print(x / 10);
    }
    putchar(x % 10 + '0');
}

int main()
{

    __int128 my_large_number = read();

    print(my_large_number);
    putchar('\n');


}
