# C++ Class Notları

## Inheritance

- simple inheritance

```cpp
class MyBaseClass
{
public:
char c;
int x;
};

class MyDerivedClass : public MyBaseClass
{
// c and x also accessible here
};
```

- private class examples

```cpp
```cpp
class MyBaseClass
{
protected:
char c;
int x;
};

class MyDerivedClass : public MyBaseClass
{
// c and x also accessible here
};
int main()
{
MyDerivedClass o;
o.c = 'a'; // Error, not accessible to object
o.x = 123; // error, not accessible to object
}
```
```

```cpp
class MyBaseClass
{
public:
char c;
int x;
};
class MyDerivedClass : public MyBaseClass
{
public:
double d;
};
int main()
{
MyDerivedClass o;
o.c = 'a'; // you can access now.
o.x = 123;  
o.d = 456.789;
}
```

## Polymorphism

- `A virtual function is a function whose behavior can be overridden in subsequent derived classes. And our pointer/object morphs into different types to invoke the appropriate function. Example:`

```cpp
class MyBaseClass
{
public:
virtual void dowork()
{
std::cout << "Hello from a base class." << '\n';
}
};

class MyDerivedClass : public MyBaseClass
{
public:
void dowork()
{
std::cout << "Hello from a derived class." << '\n';
}
};

int main()
{
MyBaseClass* o = new MyDerivedClass;
o->dowork();
delete o;
}
```

- `virtual` means this function can be overridden/redefined in subsequent derived classes,
  and the appropriate version will be invoked through a polymorphic object.

- pure virtual function
  
  ```cpp
  #include <iostream>
  class MyAbstractClass
  {
  public:
  virtual void dowork() = 0; // a pure virtual function
  };
  
  class MyDerivedClass : public MyAbstractClass
  {
  public:
  void dowork()
  {
  std::cout << "Hello from a derived class." << '\n';
  }
  };
  
  int main()
  {
  MyAbstractClass* o = new MyDerivedClass;
  o->dowork();
  delete o;
  }
  ```


