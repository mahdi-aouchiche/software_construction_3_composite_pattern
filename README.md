# Software Construction: Composite Pattern

> Author: Mahdi Aouchiche (<https://github.com/mahdi-aouchiche/software_construction_3_composite_pattern>)

* Creating a composite pattern for representing an expression tree.
* An expression tree is a tree representation of an equation, so the expression

```code
3 + 7 * 4 - 2
```

would be represented with the following expression tree:

![example expression tree](https://github.com/cs100/template-lab-03-composite-strategy/blob/master/images/intro-tree.png?raw=true)

* The depth of each operation and its operands is based on their precedence, with the highest precedence operations being at the lowest levels of the tree. The first expression to be executed (in this case, `7 * 4`) will be at the deepest level. The result of that calculation then becomes an input to the addition (which becomes `3 + 28`), and that result becomes an input to the subtraction (`31 - 2`). The tree is evaluated recursively using a head recursive so the evaluation travels from the bottom to the top in order to yield the correct result.

## Initial Setup

* Practicing test driven development to create each of the classes necessary for building the composite pattern before putting it together and testing the entire system.
* Provided files:
  * `unit_test.cpp` file which contains the test runner code for executing google unit tests.
  * `op_test.hpp` file which has a single basic unit test for the `Op` class.
  * `op.hpp` file which contains an incomplete implementation of the `Op` class.
  * `base.hpp` file which contains the abstract base class which `Op` inherits from.
  * `main.cpp` file which you will use at the end of the lab.
* Creating a `CMakeLists.txt` file which is capable of generating a `test` executable which uses the `unit_test.cpp` file for its main.

## Testing Mocks

* Creating a large number of classes whose execution is dependent on other classes can make system hard to test. To make testing easier, create several mock classes that can be used for testing purposes (choose varied enough values to be effective for testing. For example, negative values and zero as these could be potential edge cases).
* Below is a mock for a basic `Op` class which returns a static value:

```c++
class SevenOpMock: public Base {
    public:
        SevenOpMock() { };

        virtual double evaluate() { return 7.5; }
        virtual string stringify() { return "7.5"; }
}
```

* Use these mock classes all the developed classes can at least be minimally tested until dependent classes can be completed.

## Implementation

* Develop a composite pattern for representing expression trees, use the following abstract base class which has been provided in `base.h`:

```c++
class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual string stringify() = 0;
};
```

* There are two main functions that need to be develop for this composite pattern lab:
  * `evaluate()`: returns the value of a node while the second.
  * `stringify()`: returns a string representation of the node (a node in this case could represent a single value or an entire subtree).

> Note: The above Base class header file will be included in multiple subclasses, which would normaly cause a duplication error. This error occurs because when you include a header file the contents of that file are essentially pasted to replace that include. This leads to multiple definitions of the Base calss when mulitple includes exist in your program. To solve this we add [header guards](https://www.learncpp.com/cpp-tutorial/header-guards/) which exist to make sure only one copy of a header are included within a program. Depending on how you develop your classes you may need to include header guards on other files as well, and its standard practice to include them on all header files by default.

* Develop the following classes for creating your expression trees:
  * class `Op`: This class represents the [operands](https://en.wikipedia.org/wiki/Operand) in an expression, and can be any double value. It's string representation should be a string version of its double value.
  * class `Rand`: This class is exactly the same as the `Op` class, but rather than being able to set its value its value is set during construction by the the equation `rand() % 100`
  * class `Mult`: This class represents the multiplication operation. It's string representation should be "\*" along with its operands (which might be operands or another operator).
  * class `Div`: This class represents the division operation. It's string representation should be "/" along with its operands (which might be operands or another operator).
  * class `Add`: This class represents the add operaiton. It's string representation should be "+" along with its operands (which might be operands or another operator).
  * class `Sub`: This class represents the subtraction operation. It's string representation should be "-" along with its operands (which might be operands or another operator).
  * class `Pow`: This class represents the [power or exponentiation](https://en.wikipedia.org/wiki/Exponentiation) operation. It's string representation should be "\*\*" along with its operands (which might be operands or another operator).

> Note: Any parentheses that would normally be necessary in the expression can be implemented in the tree's structure rather than requiring a specific node or other element to represent it. It is recommend that you utilize the `to_string()` function introducted in c++11 to make the `stringify()` function. You may add parenthesies to your `stringify()` function to make it easier to read, but this is optional.

* Create each operation separately and use google test unit tests to fully validate it is functioning before moving on. Make sure to fully test all the functions (`evaluate()` and `stringify()` along with any helper functions) with a range of possible values (both valid and invalid) and using a range of input types where appropriate (for example, use a `Mult` as one of the children when testing an `Add` class and vice-versa).
* Use the [GitHub flow](https://guides.github.com/introduction/flow/) workflow to work on different classes simultantely and then use pull requests (with reviews) to merge code into the `master` branch. It is recommended that you make one commit per class declaration, function definition, and added unit test.

### To run the project nicely run the following commands

```c++
cmake -S . -B build
cmake --build build/
```

### 2 executables are created, use one of the commands to run an executable

```c++
// runs the a simple main for the composit pattern
./build/composite_pattern

// runs the google unit tests for all the classes.
./build/composite_tests
```
