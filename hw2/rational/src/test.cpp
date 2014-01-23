#include "rational.h"
#include "gcd.h"
#include <iostream>
#include <iomanip>

int main() {
  //std::cout << gcd(1,3) << std::endl;

  Rational a = Rational{ 1, 3 }; // the number 1/3
  auto b = Rational{ -6, 7 }; // the number -6/7
  std::cout << a << " * " << b << " = " << a * b << "\n";
  std::cout << "Now for something more complicated...\n";
  std::cout << "a / ( a + b / a ) = " << a / ( a + b / a ) << "\n";

  auto phi = Rational{ 1 };

  for( int i = 0; i < 10; ++i ) {
    phi = 1 / ( 1 + phi );
    std::cout << phi << "\n";
  }
  std::cout << std::setprecision( 15 );
  std::cout << "phi = " << ( 1 + phi ).to_double() << "\n";

  return 0;
}
