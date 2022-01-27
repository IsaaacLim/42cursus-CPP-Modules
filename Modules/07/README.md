# Topics Covered

### ex00

- Template functions
- **Obj: Introduction**
- Using scope-resolution operator (`::`) to call functions
  - This just tells the compiler to look in the global namespace for the type/function, which prevents my `function name` used to get clobbered by a new definition inside another namespace

### ex01

- Specialization template functions
- **Obj: Learn to pass template functions into template functions**
- `std::boolalpha` to print `true/false` rather than `1/0`

### ex02

- Data Structure / Template Classes & Structures
- **Obj: Create an `Array` class that can create/copy an array of any specified type**
- Operator overload for `[]`
- Tried to create a `copy constructor`/`assignment operator` that will delete the instance to be overwritten if was already initialized. But realized that the practice is to create another function (eg: `change`) that replicates the `copy` features but with a manual delete. This function is called intentionally by the user
- Extra: [Copy Constructor vs Assignment Operator](https://www.geeksforgeeks.org/copy-constructor-vs-assignment-operator-in-c/)

  > **Copy Constructor**: Called when a new object is created from an existring object, as a copy of the existing object

  > **Assignment Operator**: Is called when an already initialized object is assigned a new value from another existing object

  ```
  Class p1;
  Class p2(p1); //Copy constructor
  Class p3 = p1;//Copy constructor

  Class p4;
  p4 = p1;      //Assignment operator
  ```

- _Note: a `main.cpp` file was given in the intra. It's for ex02 but it wasn't explicitly mentioned that it needs to be used. I've included a copy of this file in my repo under `main_intra.cpp`_
