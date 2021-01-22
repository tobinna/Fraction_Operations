#include <iostream>
#include "application.h"
#include "rational.h"
#include <limits.h>

using namespace std;

rational::rational(){
  num = 1;
  den = 1;
}

int rational::gcd(int a, int b) {
	int x = a;
	int y = b; 

	while (x != y) {
		if (x < 0) {
			x = -x;
		}
		if (y < 0) {
			y = -y;
		}
		if (x > y) {
			x = x - y;
		}
		else
			y = y - x;
	}

	return x;
}

void rational :: printValue(int a, int b, int c){
    cout << "This fraction is: ";
    cout << a/c << "/";
    cout << b/c << endl;

}

void rational :: setValues(void)  {
    int a, b;
    cout << "Please enter a rational number (numerator followed by denominator): ";
    cin >> a >> b;
    testread(a,b);
    num = a;
    den = b;
  }

  void rational :: multiply(rational d){
    rational second;
    second.setValues();
    testmultiply(num, second.num);
    testmultiply(den, second.den); 
    if ((testmultiply(num, second.num) == 1) || (testmultiply(den, second.den) == 1)){
      cout << "\nTest has failed. ";
    }
    else {
    int x = num*second.num;
    int y = den*second.den;
    int z = gcd(x,y);
    printValue(x, y, z);
    }
  }

  void rational :: divide(rational d){
    rational second;
    second.setValues();
    testdivide(num, second.num);
    testdivide(den, second.den); 
    if ((testdivide(num, second.num) == 1) || (testdivide(den, second.den) == 1)){
      cout << "\nTest has failed. ";
    }
    else{
    int x = num*second.den;
    int y = den*second.num;
    int z = gcd(x,y);
    printValue(x, y, z);
    }
  }

  void rational :: add(rational d){
    rational second;
    second.setValues();
    testadd(num, second.num);
    testadd(den, second.den); 
    if ((testadd(num, second.num) == 1) || (testadd(den, second.den) == 1)){
      cout << "\nTest has failed. ";
    }
    else{
    int x = second.num*den + second.den*num;
    int y = den*second.den;
    int z = gcd(x,y);
    printValue(x, y, z);
    }
  }

  void rational :: subtract(rational d){
    rational second;
    second.setValues();
    testminus(num, second.num);
    testminus(den, second.den); 
    if ((testminus(num, second.num) == 1) || (testminus(den, second.den) == 1)){
      cout << "\nTest has failed. ";
    }
    int x = second.den*num - second.num*den;
    int y = den*second.den;
    int z = gcd(x,y);
    printValue(x, y, z);
  }

  void rational :: testread(int& a, int& b){
    try{
      if (cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        throw(1);
      }
      cout << "This input has been tried" << endl;
    }
    catch(...){
      cout << "These inputs are invalid" << endl;
      cout << "Enter a different numerator and denominator: ";
      cin >> a >> b;
      testread(a,b);
    }
  }

  void rational :: testoperation(char& a){
    try{
      if (a == '*' || a == '/' || a == '+' || a == '-' ){
        cout << "This operation is fine\n";
      }
       else{
        throw(1);
      }
  }
    catch(...){
      cout << "The input is invalid" << endl;
      cout << "Please enter an operation character (+, -, * or /): ";
      cin >> a;
      testoperation(a);
    }
    
  }
  int rational :: testmultiply(int a, int b){
    try{
      if (a<0){
        a=-a;
      }
      if (b<0){
        b=-b;
      }
      if (((INT_MAX/a) < b) || ((INT_MIN/a) > b)){
        throw(2);
      }
    }
    catch(...){
      return 1;
    }
    return 0;
  }

  int rational :: testdivide(int a, int b){
    try{
      if (a<0){
        a=-a;
      }
      if (b<0){
        b=-b;
      }
      if (((INT_MAX*a) < b) || ((INT_MIN*a) > b)){
        throw(2);
      }
    }
    catch(...){
      return 1;
    }
    return 0;
  }

 int rational :: testadd(int a, int b){
    try{
      if (((INT_MAX - a) < b) || ((INT_MIN + a) > b)){
        throw(2);
      }
    }
    catch(...){
      return 1;
    }
    return 0;
  } 

  int rational :: testminus(int a, int b){
    try{
      if (((INT_MAX + a) < b) || ((INT_MIN - a) > b)){
        throw(2);
      }
    }
    catch(...){
      return 1;
    }
    return 0;
  }
