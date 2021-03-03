#include <stdio.h>
struct Fraction{
    int numerator;
    int denominator;
};

typedef struct Fraction Fraction;

//declarations
Fraction add(Fraction, Fraction);
Fraction subtract(Fraction, Fraction);
Fraction multiply(Fraction, Fraction);
Fraction divide(Fraction, Fraction);
Fraction get_fraction(int, int);

//Everything above is a Header File.


int main() {
    Fraction a =get_fraction(2,3);
    Fraction b =get_fraction(5,6);
    Fraction c =multiply(a,b);
    printf("%d/%d\n",c.numerator,c.denominator);
}

int __get_gcd(int a,int b) {
    if(b==0) {
        return a;
    }
    return __get_gcd(b,a%b);
}

Fraction __reduceFrac(Fraction x){
    int gcd = __get_gcd(x.numerator, x.denominator);
    x.numerator/=gcd;
    x.denominator/=gcd;
    return x;
}

Fraction get_fraction(int a, int b)
{
    Fraction frac;
    frac.denominator = b;
    frac.numerator = a;
    return __reduceFrac(frac);
}


Fraction subtract(Fraction a, Fraction b) {
    Fraction frac;
    frac.denominator = a.denominator * b.denominator;
    frac.numerator = a.numerator*b.denominator - b.numerator*a.denominator;
    return __reduceFrac(frac);
}

Fraction multiply(Fraction a, Fraction b) {
    Fraction frac;
    frac.denominator = a.denominator * b.denominator;
    frac.numerator = a.numerator*b.numerator;
    return __reduceFrac(frac);
}

Fraction divide(Fraction a, Fraction b) {
    Fraction frac;
    frac.denominator = a.denominator * b.numerator;
    frac.numerator = a.numerator*b.denominator;
    return __reduceFrac(frac);
}

Fraction add(Fraction a, Fraction b) {
    Fraction frac;
    frac.denominator = a.denominator * b.denominator;
    frac.numerator = a.numerator*b.denominator + b.numerator*a.denominator;
    return __reduceFrac(frac);
}