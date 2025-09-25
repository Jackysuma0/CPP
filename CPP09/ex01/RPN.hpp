#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>

class RPN
{
    private:
        std::string _str;
        std::list<int> _container;
    public:
        RPN( );
        ~RPN( );
        RPN( std::string str);
        RPN( RPN const &other );
        RPN     &operator=(RPN const &src);
        bool    parse(void);
};