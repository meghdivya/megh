#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#if 0
int years[] = {2010, 2015, 2016, 2017, 2019};
int bsearch(int[] years, int input)
{
    if(input > 2019 || input < 2010)
        return -1;

    if(input == 2016)
    {
        return 1;
    }
    else if(input > 2016)
    {
        if(input == 2017 || input == 2019)
            return 1;
    }
    else if(input<2016)
    {
        if(input == 2010 || input == 2015)
        {
            return 1;
        }
    }
    return -1;
}
#endif

int main()
{
    int T,N;
    cin>>T;
    for(int i = 0; i<T; i++)
    {
        int year;
        cin >> year;
        if(year == 2010 || year == 2015 || year == 2017 || year == 2016 || year == 2019)
        {
            printf("HOSTED\n");
        }
        else
        {
            printf("NOT HOSTED\n");
        }
    }
    return 0;
}
