#include <iostream>
#include <map>

using namespace std;

int main() {
    int B, An, Cn, temp, Amax = 0, Amin = 100, Cmax = 0, Cmin = 100, i = 0, lower, upper;
    int A[100];
    int C[100];
    map<int,int> B_map;
    cin >> An;
    while(An > i) {
        cin >> temp;
        if(temp > Amax) {
            Amax = temp;
        }
        if(temp < Amin) {
            Amin = temp;
        }
        A[i] = temp;
        
        i++;
    }
    
   cin >> Cn;
   i = 0;
   while(Cn > i) {
        cin >> temp;
        if(temp > Cmax) {
            Cmax = temp;
        }
        if(temp < Cmin) {
            Cmin = temp;
        }
        C[i] = temp;
        
        i++;
    }
    lower = Cmin - Amin;
    upper = Cmax - Amax;
    for(int i = 0; i < Cn; i++) {
        for(int j = 0; j < An; j++) {
            if(C[i] >= A[j]) {
               B = C[i] - A[j];
               int ref = B_map[B];
               ref++;
               B_map[B] = ref;
            }
        }
    }
    for(auto it = B_map.begin(); it != B_map.end(); ++it)
    {
        if(it->second == An){
            cout<<it->first<<"";
        }
    }
}
