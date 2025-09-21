#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( ) { }

BitcoinExchange::~BitcoinExchange( ) { }

BitcoinExchange::BitcoinExchange( const BitcoinExchange &toCopy )
{
	*this = toCopy;
}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &toTheRight )
{
	
    if (this == &toTheRight) {
        return *this;
    }
	this->_historical_prices = toTheRight._historical_prices;
    return *this;
}

void BitcoinExchange::readFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        double price;
        std::getline(ss, date, ',');
		ss >> price;
        this->_historical_prices.push_back(std::make_pair(date, price));
    }
}

double BitcoinExchange::getPriceForDate(const std::string &date) const
{
    for (std::vector<std::pair<std::string, double> >::const_reverse_iterator it = _historical_prices.rbegin();
         it != _historical_prices.rend(); ++it)
    {
        if (it->first <= date)
            return it->second;
    }
    return 0.0;
}

void BitcoinExchange::processData(const std::string &inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::string date;
        double value;

        if (!isValidInput(line, date, value))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        double btcPrice = getPriceForDate(date);
        double result = value * btcPrice;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}

std::string trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");
    if (start == std::string::npos || end == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

bool isValidDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int year, month, day;
    char dash1, dash2;
    std::istringstream ss(date);
    if (!(ss >> year >> dash1 >> month >> dash2 >> day))
        return false;
    if (dash1 != '-' || dash2 != '-')
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    int days_in_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2)
    {
        bool is_leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (is_leap ? 29 : 28))
            return false;
    }
    else
    {
        if (day > days_in_month[month - 1])
            return false;
    }
    return true;
}

bool BitcoinExchange::isValidInput(const std::string &line, std::string &date, double &value)
{
    std::istringstream iss(line);
    if (!std::getline(iss, date, '|'))
        return false;

    std::string valueStr;
    if (!std::getline(iss, valueStr))
        return false;

    date = trim(date);
    valueStr = trim(valueStr);

    if (!isValidDate(date))
        return false;
    std::istringstream vs(valueStr);
    if (!(vs >> value))
        return false;
    return true;
}