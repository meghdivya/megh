
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

int main() {
    int T;
    cin >> T;
    int D,A,M,B,X;
    vector<int> output;
    for(int i=0; i<T; i++)
    {
        cin >> D >> A >> M >> B >> X;
        double min_month = ((double)X - (double)D - ((double)M-1)*(double)A + (double)B)/((double)A+(double)B);
        //cout<<calculate_sum(D,A,M,B,X,min_month)<<endl;
        output.push_back(calculate_sum(D,A,M,B,X,min_month));
    }
    for(auto it=output.begin(); it!=output.end(); ++it)
        cout<<*it<<endl;
    return 0;
}
