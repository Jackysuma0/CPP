#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(const std::string& name);
        ~HumanB();
        void    attack();
        void    setWeapon(Weapon &weapon);
    private:
        std::string name;
        Weapon *weapon;
};

#endif