/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/02/2020
 * 
 * Problem17_11
 * Complete the "list of gods" example from Section 17.10.1 and run it.
 * -----------------------------------------------------------------------------
 */

#include "../std_lib_facilities.h"

class Link{
public:
    string value;
    Link(const string &v, Link *p = nullptr, Link *s = nullptr)
	: value{v}, prev{p}, succ{s} { }

    Link* insert(Link *n);
    Link* add(Link *n);
    Link* erase();
    Link* find(const string &s);
    const Link* find(const string &s) const;

    Link* advance(int n) const;
    Link* next() const {return succ;}
    Link* previous() const{ return prev;}
    
private:
    Link *prev;
    Link *succ;

};

// Class Definitions:

Link* Link::insert(Link *n){
    if (n == nullptr) return this;
    if (this == nullptr) return n;
    n->succ = this;
    if (prev) prev->succ = n;
    n->prev = prev;
    prev = n;
    
    return n;
    
}

Link* Link::add(Link *n){
    // first determine if n or this is nullptr.
    if (n == nullptr) return this;
    if (this == nullptr) return n;
    n->prev = this;
    if (succ){
	    succ->prev = n;
	    n->succ = succ;
    }

    succ = n;
    return n;
}


void print_all(Link *p){
    cout << "(";
    while (p){
	cout << p->value;
        p = p->next();
        if (p)
	    cout << ",";
    }
    cout << ")\n";

}


int main(void){
    Link *list = new Link("Thor", nullptr, nullptr);
    Link *test = list->add(new Link("Odin"));
    test->add(new Link("Freia"));
    print_all(list);
    test->add(new Link("Loki"));
    print_all(list);

}
