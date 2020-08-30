/* -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 12/31/2019
 *
 * Chapter17_Drill
 *
 * 
 * -----------------------------------------------------------------------------
 */

#include <iostream>

using namespace std;
void drill01(void){
	int *list = new int[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};
	cout << "Address of list: " << list << endl;
	for (int i = 0; i < 10; i++){
	    cout << list[i] << " ";
	}


	int *p2 = new int[7]{1, 2, 4, 8, 16, 32, 64};
	cout << "\nAddress of p2: " << p2 << "\tValue: " << *p2 << endl;


	int *p3 = p2;
	p2 = list;
	p2 = p3;

	cout << "Printing out values of pointer p1 and p2: " << endl;
	for (int i = 0; i < 10; i++){
		cout << list[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 7; i++){
		cout << p3[i] << " ";
	}

	delete[] list;
	delete[] p2;
	delete[] p3;
		
}


void drill02(void){
    int *p1 = new int[10]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    int *p2 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Printing P1: " << endl;
    for (int i = 0; i < 10; i++)
	    cout << p1[i] << " ";

    cout << endl;
    
    for (int i = 0; i < 10; i++){
	    p2[i] = p1[i];
    }

    cout << "Printing P2: " << endl;
    for (int i = 0; i < 10; i++){
	    cout << p2[i] << " ";
    }
    cout << endl;

}

int main(void){
    drill01();
    drill02();
    return 0;
}
