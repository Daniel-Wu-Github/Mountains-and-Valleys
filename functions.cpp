#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	// return true if 10 <= a <= b < 10000, and return false otherwise
	if (a >= 10 && a <= b && b < 10000) {
		return true;
	}
	else{
		return false;
	}
}

char classify_mv_range_type(int number) {
	int *arrayDigits, numDigits;
	numDigits = countDigits(number);
	arrayDigits = new int[numDigits];
	int temp = number;
	for (int i = 0; i<countDigits(number);++i){ //make array store all the digits
		arrayDigits[i] = temp%10;
		temp = temp/10;
	}
	bool isM = false;
	bool isV = false;
	bool peak = false; //record if peak or bottom
	//reverse elements of arrayDigits
	for (int i = 0; i<countDigits(number)/2;++i){ //reverse array
		int temp = arrayDigits[i];
		arrayDigits[i] = arrayDigits[countDigits(number)-1-i];
		arrayDigits[countDigits(number)-1-i] = temp;
	}
	for (int i = 0; i<countDigits(number)-1;++i){
		if (arrayDigits[i] == arrayDigits[i+1]) {
			return 'N';
		}
		if (isM==false&&isV==false){//initial check
			if (arrayDigits[i]>arrayDigits[i+1]){
				isV = true;
				continue;
			}
			if (arrayDigits[i]<arrayDigits[i+1]){
				isM = true;
				peak = true;
				continue;
			}
		}
		if (isM){
			if (peak && arrayDigits[i]>arrayDigits[i+1]){
				peak = false;
			}
			else if (!peak && arrayDigits[i]<arrayDigits[i+1]){
				peak = true;
			}
			else if ((peak && arrayDigits[i]<arrayDigits[i+1])||(!peak && arrayDigits[i]>arrayDigits[i+1])){
				return 'N';
			}
		}
		if (isV){
			if (peak && arrayDigits[i]>arrayDigits[i+1]){
				peak = false;
			}
			else if (!peak && arrayDigits[i]<arrayDigits[i+1]){
				peak = true;
			}
			else if ((peak && arrayDigits[i]<arrayDigits[i+1])||(!peak && arrayDigits[i]>arrayDigits[i+1])){
				return 'N';
			}
		}
	}
	if (isV){
		return 'V';
	}
	if (isM){
		return 'M';
	}
	return 'N';
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	int mountainCount = 0;
	int valleyCount = 0;
	for (int i = a; i<=b;++i){
		if (classify_mv_range_type(i) == 'M'){
			++mountainCount;
		}
		if (classify_mv_range_type(i) == 'V'){
			++valleyCount;
		}
	}
	cout << "There are " << mountainCount << " mountain ranges and " << valleyCount << " valley ranges between " << a << " and " << b << "." << endl;
}

int countDigits(int number) {
    int digitCount = 0;
    while (number != 0) {
        number = number / 10;
        ++digitCount;
    }
    return digitCount;
}
