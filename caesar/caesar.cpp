#include <iostream>
#include <string>
#include <sstream>

#define OFFSET 65
#define END 90

using namespace std;


int main() {
	int rotate;
	string code;

	getline(cin, code);
	stringstream(code) >> rotate;

	getline(cin, code);
	
	int val;
	for (string::iterator it = code.begin(); it != code.end(); ++it) {
		val = (int)*it + rotate;
		if (val > END) {
			*it = OFFSET + (val - (END + 1));
		}
		else {
			*it += rotate;
		}
	}
	
	cout << code << endl;
	return 0;
}
