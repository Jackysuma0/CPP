#include "RPN.hpp"

RPN::RPN( ) : _str(""), _container() { }

RPN::RPN(std::string str) : _str(str), _container() { }

RPN::RPN(RPN const &src)
{
    *this = src;
    return ;
}

RPN::~RPN( ) { }

RPN &RPN::operator=(RPN const &src)
{
    this->_str = src._str;
    this->_container = src._container;
    return (*this);
}

bool isInteger(const std::string& token)
{
    if (token.empty()) return false;

    size_t i = 0;
    if (token[0] == '-' || token[0] == '+') i++;

    for (; i < token.length(); ++i) {
        if (!isdigit(token[i])) return false;
    }

    return true;
}

bool isDecimal(const std::string& token)
{
    return token.find('.') != std::string::npos;
}


bool RPN::parse()
{
    std::istringstream iss(this->_str);
    std::string token;

    while (iss >> token)
    {
        if (token.size() == 1 && isdigit(token[0]))
        {
            _container.push_back(token[0] - '0');
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_container.size() < 2)
            {
                std::cerr << "Error: Not enough operands" << std::endl;
                return false;
            }
            int b = _container.back(); _container.pop_back();
            int a = _container.back(); _container.pop_back();
            int result = 0;

            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else if (token == "/")
            {
                if (b == 0)
                {
                    std::cerr << "Error: Division by zero" << std::endl;
                    return false;
                }
                result = a / b;
            }
            _container.push_back(result);
        }
        else if (isInteger(token))
        {
            int value = std::atoi(token.c_str());
            if (value < 0 || value > 9)
            {
                std::cerr << "Error: numbers must be single digits (0–9)" << std::endl;
                return false;
            }
            _container.push_back(value);
        }
        else if (isDecimal(token))
        {
            std::cerr << "Error: decimal numbers are not allowed" << std::endl;
            return false;
        }
        else if (token == ")" || token == "%")
        {
            std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
            return false;
        }
    }

    if (_container.size() != 1)
    {
        std::cerr << "Error: Invalid expression" << std::endl;
        return false;
    }

    std::cout << _container.back() << std::endl;
    return true;
}