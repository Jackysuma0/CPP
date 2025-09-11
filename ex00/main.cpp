#include "Bureaucrat.hpp"

int main( void ) {

    Bureaucrat *crat;
    
    crat = new Bureaucrat("Jacques", 1);

    //////////////////////////////////////
    //                                  //
    //         Testing decrement        //
    //                                  //
    //////////////////////////////////////

    std::cout << " simple decrementGrade( 10 ) test on " << std::endl;
    try {
        crat->decrementGrade( 10 );
        std::cout << "You should be able to see me" << std::endl;
    }
    catch ( std::exception & e ) {
        
        std::cout << e.what() << std::endl;
    }
    
    //////////////////////////////////////
    //                                  //
    //         Testing increment        //
    //                                  //
    //////////////////////////////////////
    
    std::cout << " simple incremetGrade( 10 ) test on " << std::endl;
    try {
        crat->incrementGrade( 10 );
        std::cout << "You should be able to see me" << std::endl;
    }
    catch ( std::exception & e ) {
        
        std::cout << e.what() << std::endl;
    }

    //////////////////////////////////////
    //                                  //
    //      Testing over increment      //
    //                                  //
    //////////////////////////////////////    

    std::cout << " increment over grade of 10 on " << std::endl;
    try {
        crat->incrementGrade( 10 );
        std::cout << "You should not be able to see me" << std::endl;
    }
    catch ( std::exception & e ) {
        
        std::cout << e.what() << std::endl;
    }

    //////////////////////////////////////
    //                                  //
    //      Testing over decrement      //
    //                                  //
    //////////////////////////////////////
    
    std::cout << " decrement over grade of 300 on " << std::endl;
    try {
        crat->decrementGrade( 300 );
        std::cout << "You should not be able to see me" << std::endl;
    }
    catch ( std::exception & e ) {
        
        std::cout << e.what() << std::endl;
    }

    delete( crat );
    return ( 0 );
}