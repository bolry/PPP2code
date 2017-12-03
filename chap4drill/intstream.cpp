#include "std_lib_facilities.h"

int main() {
	cout << "write stream of white-separated integers, terminate with '|': ";
	double smallest = numeric_limits<double>::max();
	double largest = numeric_limits<double>::lowest();
	double val;
	while (cin >> val) {
		cout << val;
		if (val < smallest) {
			cout << " the smallest so far";
			smallest = val;
		}
		if (val > largest) {
			cout << " the largest so far";
			largest = val;
		}
		cout << '\n';
	}
	return 0;
}
