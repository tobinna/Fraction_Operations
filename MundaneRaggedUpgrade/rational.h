#pragma once
using namespace std;
class rational{

  //private:
public:
  int num;
  int den;

   
  
  rational();
  void printValue(int a, int b, int c);
  void setValues(void);
  void multiply(rational d);
  void divide(rational d);
  void add(rational d);
  void subtract(rational d);
  int gcd(int a, int b);
  void testread(int& a, int& b);
  int testmultiply(int a, int b);
  int testdivide(int a, int b);
  int testadd(int a, int b);
  int testminus(int a, int b);
  void testoperation(char& a);
  };