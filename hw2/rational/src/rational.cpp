#include "rational.h"
#include "gcd.h"

#include <stdexcept>
#include <ostream>
#include <iostream>

// Implement this
const Rational Rational::inverse() const {
  /* Return the Rational number 1 / current rational */
  return Rational{ this->den(), this->num() };
}

// Implement this
Rational::sign_type Rational::sign() const {
  /* Return, as a sign_type, the sign of the Rational */
  if (this->den()>=0 && this->num()>=0){return POSITIVE;}
  else {return NEGATIVE;}
}

/* Print the value num/den to the supplied output stream, or 0 if 
 * the Rational happens to be identically zero.
 */
std::ostream& operator<<( std::ostream &os, const Rational &ratio ) {
  if( ratio == 0 ) {
    os << "0";
  } else {
    if( ratio.sign() == Rational::NEGATIVE ) {
      os << "-";
    }
    os << std::abs( ratio.num() ) << "/" << std::abs( ratio.den() );
  }
  return os;
}

/* This function will be called whenever the 
 * Rational is constructed from integers that
 * are supplied as numerator and denominator.
 * It should reduce the fraction to lowest terms;
 * for example, when we try to construct a
 * Rational{ 4, -8 }, this is the function that
 * will cause the number to be exactly the same
 * as Rational{ -1, 2 }. Numerators should be
 * the only value potentially negative after
 * the call to ::normalize().
 * Throw bad_rational if there is an attempt
 * to set one with a zero denominator.
 */
void Rational::normalize() {
  // You should implement
  intmax_t n = abs(_num);
  intmax_t d = abs(_den);
  //std::cout << n << std::endl;
  intmax_t g = gcd( n, d);
  if (g==0) {bad_rational();}
  if (_den<0){
    this->_den = abs(d/g);
    this->_num = -n/g;
  }
  else{
    this->_den = _den/g;
    this->_num = _num/g;
  }
}

// Return the float precision number corresponding to the Rational
float Rational::to_float() const {
  // You should implement
  float f = (float)num()/(float)den();
  return f;
}

// Return the double precision number corresponding to the Rational
double Rational::to_double() const {
  // You should implement
  double d = (double)num()/(double)den();
  return d;
}
