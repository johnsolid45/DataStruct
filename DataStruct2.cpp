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
using namespace std;

const int ROWS = 5, COLS = 5;
int arrayTotal(int[][COLS]);
int arrayAverage(int[][COLS]);
int arrayTotalRow(int[][COLS]);
int arrayTotalCol(int[][COLS]);
int arrayHighRow(int[][COLS]);
int arrayLowRow(int[][COLS]);

int main()
{
    /*Variables list*/
    int choice = 0;
    int result;
    int myArray[ROWS][COLS] = ({2, 8, 6, 16, 10},
                               {-1, -2, -3, -4, -5},
                               {9, 6, 9, 20, 27},
                               {49, 63, 89, 12, 17},
                               {-900, -800, 800, 600, 200});
        
    /*Loops through until user chooses to close file and exit*/
    while (choice != 7) {
        /*Displays the option menu list to user*/
        cout << "Please select an array operation from the list\n"
             << "1. Find the sum total value of all array elements\n>"
             << "2. Find the average for all array elements\n>"
	     << "3. Find the sum total value of a single array row\n>"
	     << "4. Find the sum total value of a single array column\n>";
             << "5. Find the highest value in a single array row\n>";
             << "6. Find the lowest value in a single array row\n>";
             << "7. Exit the program\n>";
	     cin >> choice; //Users choice to be used in switch statement
            
        /*Switch executes option 1-7 from menu list, default catches
        *selections outside of range and returns user back to menu*/
	switch (choice) {
            /*Opens file for read write and verifies file opened*/
            case 1:
                result = arrayTotal(myArray);
		break;
            case 2:
                result = arrayAverage(myArray);
		break;
            case 3:
                result = arrayTotalRow(myArray);
		break;
            case 4:
                result = arrayTotalCol(myArray);
		break;
            case 5:
                result = arrayHighRow(myArray);
		break;
            case 6:
                result = arrayLowRow(myArray);
		break;
            case 7:
                cout << setw(40) <<"Exiting Program";
		break;
	    default:
                cerr << " Error: Please select a choice from 1-7\n\n";
            }
	}
   return(EXIT_SUCCESS);
}
