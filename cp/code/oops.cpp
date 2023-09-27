// C++ program to demonstrate the working of copy elision
// via RVO
#include <iostream>
using namespace std;
 
class GFG {
public:
	int a = 1;
    GFG() { cout << "Default Constructor\n"; }
    GFG(const GFG&) // Copy Construcctor
    {
        cout << "Copy Constructor\n";
    }
};
 
GFG func()
{
	GFG g;//calls default constructor.
	return g; // RVO example //calls copy constructor
}
 
int main()
{
    // GFG G = func();
	GFG G = func();
	//above line initializes a temp G.
	//
    return 0;
}