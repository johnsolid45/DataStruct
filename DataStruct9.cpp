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
#include <cctype>

using namespace std;

/*Constants to be used*/
const int BOUND_LOW = 0;
const int BOUND_HIGH = 100;
const int DEF_VAL = 0; //Serves as a default initialization value for variables

/*Function prototypes*/
int getValidIntEntry();
string getValidStringEntry();
int getVal();
int *createSaleArray(int num);
string *createNameArray(int num);

int main()
{
    int *sales;
    string *names;
    
    cout << "How many artist participated in the fair?";
    int numArtists = getVal();
    
    sales = createSaleArray(numArtists);
    names = createNameArray(numArtists);
    
    for (int count = 0; count < numArtists; count++) {
        cout << "Please enter the artists name: \n";
        names[count] = getValidStringEntry();
        cout << "Please enter how much the artist earned: \n";
        sales[count] = getValidIntEntry();
    }
    
    cout << left << setw(10) << "Artist" << "Earned" << "Due" <<endl;
    for (int count = 0; count < numArtists; count++) {
        cout << left << setw(10) << names[count] << sales[count] <<endl;
    }
    
    delete[] sales;
    delete[] names;
    sales = 0;
    names = 0;
    
   return(EXIT_SUCCESS);
}

/* This function continuously prompts the user for input until a valid int 
 * input is entered. This function uses a string and a istringstream constructor
 * which is then parsed for validation.
 */
int getValidIntEntry() {
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

string getValidStringEntry() {
    string entry;
    while(true) {
        getline(cin, entry);
        if(entry.empty()) {
            cerr << "ERROR: Please enter a valid input\n";
        }
        else {
            return(entry);
        }
    }
}

/* This function makes a call to the getValidEntry function and then verifies 
 * that the entry is within the set bounds of the array. This function 
 * continuously loops until a valid entry is made.
 */
int getVal() {
    int val;
    bool invalid = true;
    while(invalid) {
        val = getValidIntEntry();
        if (val <= BOUND_LOW || val >= BOUND_HIGH) {
            cerr << "ERROR: Please select a valid entry from 1-99\n";
        }
        else {
            invalid = false;
        }
    }
    return(val);   
}

int *createSaleArray(int num) {
    int *arr;
    arr = new int[num];
    return arr;
}

string *createNameArray(int num) {
    string *arr;
    arr = new string[num];
    return arr;
}

