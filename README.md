## README.md file for project PythonTestModule

### What this project does.

This project implements a Python module. It does this by way of a C++ file named PythonTestModule.cpp.  
This file forms the core of this project, and the Python module which it implements, is rather simple
in nature. This is a deliberate design choice which was made in order to try and keep the focus on
how to create a Python module in C++.

### How it does it.

This file implements a single C++ class which is named TestClass. In turn, this class implements
three methods - one of which is a constructor. After the class has finished being defined, the file
then uses the BOOST_PYTHON_MODULE macro from the Boost Python C++ library in order to create some
Python bindings for this class and its three methods. 

```c++
#include <iostream>

#include <boost/python.hpp>


int
testFunction
(
 int   a
)
{
    return a;
}


class
TestClass
{
public :

    TestClass
    (
     int   value
    )
    :
    value
    (
     value
    )
    {
        std::cout << "TestClass::Ctor : Enter" << std::endl;
        std::cout << "TestClass::Ctor : Exit"  << std::endl;
    }


    void
    testFunction
    (
    )
    {
        std::cout << "TestClass::testFunction : Enter" << std::endl;
        std::cout << "TestClass::testFunction : Exit"  << std::endl;
    }


    int
    getValue
    (
    )
    const
    {
        return this->value;
    }

    private :

        int   value;
};


/*
 * Create Python bindings for this class and its three methods. Doing this will allow Python to use them.
 *
 * This file uses the macro BOOST_PYTHON_MODULE from the Boost Python C++ library to accomplish this.
 */

BOOST_PYTHON_MODULE(PythonTestModule)
{
    using namespace boost::python;


    // Create a binding for the free function named testFunction.
    //
    // This will

    boost::python::def
    (
     "testFunction",  // Name of the C++ function which we want to create a binding for.
     testFunction     // Name of the Python function which has resulted from the binding.
    );


    // Create a binding for the class named TestClass. with an int constructor.
    // This will cause it to be exposed to Python.

    class_<TestClass>
    (
     "TestClass",
     init<int>()
    )

    // Create a binding for the other two methods in TestClass.

    .def("getValue",     &CraigClass::getValue)
    .def("testFunction", &CraigClass::testFunction);
}
```

