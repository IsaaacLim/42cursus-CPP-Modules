> Grades: 92/100
>
> - ex00 required a `WrongCat` class which inherits from a `WrongAnimal` class. I didn't create a `WrongAnimal` class.

# Topics Covered

## Polymorphism

- **Polymorphism** is like **inheritance** but the child class has it's own function that allows the object to decide which form of the function to implement at compile-time (overloading) as well as run-time (overriding)

### ex00

- Base class: `Animal`
- Child classes: `Dog`, `Cat`, `WrongCat`
- Base class has a `makeSound()` function that will be overwritten by the child classes

### ex01

- Follow up from ex00, `Animal` base class now obtained `Brains`(class)
- Made `getBrain()` in `Animal` class an abstract function
  - `Dog` & `Cat` has `getBrain()`
  - `WrongCat` doesn't so it can't be declared
- **Obj:** Deep and Shallow copy

### ex02

- Exactly as ex01 but `Animal` class is now an **Abstract Class**
  - Abstract classes contains only _pure virtual functions_
  - Hence, the default animal class _cannot be instantiate_

### ex03

- **Interface** only permits user to state functionalily but not to implement it, **abstract classes** permits users to make functionality that subclasses can implement or override
- Project instruction:
  1.  Create a `MateriaSource` _(Spellbook)_
  2.  Include some spells into the _Spellbook_ (only `Ice` & `Cure` available)
  3.  Create `Character`s
  4.  Create the spells available from the _Spellbook_ and equip them to the `Character`(s) _(Cannot have duplicate spells and can only hold upt o 4 spells, but since we only have `ice` & `cure`, the 4 spell limit can't be tested)_
  5.  Spells must be able to be used and unequipped appropriately
