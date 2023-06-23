#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#define INT_TYPE 0
#define FLOAT_TYPE 1
#define DOUBLE_TYPE 2
#define CHAR_TYPE 3
#define UNKNOWN_TYPE 4

#include <iostream>
#include <cmath>
#include <string>
#include <cfloat>
#include <ostream>
#include <iomanip>

class ScalarConverter
{
    private:
        std::string strip(std::string input);

        int getType(std::string input);
        bool checkInt(std::string input);
        bool checkFloat(std::string input);
        bool checkChar(std::string input);
        bool checkDouble(std::string input);

        void convertInt(std::string);
        void convertFloat(std::string);
        void convertChar(std::string);
        void convertDouble(std::string);

    public:
        ScalarConverter(void);
        ~ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &operator=(ScalarConverter const &assign);

        void convert(std::string toConvert);

};

#endif