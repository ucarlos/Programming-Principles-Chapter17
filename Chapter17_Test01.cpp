/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 12/29/2019
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;
class A{
public:
    A(){ cout << "Creating Class A\n";}
    virtual ~A(){
        cout << "Destroying Class A\n";
    }
    virtual void print(){
        cout << "Calling Class A\n";
    }
};

class B : public A{
public:
    B(){
        cout << "Creating Class B\n";
    }
    ~B() override{
        cout << "Destroying Class B\n";
    }
    void print() override{
        cout << "Calling Class B\n";
    }
};


int main(void){
    // Create Class A:
    puts("---CREATING OBJECT OF CLASS A---");
    A *a_object = new A();
    puts("---CREATING OBJECT OF CLASS B---");
    B *b_object = new B();
    puts("---EXECUTING PRINT ON BOTH OBJECTS---");
    a_object->print();
    b_object->print();
    puts("---DELETING OBJECT OF CLASS A---");
    delete a_object;
    puts("---DELETING OBJECT OF CLASS B---");
    delete b_object;
}
