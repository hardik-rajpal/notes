// C++ program to demonstrate the working of copy elision
// via RVO
#include <bits/stdc++.h>
using namespace std;
class Storage{
    int val = 1023;
    public:
    friend class Display;
};
class Display{
    public:
    void print(const Storage& storage){
        cout<<storage.val<<endl;
    }
};
int main()
{   

    return 0;
}