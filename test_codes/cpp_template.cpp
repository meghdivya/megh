#include<iostream>
#include<vector>
using namespace std;

template<typename T>
struct is_pointer { static const bool value = false; };

template<typename T>
struct is_pointer<T*> { static const bool value = true; };

template<typename T>
void skm(T) {
        cout << "is it a pointer? " << is_pointer<T>::value << endl;
}

int main()
{
    int a;
    skm(a);
    int *b;
    skm(b);
    vector<int> c;
    skm(&c);
    skm(c);
    return 0;
}

