# Topics Covered

## Inheritance

### ex00

 - Just create a base class that follows the conical form

### ex02

 - Create a child class from the class made from ex00
 - It has it's own `attack()` function that overrides the parent class's
 - It has it's own additional `guardGate()` function

### ex03

 - Same with `ex02`, just that it's unique function is `highFiveGuys()`

### ex04

 - `DiamondTrap` inherited from `ScavTrap` & `FragTrap`, which were inherited from `ClapTrap`
 - `virtual` public class inheritance for `DiamondTrap` to avoid ambiguity from accessing `ClapTrap`'s variables
 - Cannot set `DiamondTrap`'s variables to be partially from 2 classes. It'll be overwritten by which Inherited class comes later.
  - Fix: Declare individual `protected` variables for `FragTrap`. (Creating another `protected` variables to `ScavTrap` will also create ambiguity)

