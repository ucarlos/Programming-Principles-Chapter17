/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/01/2020 at 22:15
 *
 * Problem17_05
 * Write a function char* findx(const char *s, const char *x), that find the
 * first occurrence of the C-style x in s
 * -----------------------------------------------------------------------------
 */


#include "../std_lib_facilities.h"

char *findx(const char *s, const char *x){ // Fucking horrible
    int x_strlen = strlen(x);
    int s_strlen;

    for (const char *p = s; *p; p++){
	    s_strlen = strlen(p);
	    if (x_strlen > s_strlen) return nullptr;
	    else {
            bool is_valid = true;
            for (int i = 0; i < x_strlen; i++) {
                if (*(p + i) != *(x + i)) {
                    is_valid = false;
                    break;
                }
            }

	        if (is_valid) return (char *) p;
	    
	    }
    }

    return nullptr; // If not found
}

void check_string (String cpp_string, const char *string1, String test){
    if (string1)
        cout << "\"" << test << "\" could be found in string " << cpp_string << endl;
    else
        cout << "\"" << test << "\" could not be found in string " << cpp_string << endl;

}


int main(void){
    String name {"John Jurasek"};
    String test1 {"Jurasek"};
    String test2 {"Brah"};
    char *result1 = findx(name.c_str(), test1.c_str());
    char *result2 = findx(name.c_str(), test2.c_str());

    check_string(name, result1, test1);
    check_string(name, result2, test2);

    return 0;

}
