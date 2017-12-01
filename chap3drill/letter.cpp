// read and write a first name
#include "std_lib_facilities.h"
int main() {
	cout << "Enter the name of the person you want to write to: ";
	string first_name; // first_name is a variable of type string
	cin >> first_name; // read characters into first_name
	cout << "Enter age of " << first_name << ": ";
	int age;
	cin >> age;
	cout << "Enter the name of another friend: ";
	string friend_name;
	cin >> friend_name;
	cout << "Is " << friend_name << " male (enter 'm') or female (enter 'f'): ";
	char friend_sex = 0;
	cin >> friend_sex;
	cout << "Dear " << first_name
			<< ",\n\n    How are you?  I am fine.  I miss you.\n"
			<< "Have you seen " << friend_name << " lately?  ";
	if (friend_sex == 'f')
		cout << "If you see " << friend_name << " please ask her to call me.\n";
	if (friend_sex == 'm')
		cout << "If you see " << friend_name << " please ask him to call me.\n";
	cout << "I hear you just had a birthday and you are " << age
			<< " years old.\n";
	if (age <= 0 || 110 <= age)
		simple_error(" You're kidding!");
	if (age < 12)
		cout << "Next year you will be " << age + 1 << ".\n";
	if (age == 17)
		cout << "Next year you will be able to vote.\n";
	if (age > 70)
		cout << "I hope you are enjoying retirement.\n";
}
