#include <iostream>
using std::cout;
using std::endl;

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
    {
        if (!denominator)
            throw std::invalid_argument("Division by 0! Fraction cannot be created.");
    }
    bool operator== (const Fraction& other)
    {
        return ((numerator * other.denominator) == (other.numerator * denominator));
    }
    bool operator!= (const Fraction& other)
    {
        return !(*this == other);
    }
    bool operator> (const Fraction& other)
    {
        return ((numerator * other.denominator) > (other.numerator * denominator));
    }
    bool operator>= (const Fraction& other)
    {
        return ((*this == other) || (*this > other));
    }
    bool operator< (const Fraction& other)
    {
        return !(*this >= other);
    }
    bool operator <= (const Fraction& other)
    {
        return !(*this > other);
    }
};

int main()
{
    try
    {
        Fraction f1(7, 6000);
        Fraction f2(5, 6000);

        cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << endl;
        cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << endl;
        cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << endl;
        cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << endl;
        cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << endl;
        cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what();
    }
   
    return EXIT_SUCCESS;
}
