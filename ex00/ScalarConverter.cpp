#include "ScalarConverter.hpp"

//Convert constructors & destructors
ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::~ScalarConverter()
{
	// std::cout << "Destructor called" << std::endl;
}


ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    (void)src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &assign)
{
    (void)assign;
    return *this;
}

std::string ScalarConverter::strip(std::string input)
{
    unsigned long start = 0;
    while (start < input.length()) {
        if (isspace(input[start]))
            start++;
        else
            break;
    }

    unsigned long end = input.length() - 1;
    while (end >= 0) {
        if (isspace(input[end]))
            end--;
        else
            break;
    }

    // If string is all spaces, return empty string
    if (start > end)
        return "";

    return input.substr(start, end - start + 1);
}


bool ScalarConverter::checkInt(std::string input)
{
    std::string inputNoSign;

	if (input.find('.') != std::string::npos)
		return false;
    if (input[0] == '-' || input[0] == '+')
        inputNoSign = input.substr(1, input.length() - 1);
    else
        inputNoSign = input;

    for (unsigned long i = 0; i < inputNoSign.length(); i++) {
        if (!isdigit(inputNoSign[i]))
            return false;
    }
    
    try {
        std::stoi(input);
    } catch (std::invalid_argument &e) {
        return false;
    } catch (std::out_of_range &e) {
        return false;
    }
    
	return true;
}

bool ScalarConverter::checkFloat(std::string input)
{
    if (input == "-inff" || input == "+inff" || input == "nanf")
        return true;

	if ((input.find('.') == std::string::npos) || (input.find('f') == std::string::npos))
		return false;
    
    if (input.find('f') != input.length() - 1)
        return false;

    input = input.substr(0, input.length() - 1);

    if (input[0] == '-' || input[0] == '+')
        input = input.substr(1, input.length() - 1);

    int dotCount = 0;
    for (unsigned long i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            if (input[i] == '.' && dotCount == 0) {
                dotCount++;
            } else {
                return false;
            }
        }
    }
    
    try {
        std::stof(input);
    } catch (...) {
        return false;
    }
    return true;
}


bool ScalarConverter::checkDouble(std::string input)
{
    if (input == "-inf" || input == "+inf" || input == "nan")
        return true;

	if ((input.find('.') == std::string::npos))
		return false;

    if (input[0] == '-' || input[0] == '+')
        input = input.substr(1, input.length() - 1);

    int dotCount = 0;

    for (unsigned long i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            if (input[i] == '.' && dotCount == 0) {
                dotCount++;
            } else {
                return false;
            }
        }
    }
    
    try {
        std::stod(input);
    } catch (...) {
        return false;
    }
    return true;
}

bool ScalarConverter::checkChar(std::string input)
{
    if (input.length() != 1)
        return false;
    if (isdigit(input[0]))
        return false;
    return true;
}

int ScalarConverter::getType(std::string input) {
    for (unsigned long i = 0; i < input.length(); i++) {
        if (!isprint(input[i])) {
            return UNKNOWN_TYPE;
        }
    }

    if (this->checkChar(input)) 
        return CHAR_TYPE;
    if (this->checkFloat(input)) 
        return FLOAT_TYPE;
    if (this->checkDouble(input)) 
        return DOUBLE_TYPE;
    if (this->checkInt(input)) 
        return INT_TYPE;
    return UNKNOWN_TYPE;
};



void ScalarConverter::convertChar(std::string input) {
    char charValue = input[0];

	int intValue =  static_cast<int>(charValue);
	float floatValue =  static_cast<float>(charValue);
	double doubleValue =  static_cast<double>(charValue);

	std::cout << "Char: '" << charValue << "'" << std::endl;
	std::cout << "Int: " << intValue << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
	std::cout << "Double: " << doubleValue << std::endl;
}


void ScalarConverter::convertFloat(std::string input) {
    if (input == "+inff" || input == "-inff" || input == "nanf") {
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: " << input << std::endl;
        std::cout << "Double: " << input.substr(0, input.length() - 1) << std::endl;
        return ;
    }

    float floatValue = stof(input);

	if (floatValue >= 32 && floatValue <= 126)
	{
		char charValue =  static_cast<char>(floatValue);
		std::cout << "Char: '" << charValue << "'" << std::endl;
	}
	else if ((floatValue > -1.0 && floatValue < 32.0) || static_cast<int>(floatValue) == 127)
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: impossible" << std::endl;

	if (floatValue > -2147483649.0 && floatValue < 2147483647.0 + 1) {

		int intValue =  static_cast<int>(floatValue);
		std::cout << "Int: " << intValue << std::endl;
    }
	else
		std::cout << "Int: impossible" << std::endl;

	double doubleValue = static_cast<double>(floatValue);
	std::cout << "Float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
	std::cout << "Double: " << doubleValue << std::endl;
}

void ScalarConverter::convertDouble(std::string input) {
    if (input == "+inf" || input == "-inf" || input == "nan") {
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: " << input << "f" << std::endl;
        std::cout << "Double: " << input << std::endl;
        return ;
    }

    double doubleValue = stod(input);

	if (doubleValue >= 32 && doubleValue <= 126) {
		char charValue =  static_cast<char>(doubleValue);
		std::cout << "Char: '" << charValue << "'" << std::endl;
	}
	else if ((doubleValue  > -1 && doubleValue  < 32) || static_cast<int>(doubleValue) == 127)
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: impossible" << std::endl;

	if (doubleValue > -2147483649.0 && doubleValue < 2147483648.0) {
		int intValue =  static_cast<int>(doubleValue);
		std::cout << "Int: " << intValue << std::endl;
    }
	else
		std::cout << "Int: impossible" << std::endl;

	if (doubleValue >= -FLT_MAX && doubleValue <= FLT_MAX) {

		float floatValue = static_cast<float>(doubleValue);
		std::cout << "Float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
    }
	else {
        if (doubleValue < 0)
            std::cout << "Float: " << "-inff" << std::endl;
        else
            std::cout << "Float: " << "+inff" << std::endl;
    }

	std::cout << "Double: " << doubleValue << std::endl;
}

void ScalarConverter::convertInt(std::string input) {
    int intValue = stoi(input);

	if (intValue >= 32 && intValue <= 126)
	{
		char charValue = static_cast<char>(intValue);
		std::cout << "Char: '" << charValue << "'" << std::endl;
	}
	else if (intValue == 127 || (intValue >= 0 && intValue <= 31))
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: impossible" << std::endl;

	float floatValue = static_cast<float>(intValue);
	double doubleValue = static_cast<double>(intValue);

	std::cout << "Int: " << intValue << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
	std::cout << "Double: " << doubleValue << std::endl;

	return ;
}

void ScalarConverter::convert(std::string input)
{

    input = this->strip(input);
	int type = this->getType(input);
	switch(type)
	{
		case CHAR_TYPE:
            this->convertChar(input);
			return;
		case FLOAT_TYPE:
            this->convertFloat(input);
			return;
		case DOUBLE_TYPE:
            this->convertDouble(input);
			return;
		case INT_TYPE:
            this->convertInt(input);
			return;
		default:
			std::cerr << "Invalid input" << std::endl;
	}
	return ;
}