#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void getRoots(double a, double b, double c);

int main() {

	string input = "";
	double a = 0.0, b = 0.0, c = 0.0;
	int spaces = 1;

	cout << "Program computes and prints the real roots of a quadratic polynomial a*x^2 + b*x + c\n";
	cout << "Enter three real numbers a, b, and c, all separated by spaces: ";

	// get all nums from a single line:
	getline(cin, input);
	input += " ";
	string temp = "";
	for (int i = 0; i < input.length(); i++) {
		if (input[i] != ' ') {
			temp += input[i];
		}
		else {
			if (spaces == 1) {
				a = stod(temp.c_str());
				spaces++;
				temp = "";
			}
			else if (spaces == 2) {
				b = stod(temp.c_str());
				spaces++;
				temp = "";
			}
			else if (spaces == 3) {
				c = stod(temp.c_str());
				spaces = 1;
				temp = "";
			}
		}
	}

	// get roots:
	getRoots(a, b, c);

	return 0;
}

void getRoots(double a, double b, double c) {
	double root1 = 0.0;
	double root2 = 0.0;

	// linear case:
	if (a == 0 && b != 0) {
		root1 = -(c / b);
		cout << "The only root for the linear case of " << b << "*x + " << c << " = 0 is: " << root1 << "\n";
	}
	// inconsistent case:
	else if (a == 0 && b == 0 && c != 0) {
		cout << "No roots for the constant function " << c << "\n";
	}
	// degenerate case:
	else if (a == 0 && b == 0 && c == 0) {
		cout << "No roots for the degenerate function 0 = 0\n";
	}
	// others:
	else {
		// find the discriminant:
		int discrim = (b * b) - (4 * a * c);

		// equal roots
		if (discrim == 0) {
			root1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
			cout << "The quadratic polynomial " << a << "*x^2 + " << b << "*x + " << c << " has two equal real roots:\nroot1 = root2 = " << root1 << "\n";
		}
		// distinct roots:
		else if (discrim > 0){
			root1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
			root2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
			cout << "The quadratic polynomial " << a << "*x^2 + " << b << "*x + " << c << " has two distinct real roots:\nroot1 = " << root1 << " root2 = " << root2 << "\n";
		}
		// complex roots:
		else if (discrim < 0) {
			cout << "The quadratic polynomial " << a << "*x^2 + " << b << "*x + " << c << " has two complex roots" << "\n";
		}
	}
}