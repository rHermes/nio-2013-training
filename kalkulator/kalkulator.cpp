#include <iostream>
#include <string>
#include <sstream>
#include <sys/types.h>

using namespace std;

int main() {
	int lines;
	string line;
	
	// Get the amount of lines
	getline(cin, line);
	stringstream(line) >> lines;
	
	int64_t *svar;
	svar = new int64_t[lines];

	// main loop 
	int64_t a = 0LL;
	int64_t b = 0LL;
	char op;

	for (int i = 0; i < lines; i++) {
		getline(cin, line);
		stringstream(line) >> a >> op >> b;
		switch (op) {
		case '*':
			svar[i] = a * b;
			break;

		case '+':
			svar[i] = a + b;
			break;

		case '-':
			svar[i] = a - b;
			break;
		}
	}

	for (int i = 0; i < lines; i++) {
		cout << svar[i] << endl;
	}

	delete[] svar;
	return 0;
}
