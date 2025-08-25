#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    public:
        Weapon();
        Weapon(const std::string& type);
        ~Weapon();
        void    setType(const std::string& new_type);
        const std::string& getType();
    private:
        std::string type;
};

#endif