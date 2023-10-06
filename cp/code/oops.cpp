// C++ program to demonstrate the working of copy elision
// via RVO
#include <bits/stdc++.h>
using namespace std;
class Storage{
    int val = 1023;
    public:
    friend class Display;
};
class Base{
    
};
class Display: public Base{
    public:
    Display(){}
    void print(const Storage& storage){
        cout<<storage.val<<endl;
    }
    Display(const Display&d) = delete;
};
int safemod(int a, int m){
    return (m + (a % m)) % m;
}
int main()
{   
    int a = -7;
    cout<<(a/2)<<endl;
    return 0;
}