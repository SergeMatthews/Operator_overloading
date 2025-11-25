#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Fraction
{
private:
    int numerator;
    int denominator;
    Fraction() 
    {
        numerator = 0;
        denominator = 0;
    }
    int GCD(int a, int b);
    void ReduceFraction(int& num, int& denom);
public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
    {
        if (!denominator)
            throw std::invalid_argument("Division by 0! Fraction cannot be created.");
    }
    void PrintFraction()
    {
        cout << numerator << '/' << denominator;
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
    Fraction operator+ (const Fraction& other)
    {
        Fraction temp;
        if (denominator == other.denominator)
        {
            temp.numerator = numerator + other.denominator;
            temp.denominator = denominator;
        }
        else
        {
            temp.denominator = denominator * other.denominator;
            temp.numerator = (numerator * other.denominator) + (other.numerator * denominator);
            ReduceFraction(temp.numerator, temp.denominator);
        }
        return temp;
    }
    Fraction operator- (const Fraction& other)
    {
        Fraction temp;
        if (denominator == other.denominator)
        {
            temp.numerator = numerator - other.denominator;
            temp.denominator = denominator;
        }
        else
        {
            temp.denominator = denominator * other.denominator;
            temp.numerator = (numerator * other.denominator) - (other.numerator * denominator);
            ReduceFraction(temp.numerator, temp.denominator);
        }
        return temp;
    }
    Fraction operator* (const Fraction& other)
    {
        Fraction temp;
        temp.denominator = denominator * other.denominator;
        temp.numerator = numerator * other.numerator;
        ReduceFraction(temp.numerator, temp.denominator);
        return temp;
    }
    Fraction operator/ (const Fraction& other)
    {
        if (other.numerator)
        {
            Fraction temp;
            temp.numerator = numerator * other.denominator;
            temp.denominator = denominator * other.numerator;
            ReduceFraction(temp.numerator, temp.denominator);
            return temp;
        }
        else
        {
            Fraction temp;
            temp.numerator = temp.denominator = 0;
            return temp;
        }
            
    }
    Fraction& operator-()
    {
        numerator = -numerator;
        ReduceFraction(numerator, denominator);
        return *this;
    }
    Fraction& operator++()
    {
        numerator += denominator;
        ReduceFraction(numerator, denominator);
        return *this;
    }
    Fraction operator++(int)
    {
        Fraction temp = *this;
        numerator += denominator;
        ReduceFraction(numerator, denominator);
        return temp;
    }
    Fraction& operator--()
    {
        numerator -= denominator;
        ReduceFraction(numerator, denominator);
        return *this;
    }
    Fraction operator--(int)
    {
        Fraction temp = *this;
        numerator -= denominator;
        return temp;
    }

    friend std::ostream& operator<< (std::ostream& os, const Fraction& frac);
};



int main()
{
    setlocale(LC_ALL, "RU");
    
    int num{}, denom{};
    cout << "Введите числитель дроби 1: ";
    cin >> num;
    do {
        cout << "Введите знаменатель дроби 1: ";
        cin >> denom;
    } while (!denom);
    Fraction f1(num, denom);

    cout << "Введите числитель дроби 2: ";
    cin >> num;
    do {
        cout << "Введите знаменатель дроби 2: ";
        cin >> denom;
    } while (!denom);
    Fraction f2(num, denom);
    
    cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
    cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;
    cout << f1 << " * " << f2 << " = " << (f1 * f2) << endl;
    cout << f1 << " / " << f2 << " = " << (f1 / f2) << endl;
    cout << "++" << f1 << " * " << f2 << " = ";
    cout << (++f1 * f2) << endl;
    cout << "Значение дроби 1 = " << f1 << endl;
    cout << f1 << "--" << " * " << f2 << " = ";
    cout << (f1-- * f2) << endl;
    cout << "Значение дроби 1 = " << f1 << endl;
    

    return EXIT_SUCCESS;
}

int Fraction::GCD(int a, int b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    while (b)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::ReduceFraction(int& num, int& denom)
{
    int common = Fraction::GCD(num, denom);

    num /= common;
    denom /= common;

    if (denom < 0)
    {
        num = -num;
        denom = -denom;
    }
}

std::ostream& operator<< (std::ostream& os, const Fraction& frac)
{
    os << frac.numerator << '/' << frac.denominator;
    return os;
}