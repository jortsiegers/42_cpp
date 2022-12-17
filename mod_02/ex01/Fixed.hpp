#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>


class Fixed {
    public:
        Fixed();
        Fixed(const int val);
        Fixed(const float val);
        Fixed(const Fixed &src);
        ~Fixed();

        Fixed &operator=(const Fixed &other);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

    private:
        int raw_value;
        static const int frac_bits = 8;
};

// The out stream overloader
std::ostream & operator<<(std::ostream& os, const Fixed& fixed);

#endif