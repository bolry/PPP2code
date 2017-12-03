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
		if (unit == "m") // meters
			val_in_meters = val;
		else if (unit == "cm") // centimeters
			val_in_meters = val / 100.;
		else if (unit == "in") // inches
			val_in_meters = val * 2.54 / 100.;
		else if (unit == "ft") // feet
			val_in_meters = val * 12. * 2.54 / 100.;
		else if (unit == "|") // terminator
			break;
		else
			error("unknown unit `" + unit + '\'');

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
