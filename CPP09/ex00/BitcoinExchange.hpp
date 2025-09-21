#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>

class BitcoinExchange
{
    private:
	
		std::vector<std::pair<std::string, double> > _historical_prices;

	public:
		
		BitcoinExchange( );
		BitcoinExchange( const BitcoinExchange &toCopy );
		BitcoinExchange& operator=( const BitcoinExchange &toTheRight );
		~BitcoinExchange( );
		
		void readFile( const std::string &filename );
		void processData( const std::string &inputFile );
		bool isValidInput( const std::string &line, std::string &date, double &value );
        double    getPriceForDate(const std::string &date) const;

        class FileOpenException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error: could not open file.");
                }
        };

        class BadInputException : public std::exception {
        private:
            std::string _message;
        public:
            BadInputException(const std::string& input) {
                _message = "Error: bad input => " + input;
            }

            virtual ~BadInputException() throw() {}  // C++98 style

            virtual const char* what() const throw() {
                return _message.c_str();
            }
        };

        class InvalidDateException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error: invalid date format.");
                }
        };

        class InvalidValueException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error: invalid value.");
                }
        };

        class NegativeValueException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error: not a positive number.");
                }
        };

        class TooLargeValueException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error: too large a number.");
                }
        };
};