/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/01/2020 at 21:57
 * 
 * Problem17_04
 * Write a function char *stdup(const char*) that copies a C-style string
 * into memory it allocates on the free store. Do not use any standard library
 * functions.
 * -----------------------------------------------------------------------------
 */


#include "../std_lib_facilities.h"



char *stdup_c_style(const char *str){
    char *temp = (char *)calloc(strlen(str), sizeof(char));
    
    for (int i = 0; i < strlen(str); i++)
		temp[i] = str[i];

    return temp;

}

char* stdup(const char *str){
    int str_size = strlen(str);
    char *temp = new char[str_size];
    for (int i = 0; i < str_size; i++)
		temp[i] = str[i];

    return temp;

}

int main(void){
    String name {"John Jurasek"};
    char *new_name = stdup(name.c_str());
    cout << "Name: " << new_name << endl;

    delete[] new_name;
    // free(new_name);
}
