/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/02/2020
 * 
 * Problem17_09
 * Which way does the stack grow : up (toward higher addresses) or down 
 * (toward lower addresses)? Which way does the free store initially grow
 * (that is, before you use delete)? Write a program to determine the answers.
 *
 * Solution:
 * From what I see, the addresses are moving toward high addresses, which
 * reminds me that the stack grows up, and the bottom is 0x0 and the top
 * has to be 0x???
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <new>
#include <vector>
using namespace std;
int main(void){
    vector<long double *>list;
    
    for (int i = 0; i < 100; i++){
	list.push_back(new long double);
	cout << "Address of Pointer: " << list[i] << endl;
    }
    
    return 0;
}
