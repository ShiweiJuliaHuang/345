// Last update: 10/05 19:42 Fully working version that read data from the file and store in an array;

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main () {

	ifstream file ( "shiwei.txt" );
	char character;
	char array[200][60];
	int row = 0, col = 0;

	// 2D Array initialization
	for ( int row = 0; row < 200; row ++ ) {
		for ( int col = 0; col < 60; col ++ ) {
			array[row][col] = ' ';
		}
	}

	
	// From file to 2D array;
	if ( file.is_open() ) { //if I could locate my file;
		while ( file.get(character) ) {
			if ( character != '\\' ) {
				array[row][col] = character;
				col ++;
				if ( character == '\n' ) {
					row ++;
					col = 0;
				}//if
			}//if
		}//while
	} //if


	cout << "*************************** BEGINING FROM HERE TO PRINT OUT MY 2D ARRAY ***************************" << endl;
	for ( int i = 0; i < 200; i++ ) { //(due to my 'if statement', this print array don't contain \(slash)
		for ( int j = 0; j < 60; j++ ) {
			cout << array[i][j];
		}
	}

	// this is the sample output:
	// Hi 
 //                                                        I am cshiwei,
 //                                              It's Cme. How uare you?   

	cout << "*************************** END FROM HERE TO PRINT OUT MY 2D ARRAY ***************************" << endl;



	






}//main









