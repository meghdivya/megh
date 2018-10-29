#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
#define MAX_DIST 598 

typedef struct{
    int rowi;
    int coli;
    int val;
}input;

int main()
{
    int T,maxrow,maxcol;
    cin>>T;
    int distance_arr[599] = {0};
    input input_arr[300*300] = {0};
    for(int i=0; i<T; i++)
    {
        cin>>maxrow>>maxcol;
        //vector<string> input;
        int counter = 0;
        for(int j=0; j<maxrow; j++)
        {
            string s;
            cin>>s;
            for(int k=0; k<maxcol; k++)
            {
                input_arr[counter].val = (s[k]=='1');
                input_arr[counter].rowi = j;
                input_arr[counter].coli = k;
                counter++;
            }
        }
        for(int l = 0; l<counter; l++)
        {
            if(!input_arr[l].val)
                continue;
            for(int m = l+1; m<counter; m++)
            {
                if(!input_arr[m].val)
                    continue;
                int dist = abs(input_arr[m].coli - input_arr[l].coli) + abs(input_arr[m].rowi - input_arr[l].rowi);
                distance_arr[dist]++;
            }
        }
        for(int i=1; i<=(maxrow+maxcol-2); i++)
        {
            cout<<distance_arr[i]<<" ";
        }
        memset(distance_arr, 0, 599*sizeof(int));

     }
    return 0;
}

