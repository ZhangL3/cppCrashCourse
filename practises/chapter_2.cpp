
#include <stdio.h>

enum class Operation
{
  Add,
  Subtract,
  Multiply,
  Divide
};

struct Calculator
{
  Calculator(Operation operation)
      : operation(operation) {}

  Operation operation;

  int calculate(int a, int b) {
    switch (this->operation)
    {
    case Operation::Add:
      return a + b;
    case Operation::Subtract:
      return a - b;
    case Operation::Multiply:
      return a * b;
    case Operation::Divide:
      return a / b;
    
    default:
      return -1;
    }
  }
};

int main(int argc, char const *argv[])
{
  int result = 0;
  Operation operation = Operation::Add;
  // Calculator calculator(operation);
  Calculator calculator{operation};
  result = calculator.calculate(1, 2);
  printf("Result: %d\n", result);
  return 0;
}
