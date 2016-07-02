/*
 * Jonathan Zinn
 * solidzinn45@msn.com
 * Data Structures
 * 06/26/2016
 * DataStruct2.cpp 
 * Win10
 * NetBeans 8.1
 * 
 * DataStruct2 is a menu driven program from which the user can analyze the 
 * contents of a pre existing multi-dimensional array. The user will be 
 * presented with options such as finding the sum of all the array elements,
 * find the lowest/highest value from a row in the array, and averaging all the
 * array elements. 
 */

        
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream> 

using namespace std;

/*Constants to be used*/
const int BOUND_LOW = 0;
const int BOUND_HIGH = 4;
const int ROWS = 5, COLS = 5;
const int DEF_VAL = 0; //Serves as a default initialization value for variables

struct PhotoStuff {
    int imgNum;
    string imgName;
    string imgType;
    double price;
    int numSold;
};

/*Function prototypes*/
int getValidNumEntry();
int getNumVal();
string getValidStringEntry(int charLim);
PhotoStuff *photoCreate(PhotoStuff[100]);
void photoDisplay(PhotoStuff[100]);


int main()
{
    PhotoStuff *photoFilled; 
    PhotoStuff photoArray[100];
    
    photoFilled = photoCreate(photoArray);
    
    cout << "Display some stuff";
    photoDisplay(photoFilled);

   return(EXIT_SUCCESS);
}

/* This function continuously prompts the user for input until a valid int 
 * input is entered. This function uses a string and a istringstream constructor
 * which is then parsed for validation.
 */
int getValidNumEntry() {
    int choice;
    string entry;
    while(true) {
        getline(cin, entry);
        istringstream iss(entry);
        iss >> choice >> ws;
        if(iss.fail() || !iss.eof()) {
            cerr << "ERROR: Please enter a valid input\n";
        }
        else {
            return(choice);
        }
    }
}

/* This function makes a call to the getValidEntry function and then verifies 
 * that the entry is within the set bounds of the array. This function 
 * continuously loops until a valid entry is made.
 */
int getNumVal(int low, int high) {
    int val;
    bool invalid = true;
    while(invalid) {
        val = getValidNumEntry();
        if (val < low || val > high) {
            cerr << "ERROR: Please select a valid entry from 1-5\n";
        }
        else {
            invalid = false;
        }
    }
    return(val);   
}

PhotoStuff *photoCreate(PhotoStuff arr[100]) {
    bool cont = true;
    int count = 0;
    string another;
    while(cont) {
        cout << "Please enter the image number" << endl;
        arr[count].imgNum = getNumVal(0, 10);
        arr[count].imgName = getNumVal(0, 10);
        arr[count].imgType = getNumVal(0, 10);
        arr[count].numSold = getNumVal(0, 10);
        arr[count].price = getNumVal(0, 10);
        while() {
            cout << "Would you like to enter another entry? Enter yes or no.\n";
            another = getValidStringEntry(10);
            if (another)
        }
    }
    
}

