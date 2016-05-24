#include <iostream>
#include <boost/signals2.hpp>
struct Hello
{
  void operator()() const                       // function object?
  {
    std::cout << "Hello ";
  }
};

struct World
{
  void operator()() const                       // function object?
  {
    std::cout << "world !!" << std::endl;
  }
};



int main()
{

 // Signal with no arguments and a void return value
  boost::signals2::signal<void ()> sig;          // create a signalm sig with void return type and no input parameters

  // Connect a HelloWorld slot
  //HelloWorld hello;                              // hello is a function object
  sig.connect(Hello());                            // connect te signal to hello fn object
  sig.connect(World());

  // Call all of the slots
  sig();

}
