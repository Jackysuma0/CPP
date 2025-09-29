#include <cstdlib>
#include <time.h>
#include <string>
#include <sstream>
#include <list>
#include <deque>
#include <stdexcept>
#include <iostream>
#include <iomanip>

class PmergeMe
{
    private:
        std::list<int>	_list;
		double 			_time_list;
		std::deque<int> _deque;
		double 			_time_deque;
        void 			_merge_insert_sort_deque( std::deque<int> &deq );
		void 			_merge_insert_sort_list( std::list<int> &lst );
    public:
        PmergeMe();
        PmergeMe( const PmergeMe& other );
        PmergeMe& operator=( const PmergeMe& other );
        ~PmergeMe();
        void merge_insert_sort_list( int &argc, char **argv );
		void merge_insert_sort_deque( int &argc, char **argv );
		void print_informations( int &argc, char **argv ) const;
};