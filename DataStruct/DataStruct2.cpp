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
const int PROG_EXIT = 7;
const int DEF_VAL = 0; //Serves as a default initialization value for variables

/*Function prototypes*/
int getValidEntry();
int getVal();
void arrayTotal(int[][COLS]);
void arrayAverage(int[][COLS]);
void arrayTotalRow(int[][COLS], int);
void arrayTotalCol(int[][COLS], int);
void arrayHighRow(int[][COLS], int);
void arrayLowRow(int[][COLS], int);

int main()
{
    /* Variables list */
    int choice = DEF_VAL; //value to be used in switch statement
    int myArray[ROWS][COLS] = {{2, 8, 6, 16, 10}, //5x5 array to be analyzed
                               {-1, -2, -3, -4, -5},
                               {9, 6, 9, 20, 27},
                               {49, 63, 89, 12, 17},
                               {-900, -800, 800, 600, 200}};
        
    /* Loops through until user chooses to close file and exit (7) */
    while (choice != PROG_EXIT) {
        /* Displays the option menu list to user */
        cout << "Please select an array operation from the list\n"
             << setfill('-') << setw(80) << '-' << endl
             << "1. Find the sum total value of all array elements\n>"
             << "2. Find the average for all array elements\n>"
	     << "3. Find the sum total value of a single array row\n>"
	     << "4. Find the sum total value of a single array column\n>"
             << "5. Find the highest value in a single array row\n>"
             << "6. Find the lowest value in a single array row\n>"
             << "7. Exit the program\n>"
             << setfill('-') << setw(80) << '-' << endl;
       choice = getValidEntry(); //Sets choice to a valid entry
   
        /* Switch executes option 1-7 from menu list, default catches
         * selections outside of range and returns user back to menu
         */
	switch (choice) {
            case 1:
                arrayTotal(myArray); //Find total sum for all array elements
		break;
            case 2:
                arrayAverage(myArray); //Find the average of all array elements
		break;
            case 3:
            {   
                cout << "Please enter a row value\n\n";
                arrayTotalRow(myArray, getVal()); //Sum of elements for one row
		break;
            }
            case 4:
            {
                cout << "Please enter a column value\n";
                arrayTotalCol(myArray, getVal()); //Sum of elements for one col
		break;
            }
            case 5:
            {
                cout << "Please enter a row value\n\n";
                arrayHighRow(myArray, getVal()); //Highest val for one row
		break;
            }
            case 6:
                cout << "Please enter a row value\n\n";
                arrayLowRow(myArray, getVal()); //Lowest val for one row
		break;
            case 7:
                cout << setfill(' ') << setw(40) <<"Exiting Program";
		break;
	    default:
                cerr << "ERROR: Please select a choice from 1-7\n\n";
            }
	}
   return(EXIT_SUCCESS);
}

/* This function continuously prompts the user for input until a valid int 
 * input is entered. This function uses a string and a istringstream constructor
 * which is then parsed for validation.
 */
int getValidEntry() {
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
int getVal() {
    int val;
    bool invalid = true;
    while(invalid) {
        val = getValidEntry();
        val -= 1;
        if (val < BOUND_LOW || val > BOUND_HIGH) {
            cerr << "ERROR: Please select a valid entry from 1-5\n";
        }
        else {
            invalid = false;
        }
    }
    return(val);   
}

/* Finds the sum of all array elements. The bounds of the array are determined
 * by utilizing the sizeof operator.
 */
void arrayTotal(int array[][COLS]) {
    int sum = DEF_VAL;
    for(int row = 0; row < sizeof(array[0]) / sizeof(array[0][0]); row++) {
        for(int col = 0; col < COLS; col++){
            sum += array[row][col];
        }
    }
    cout << "The total sum of the array elements is: " << sum << "\n\n";
}

/* Find the average value for all of the array elements. The bounds are 
 * determined with the sizeof operator. The number of elements is determined
 * using a counter which increments by 1 at each iteration.
 */
void arrayAverage(int array[][COLS]) {
    int sum = DEF_VAL;
    int avg = DEF_VAL;
    int count = DEF_VAL;
    for(int row = 0; row < sizeof(array[0]) / sizeof(array[0][0]); row++) {
        for(int col = 0; col < COLS; col++){
            sum += array[row][col];
            count += 1; //Counter increments by 1 for each element added
        }
    }
    avg = sum / count;
    cout << "The average of the all the array elements is: " << avg << "\n\n";
}

/* Finds the sum of elements for a specified row. The bounds are determined 
 * with the sizeof operator.
 */
void arrayTotalRow(int array[][COLS], int row) {
    int sum = DEF_VAL;
    for(int i = 0; i < sizeof(array[row]) / sizeof(array[row][0]); i++) {
        sum += array[row][i];
    }
    cout << "The total sum of row " << row+1<< " is: " << sum << "\n\n";  
}

/* Finds the sum of elements for a specified column. The bounds are determined 
 * with a predetermined constant.
 */
void arrayTotalCol(int array[][COLS], int col) {
    int sum = DEF_VAL;
    for(int i = 0; i < COLS; i++) {
        sum += array[i][col];
    }
    cout << "The total sum of column " << col+1 << " is: " << sum << "\n\n";  
}

/* Finds the highest value in a row using a range based for loop */
void arrayHighRow(int array[][COLS], int row) {
    int high = array[row][0];
    for( int val : array[row] ) {
        if(high < val) {
        high = val;
        }
    }
    cout << "The highest value of row " << row+1 << " is: " << high << "\n\n";
}

/* Finds the lowest value in a row using a range based for loop */
void arrayLowRow(int array[][COLS], int row) {
    int low = array[row][0];
    for( int val : array[row] ) {
        if(low > val) {
        low = val;
        }
    }
    cout << "The lowest value of row " << row+1 << " is: " << low << "\n\n";
}