#include "std_lib_facilities.h"

int main() {
	cout << "write pairs of white-separated integer, terminate with '|': ";
	int val1;
	int val2;
	while (cin >> val1 >> val2) {
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
		cout << '\n';
	}
	return 0;
}
