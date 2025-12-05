## README.md file for project PythonTestModule

### What this project does.

The core of this project is a C++ file which is named PythonTestModule.cpp. As you can probably
guess from this file's name, it contains C++ code which implements a Python module. The module which
is implemented by this code, is a rather simple in nature. This is a deliberate design choice. It was
done in order to try and keep the focus on how to write and create bindings for a Python module in C++.

### How it does it.

This file implements a single C++ class which is named CraigClass. In turn, this class implements
three methods - one of which is a constructor. After the class has finished being defined, the file
then uses the BOOST_PYTHON_MODULE macro from the Boost Python C++ library to create some Python
bindings for this class and its three methods. 

```c++
#include <iostream>

#include <boost/python.hpp>


class
CraigClass
{
public :

    CraigClass
    (
     int   value
    )
    :
    value
    (
     value
    )
    {
        std::cout << "CraigClass::Ctor : Enter" << std::endl;
        std::cout << "CraigClass::Ctor : Exit"  << std::endl;
    }


    void
    testFunction
    (
    )
    {
        std::cout << "CraigClass::testFunction : Enter" << std::endl;
        std::cout << "CraigClass::testFunction : Exit"  << std::endl;
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


BOOST_PYTHON_MODULE(PythonTestModule)
{
    using namespace boost::python;

    boost::python::def
    (
     "craig_add",
     craig_add
    ); // "craig_add" is the Python name, 'craig_add' is the C++ function

    class_<CraigClass>("CraigClass", init<int>()) // Expose MyClass with an int constructor
            .def("getValue",     &CraigClass::getValue)
            .def("testFunction", &CraigClass::testFunction);
}
```

[GitHub CLI quickstart](https://docs.github.com/en/github-cli/github-cli/quickstart)

#### - Initialise a directory to hold a local copy of a repository
```
  > git init
```

* #### Cloning a remote repository into a local directory

Example using git;
```
  > git clone https://github.com/c-sanders/Gtk4-Example-1.git
```

Example using gh;
```
  > gh repo clone c-sanders/ImaginaryNumbers
```

* #### Check the status of a local repository
```
  > git status
```

* #### Add a local file to a local repository
```
  > git add Filename.cpp
```

* #### Remove a file from a repository
```
  > git rm Filename.cpp
```

* #### Commit changes, i.e. additions and removals of files, to the local repository
```
  > git commit -m "Commit comment."
```

* #### Pushing locally committed changes to a remote repositoy
```
  > git push
```
or
```
  > git push origin master