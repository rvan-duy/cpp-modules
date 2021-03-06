#include <cassert>
#include <cstdlib>

#include "ScavTrap.hpp"

static void checkClapTrap(ClapTrap &trap, std::string name, unsigned int hit_points, unsigned int energy_points,
                          unsigned int attack_damage) {
  assert(trap.getName() == name);
  assert(trap.getHitPoints() == hit_points);
  assert(trap.getEnergyPoints() == energy_points);
  assert(trap.getAttackDamage() == attack_damage);
}

int main(void) {
  {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Testing ScavTrap Class with 10 attacks" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    ScavTrap hero("Hero");
    checkClapTrap(hero, "Hero", 100, 50, 20);
    ScavTrap bandit("Bandit");
    checkClapTrap(bandit, "Bandit", 100, 50, 20);

    std::cout << hero << std::endl;
    std::cout << bandit << std::endl;

    for (int i = 0; i < 10; i++) {
      if (bandit.getHitPoints() == 0) break;
      hero.attack("Bandit");
      bandit.takeDamage(hero.getAttackDamage());
    }

    checkClapTrap(hero, "Hero", 100, 45, 20);
    checkClapTrap(bandit, "Bandit", 0, 50, 20);

    std::cout << hero << std::endl;
    std::cout << bandit << std::endl;
  }

  {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Testing ScavTrap Class with guard mode" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    ScavTrap hero("Hero");
    checkClapTrap(hero, "Hero", 100, 50, 20);

    std::cout << hero << std::endl;

    hero.guardGate();
    assert(hero.getState() == ScavTrap::GATE_KEEPING_MODE);

    std::cout << hero << std::endl;
  }

  return EXIT_SUCCESS;
}