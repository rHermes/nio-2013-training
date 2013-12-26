#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//TODO: This is not optimal. It takes to long. I did extensive work here, and found
// A way to do it mathematically, but I couldn't code it. The trick here is that
// a * b * c = a + b + c
// Then the worst case is
// a * b * c <= 3a
// Then we have
// b * c <= 3
// When
// a >= b >= c
//
// REMEMBER THAT!
//
bool spesielt(unsigned long long t) {
	unsigned long long product, sum;
	int single;

	product = 1;
	sum = 0;

	while (t > 0) {
		single = t % 10;
		t /= 10;

		sum += single;
		product *= single;
	}

	return (sum == product);
}

int main() {
	unsigned long long m, n;
	int answers = 0;
	
	string temp;
	getline(cin, temp);
	stringstream(temp) >> m;
	getline(cin, temp);
	stringstream(temp) >> n;
	
	for (unsigned long long i = m; i <= n; i++) {
		if (spesielt(i))
			answers++;
	}
	cout << answers << endl;
	return 0;
}
