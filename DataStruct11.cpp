/*
 * Jonathan Zinn
 * solidzinn45@msn.com
 * Data Structures
 * 07/04/2016
 * DataStruct2.cpp 
 * Win10
 * NetBeans 8.1
 * 
 * DataStruct 11 produces an array of data structures which holds elements 
 * associated with photography. The program requests the user input the values
 * associated with the array elements and then displays them to the user.
 */

        
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream> 

using namespace std;

/* Constants to be used */
const int DEF_VAL = 0; //Serves as a default initialization value for variables
const int NAME_LEN = 25;
const int TYPE_LEN = 5;
const int MIN_IMG_NUM = 1;
const int MIN_NUM_SOLD = 0;
const double MIN_VAL = 50.0;

/* Decleration of the data structure which contains the elements to filled */
struct PhotoStuff {
    int imgNum;
    string imgName;
    string imgType;
    double price;
    int numSold;
};

/*Function Declerations*/
double getValidDoubleNumEntry();
int getValidIntNumEntry();
int getNumValInt();
int getNumValDouble();
string getValidStringEntry(int charLim);
PhotoStuff *photoCreate(PhotoStuff arr[100]);
void photoDisplay(PhotoStuff arr[100]);
void displayHeadCols();

int main()
{   
    PhotoStuff *photoFilled;
    PhotoStuff photoArray[100];
    
    /* Calls function to fill elements of array containing PhotoStuff structs*/
    photoFilled = photoCreate(photoArray);
    
    /* Function to display header columns */
    displayHeadCols();
    
    /* Loops through and displays array containing PhotoStuff structs*/
    photoDisplay(photoFilled);
    
    cout << "Please enter any key to exit";
    cin.get();
   return(EXIT_SUCCESS);
}

/* This function continuously prompts the user for input until a valid int input 
 * is entered. This function uses a string and a istringstream 
 * constructor which is then parsed for validation.
 */
int getValidIntNumEntry() {
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

/* This function continuously prompts the user for input until a valid double 
 * input is entered. This function uses a string and a istringstream 
 * constructor which is then parsed for validation.
 */
double getValidDoubleNumEntry() {
    double choice;
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

/* This function continuously prompts the user for input until a valid string 
 * input is entered
 */
string getValidStringEntry(int charLim) {
    string entry;
    while(true) {
        getline(cin, entry);
        istringstream iss(entry);
        if(entry.empty() || entry.size() > charLim) {
            cerr << "ERROR: Please enter a valid input\n";
        }
        else {
            return(entry);
        }
    }   
}

/* This function makes a call to the getValidDoubleNumEntry function and then 
 * verifies that the entry is within the set bounds of the array. This function 
 * continuously loops until a valid entry is made.
 */
double getNumValDouble(double low) {
    double val;
    bool invalid = true;
    while(invalid) {
        val = getValidDoubleNumEntry();
        if (val < low) {
            cerr << "ERROR: Please enter a value in bounds\n";
        }
        else {
            invalid = false;
        }
    }
    return(val);   
}

/* This function makes a call to the getValidIntNumEntry function and then 
 * verifies that the entry is within the set bounds of the array. This function 
 * continuously loops until a valid entry is made.
 */
int getNumValInt(int low) {
    double val;
    bool invalid = true;
    while(invalid) {
        val = getValidIntNumEntry();
        if (val < low) {
            cerr << "ERROR: Please enter a value in bounds\n";
        }
        else {
            invalid = false;
        }
    }
    return(val);   
}

/* This function takes in the array containing PhotoStuff elements and asks the
 * user to continuosly input values associated with the PhotoStuff struct.*/
PhotoStuff *photoCreate(PhotoStuff arr[100]) {
    int count = DEF_VAL;
    string another;
    
    while(true) {
        bool more = true;
        
        cout << "Please enter the image number" << endl;
        arr[count].imgNum = getNumValInt(MIN_IMG_NUM);
        cout << "Please enter the image name" << endl;
        arr[count].imgName = getValidStringEntry(NAME_LEN);
        cout << "Please enter the image type" << endl;
        arr[count].imgType = getValidStringEntry(TYPE_LEN);
        cout << "Please enter the number of images sold" << endl;
        arr[count].numSold = getNumValInt(MIN_NUM_SOLD);
        cout << "Please enter the image price" << endl;
        arr[count].price = getNumValDouble(MIN_VAL);
        count += 1;
        while(more) {
            cout << "Would you like to enter another entry? Enter yes or no.\n";
            another = getValidStringEntry(10);
            if (another == "yes") {
                more = false;
            }
            else if (another == "no") {
                arr[count].imgNum = DEF_VAL;
                return (arr);
            }
            else if (count == 99) {
                cerr << "ERROR: Array memory filled!!";
                arr[count+1].imgNum = DEF_VAL;
                return (arr);
            }
            else {
                cout << "Please enter either yes or no" << endl;
            }
        }
    }   
}

/* Reads in the array containing PhotoStuff structs and displays the contents.
 * Stops displaying if the img num is equal to default value 0, indicating no 
 * more entries are made.*/
void photoDisplay(PhotoStuff arr[100]) {
    for (int i =0; i < 100; i++) {
        if (arr[i].imgNum == 0) {
            i = 100;
        }
        else{
            cout << setfill(' ') << left << setw(20) << arr[i].imgNum 
                 << setw(26) << arr[i].imgName << setw(20) << arr[i].imgType 
                 << "$" << setw(20) << arr[i].price << setw(20) 
                 << arr[i].numSold << "$" << arr[i].price * arr[i].numSold 
                 << endl;
        }
    }
}

/* Displays the header columns*/
void displayHeadCols() {
    cout << setfill('-') << setw(140) << ('-') << endl;
    cout << setfill(' ') << setw(90) << "Photography by Large Format Dude\n";
    cout << setfill('-') << setw(140) << ('-') << endl;
    cout << setfill(' ') << left << setw(20) << "Image No." << setw(26) 
         << "Name" << setw(20) << "Film Type" << setw(20) << "Print Price" 
         << setw(20) << "Prints Sold" << "Total Revenue From This Print\n";
}
