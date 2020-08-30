/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/01/2020
 * 
 * Problem17_07
 * Write a program that reads characters from cin into an array that you 
 * allocate on the free store. Read individual characters until an exclamation
 * mark (!) is entered. Do not use a std::string. Do not worry about memory
 * exhaustion.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

int main(void){
    int val = 100;
    char *str = new char[val];
    char temp;
    int i = 0;
    cout << "Please type in some character. To exit, press \"!\""
	 << endl;
    while ((cin >> temp) && (temp != '!')){
	str[i++] = temp;
    }
    cout << str << endl;
    delete[] str;
}
