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
/*
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
*/

float product(float x, float y) { return x * y; }
float quotient(float x, float y) { return x / y; }
float sum(float x, float y) { return x + y; }
float difference(float x, float y) { return x - y; }

int main()
{

 // Signal with no arguments and a void return value
  boost::signals2::signal<float (float,float)> sig; // create a signalm sig with void return type and no input parameters

  // Connect a HelloWorld slot
  //HelloWorld hello;                               // hello is a function object
  //sig.connect(100,Hello());                       // connect te signal to hello fn object
  //sig.connect(World(),boost::signals2::at_front);
  //sig.connect(&print_args);
  sig.connect(&sum);
  sig.connect(&product);
  sig.connect(&difference);
  sig.connect(&quotient);                           // use groups to reorder the sequnce the slots are called. Otherwise they are default ordered the way you connect
                                                    // ungrouped are called at end by default

   std::cout << *sig(5, 3) << std::endl;
  // Call all of the slots


}
