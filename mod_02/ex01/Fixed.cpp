#include "Fixed.hpp"

static int power(const int a, const int b) {
    int result = 1;

    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    if (b < 0)
        return 1 / power(a, -b);
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

static int round(const float a) {
    float res = a - (int)a;
    if (res < 0.5)
        return (int)a;
    return (int)a + 1;
}

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->raw_value = 0;
}

Fixed::Fixed(int val) {
    std::cout << "Int constructor called" << std::endl;
    this->raw_value = val << this->frac_bits;
}

Fixed::Fixed(float val) {
    std::cout << "Float constructor called" << std::endl;
    this->raw_value = round(val * (float)power(2, this->frac_bits));
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->raw_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->raw_value = raw;
}

int Fixed::toInt(void) const {
    return this->raw_value >> this->frac_bits;
}

float Fixed::toFloat(void) const {
    float val = (float)this->raw_value;
    return val / power(2, this->frac_bits);
}

Fixed & Fixed::operator=(Fixed const & other) {
    std::cout << "Copy assignment operator called" << std::endl;

    this->raw_value = other.raw_value;
    return *this;
}

std::ostream & operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}