#include <cassert>
#include <cstdlib>

#include "DiamondTrap.hpp"

static void checkDiamondTrap(DiamondTrap &trap, std::string name, unsigned int hit_points, unsigned int energy_points,
                             unsigned int attack_damage, DiamondTrap::State state) {
  assert(trap.ScavTrap::ClapTrap::getName() == name + "_clap_name");
  assert(trap.FragTrap::ClapTrap::getName() == name + "_clap_name");
  assert(trap.getName() == name);
  assert(trap.getHitPoints() == hit_points);
  assert(trap.getEnergyPoints() == energy_points);
  assert(trap.getAttackDamage() == attack_damage);
  assert(trap.getState() == state);
};

int main(void) {
  {
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Testing DiamondTrap going on an adventure" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    // Initializing hero with DiamondTrap class
    DiamondTrap hero("Hero");
    checkDiamondTrap(hero, "Hero", 100, 50, 30, DiamondTrap::IDLE);

    // Initializing bandit with ClapTrap class
    ClapTrap bandit("bandit");

    // Printing
    std::cout << hero << std::endl;
    std::cout << bandit << std::endl;

    // Hero is attacking the bandit
    hero.attack("bandit");  // hero loses 1 energy, inherreted from ClapTrap
    bandit.takeDamage(30);  // bandit takes 30 damage, inherreted from ClapTrap

    // Bandit is retaliating
    bandit.attack("Hero");  // bandit loses 1 energy, inherreted from ClapTrap
    hero.takeDamage(0);     // hero takes 0 damage, inherreted from ClapTrap

    // Here goes into guard mode
    hero.guardGate();  // this is inherreted from ScavTrap

    // Asking the right quests
    hero.whoAmI();  // from DiamondTrap

    checkDiamondTrap(hero, "Hero", 100, 49, 30, DiamondTrap::GATE_KEEPING_MODE);

    // Printing
    std::cout << hero << std::endl;
    std::cout << bandit << std::endl;
  }

  {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Basic tests with default constructor" << std::endl;
    std::cout << "------------------------------------" << std::endl; 
    
    DiamondTrap nameless;
    checkDiamondTrap(nameless, "", 100, 50, 30, DiamondTrap::IDLE);
  }
  return EXIT_SUCCESS;
};
