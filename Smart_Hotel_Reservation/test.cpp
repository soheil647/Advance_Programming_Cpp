#include <iostream>
using namespace std;

// Question 1
//class Point {
//public:
//    Point() { cout << "Normal Constructor called\n"; }
//
//    Point(const Point &t) { cout << "copy constructor called\n"; }
//};
//
//int main() {
//    Point *t1, *t2;
//    t1 = new Point();
//    t2 = new Point(*t1);
//    Point t3 = *t1;
//    Point t4;
//    t4 = t3;
//    return 0;
//}

// Question 2
//class Base
//{
//public:
//    void show()
//    {
//        cout << " In Base ";
//    }
//};
//class Derived: public Base
//{
//public:
//    int x;
//    void show()
//    {
//        cout << " In Derived ";
//    }
//    Derived()
//    {
//        x = 10;
//    }
//};
//int main()
//{
//    Base *bp;
//    Derived d;
//    bp = &d;
//    bp->show();
//    cout << bp->x;
//    return 0;
//}


// Question 3
//class Base
//{
//public:
////    void hello(){ return;}
//    int fun() { cout << "Base::fun() called"; }
//    int fun(int i) { cout << "Base::fun(int i) called"; }
//};
//class Derived: public Base
//{
//public:
//    int fun() { cout << "Derived::fun() called"; }
//};
//int main()
//{
//    Derived d;
////    d.hello();
//    d.fun(5);
//    return 0;
//}


// Question 4
//class Base
//{
//public:
//    virtual string print() const
//    {
//        return "This is Base class";
//    }
//};
//class Derived: public Base
//{
//public:
//    virtual string print() const
//    {
//        return "This is Derived class";
//    }
//};
//void describe(Base p)
//{
//    cout << p.print() << endl;
//}
//int main()
//{
//    Base b;
//    Derived d;
//    describe(b);
//    describe(d);
//    return 0;
//}


// Question 5
//class Test {
//    static int count;
//    int id;
//public:
//    Test() {
//        count++;
//        id = count;
//        cout << "Constructing object number " << id << endl;
//        if(id == 4)
//            throw 4;
//    }
//    ~Test() { cout << "Destructing object number " << id << endl; }
//};
//int Test::count = 0;
//int main() {
//    try {
//        Test array[5];
//    } catch(int i) {
//        cout << "Caught " << i << endl;
//    }
//}


// Question 6
class Base
{
public:
    void show() { cout << " In Base "; }
    virtual void print() { cout << " In Base ";}
};
class Derived: public Base
{
public:
    void show() { cout << " In Derived "; }
    virtual void print() { cout << " In Derived "; }
};
int main()
{
    Derived d;
    try {
        throw d;
    }
    catch(Base& b) {
        cout << "Caught Base Exception";
        b.show();
        b.print();
    }
    catch(Derived& d) {
        cout << "Caught Derived Exception";
        d.show();
        d.print();
    }
    return 0;
}