int main(){
    Complex complex1, complex2(2, 3);
    cout << "Enter an complex:" << endl;
    cin >> complex1;
    //show two complex
    cout << "Complex 1 is " << complex1 << "\t" << "Complex2 is " << complex2 << endl;
    //testing addition
    cout << "The addition of two complex is " << complex1+complex2 << endl;
    //testing substraction
    cout << "The substraction of two complex is " << complex1-complex2 << endl;
    //testing multiplication
    cout << "The multiplication of two complex is " << complex1*complex2 << endl;
    //testing negative
    cout << "The negative of complex1 is " << -complex1 << endl;
    //testing equal
    if(complex1==complex2){
        cout << complex1 << " is equals to " << complex2 << endl;
    }else{
        cout << complex1 << " is not equals to " << complex2 << endl;
    }
    //testing constant 'i'
    cout << 2*i << endl;

    return 0;
}