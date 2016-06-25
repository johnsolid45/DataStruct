
/*
 * Jonathan Zinn
 * solidzinn45@msn.com
 * Data Structures
 * 06/05/2016
 * DataStruct1.cpp 
 * Win10
 * NetBeans 8.1
 * 
 * DataStruct1 provides a menu from which the user can select from a list
 * of options. The user first must open an already existing file, from there
 * the user can select to write a valid name and user score to the file, and
 * also read the content the file. The user can also select to close the 
 * file and exit the program.
 */

        
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
        /*Variables list*/
	int choice = 0;
	bool isOpen = false; //To verify file is open
	ifstream ifFile;     //Stream for output
        ofstream ofFile;     //Stream for input
	string name;
	string content;
	int score;
        
        /*Loops through until user chooses to close file and exit*/
	while (choice != 4) {
            /*Displays the option menu list to user*/
            cout << "Please select one of the following\n"
		 << "1. Display the filename and open the file\n>"
		 << "2. Append a name and game score to the file\n>"
		 << "3. Display the contents of a file\n>"
		 << "4. Close the file\n>";
		 cin >> choice; //Users choice to be used in switch statement
            
            /*Switch executes option 1-4 from menu list, default catches
             *selections outside of range and returns user back to menu*/
	    switch (choice) {
                /*Opens file for read write and verifies file opened*/
                case 1:
                    cout << "Opening file CoolFile.dat\n\n";
		    ifFile.open("CoolFile.dat");
                    ofFile.open("CoolFile.dat", ios::app);
                    if (!ifFile || !ofFile){
                        cerr << "Error file failed to open\n\n";
                    }
                    else {
                        isOpen = true;
                    }
		    break;
                /*User inputs a name and score and saves it to the file*/
                case 2:
		    if (isOpen) {
			cout << "Enter a name\n";
                        cin >> name;
                        cout << "Enter a score\n";
			cin >> score;
                        /*Verify name is not empty and score is positive, if
                         *valid, saves name and score to file, else returns 
                         *an error*/
			if (!name.empty() && score >= 0) {
                            ofFile << setw(15) << left << name << right 
                                   << score << endl;
			}
                        else {
                            cout << "Error: Please enter a valid input\n\n";
                        }
                    }
                    else {
                        cerr << "Error: Open File First\n\n";
                    }
                    cout << endl;
                    break;
                /*Reads file contents*/
		case 3:
                    if (isOpen) {
                        ifFile.clear(); //Clears the file
                        ifFile.seekg( 0, ios::beg ); //Sets pointer file begin
			while (getline(ifFile, content)){ //Read line until EOF
                            cout << content << endl;
                        }                        
                    }
                    else {
                        cerr << "Error: Open File First\n\n";
                    }
                    cout << endl;
                    break;
                /*Closes files, choice equal to 4 results in end of loop*/
		case 4:
                    ifFile.close();
                    ofFile.close();
                    break;
		default:
                    cerr << " Error: Please select a choice from 1-4\n\n";
            }
	}
   return(EXIT_SUCCESS);
}

