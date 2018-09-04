#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double calculate_sum(double D, double A, double M, double B, double X, double min_month)
{
    double min_guess = floor(min_month) * 2;
    //cout<<"min-guess = "<<min_guess<<endl;
    double min_sum = D + (M*A) + ((min_guess-M)/2)*A + ((min_guess-M)/2)*B - B;
    //cout<<"min-sum= "<<min_sum<<endl;
    int i = 0;
    while(min_sum <X)
    {
        if(i%2==0)
            min_sum = min_sum + B;
        else
            min_sum = min_sum + A;
        i++;
    }
    if(i==0)
        i++;

    return min_guess+i-1;

}

int min_months_f1(int D, int A, int M, int B, int X)
{
    int sum = D;
    int months = 0;
    int counter = 0;
    while(X > sum)
    {
        if(months<= M)
        {
            sum = sum + A;
            months++;
        }
        else
        {
            if(counter%2==0)
            {
                sum = sum + B;
            }
            else
            {
                sum = sum + A;
            }
            months++;
            counter++;
        }

    }
    return months;
}

int min_months_f2(int D, int A, int M, int B, int X)
{
    int sum_diff = X - D;
    if(sum_diff == 0)
    {
        return 0;
    }
    else if(sum_diff <= M*A)
    {
        return ceil(sum_diff/A);
    }
    else
    {
        int min_month = M;
        sum_diff = sum_diff - M*A;
        if(sum_diff > B)
        {
            sum_diff = sum_diff -B;
            min_month++;
            int max_months = min_month + 2*(sum_diff/(A+B));
            cout<<"max-month = "<<max_months<<endl;
            int Aa = A*max_months;
            int Bb = B*max_months;
            if(sum_diff <= (Aa + Bb))
            {
                return max_months;
            }
            else
            {
                if(sum_diff <= (Aa+Bb+A))
                    return max_months+1;
                else
                    return max_months+2;
            }

#if 0
            while(sum_diff>=0)
            {
            }
            if((sum_diff - B) >= A)
            {
                int max_months = min_month + ceil(2*sum_diff/(A+B));
                int Aa = max_months*A;
                int Bb = max_months*B;

                if(sum_diff - Aa - Bb - B -A >= 0)
                {
                    return max_months-2;
                }
                else if(sum_diff - Aa - Bb - A >= 0)
                {
                    return max_months-1;
                }
                return max_months;

            }
            else{
            return min_month+2;
            }
#endif
        }
        else
        {
            return min_month+1;
        }

    }
}

int main() {
    int T;
    cin >> T;
    int D,A,M,B,X;
    vector<int> output;
    for(int i=0; i<T; i++)
    {
        cin >> D >> A >> M >> B >> X;
        //output.push_back(min_months_f1(D,A,M,B,X));
        output.push_back(min_months_f2(D,A,M,B,X));
#if 0
        int f1 = D + M*A;
        if((X-D)/A == 0)
        {
            return 1;
        }
        else
        {

        }
        if(f1>X)


        double min_month = ((double)X - (double)D - ((double)M-1)*(double)A + (double)B)/((double)A+(double)B);
        //cout<<calculate_sum(D,A,M,B,X,min_month)<<endl;
        output.push_back(calculate_sum(D,A,M,B,X,min_month));
#endif
    }
    for(auto it=output.begin(); it!=output.end(); ++it)
        cout<<*it<<endl;
    return 0;
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here

