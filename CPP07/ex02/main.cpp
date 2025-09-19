#include "Array.hpp"

// int main()
// {
//     Array<int> arr(5);

//     for (size_t i = 0; i < arr.size(); ++i)
//         arr[i] = i * 10;

//     for (size_t i = 0; i < arr.size(); ++i)
//         std::cout << arr[i] << std::endl;

//     try {
//         std::cout << arr[100] << std::endl; // should throw
//     } catch (const std::exception& e) {
//         std::cerr << "Caught exception: " << e.what() << std::endl;
//     }

//     return 0;
// }

int main( void ) {

    unsigned int size = 10;
    unsigned int i = 0;

    Array<int>   empty( 0 );
    Array<int>   full( size );
    int*         tab = new int[size];
    srand(time(NULL));

    //////////////////////////////////////
    //                                  //
    //     operateur d'assignation      //
    //                                  //
    //////////////////////////////////////

    while ( i < size ) {
    
        const int value = rand();
        full[i] = value;
        tab[i] = value;
        i++;
    }
    
    Array<int> tmp = full;

    i = 0;
    while ( i < size ) {
    
        std::cout << "Array[" << i << "] = " << full[i] << ", Tab[" << i << "] = " << tab[i] << std::endl;
        i++;
    }
	
    //////////////////////////////////////
    //                                  //
    //           exceptions             //
    //                                  //
    //////////////////////////////////////
    
    try
    {
        full[-23] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
	
    try
    {
        full[size] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

	try
    {
        full[100000] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete [] tab;
    return 0;
}