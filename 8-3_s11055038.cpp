#include<iostream>
#include<cmath>   //for absolute value
using namespace std;

class Complex {
public:
	Complex();    //default constructor => 0 + 0*i
	Complex(double real, double imaginary);   //real + imaginary*i
	Complex(double realpart);                //realpart + 0*i
	double getreal() const { return real; }
	double getimaginary() const { return imaginary; }

	friend const Complex operator +(Complex& c1, Complex& c2);
	friend const Complex operator -(Complex& c1, Complex& c2);
	
	friend bool operator ==(Complex& c1, Complex& c2);
	friend ostream& operator<<(ostream& ouputStream, const Complex& c);
	friend istream& operator>>(istream& inputStream, Complex& c);
private:
	double real;
	double imaginary;
};

int main(void) {
	const Complex i(0, 1);
	Complex num1, num2;     //two complex numbers
	cout << "Enter two complex numbers to operate." << endl;
	cout << "Enter real part and imaginary with a space: ";
	cin >> num1;
	cout << "Enter real part and imaginary with a space: ";
	cin >> num2;

	cout << endl;
	Complex sum = num1 + num2;    //sum of two complex numbers
	cout << "Complex1 + complex2= " << sum << endl;

	Complex diff = num1 - num2;   //difference of two complex numbers
	cout << "Complex1 - complex2= " << diff << endl;

	/*Complex pro = num1 * num2;    product of two complex numbers
	cout << "Complex1 * complex2= " << pro << endl;*/

	cout << endl;
	if (num1 == num2) {
		cout << "Complex1 is equal to complex2=> " << num1 << endl;
	}
	else {
		cout << "Complex1 is not equal to complex2." << endl;
		cout << "Complex1=> " << num1 << endl;
		cout << "Complex2=> " << num2 << endl;
	}

	system("PAUSE");
	return 0;
}

//class Complex
//default constructor
Complex::Complex() {
	real = 0;
	imaginary = 0;
}

//constructor of 2 variables
Complex::Complex(double real, double imaginary) {
	this->real = real;
	this->imaginary = imaginary;
}

//constructor of 1 variables
Complex::Complex(double realpart) {
	this->real = realpart;
	imaginary = 0;
}

//operator +
const Complex operator +(Complex& c1, Complex& c2) {
	int realSum = c1.real + c2.real;
	int imaginarySum = c1.imaginary + c2.imaginary;

	return Complex(realSum, imaginarySum);
}

//operator -
const Complex operator -(Complex& c1, Complex& c2) {
	int realSub = c1.real - c2.real;
	int imaginarySub = c1.imaginary - c2.imaginary;

	return Complex(realSub, imaginarySub);
}


//operator ==
bool operator ==(Complex& c1, Complex& c2) {
	return ((c1.real == c2.real) && (c1.imaginary == c2.imaginary));
}

//operator <<
ostream& operator<<(ostream& ouputStream, const Complex& c) {
	if (c.imaginary < 0) {
		ouputStream << c.real << " - " << abs(c.imaginary) << "i";
	}
	else {
		ouputStream << c.real << " + " << c.imaginary << "i";
	}

	return ouputStream;
}

//operator >>
istream& operator>>(istream& inputStream, Complex& c) {
	double inputReal;
	double inputImag;
	inputStream >> inputReal;
	inputStream >> inputImag;

	c = Complex(inputReal, inputImag);

	return inputStream;
}