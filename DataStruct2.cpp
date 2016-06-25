/*
 * Jonathan Zinn
 * solidzinn45@msn.com
 * Data Structures
 * 06/22/2016
 * DataStruct.cpp 
 * Win10
 * NetBeans 8.1
 * 
 * DataStruct2 provides a menu from which the user can select from a list
 * of options. The user first must open an already existing file, from there
 * the user can select to write a valid name and user score to the file, and
 * also read the content the file. The user can also select to close the 
 * file and exit the program.
 */

        
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream> 

using namespace std;

const int ROWS = 5, COLS = 5;
const int PROG_EXIT = 7;
const int DEF_VAL = 0;

int validateEntry();
int getVal();
void arrayTotal(int[][COLS]);
int arrayAverage(int[][COLS]);
int arrayTotalRow(int[][COLS], int);
int arrayTotalCol(int[][COLS], int);
int arrayHighRow(int[][COLS], int);
int arrayLowRow(int[][COLS], int);

int main()
{
    /*Variables list*/
    int choice = DEF_VAL;
    int result;
    int oneArray[5] = {1,2,3,4,5};
    int myArray[ROWS][COLS] = {{2, 8, 6, 16, 10},
                               {-1, -2, -3, -4, -5},
                               {9, 6, 9, 20, 27},
                               {49, 63, 89, 12, 17},
                               {-900, -800, 800, 600, 200}};
        
    /*Loops through until user chooses to close file and exit*/
    while (choice != PROG_EXIT) {
        /*Displays the option menu list to user*/
        cout << "Please select an array operation from the list\n"
             << "1. Find the sum total value of all array elements\n>"
             << "2. Find the average for all array elements\n>"
	     << "3. Find the sum total value of a single array row\n>"
	     << "4. Find the sum total value of a single array column\n>"
             << "5. Find the highest value in a single array row\n>"
             << "6. Find the lowest value in a single array row\n>"
             << "7. Exit the program\n>";     
       choice = validateEntry(); 
   
        /*Switch executes option 1-7 from menu list, default catches
        *selections outside of range and returns user back to menu*/
	switch (choice) {
            /*Opens file for read write and verifies file opened*/
            case 1:
                arrayTotal(myArray);
		break;
            case 2:
                arrayAverage(myArray);
		break;
            case 3:
            {   
                cout << "Please enter a row value\n\n";
                arrayTotalRow(myArray, getVal());
		break;
            }
            case 4:
            {
                cout << "Please enter a column value\n";
                arrayTotalCol(myArray, getVal());
		break;
            }
            case 5:
            {
                cout << "Please enter a row value\n\n";
                arrayHighRow(myArray, getVal());
		break;
            }
            case 6:
                cout << "Please enter a row value\n\n";
                arrayLowRow(myArray, getVal());
		break;
            case 7:
                cout << setw(40) <<"Exiting Program";
		break;
	    default:
                cerr << " Error: Please select a choice from 1-7\n";
            }
	}
   return(EXIT_SUCCESS);
}

int validateEntry() {
    int choice;
    string entry;
    while(true) {
        getline(cin, entry);
        istringstream iss(entry);
        iss >> choice >> ws;
        if(iss.fail() || !iss.eof()) {
            cout << setw(40) << "Please enter a valid input\n";
        }
        else {
            return(choice);
        }
    }
}

int getVal() {
    int val;
    bool invalid = true;
    while(invalid) {
        val = validateEntry();
        val -= 1;
        if (val < 0 || val > 5) {
            cout << "Please select a valid entry from 1-5\n";
        }
        else {
            invalid = false;
        }
    }
    return(val);   
}

void arrayTotal(int array[][COLS]) {
    int sum = DEF_VAL;
    for(int row = 0; row < sizeof(array[0]) / sizeof(array[0][0]); row++) {
        for(int col = 0; col < COLS; col++){
            sum += array[row][col];
        }
    }
    cout << sum << endl;
}

int arrayAverage(int array[][COLS]) {
    int sum = DEF_VAL;
    int avg = DEF_VAL;
    int count = DEF_VAL;
    for(int row = 0; row < sizeof(array[0]) / sizeof(array[0][0]); row++) {
        for(int col = 0; col < COLS; col++){
            sum += array[row][col];
            count += 1;
        }
    }
    avg = sum / count;
    cout << avg << endl;
}

int arrayTotalRow(int array[][COLS], int row) {
    int sum = DEF_VAL;
    for(int i = 0; i < 5; i++) {
        sum += array[row][i];
    }
    cout << sum << endl;
}

int arrayTotalCol(int array[][COLS], int col) {
    int sum = DEF_VAL;
    for(int i = 0; i < 5; i++) {
        sum += array[i][col];
    }
    cout << sum << endl;  
}

int arrayHighRow(int array[][COLS], int row) {
    int high = array[row][0];
    for( int val : array[row] ) {
        if(high < val) {
        high = val;
        }
    }
    cout << high << endl;
}

int arrayLowRow(int array[][COLS], int row) {
    int low = array[row][0];
    for( int val : array[row] ) {
        if(low > val) {
        low = val;
        }
    }
    cout << low << endl;
}