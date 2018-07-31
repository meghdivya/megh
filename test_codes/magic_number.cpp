#include<iostream>
using namespace std;


// Function to find nth magic numebr
int nthMagicNo(int n)
{
    int pow = 1, answer = 0;
 
    // Go through every bit of n
    while (n)
    {
       pow = pow*5;
 
       // If last bit of n is set
       if (n & 1)
         answer += pow;
 
       // proceed to next bit
       n >>= 1;  // or n = n/2
      cout <<" value of n = " << n <<endl;
    }
    return answer;
}

void bin(unsigned int n)
{
    /* step 1 */
    if (n > 1)
        bin(n/2);
 
    /* step 2 */
    cout<< n%2;
}


int main()
{
    int i;
    while(1)
    {
        cout<<"Enter n for magic number, -1 to exit\n";
        cin >> i;
        if(i == -100)
            return 0;
        //cout << "Magic number is " << nthMagicNo(i)<< endl;
        //bin(nthMagicNo(i));
        bin(i);
        cout<<endl;

    }
    return 0;

}

#if 0
unsigned long long return_binary(int n)
{
    int num = n;
    int div, remainder =0;
    unsigned long long binary = 0;
    while(num > 1)
    {
        remainder = num%2;
        if(remainder != 0)
        {
            binary = 1 + binary; 
        }
        else
        {
            if(binary == 0)
                binary = 1;
            binary = binary*10;
        }
        num = num/2;
    }
    return binary;
}

#endif
