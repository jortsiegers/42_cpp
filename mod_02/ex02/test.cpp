#include "Fixed.hpp"
#include <cassert>

int main() {

    // Test default constructor
    {
        Fixed f1;
        assert(f1.getRawBits() == 0);
        assert(f1.toFloat() == 0.0f);
        assert(f1.toInt() == 0);
    }

    // Test int constructor
    {
        Fixed f2(42);
        assert(f2.getRawBits() == 42 * (1 << 8));
        assert(f2.toFloat() == 42.0f);
        assert(f2.toInt() == 42);
        assert(f2.getRawBits() == 42 << 8);
    }

    // Test float constructor
    {
        Fixed f3(4.2f);
        assert(f3.toFloat() - 4.23f < 0.01);
        assert(f3.toInt() == 4);
        assert(f3.getRawBits() == 1075);
    }

    // Test copy constructor
    {
        Fixed f3(4.2f);
        Fixed f4(f3);
        assert(f3.toFloat() - 4.23f < 0.01);
        assert(f3.toInt() == 4);
        assert(f3.getRawBits() == 1075);
    }

    // Test assignment operator
    {
        Fixed f1;
        Fixed f2(42);
        f1 = f2;
        assert(f1.getRawBits() == 42 * (1 << 8));
        assert(f1.toFloat() == 42.0f);
        assert(f1.toInt() == 42);

    }

    // Test comparison operators
    {
        Fixed f1;
        Fixed f3(4.2f);
        Fixed f4(f3);
        assert(f1 < f3);
        assert(f3 > f1);
        assert(f1 <= f3);
        assert(f3 >= f1);
        assert(f3 == f4);
        assert(f1 != f3);

    }

    // Test arithmetic operators
    {
        Fixed f1;
        Fixed f3(4.2f);
        Fixed f2(42);

        std::cout << f3.getRawBits() << std::endl;
        std::cout << f1.getRawBits() << std::endl;
        std::cout << (f1 + f3).getRawBits() << std::endl;
        assert((f1 + f3).getRawBits() == f3.getRawBits());
        assert((f1 - f3).getRawBits() == -f3.getRawBits());
        Fixed f10(42 + 4.2f);
        Fixed f11(42 - 4.2f);
        assert((f2 + f3).getRawBits() == f10.getRawBits());
        assert((f2 - f3).getRawBits() == f11.getRawBits());
        Fixed f4(f2.toFloat() * f3.toFloat());
        Fixed f6(f1.toFloat() * f3.toFloat());
        assert((f2 * f3).getRawBits() == f4.getRawBits());
        assert((f1 * f3).getRawBits() == f6.getRawBits());
        Fixed f5(f2.toFloat() / f3.toFloat());
        Fixed f7(f3.toFloat() / f1.toFloat());
        assert((f2 / f3).getRawBits() == f5.getRawBits());
        assert((f3 / f1).getRawBits() == f7.getRawBits());

    }

    // Test toInt and toFloat methods
    {

        Fixed f4(4.25f * 10);
        assert(f4.toInt() == 42);
        assert(f4.toFloat() == 42.5f);
        Fixed f5;
        f5 = f4;
        Fixed f6 = f4 + f5;
        assert(f6.toInt() == 85);
        assert(f6.toFloat() == 85.0f);

        Fixed f7 = f4 - f5;
        assert(f7.toInt() == 0);
        assert(f7.toFloat() == 0.0f);

        Fixed f8 = f4 * f5;
        assert(f8.toInt() == 1806);
        assert(f8.toFloat() == 1806.25);

        Fixed f9 = f4 / f5;
        assert(f9.toInt() == 1);
        assert(f9.toFloat() == 1.0f);
    }

    // Test getRawBits and setRawBits methods
    {

        Fixed f4(4.2f);
        Fixed f5;
        f5 = f4;
        Fixed f6 = f4 + f5;
        Fixed f10;
        f10.setRawBits(f6.getRawBits());
        assert(f6 == f10);

        Fixed f7 = f4 - f5;
        assert(f7.getRawBits() == 0);

        Fixed f8 = f4 * f5;
        assert(f8.getRawBits() == (f4 * f5).getRawBits());

        Fixed f9 = f4 / f5;
        assert(f9.getRawBits() == (f4 / f5).getRawBits());
    }


    // Test increment/decrement operators
    {
        Fixed f1(42);
        assert((++f1).getRawBits() == 42 * (1 << 8) + 1);
        assert((f1++).getRawBits() == 42 * (1 << 8) + 1);

        assert(f1.getRawBits() == 42 * (1 << 8) + 2);
        assert((--f1).getRawBits() == 42 * (1 << 8) + 1);
        assert((f1--).getRawBits() == 42 * (1 << 8) + 1);
        assert((++f1).getRawBits() == (42 << 8) + 1);
        assert((f1++).getRawBits() == (42 << 8) + 1);
        assert(f1.getRawBits() == (42 << 8) + 2);
        assert((--f1).getRawBits() == (42 << 8) + 1);
        assert((f1--).getRawBits() == (42 << 8) + 1);
        assert(f1.getRawBits() == (42 << 8));

    }

    // Test min and max functions
    {
        Fixed f2(42);
        Fixed f3(4.2f);
        assert(Fixed::min(f2, f3) == f3);
        assert(Fixed::max(f2, f3) == f2);
        assert(Fixed::min(f2, f3).getRawBits() == Fixed::min(f3, f2).getRawBits());
        assert(Fixed::max(f2, f3).getRawBits() == Fixed::max(f3, f2).getRawBits());
    }
    return (0);

}

