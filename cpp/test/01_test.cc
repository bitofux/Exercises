#include <iostream>
using std::cout;

struct A {
    int a{};
    A()                 { cout << "A::A()   this=" << this << "\n"; }
    virtual ~A()        { cout << "A::~A()  this=" << this << "\n"; }
    virtual void Bar()  { cout << "A::Bar() this=" << this << "\n"; }
};
struct B {
    int b{};
    B()                 { cout << "B::B()   this=" << this << "\n"; }
    virtual ~B()        { cout << "B::~B()  this=" << this << "\n"; }
    void Foo()          { cout << "B::Foo() this=" << this << "\n"; }
};
struct C : A ,B  {
    int c{};
    C()                 { cout << "C::C()   this=" << this << "\n"; }
    virtual ~C()        { cout << "C::~C()  this=" << this << "\n"; }
    virtual void Bar()  { cout << "C::Bar() this=" << this << "\n"; Foo(); }
};

int main() {
    cout << "\nC* pC = new C;\n";
    C* pC = new C;
    B* pB = pC;
    A* pA = pC;
    cout << "\npA=" << pA << " pA->Bar();\n";
    pA->Bar();
    cout << "\npC=" << pC << " pC->Foo(); \n";
    pC->Foo();
    cout << "\npB=" << pB << " delete pB;\n";
    delete pB;
}
