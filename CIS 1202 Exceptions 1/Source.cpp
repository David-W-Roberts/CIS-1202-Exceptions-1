// David Roberts
// CIS 1202 101
// 5/2/2022
#include <iostream>
#include <string>

using namespace std;

char Character(char start, int offset);

int main() {
	bool again = 1;
	char start;
	int offset;
	while (again) {
		try {
			cout << "Input a character > ";
			cin >> start;
			cout << "Enter a whole number > ";
			cin >> offset;
			start = Character(start, offset);

			cout << "The start is: " << start;
		}
		catch (string invalidCharacterException){
			cout << invalidCharacterException;
		}
		catch (char invalidRangeException[]){
			cout << invalidRangeException;
		}

		cout << "\nDo you want to process another letter (Enter 0 for no or 1 for yes)> ";
		cin >> again;
	}

	cout << endl << endl;
	system("pause");
	return 0;
}

char Character(char start, int offset) {
	string invalidRangeException = "The start is not a valid character";
	char invalidCharacterExeption[] = { "The start cannot transform from this character" };
	if (start == 65 || start == 90) {
		// uppercase 'A' or 'Z'
		start += offset;
		if (start < 65 || start > 90) {
			// Will thow this if the initial letter is 'A' or 'Z' but the offset makes this a non Uppercase letter
			throw invalidRangeException;
		}
	}
	else if (start == 97 || start == 122) {
		// lowercase 'a' or 'z'
		start += offset;
		if (start < 97 || start > 122) {
			// throws this if the inital letter is 'a' or 'z' but the offset makes this a non lowercase letter
			throw invalidRangeException;
		}
	}
	else if (start > 65 /*A*/ && start < 90 /*Z*/) {
		// if the start is an uppercase letter but is not 'A' or 'Z' it will throw this
		throw invalidCharacterExeption;
	}
	else if (start > 97 /*a*/ && start < 122 /*z*/) {
		// if the start is a lowercase letter but is not 'a' or 'z' it will throw this
		throw invalidCharacterExeption;
	}
	else {
		// if the original start is not a lowercase letter or an uppercase letter
		throw invalidRangeException;
	}

	// return the changed start if the start was changed
	return start;
}
