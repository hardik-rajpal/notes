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
int mymax(int a,int b){
    cout<<"int max"<<endl;
    return 0;
}
// double mymax(double a,double b){
//     cout<<"double max"<<endl;
//     return 0;
// }
int main()
{   
    cout<<mymax(1.1,2.3)<<endl;
    return 0;
}