#include <iostream>

int main(int argc, char **argv)
{
    (void)argv;
    if (argc == 2)
        std::cout << "SHHHHH... I THINK THE STUDENTS ARE ASLEEP...\n";
    if (argc == 4)
        std::cout << "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.\n";
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return (0);
}
