#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define RIKTIG "RIKTIG"
#define LITE "FOR LITE"
#define STOR "FOR MYE"

int main() {
	int lines, hemmelig;
	string line;

	// Get the amount of lines
	getline(cin, line);
	stringstream(line) >> hemmelig >> lines;

	string * svar;
	svar = new string[lines];

	// main loop 
	unsigned int gjett;
	for (int i = 0; i < lines; i++) {
		getline(cin, line);
		stringstream(line) >> gjett;

		if (gjett == hemmelig) {
			svar[i] = RIKTIG;
		}
		else if (gjett > hemmelig) {
			svar[i] = STOR;
		}
		else {
			svar[i] = LITE;
		}
	}

	for (int i = 0; i < lines; i++) {
		cout << svar[i] << endl;
	}

	delete[] svar;
	return 0;
}
