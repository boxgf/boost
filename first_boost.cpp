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



// combiner which returns the maximum value returned by all slots
template<typename T>
struct maximum
{
  typedef T result_type;

  template<typename InputIterator>
  T operator()(InputIterator first, InputIterator last) const   // operator "()" gets the reference to the inputs by default? ans: When a maximum object is invoked,
                                                                //it is given an input iterator sequence [first, last) that includes the results of calling all of the slots
  {
    // If there are no slots to call, just return the
    // default-constructed value
    if(first == last ) return T();
    T max_value = *first++;
    while (first != last) {
      if (max_value < *first)
        max_value = *first;
      ++first;
    }

    return max_value;
  }
};



int main()
{

 // Signal with no arguments and a void return value
  boost::signals2::signal<float (float x, float y), maximum<float> > sig; // the second arguement is the combiner template arguement

  // Connect a HelloWorld slot
  //HelloWorld hello;                               // hello is a function object
  //sig.connect(100,Hello());                       // connect te signal to hello fn object
  //sig.connect(World(),boost::signals2::at_front);
  //sig.connect(&print_args);


  sig.connect(&sum);
  sig.connect(&product);
  sig.connect(&difference);
  sig.connect(&quotient);                          // use groups to reorder the sequnce the slots are called. Otherwise they are default ordered the way you connect
                                                   // ungrouped are called at end by default

   std::cout << "maximum: " << sig(5, 3) << std::endl; // notice there is not *sig which was present when the return type was just float now it it
  // Call all of the slots


}
