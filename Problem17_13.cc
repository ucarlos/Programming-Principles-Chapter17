/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/04/2020
 * 
 * Problem17_13
 * Modify the Link class from Section 17.10.1 to hold a value of a struct God.
 * struct God should have members of type string, name, mythology, vehicle, and
 * weapon. For example, God{"Zeus", "Greek", "", "lightning"} and 
 * God{"Odin", "Norse", "Eight-legged flying horse called Sleipner", 
 * "Spear called Gungnir"}. Write a print_all() function that lists gods with 
 * their attributes one per line. Add a member function add_ordered() that
 * places its new element in its correct lexicographical position. Using the
 * Link s with the values of type God , make a list of gods from three mythol-
 * ogies; then move the elements (gods) from that list to three lexicographi-
 * cally ordered lists — one for each mythology.
 * -----------------------------------------------------------------------------
 */

#include "../std_lib_facilities.h"

class God{
public:
    string name;
    string mythology;
    string vehicle;
    string weapon;
    God(const string &n, const string myth, const string veh, const string weap
		, God *p = nullptr, God *s = nullptr)
		: name{n}, mythology{myth}, vehicle{veh}, weapon{weap}, prev{p}, succ{s} {}

    God* insert(God *n);
    God* add(God *n);
    // Added Ordered:
    God* add_ordered(God *n);
    
    God* erase();
    God* find(const string &s);
    const God* find(const string &s) const;

    God* advance(int n) const;
    God* next() const {return succ;}
    God* previous() const{ return prev;}
    
private:
    God *prev;
    God *succ;
    unsigned int size{1};

};

God* God::add_ordered(God *n){
    //Problem is, we need to first how to sort this BEFORE adding it.
    if (n == nullptr) return this;
    if (this == nullptr) return n;
    God *temp = this;
    // First, compare the god names. if name < n.name or it eaches the end, then break
    
    while (temp->succ != nullptr){
		if (n->name <= temp->name)
			break;
		else temp = temp->succ;
    }

    // If temp->succ is really null, then just return the add.
    if (!temp->succ && this->size > 1) return temp->add(n);
    else return temp->insert(n);
}
// Class Definitions:

God* God::insert(God *n){
    if (n == nullptr) return this;
    if (this == nullptr) return n;
    n->succ = this;
    if (prev) prev->succ = n;
    n->prev = prev;
    prev = n;
    size++;
    return n;
    
}

God* God::add(God *n){
    // first determine if n or this is nullptr.
    if (n == nullptr) return this;
    if (this == nullptr) return n;
    n->prev = this;
    if (succ){
	    succ->prev = n;
	    n->succ = succ;
    }

    succ = n;
    size++;
    return n;
}


void print_all(God *p){
    if (!p){
		cout << "Warning: Empty List." << endl;
		return;
    }

    // Otherwise
    while (p){
		cout << "Deity Name: " << p->name
			 << "\tMythology: " << p->mythology
			 << "\tVehicle: " << p->vehicle
			 << "\tWeapon: " << p->weapon
			 << endl;

		p = p->next();

    }

}

God* begin (God *n){
    // Go back as far possible
    while (n->previous()){
        n = n->previous();
    }
    return n;
}

void add_to_list(God *list , Vector<string> god_list, String mythology){
    for (int i = 0; i < god_list.size(); i++){
        list->add_ordered(new God(god_list[i], mythology, "", ""));
        list = begin(list);
    }
}

int main(void){
    God *Greek_list = new God("Zeus", "Greek", "", "Lightning", nullptr, nullptr);
    God *Norse_list = new God("Ymir", "Norse", "", "", nullptr, nullptr);
    Vector<string> Norse = {"Odin", "Thor", "Freia", "Loki"};
    add_to_list(Norse_list, Norse, String{"Norse"});
    Vector<string> Greek = {"Apollo", "Hades", "Artemis", "Athena"};
    add_to_list(Greek_list, Greek, String{"Greek"});
    Greek_list = begin(Greek_list);
    Norse_list = begin(Norse_list);
    print_all(Greek_list);
    cout << endl;
    print_all(Norse_list);


    


}
