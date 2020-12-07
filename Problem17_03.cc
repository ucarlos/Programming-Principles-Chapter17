/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/01/2020
 * 
 * Problem17_03
 * Write a function void to_lower(char *s) that replaces all uppercase 
 * characters in the C-style string s with their lowercase equivalents. For 
 * example, Hello, World! becomes hello, world!. Do not use any standard library
 * functions. A C-style string is a zero-terminated array of characters, so if
 * you find a char with the value 0, you are at the end.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <cstdio>
using namespace std;

void to_lower(char *s){
    char temp;
    for (char *p = s; *p; p++){
		if ('A' <= *p && *p <= 'Z'){
			*p += ('a' - 'A');
		}
	
    }
}


int main(void){
    string temp = "Hello World!";
    char *name = (char *)(temp.c_str());
    printf("Before: %s\n", name);
    to_lower(name);
    printf("After: %s\n", name);


}


