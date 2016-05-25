#include <iostream>
#include <boost/signals2/signal.hpp>
#include <vector>
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


// aggregate_values is a combiner which places all the values returned
// from slots into a container
template<typename Container>
struct aggregate_values
{
  typedef Container result_type;

  template<typename InputIterator>
  Container operator()(InputIterator first, InputIterator last) const  // operator "()" gets the reference to the inputs by default? ans: When a maximum object is invoked,
                                                                       //it is given an input iterator sequence [first, last) that includes the results of calling all of the slots
  {
    Container values;

    while(first != last) {
      values.push_back(*first);
      ++first;
    }
    return values;
  }
};



int main()
{

 // Signal with no arguments and a void return value
  boost::signals2::signal<float (float x, float y), aggregate_values<std::vector<float> > > sig; // the second arguement is the combiner template arguement

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

   std::vector<float> res= sig(5, 3);
   for (unsigned int i =0; i < res.size(); i++)
   {
   std::cout<< res[i]<<" ";

   }
  std::cout<<"\n";
  std::vector<float> results = sig(5, 3);
  std::cout << "aggregate values: ";
  std::copy(results.begin(), results.end(),
    std::ostream_iterator<float>(std::cout, " ")); //how the fuck is he printing like that?
  std::cout << "\n";
}
