# About Cast

1. [General Information](#general-info)
2. [Identity Cast](#identity-cast)

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

There is a **heiracy** between types, and there are restriction between one to another.

- `void` type is the most genetic type. It's less accurate. No problem with implicit cast since it'll be a promotion.
- "Demotion" means gaining precision.

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
