#include "std_lib_facilities.h"

int main() {
	cout << "write stream of white-separated integers, terminate with '|': ";
	double smallest = numeric_limits<double>::max();
	double largest = numeric_limits<double>::lowest();
	double val;
	string unit;
	while (cin >> val >> unit) {
		cout << val << ' ' << unit;

		double val_in_meters;
		if (unit == "m") val_in_meters = val;
		if (unit == "cm") val_in_meters = val / 100.;
		if (unit == "in") val_in_meters = val * 2.54 / 100.;
		if (unit == "ft") val_in_meters = val * 12. * 2.54 / 100.;

		if (val_in_meters < smallest) {
			cout << " the smallest so far";
			smallest = val_in_meters;
		}
		if (val_in_meters > largest) {
			cout << " the largest so far";
			largest = val_in_meters;
		}
		cout << '\n';
	}
	return 0;
}
