#include "PmergeMe.hpp"

bool isPositiveInteger(std::string str) {
    
    for (unsigned long i = 0; i < str.length(); i++) {
        
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

//this function will be used to take the existing array of integers and turn it into a list

std::list<int> arrayToList(int *array, int size) {
    
    std::list<int> list;
    
    for (int i = 0; i < size; i++)  {
        
        list.push_back(array[i]);
    }
    return list;
}

//this fuction will be used to take the existing array of integers and turn it into a deque

std::deque<int> arrayToDeque(int *array, int size) {
    
    std::deque<int> deque;
    
    for (int i = 0; i < size; i++)  {
        
        deque.push_back(array[i]);
    }
    return deque;
}

int main ( int argc, char **argv) {
    
    // int timeDeque;
    // int timeStack;
    
    // timeDeque = 0;
    // timeStack = 0;
    if (argc < 2)   {
        
        std::cout << "Error: No arguments" << std::endl;
        return 0;
    }
    
    std::string *str = new std::string[argc - 1];
    
    for (int i = 1; i < argc; i++)  {
        
        str[i - 1] = argv[i];
        
        if (!isPositiveInteger(str[i - 1])) {
            
            std::cout << "Error: Invalid argument" << std::endl;
            delete [] str;
            return 0;
        }
    }
    
    int *array = new int[argc - 1];
    
    for (int i = 0; i < argc - 1; i++)  {

        array[i] = std::atoi(str[i].c_str());
    }
    
    std::deque<int> deque;
    std::list<int> list;

    PmergeMe pmm;

    try {
		
        pmm.merge_insert_sort_list( argc, argv );
        pmm.merge_insert_sort_deque( argc, argv );
        pmm.print_informations( argc, argv );
    } catch (const std::runtime_error& e) {
		
        std::cerr << "Error: " << e.what() << std::endl;
        delete [] array;
        delete [] str;
        return EXIT_FAILURE;
    }
    delete [] array;
    delete [] str;

    return 0;
}