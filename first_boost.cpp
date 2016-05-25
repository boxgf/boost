#include <iostream>
#include <boost/signals2/signal.hpp>
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

void print_args(float x, float y)
{
  std::cout << "The arguments are " << x << " and " << y << std::endl;
}

void print_sum(float x, float y)
{
  std::cout << "The sum is " << x + y << std::endl;
}

void print_product(float x, float y)
{
  std::cout << "The product is " << x * y << std::endl;
}

void print_difference(float x, float y)
{
  std::cout << "The difference is " << x - y << std::endl;
}

void print_quotient(float x, float y)
{
  std::cout << "The quotient is " << x / y << std::endl;
}

int main()
{

 // Signal with no arguments and a void return value
  boost::signals2::signal<void (float,float)> sig;          // create a signalm sig with void return type and no input parameters

  // Connect a HelloWorld slot
  //HelloWorld hello;                              // hello is a function object
  //sig.connect(100,Hello());                            // connect te signal to hello fn object
  //sig.connect(World(),boost::signals2::at_front);
  sig.connect(&print_args);
  sig.connect(&print_sum);
  sig.connect(&print_product);
  sig.connect(&print_difference);
  sig.connect(&print_quotient);

  sig(5., 3.);

  // Call all of the slots


}
