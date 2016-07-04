#include <iostream>
#include <string>

// global constant;
const int windowSize = 5;
// global variable
int workingSetSize = 0;


using namespace std;
int main () {

	string referenceString = "ABCADABEABCDECE";
	int referenceStringLength = referenceString.length();
	cout << "Debugging statement: Reference String Length is: " << referenceStringLength << endl;

	// fill referenceString in an array;
	char referenceStringArray[referenceStringLength]; // array to store reference string;
	for ( int i = 0; i < referenceStringLength; i++ ) {
		referenceStringArray[i] = referenceString.at(i); 
	}

	//Debugging statement:
	cout << "Cout my referenceString" << endl;
	for (int i = 0; i < referenceStringLength; i++) {
		cout << referenceString.at(i) << " ";
	}
	cout << endl;


	char workingSetArray[windowSize]; // array to store the current working set;
	//fill workingSetArray with '*';
	for (int i = 0; i < windowSize; i++ ) {
		workingSetArray[i] = '*';
	}


	int workingSetArraySize[referenceStringLength]; // array to store the size of the current working set;
	int pageFaultStatus[referenceStringLength]; // array to store the status of page fault. In addition, 0 means no page fault; 1 means page fault exists;
	// initialize pageFaultCounter to all 0;
	for ( int i = 0; i < referenceStringLength; i++ ) {
		pageFaultStatus[i] = 0; //initially set up to 0 meaning there is no page fault;
	}

	//put the first character from referenceString to workingSetArray;
	workingSetArray[0] = referenceStringArray[0];

	// Debugging statement:
	cout << "at 0, workingSetArray: " << workingSetArray[0] << endl;

	// update workingSetArraySize;
	for (int i = 0; i < windowSize; i++ ) {
		if ( workingSetArray[i] != '*' ) {
			workingSetSize ++;
		}
	}
	workingSetArraySize[0] = workingSetSize;


	//Debugging statement:
	cout << "at 0, workingSetArraySize: " << workingSetArraySize[0] << endl;

	//update pageFault;
	pageFaultStatus[0] ++;
	cout << "at 0, pageFaultStatus: " << pageFaultStatus[0] << endl;

	for (int i = 1; i < referenceStringLength; i++ ) {
		if ( i < windowSize ) {
			// function to check whether there is character in this workingSetArray;
			bool characterExistStatus = false;
			for ( int j = 0; j < windowSize; j++ ) {
				if (workingSetArray[j] == referenceString.at(i)) {
					characterExistStatus = true;
					break;
				}
			}
			if (characterExistStatus == false) {
				for (int j = 0; j < windowSize; j++ ) {
					if (workingSetArray[j] == '*') {
						cout << "this is j: " << j << " and this is the workingSetArray at j: " << workingSetArray[j] << endl;
						cout << "this is referencestring at i " << "and i is: " << i << " and referencestring is: " << referenceString.at(i) << endl;
						cout << "and j stops at: " << j << endl;
						workingSetArray[j] = referenceString.at(i);
						break;
					}
				}
				// workingSetArray[i] = referenceString.at(i); // need to debug this part
				
				cout << endl;
				cout << "at " << i << " characterExistStatus is: " << characterExistStatus << endl;
				cout << "A) debugging statement, at " << i << " : workingSetArray is: ";
				for (int j = 0; j < windowSize; j++ ) {
					cout << j << ": " << workingSetArray[j] << " ";
				}
				cout << endl;

				// update workingSetArraySize;
				workingSetSize ++;
				workingSetArraySize[i] = workingSetSize;
				cout << "at " << i << " :workingSetArraySize is: " << workingSetArraySize[i] << endl;

				// update pageFault;
				pageFaultStatus[i] ++;
				cout << "at " << i << " :pageFaultStatus is: " << pageFaultStatus[i] << endl;
				cout << endl;
			} //if

			else { // characterExistStatus == true;
				//don't update workingSetArray;
				cout << endl;
				cout << "at " << i << " characterExistStatus is: " << characterExistStatus << endl;
				cout << "B) debugging statement, at " << i << " : workingSetArray is: ";
				for ( int j = 0; j < windowSize; j++ ) {
					cout << workingSetArray[j] << " ";
				} //for
				cout << endl;

				//workingSetArraySize;
				workingSetArraySize[i] = workingSetSize;
				cout << "at " << i << " :workingSetSize is: " << workingSetSize << endl;

				// don't update pageFault;
				cout << "at " << i << " :pageFault is: " << pageFaultStatus[i] << endl;
				cout << endl;
			} //else
		}//if ( i < windowSize )
		else { // i >= windowSize;
			string subStr = referenceString.substr(i - windowSize+1, windowSize);
			if ( referenceString.at(i) == referenceString.at(i - windowSize) ) {
				// debugging statement;
				cout << "This is referenceString at i and i is " << i << " " << referenceString.at(i) << endl;
				cout << "This is referenceString at i - windowSize " << referenceString.at(i - windowSize) << endl;
				// don't update workingSetArray;
				// use the old workingSetArraySize;
				workingSetArraySize[i] = workingSetArraySize[i-1];
				cout << "at " << i << " workingSetArray size is: " << workingSetArraySize[i] << endl;

				// debug statement to see what is the elements in my current working set array;
				for ( int j = 0; j < windowSize; j++ ) {
					cout << workingSetArray[j] << " ";
				} //for
				cout << endl;


				// no pageFault;
				// so don't update pageFault;
				cout << "at " << i << " pageFault is " << pageFaultStatus[i] << endl;
				cout << endl;
			}
			else { //referenceString.at(i) != referenceString.at(i - windowSize)
				// since I already have the subsString;
				// Put the subString into the array with all unique elements;
				cout << "at " << i << ": the referenceString.at(i) is: " << referenceString.at(i) << endl;
				for (int i = 0; i < windowSize; i++ ) {
					workingSetArray[i] = '*';
				}
				cout << "at " << i << ": my substring is: " << subStr << endl;
				workingSetArray[0] = subStr.at(0);
				cout << "my workingSetArray[0] is: " << workingSetArray[0] << endl;
				int countUniqueElementsInWorkingSetArray = 1; // update unique elements in workingSetArray;

				// debug statement;
				// before fill the rest of my string from 1-4; first check with my workingSetArray;
				cout << "this is before filling the rest of the string in the workingSetArray." << endl;
				for (int j = 0; j < windowSize; j++ ) {
					cout << workingSetArray[j] << " ";
				}
				cout << endl;

				for ( int i = 1; i < windowSize; i++ ) {
					char curChar = subStr.at(i);
					cout << "at " << i << ", my curChar is: " << curChar << endl;
					bool check = true;
					for ( int j = 0; j < i; j++ ) {
						if ( curChar == workingSetArray[j] ) {
							check = false;
						}
					}
					if ( check == true ) {
						workingSetArray[i] = curChar;
						countUniqueElementsInWorkingSetArray ++;
					} //if
				} //for
				// debug statement;
				// this is after filling the subString in my array
				cout << "this is after filling the subString in my array" << endl;
				for (int j = 0; j < windowSize; j++ ) {
					cout << workingSetArray[j] << " ";
				}
				cout << endl;

				workingSetArraySize[i] = countUniqueElementsInWorkingSetArray;
				// debug statement;
				cout << "at " << i << " workingSetArraySize is: " << workingSetArraySize[i] << endl;
				pageFaultStatus[i] ++; // this needs debug;
				// check with the pageFaultStatus;
				
				cout << "at " << i << " pageFaultStatus is: " << pageFaultStatus[i] << endl;
				cout << endl;

			} //else

		}


	}//giant for loop



} //main;















