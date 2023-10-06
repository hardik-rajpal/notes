// C++ program to demonstrate the working of copy elision
// via RVO
#include <bits/stdc++.h>
using namespace std;
class Base{
    public:
    ~Base(){
        cout<<"DB";
    }
};
class Derived: public Base{
    ~Derived(){
        cout<<"DD";
    }
};
int safemod(int a, int m){
    return (m + (a % m)) % m;
}
int main()
{   
    Base *b;
    b = new Derived;
    delete b;
    return 0;
}