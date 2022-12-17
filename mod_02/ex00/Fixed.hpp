#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>


class Fixed {
    public:
        Fixed();
        Fixed(const Fixed &src);
        ~Fixed();

        Fixed &operator=(const Fixed &other);

        int getRawBits(void) const;
        void setRawBits(int const raw);


    private:
        int raw_value;
        static const int frac_bits = 8;
        


};

#endif