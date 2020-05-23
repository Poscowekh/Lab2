#ifndef DATATYPES_H
#define DATATYPES_H
#include <iostream>

//No log

using namespace std;
template <class TypeReal, class TypeIm>
class Complex
{
    private:
        TypeIm imaginary;
        TypeReal real;
    public:
        Complex()
        {
            real = 0;
            imaginary = 0;
        };
        Complex(TypeReal re, TypeIm im){
            real = re;
            imaginary = im;
        };
        void PrintComplex(){
            cout << real << " + " << imaginary << 'i' << endl;
        };
        TypeReal GetReal(){
            return real;
        };
        TypeIm GetImaginary(){
            return imaginary;
        };
        Complex<TypeReal, TypeIm> GetConjugate()
        {
            return Complex<TypeReal, TypeIm>(real, -imaginary);
        };
        void Conjugate()
        {
            imaginary = -imaginary;
        };
        Complex<TypeReal, TypeIm>& operator+=(const Complex<TypeReal, TypeIm>& complex)
        {
            imaginary += complex.imaginary;
            real += complex.real;
            return *this;
        };
        Complex<TypeReal, TypeIm>& operator-=(const Complex<TypeReal, TypeIm>& complex)
        {
            imaginary -= complex.imaginary;
            real -= complex.real;
            return *this;
        };
        Complex<TypeReal, TypeIm>& operator*=(const Complex<TypeReal, TypeIm>& complex)
        {
            real = real * complex.real - imaginary * complex.imaginary;
            imaginary = real * complex.imaginary + imaginary * complex.real;
            return *this;
        };
        Complex<TypeReal, TypeIm>& operator/=(const Complex<TypeReal, TypeIm>& complex)
        {
            real = (real * complex.real + imaginary * complex.imaginary)/
                    (complex.real * complex.real + complex.imaginary * complex.imaginary);
            imaginary = (imaginary * complex.real - real * complex.imaginary)/
                    (complex.real * complex.real + complex.imaginary * complex.imaginary);
            return *this;
        };
        const Complex<TypeReal, TypeIm> operator+(const Complex<TypeReal, TypeIm>& complex) const
        {
            return Complex<TypeReal, TypeIm>(*this) += complex;
        };
        const Complex<TypeReal, TypeIm> operator-(const Complex<TypeReal, TypeIm>& complex) const
        {
            return Complex<TypeReal, TypeIm>(*this) -= complex;
        };
        const Complex<TypeReal, TypeIm> operator*(const Complex<TypeReal, TypeIm>& complex) const
        {
            return Complex<TypeReal, TypeIm>(*this) *= complex;
        };
        const Complex<TypeReal, TypeIm> operator/(const Complex<TypeReal, TypeIm>& complex) const
        {
            return Complex<TypeReal, TypeIm>(*this) /= complex;
        };
        Complex<TypeReal, TypeIm> operator-()
        {
            Complex<TypeReal, TypeIm> tmp(*this);
            tmp.real *= -1;
            tmp.imaginary *= -1;
            return tmp;
        };
        bool operator==(const Complex<TypeReal, TypeIm>& complex) const
        {
            return (this->real == complex.real && this->imaginary == complex.imaginary);
        };
        bool operator!=(const Complex<TypeReal, TypeIm>& complex) const
        {
            return !(*this == complex);
        };
        Complex<TypeReal, TypeIm>& operator++()
        {
            imaginary += 1;
            real += 1;
            return *this;
        };
        Complex<TypeReal, TypeIm>& operator--()
        {
            imaginary -= 1;
            real -= 1;
            return *this;
        };
};

#endif // DATATYPES_H
