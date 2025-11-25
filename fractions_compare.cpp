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
        if ((other.numerator == numerator) && (other.denominator == denominator))
            return true;
        else if ((numerator) && (other.numerator))
        {
            if (!(other.numerator % numerator) && !(other.denominator % denominator))
            {
                int ratio = other.denominator / denominator;
                int numerator_temp = other.numerator / ratio;
                int denominator_temp = other.denominator / ratio;
                if ((numerator_temp == numerator) && (denominator_temp == denominator))
                    return true;
            }
            else if (!(numerator % other.numerator) && !(denominator % other.denominator))
            {
                int ratio = denominator / other.denominator;
                int numerator_temp = numerator / ratio;
                int denominator_temp = denominator / ratio;
                if ((numerator_temp == other.numerator) && (denominator_temp == other.denominator))
                    return true;
            }
        }
        else if (numerator == other.numerator)
            return true;
        return false;
    }
    bool operator!= (const Fraction& other)
    {
        return !(*this == other);
    }
    bool operator> (const Fraction& other)
    {
        double fraction_own = static_cast<double>(numerator) / static_cast<double>(denominator);
        double fraction_other = static_cast<double>(other.numerator) / static_cast<double>(other.denominator);

        return (fraction_own > fraction_other);
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
        Fraction f1(3, 4);
        Fraction f2(6, 11);

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

