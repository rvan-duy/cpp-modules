#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap::ClapTrap(), state(IDLE) {
  this->hit_points    = 100;
  this->energy_points = 50;
  this->attack_damage = 20;
  std::cout << "-> (ScavTrap) Default constructor for nameless ScavTrap is called" << std::endl;
};

ScavTrap::ScavTrap(const std::string &name) : ClapTrap::ClapTrap(name), state(IDLE) {
  this->hit_points    = 100;
  this->energy_points = 50;
  this->attack_damage = 20;
  std::cout << "-> (ScavTrap) Constructor for " << name << " is called" << std::endl;
}

ScavTrap::~ScavTrap() { std::cout << "-> (ScavTrap) Deconstructor for " << this->name << " is called" << std::endl; };

ScavTrap::ScavTrap(const ScavTrap &trap) : ClapTrap::ClapTrap(trap) {
  this->state = trap.state;
  std::cout << "-> (ScavTrap) Copy constructor for " << this->name << " is called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &trap) {
  this->name          = trap.getName();
  this->hit_points    = trap.getHitPoints();
  this->energy_points = trap.getEnergyPoints();
  this->attack_damage = trap.getAttackDamage();
  this->state         = trap.state;
  std::cout << "-> (ScavTrap) Copy assignment constructor for " << this->name << " is called" << std::endl;
  return *this;
}

void ScavTrap::guardGate() {
  this->state = GATE_KEEPING_MODE;
  std::cout << "ScavTrap " << this->name << " is guarding the gate" << std::endl;
}
