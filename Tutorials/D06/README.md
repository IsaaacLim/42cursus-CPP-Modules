# Cast

###Table of Contents:

#### About c-Cast

1. [General Information](#general-info)
2. [Identity Cast](#identity-cast)
3. [Type Qualifier Cast](#type-q-cast)

#### About cpp-Cast

4. [cpp-Cast Intro](#cpp-cast-intro)
5. Types of CPP Casts

   a. [Static Cast](#static-cast)

   b. [Dynamic Cast](#dynamic-cast)

   c. [Reinterpret Cast](#reinterpret-cast)

   d. [Const Cast](#const-cast)

6. [Type Cast Operator](#type-cast-operator)
7. [Explicit Keyword](#explicit-keyword)
8. [Cast Performance Summary](#summary)

---

---

# About c-Cast

## General Information<a name="general-info"></a>

There are implicit casting and explicit casting

- Implicit casting: When not specified, the compiler will automatically type cast for us.
- Explicit cating : When we specify what type we want.
- eg:

```
int 	a = 42;
double	b = a;			//Implicit cast
double 	c = (double)a;	//explicit cast
```

There'll be infomation lost when converting a larger type to smaller type.
To prevent accidental Implicit conversions that losses accuracy, use `-Wno-conversion` flag during compilation to produce errors.

```
double	d = a;			//Implicit promotion
int		e = d;			//Implicit demotion -> Hazardous!
int		f = (int)d; 	//Explicit demotion -> Alright (intentional)
```

Data is lost and values are less accurate

---

## Identity Cast ( and Reintepretation) <a name="identity-cast"></a>

This means: **The base value keeps the same bits after conversion in order**

Reinterpretation: Is the secondary effect of this cast.

There is a **heirarchy** between types, and there are restriction between one to another.

- `void` type is the most genetic type. It's less accurate. No problem with implicit cast since it'll be a promotion.
- "Demotion" means gaining precision (moving down the hierarchy).

```
float	a = 420.042f;	//Reference value

void*	b = &a;			//Implicit reinterpretation cast
void*	c = (void *)&a;	//Explicit reinterpretation cast

void*	d = &a;			//Implicit promotion -> ok
int*	e = d;			//Implicit demotion -> Hazardous!
int*	f = (int *)d;	//Explicit demotion -> Alright

printf("%d", e);		//output: 1137837408
printf("%d", f);		//output: 1137837408
```

Type casting `d` to `e` & `f` retains the bits after conversion. However, they are reinteprated differently.

---

## Type Qualifier Cast <a name="type-q-cast"></a>

eg: `const` & `volatile`

Also involves a hierarchy. `const` is less accurate, broader and higher on the hierarchy

```
int 		a = 42;					//Reference value

int const*	b = &a;					//Implicit type qualifier cast
int const* 	c = (int const *)&a;	//explicit type qualifier cast

int const*	d = &a;					//Implicit promotion -> ok
int	*		e = d;					//Implicit demotion -> Hazardous!
int	*		f = (int *)d; 			//Explicit demotion -> Alright
```

`int *e = d` won't compile because the compiler is protecting our codes by not allowing us to modify const value. We may bypass this by conducting an _explicit demotion cast_.

---

---

# cpp-Cast

## Using c-Cast syntax to demonstrate cpp-Cast <a name="cpp-cast-intro"></a>

### Up-Cast & Down-Cast

- Up cast: Ascending reinterpretation _(to less accurate type)_
- Down cast: Descending reinterpretation _(to more specified type)_

Thanks to the notion of inheritance, a hierarchy will be created naturally inside out class.

Parent class are more generic, less specialize class than the classes who inherit it.

_Pointers are compatible between base class and daughter classes_

```
class Parent					{};
class Child1 : public Parent	{};
class Child2 : public Parent	{};

int main() {
	Child1		a;					//Reference value

	Parent *	b = &a;				//Implicit 'reinterpretation' cast
	Parent *	c = (Parent *) &a;	//Explicit 'reinterpretation' cast

	Parent *	d = &a;				//Implicit upcast -> ok
	Child1 *	e = d;				//Implicit downcast -> Hell no!
	Child2 *	f = (Child2 *) d;	//Explicit downcast -> Ok, but really?
}
```

`Child2 * f = (Child2 *)d` will run but we don't if the implementation of the `Child1` class is the same as the `Child2` class.

---

## Types of CPP Casts

### 1. Static Cast <a name="static-cast"></a>

Syntax to type case the **example above** is actually `Child2 * d = static_cast<child2 * >(b);`

`static_cast` makes sure that we cast between compatible classes in the inheritance stream

### 2. Dynamic Cast <a name="dynamic-cast"></a>

This cast runs at run-time

- Program may compile then the cast may fail
- Will work with only with polymorphic instance. At least one of the method needs to be virtual (sub-type polymorhpism)
  - Condition is known as `rtti (run-time information)`
- Only used for downcast. And only works if it's a possible downcast

_example: dynamic_cast.cpp_

### 3. Reinterpret Cast <a name="reinterpret-cast"></a>

This cast allows us to reinterpret any address as any other address

There won't be any symantic checks

Use it only when I know what type of data I want

```
float	a = 420.042f;					//Reference value

void *	b = &a;							//Implicit promotion -> Ok
int *	c = reinterpret_cast<int *>(b);	//Explicit demotion -> Ok, I obey
int &	d = reinterpret_cast<int &>(b);	//Explicit demotion -> Ok, I obey
```

### 4. Const Cast <a name="const-cast"></a>

Previous cast can't do a transformation to the type qualifiers [c-Cast ref](#type-q-cast).

cpp type qualifier cast works the same as c's type qualifier cast, just with a different syntax

(Again, const values are higher in the hierarchy, less 'accurate')

```
int			a	= 42;					//Reference value

int const *	b	= &a;					//Implicit promotion -> Ok
int *		c	= b;					//Implicit demotion -> Hell no!
int *		d	= const_cast<int *>(b);	//Explicit demotion -> Ok, I obey
```

---

## Type Cast Operator <a name="type-cast-operator"></a>

Allows us to define, in our classes, specific operators to create implicit conversions of a class to a another type

_example: type_cast_operator.cpp_

---

## Explicit Keyword <a name="explicit-keyword"></a>

The `explicit` keyword will prevent the implicit construction of instances

Using this keyword requires us to explicitly use the constructor

_example: explicit_keyword.cpp_

---

---

# Summary Table <a name="summary"></a>

- Dynamic cast is the safest
- Reinterpret cast is the most flexible (excluding Legacy C cast)

| Cast             | Conv. | Reint | UpCast | Downcast | Type qual. |
| ---------------- | :---: | :---: | :----: | :------: | :--------: |
| Implicit         |  Yes  |       |  Yes   |          |            |
| static_cast      |  Yes  |       |  Yes   |   Yes    |            |
| dynamic_cast     |       |       |  Yes   |   Yes    |            |
| const_cast       |       |       |        |          |    Yes     |
| reinterpret_cast |       |  Yes  |  Yes   |   Yes    |            |
|                  |       |       |        |          |            |
| Legacy C cast    |  Yes  |  Yes  |  Yes   |   Yes    |    Yes     |

| Cast             | Semantic Check | Reliable at run | Tested at run |
| ---------------- | :------------: | :-------------: | :-----------: |
| Implicit         |      Yes       |       Yes       |               |
| static_cast      |      Yes       |                 |               |
| dynamic_cast     |      Yes       |       Yes       |      Yes      |
| const_cast       |                |                 |               |
| reinterpret_cast |                |                 |               |
|                  |                |                 |               |
| Legacy C cast    |                |                 |               |
