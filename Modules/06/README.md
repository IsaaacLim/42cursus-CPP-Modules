# Topics Covered

- Main topic: **Cast**

### ex00 (static_cast)

- Using `stringstream` to convert string to int
- Using `c_str()` to pass `str::string` variables as `const char *`
- int, float, double's `min` `max` `inf` `nan` values
  - `atof()` & `strtod()` converts `nan` and `inf` too
- Using non-member functions for libft functions
- `ss.str(std::string())` + `ss.clear()` to clear stringstream buffer
- `double`/ `float` variables losses accuracy (eg: 2147483647(INT MAX) == 2147480000(double))

### ex01 (reinterpret_cast)

- Reinterpret the `Data` address to a `uintptr_t` address
- `uintptr_t` might be the same as a `void *`. It is an unisnged interget type that is capable of storing a data pointer.

### ex02 (dynamic_cast)

- Randomly generate a Child class, implicitly promote it to the Parent class, then identify which Child class it is using `dynamic_cast` through
  - Pointer: Handle failed cast through NULL pointers
  - Reference: Handle failed cast through `exception` _(Not allowed to use <typeinfo> header for `std::bad_cast`)_
