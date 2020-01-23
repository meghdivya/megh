#include<iostream>
using namespace std;


void normal_print(int A[4][4], int r, int c) {
    for(int i=0; i<r; ++i) {
        for(int j=0; j<c; ++j) {
            cout<<A[i][j] << ",";
        }
    }
}
int A[4][4] = { {1,2,3,4},
                {5,6,7,8},
                {9,10,11,12},
                {13,14,15,16}};

void spiral_print(int A[4][4], int r, int c) {
    int top_row = 0, last_row = r-1, left_col=0, right_col=c-1;
    cout<<"r = "<<r<<", c = "<<c<<endl;
    int i;
    while(top_row<=last_row && left_col<=right_col) {
        i=left_col;
        while(i<=right_col) {
            cout<<A[top_row][i]<<",";
            ++i;
        }
        ++top_row;
        i=top_row;
        while(i<=last_row) {
            //cout<<"debug: i="<<i<<", right_col="<<right_col<<", val=="<<A[i][right_col]<<endl;
            cout<<A[i][right_col]<<",";
            ++i;
        }
        --right_col;
        i=right_col;
        while(i>=left_col) {
            cout<<A[last_row][i]<<",";
            --i;
        }
        last_row--;
        i=last_row;
        while(i>=top_row) {
            cout<<A[i][left_col]<<",";
            --i;
        }
        ++left_col;
    }
    return;
}
int main() {
    //normal_print(A, 3, 4);
    spiral_print(A, 4, 4);
    return 0;
    
}
