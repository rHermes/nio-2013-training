#include <iostream>
#include <string>
#include <algorithm>    // std::sort

using namespace std;

//TODO: This is not fully working. It only got a 80/100 on their tests, but
// I couldn't figure out why it was not working at the current time.
bool revsort(int i, int j) { return (i>j); }

int main() {
	// mulige ressurser
	int N = 0;
	cin >> N;
	//N = 1000;
	long long hus = 0;
	long long temp = 0;
	long long * reso = new long long[N];
	for (int i = 0; i < N; i++) {
		cin >> temp;
		reso[i] = temp;
	}
	// sort array
	sort(reso, reso + N);
	
	long long profit;
	// last element
	int last = N - 1;
	while (reso[last-2] > 0) {
		if (reso[last-3] > 0) {
            // what we can divide with.
			profit = reso[last-2];
			reso[last] -= profit;
			reso[last-1] -= profit;
			reso[last - 2] = 0;
			hus += profit;
		}
		else {
			hus += reso[last-2];
			break;
		}
		sort(reso, reso + N);
	}

	delete[] reso;
	cout << hus << endl;
	return 0;
}
