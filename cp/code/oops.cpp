// C++ program to demonstrate the working of copy elision
// via RVO
#include <bits/stdc++.h>
using namespace std;
class Date{
    public:
    int m,y,d;
    Date(){
        m=9;y=2023;d=28;
    }
    int print(int arg){
        cout<<m<<" "<<d<<" "<<y<<endl;
        srand(arg);
        return rand();
    }
    const int print()const{return m;}
    // int const print(){return 0;}
};

int main()
{
    const Date d;
    time_t timev;
    cout<<d.print()<<endl;
    return 0;
}