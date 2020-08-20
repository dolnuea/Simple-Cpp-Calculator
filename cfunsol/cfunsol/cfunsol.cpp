
/* author: Dolunay Dagci
 *
 * This program makes calculation of various classes of cpp's math class. For example finding the cosine, arc cosine, hyperbolic cosine, natural and common logarithm.
 * It lets the user make choices, 1 for finding the cosine; 2 for finding logarithms; 3 for conversion between decimal-hexadecimal; 4 for exiting the program. All these choices except
 * choice number 4, have sub choices. The choice for finding cosine divides into parts: Finding the cosine[1],  finding the arc cosine[3], and finding the hyperbolic cosine[3].
 * The choice for finding logarithm divides into 2 parts: Finding the common logarithm[1] and finding the natural logarithm[2]. And this program also lets the user convert from hexade-
 * cimal to decimal, or decimal to hexadecimal. It makes it able for user to decide whether you want lowercase, or uppercase when converting from decimal to hexadecimal.
 *
 * Due Date: 09/21/2019
 * Fixed Date: 9/30/2019
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.14159265 //I defined pi in order to properly calculate cosines. 
using namespace std;


void DecToHex() {
	int num;
	cout << "Enter a decimal number: ";
	cin >> num;
	cout << "Uppercase[false] or Lowercase[true]" << endl;
	bool upperlower;
	cin >> boolalpha >> upperlower; //I used boolapha for true false input

	if (upperlower) {
		cout << "\nDecimal " << std::dec << num << " to Hexadecimal with true lower case: " << showbase << nouppercase << std::hex << num;
	}
	else {
		cout << "\nDecimal " << std::dec << num << " to Hexadecimal with false lower case - upper case: " << showbase << std::hex << uppercase << num; 
	}

}
void HexToDec() {
	cout << "Enter a hexadecimal number : ";
	long int num;
	cin >> std::hex >> num;
	cout << "\nHexadecimal " << showbase << std::hex << num << " to Decimal: " << std::dec << num;
}
int main() {

	while (true)
	{
		int a;
		cout << endl << "Find cosine[1]" << endl << "Find logarithms[2]" << endl << "Conversion between decimal-hexadecimal[3]" << endl << "Exit[4]" << endl;
		cin >> a;
		int conversion;
		//Cosine
		if (a == 1) {
			cout << "Cosine selected:" << endl << "Find cosine[1]" << endl << "Find arc cosine[2]" << endl << "Find hyperbolic cosine[3]" << endl;
			int cosine;
			cin >> cosine;
			double number, numberdegreecos, numberdegreeacos, result;
			cout.setf(ios::fixed | ios::showpoint);
			switch (cosine)
			{
			case 1:
				cout << "Finding cosine. Please enter a floating point number (in radians)." << endl;
				cin >> number;
				numberdegreecos = (number * 180) / PI; //convert radians to degrees to make cos function efficient
				result = cos((PI * numberdegreecos) / 180.0);
				cout << "Cosine of " << setprecision(3) << number << " is " << result;
				break;
			case 2:
				cout << "Finding arc cosine. Please enter a floating point number (in radians)." << endl;
				cin >> number;
				numberdegreeacos = (number * 180) / PI;  //convert radians to degrees to make acos function efficient
				/*
				 * I've benefited from the library mathematical functions of cpp: acos for calculating arc cosine
				 * and cosh for calculating hyperbolic cosine.
				 */
				result = acos(number) * 180.0 / PI; 
				cout << "Arc Cosine of " << setprecision(3) << number << " is " << result;
				break;
			case 3:
				cout << "Finding hyperbolic cosine. Please enter a floating point number (in radians)." << endl;
				cin >> number;
				result = cosh(number);
				cout << "Hyperbolic Cosine of " << setprecision(3) << number << " is " << result;
				break;
			default:
				cout << "Invalid input. Please enter a proper number." << endl;
				cin >> cosine;
				break;
			}
		}

		//Logarithm
		else if (a == 2) {
			cout << "Find logarithms:" << endl << "Find common logarithm[1]" << endl << "Find natural logarithm[2]" << endl;
			int logarithm;
			cin >> logarithm;
			double number;
			double result;
			cout.setf(ios::showpos);
			switch (logarithm)
			{
			case 1:
				cout << "Finding common logarithm. Please enter a floating point number." << endl;
				cin >> number;
				result = log10(number); //I've used the log base 10 from library functions of cpp for this calculation.
				cout << "Common Logarithm of " << setprecision(3) << number << " is " << result;
				break;
			case 2:
				cout << "Finding natural logarithm. Please enter a floating point number." << endl;
				cin >> number;
				result = log(number);
				cout << "Natural Logarithm of " << setprecision(3) << number << " is " << result;
				break;
			default:
				cout << "Invalid input. Please enter a proper number." << endl;
				cin >> logarithm;
				break;
			}
		}

		//Conversion
		else if (a == 3) {

			cout.unsetf(ios::fixed | ios::showpoint | ios::showpos);
			cout << "Conversions:" << endl << "Hexadecimal to decimal[1]" << endl << "Decimal to hexadecimal[2]" << endl;

			cin >> conversion;
			if (conversion == 1) {
				HexToDec();

			}
			else if (conversion == 2) {
				DecToHex();
			}
		}
		else if (a == 4) {
			cout << "Exit";
			return(0);
		}
	}
}




