#include "std_lib_facilities.h"

int main() {
	cout << "write pairs of white-separated integer, terminate with '|': ";
	double val1;
	double val2;
	while (cin >> val1 >> val2) {
		if (val1 == val2)
			cout << "the numbers are equal";
		else {
			cout << "the smaller value is: ";
			if (val1 < val2)
				cout << val1;
			else
				cout << val2;
			cout << " the larger value is: ";
			if (val1 > val2)
				cout << val1;
			else
				cout << val2;
			if (abs(val1 - val2) < 1.0 / 100)
				cout << "\nthe numbers are almost equal";
		}
		cout << '\n';
	}
	return 0;
}
