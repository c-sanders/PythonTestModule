#include <iostream>

#include <boost/python.hpp>


// Use C style name mangling for the function, otherwise Python won't like the resulting function name.

// extern "C"
// {
    int
    craig_add
    (
     int   a,
     int   b
    )
    {
        return a + b;
    }

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
// }


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
