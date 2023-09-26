#include<bits/stdc++.h>
using namespace std;
class Shape{
    public:
    int width,height;
    virtual int area(){
        cout<<"Shape area"<<endl;
        return 0;
    };
};
class Rectangle:public Shape{
    public:
    int area(){
        cout<<"Rect Area"<<endl;
        return 0;
    }
};
class Square:public Rectangle{
    int area(){
        cout<<"Square Area"<<endl;
        return 0;
    }
};
class Triangle:public Shape{
    public:
    int area(){
        cout<<"Triangle Area"<<endl;
        return 0;
    }
};
void printarea(Shape s){
    s.area();
}
int main(){
    Shape *s = new Square;
    Rectangle *r = new Square;
    printarea(*s);
    Shape &s2 = *r;
    s2.area();
    cout<<"Exiting gracefully!"<<endl;
}