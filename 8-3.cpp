#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Complex{
public:
    Complex();
    Complex(double real, double imaginary);
    Complex(double realPart);
    double getReal()const;
    double getImag()const;
    void setReal(double real);
    void setImag(double imag);
    friend ostream& operator <<(ostream& outputStream, const Complex& complex);
    friend istream& operator >>(istream& inputStream, Complex& complex);
private:
    double real;
    double imaginary;
};
const Complex i=Complex(0, 1);
const Complex operator +(const Complex& complex1, const Complex& complex2);
const Complex operator -(const Complex& complex1, const Complex& complex2);
const Complex operator *(const Complex& complex1, const Complex& complex2);
bool operator ==(const Complex& complex1, const Complex& complex2);
const Complex operator -(const Complex& complex1);

int main(){
    Complex complex1, complex2(2, 3);
    cout << "Enter an complex:" << endl;
    cin >> complex1;
    cout << "Complex 1 is " << complex1 << "\t" << "Complex2 is " << complex2 << endl;
    cout << "The addition of two complex is " << complex1+complex2 << endl;
    cout << "The substraction of two complex is " << complex1-complex2 << endl;
    cout << "The multiplication of two complex is " << complex1*complex2 << endl;
    cout << "The negative of complex1 is " << -complex1 << endl;
    if(complex1==complex2){
        cout << complex1 << " is equals to " << complex2 << endl;
    }else{
        cout << complex1 << " is not equals to " << complex2 << endl;
    }

    return 0;
}
Complex::Complex(){
    real=0;
    imaginary=0;
}
Complex::Complex(double real, double imaginary){
    this->real=real;
    this->imaginary=imaginary;
}
Complex::Complex(double realPart){
    real=realPart;
    imaginary=0;
}
double Complex::getReal()const{
    return real;
}
double Complex::getImag()const{
    return imaginary;
}
void Complex::setReal(double real){
    this->real=real;
}
void Complex::setImag(double imag){
    imaginary=imag;
}
const Complex operator +(const Complex& complex1, const Complex& complex2){
    double real=complex1.getReal()+complex2.getReal();
    double imaginary=complex1.getImag()+complex2.getImag();
    return Complex(real, imaginary);
}
const Complex operator -(const Complex& complex1, const Complex& complex2){
    double real=complex1.getReal()-complex2.getReal();
    double imaginary=complex1.getImag()-complex2.getImag();
    return Complex(real ,imaginary);
}
const Complex operator *(const Complex& complex1, const Complex& complex2){
    double real=complex1.getReal()*complex2.getReal()-complex1.getImag()*complex2.getImag();
    double imaginary=complex1.getReal()*complex2.getImag()+complex1.getImag()*complex2.getReal();
    return Complex(real, imaginary);
}
bool operator ==(const Complex& complex1, const Complex& complex2){
    return ((complex1.getReal()==complex2.getReal())
        && (complex1.getImag()==complex2.getImag()));
}
const Complex operator -(const Complex& complex){
    return Complex(-complex.getReal(), -complex.getImag());
}
ostream& operator <<(ostream& outputStream, const Complex& complex){
    outputStream << complex.real;
    if(complex.imaginary<0){
        outputStream << complex.imaginary << "i";
    }else{
        outputStream << "+" << complex.imaginary << "i";
    }
    return outputStream;
}
istream& operator >>(istream& inputStream, Complex& complex){
    double realPart, imagPart;
    cout << "Input real part> ";
    cin >> realPart;
    cout << "Input imaginary part> ";
    cin >> imagPart;
    complex.setReal(realPart);
    complex.setImag(imagPart);
    return inputStream;
}
