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
    
        bool operator>(const Fixed &other);
        bool operator<(const Fixed &other);
        bool operator>=(const Fixed &other);
        bool operator<=(const Fixed &other);
        bool operator==(const Fixed &other);
        bool operator!=(const Fixed &other);
    
        Fixed operator+(const Fixed &other);
        Fixed operator-(const Fixed &other);
        Fixed operator*(const Fixed &other);
        Fixed operator/(const Fixed &other);

        Fixed &operator++();
        Fixed operator++(int number);
        Fixed &operator--();
        Fixed operator--(int number);

        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);

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