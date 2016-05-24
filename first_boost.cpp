#include <iostream>
#include <boost/signals2.hpp>
struct HelloWorld
{
  void operator()() const                       // function object?
  {
    std::cout << "Hello, World!" << std::endl;
  }
};

int main()
{

 // Signal with no arguments and a void return value
  boost::signals2::signal<void ()> sig;          // create a signalm sig with void return type and no input parameters

  // Connect a HelloWorld slot
  HelloWorld hello;                              // hello is a function object
  sig.connect(hello);                            // connect te signal to hello fn object

  // Call all of the slots
  sig();

}
