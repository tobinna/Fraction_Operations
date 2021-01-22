#include <iostream>
#include "application.h"
#include <limits.h>
#include "rational.h"

using namespace std;

application :: application(){
  cout << "the application constructor has been called\n";
}

void application :: run(){
  
  char operation, fin = 'e';

while (fin != 'a') {
  
  rational first;
  
  first.setValues();
  
  cout << "Please enter an operation character (+, -, * or /): ";
  cin >> operation;
  first.testoperation(operation);

  if (operation == '*'){
    first.multiply(first);
  }

  if (operation == '/'){
    first.divide(first);
  }

  if (operation == '+'){
    first.add(first);
  }

  if (operation == '-'){
    first.subtract(first);
  }
  cout << "Press any key to continue, or 'a' to end the programe: ";
  cin >> fin;
  }
 
}

void application :: test(){
rational test;
if (test.gcd(6,3) != 3){
  cout << "The code is broken! ";
}
else{
  cout << "The gcd code is fine! "<< endl;
}
if (test.testmultiply(INT_MAX, 2) == 0){
  cout << "The multiply test is broken! "<< endl;
}
else{
  cout << "The multply code is fine! "<< endl; 
}
if (test.testdivide(INT_MIN, 2) == 0){
  cout << "The division test is broken! "<< endl;
}
else{
  cout << "The division code is fine! "<< endl;
}
if (test.testadd(INT_MAX, 2) == 0){
  cout << "The addition test is broken! "<< endl;
}
else{
  cout << "The addition code is fine! "<< endl;
}
if (test.testminus(INT_MIN, 2) == 0){
  cout << "The subtraction test is broken! "<< endl;
}
else{
  cout << "The subtraction code is fine! "<< endl;
}
}

application :: ~application(){
    cout << "the application destructor has been called";
}



  