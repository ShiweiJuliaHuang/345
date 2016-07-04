// Last update: 10/11 12:38 Fully working version 
// 1. Read data from the file and store in an array[200][60];
// 2. parallelArray knows exactly the location for '\'
// 3. Everything works ( but not thread 3 algorithm for now. )
// Question: 
// 1. What's the valid punctuation?
// 2. Would user input /uhappy!!

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main () {

	ifstream file ( "smalltest.txt" );
	char character;
	char array[200][60];
	int parallelArray[200][60];
	int row = 0, col = 0;

	// 2D Array initialization
	for ( int row = 0; row < 200; row ++ ) {
		for ( int col = 0; col < 60; col ++ ) {
			array[row][col] = ' ';
		}
	}


	// make a parallel array in order to identify the '/' location
	// parallelArray initialization;
	for ( int i = 0; i < 200; i ++ ) {
		for ( int j = 0; j < 60; j++ ) {
			parallelArray[i][j] = 0;
		}
	}


	// From file to 2D array;
	if ( file.is_open() ) { //if I could locate my file;
		while ( file.get(character) ) {
			array[row][col] = character;
			col ++;
			if ( character == '\n' ) {
				row ++;
				col = 0;
			}//if
		}//while

	} //if


	// Test to see parallelArray's '/' location;
	for ( int i = 0; i < 200; i++ ) {
		for ( int j = 0; j < 60; j++ ) {
			if ( array[i][j] == '\\' ) {
				parallelArray[i][j] = 1;
			}//if

		}//for
	}//for

// Making sure control sequence works;
	for ( int i = 0; i < 200; i++ ) {
		for ( int j = 0; j < 60; j++ ) {
			if ( parallelArray[i][j] == 1 ) {
					if ( array[i][j+1] == 'c' ) {
						//function;
						array[i][j] = ' ';
						array[i][j+1] = ' ';
						array[i][j+2] = toupper( array[i][j+2] );
					}


// FIX TAKING OUT OF CONTROL SEQUENCE ISSUE

					else if ( array[i][j+1] == 'C' ) {
						bool noSpace = true;
						int insideOneRow = j+2;
						while ( noSpace ) {
							if ( array[i][insideOneRow] == ' ' ) {
								noSpace = false;
							}
							else {
								if ( insideOneRow < 60  ) {
									array[i][j] = ' ';
									array[i][j+1] = ' ';
									array[i][insideOneRow] = toupper( array[i][insideOneRow] );
									insideOneRow ++;
								}
							}
						}//while;
					}//else if

					else { // array[i][j+1] == 'u'

						char tmpArray[0][60];
						int insideOneRow = j+2;
						bool noSpaceOrPunc = true;
						int countCharacter = 0;

						while ( noSpaceOrPunc ) {
							if ( array[i][insideOneRow] == ' ' || array[i][insideOneRow] == ',' || array[i][insideOneRow] == '!' || array[i][insideOneRow] == '.' ) {
								noSpaceOrPunc = false;
								array[i][j] = '_';
								array[i][j+countCharacter+1] = '_';
							}//if

							else {
								if ( insideOneRow < 60 ) {
									tmpArray[0][countCharacter] = array[i][insideOneRow];
									array[i][insideOneRow-1] = tmpArray[0][countCharacter];
									insideOneRow ++;
									countCharacter ++;
								}
							}//else

						}//while

					}//else
			}//if
		}//for
	}//for




cout << "hi ! for the purpose of debugging" << endl;


	cout << "*************************** BEGINING FROM HERE TO PRINT OUT MY 2D ARRAY ***************************" << endl;


	for ( int i = 0; i < 200; i++ ) { //(due to my 'if statement', this print array don't contain \(slash)
		for ( int j = 0; j < 60; j++ ) {
			cout << array[i][j];
		}
	}

	cout << "*************************** END FROM HERE TO PRINT OUT MY 2D ARRAY ***************************" << endl;


	// writing array content into file;
	ofstream myfile;
  	myfile.open ("cry10.txt");

  	// for ( int j = 0; j < 60; j++ ) {
  	// 	if ( array[0][j] != ' ') {
  	// 		myfile << array[0][j];
  	// 	}
  	// }
	for ( int i = 0; i < 200; i++ ) {
	  	for ( int j = 0; j < 60; j++ ) {
	  		if ( array[i][j] != ' ' ) { 
	  			myfile << array[i][j];
	  		}
	  		else { //only adding manmaid space if word and space are saparated by 1 space ( rather than 2 spaces or 3 spaces outputFileShiwei2);
	  			if ( ( array[i][j] == ' ' ) && ( array[i][j+1] != ' ' ) ){
	  				myfile << " ";
	  			}
	  		}
	  	}
	}

	cout << "testing the word whatever: " << endl;
	cout << array[5][0];
	cout << array[5][1];
	cout << array[5][2];
	cout << array[5][3];
	cout << array[5][4];
	cout << array[5][5];
	cout << array[5][6];
	cout << array[5][7];
	cout << array[5][8];
	cout << array[5][9];
	cout << array[5][10];
	cout << array[5][11];
	cout << array[5][12];
	cout << array[5][13];



cout << "END testing the word whatever" << endl;

  	// int j = 0;
  	// while ( j < 60 ) {
  	// 	if ( array[0][j] != ' ' ) {
  	// 		j++;
  	// 		myfile << array[0][j];
  	// 	}
  	// 	else if (( array[0][j] == ' ') && ( array[0][j+1] != ' ' )) {
  	// 		j++;
  	// 		myfile << " ";
  	// 	}
  	// 	else {
  	// 		j++;
  	// 	}
  	// }





	// // From file to 2D array;
	// if ( file.is_open() ) { //if I could locate my file;
	// 	while ( file.get(character) ) {
	// 		array[row][col] = character;
	// 		col ++;
	// 		if ( character == '\n' ) {
	// 			row ++;
	// 			col = 0;
	// 		}//if
	// 	}//while

	// } //if









  	// for ( int i = 0; i < 200; i++ ) {
  	// 	for ( int j = 0; j < 60; j++ ) {
  	// 		myfile << array[i][j];
  	// 	}
  	// }
  	myfile.close();

  	return 0;




} //main




