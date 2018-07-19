
# Abstract VM

*Summary: The purpose of this project is to create a simple virtual machine 
that can interpret programs written in a basic assembly language.*

## The Project

AbstractVM is a machine that uses a stack to compute simple arithmetic expressions.
These arithmetic expressions are provided to the machine as basic assembly programs.

### The Assembly Language

this is an example of the assembly program.

```
1 ; -------------
2 ; exemple.avm -
3 ; -------------
4
5 push int32(42)
6 push int32(33)
7
8 add
9
10 push float(44.55)
11
12 mul
13
14 push double(42.42)
15 push int32(42)
16
17 dump
18
19 pop
20
21 assert double(42.42)
22
23 exit
```
#### Description of the assembly language


AbstractVM is composed of a series of instructions, with one instruction per
line.  **However**, AbstractVM's language has limited type system, which
is a **major** difference from other real world assembly languages.

- **Comments**:  Comments start with a ’;’ and finish with a newline. 
A comment can be either at the start of a line, or after an instruction.

- **push _v_:** Pushes the value v at the top of the stack. 
The value v must have one ofthe following form:
  - **int8(n):** Creates an 8-bit integer with value n.
  - **int16(n):** Creates a 16-bit integer with value n
  - **int32(n):** Creates a 32-bit integer with value n.
  - **float(z):** Creates a float with value z.
  - **double(z):** Creates a double with value z.

- **pop:**  Unstacks the value from the top of the stack. 
If the stack is empty, theprogram execution must stop with an error.

- **dump:**  Displays each value of the stack, from the most recent one to the 
oldest one **WITHOUT CHANGING** the stack. Each value is separated from the 
next one by a newline.

- **assert: _v_** Asserts that the value at the top of the stack is equal to the
one passed as parameter for this instruction. If it is not the case, the program
execution must stop with an error. The value _v_ has the same form that those 
passed as parameters to the instruction **push**.

- **add:**  Unstacks the first two values on the stack, adds them together and 
stacks the result. _If_ the number of values on the stack is strictly inferior 
to 2, the program execution **must** stop with an error.

- **sub:** Unstacks the first two values on the stack, subtracts them, then 
stacks the result. _If_ the number of values on the stack is strictly inferior 
to 2, the program execution **must** stop with an error.

- **mul:** Unstacks the first two values on the stack, multiplies them, 
then stacks the result. _If_ the number of values on the stack is strictly 
inferior to 2, the program execution **must** stop with an error.

- **div:**  Unstacks the first two values on the stack, divides them, then 
stacks the result. _If_ the number of values on the stack is strictly inferior 
to 2, the program execution **must** stop with an error. Moreover, _if_ the 
divisor is equal to 0, the program execution **must** stop with an error too. 
Chatting about floating point values is relevant a this point. If you don’t 
understand why, some will understand. The linked question is an open one, 
there’s no definitive answer.

- **mod:** Unstacks the first two values on the stack, calculates the modulus, 
then stacks the result. _If_ the number of values on the stack is strictly 
inferior to 2, the program execution **must** stop with an error. Moreover, _if_
the divisor is equal to 0, the program execution **must** stop with an error 
too. Same note as above about _fp values_.

- **print:** Asserts that the value at the top of the stack is an **8-bit** 
integer. (_If_ not, see the instruction assert), then interprets it as an ASCII
value and displays the corresponding character on the standard output.

- **exit:** Terminate the execution of the current program. _If_ this 
instruction does not appear after all other instructions have been processed, 
the execution **must** stop with an error

```
For non commutative operations, consider the stack v1 on v2 on
stack_tail, the calculation in infix notation v2 op v1.
```

When a computation involves two operands of different types, the value returned
has the type of the more precise operand. Please do note that because of the 
extensibility of the machine, the precision question is not a trivial one. 
This is covered more in details later in this document.

### Grammar

The assembly language of AbstractVM is generated from the following grammar 
(**#** corresponds to the end of the input, not to the character ’#’):

```
1 S := INSTR [SEP INSTR]* #
2
3 INSTR :=
4 push VALUE
5 | pop
6 | dump
7 | assert VALUE
8 | add
9 | sub
10 | mul
11 | div
12 | mod
13 | print
14 | exit
15
16 VALUE :=
17 int8(N)
18 | int16(N)
19 | int32(N)
20 | float(Z)
21 | double(Z)
22
23 N := [-]?[0..9]+
24
25 Z := [-]?[0..9]+.[0..9]+
26
27 SEP := '\n'+
```

### Errors

When one of the following cases is encountered, AbstractVM must raise an 
exception and stop the execution of the program cleanly. It is forbidden to 
raise **scalar exceptions**. Moreover your exception classes must inherit 
from ``` std::exception ```.

- The assembly program includes one or several lexical errors or syntactic errors.
- An instruction is unknown
- Overflow on a value
- Underflow on a value
- Instruction pop on an empty stack
- Division/modulo by 0
- The program doesn’t have an exit instruction
- An assert instruction is not true
- The stack is composed of strictly less that two values when an arithmetic 
instruction is executed.

### Execution

Your machine must be able to run programs from a file passed as a parameter 
and from the standard input. When reading from the standard input, the end of 
the program is indicated by the special symbol ";;" otherwise absent.

examples:

```
1 $>./avm
2 push int32(2)
3 push int32(3)
4 add
5 assert int32(5)
6 dump
7 exit
8 ;;
9 5
10 $>
```
```
1 $>cat sample.avm
2 ; -------------
3 ; sample.avm -
4 ; -------------
5
6 push int32(42)
7 push int32(33)
8 add
9 push float(44.55)
10 mul
11 push double(42.42)
12 push int32(42)
13 dump
14 pop
15 assert double(42.42)
16 exit
17 $>./avm ./sample.avm
18 42
19 42.42
20 3341.25
21 $>
```
```
1 $>./avm
2 pop
3 ;;
4 Line : Error : Pop on empty stack
5 $>
```
## Mandatory Part

### Generic Instructions

- You are free to use any compiler you like.
- Your code must compile with: -Wall -Wextra -Werror.
- You are free to use any C++ version you like.
- You are free to use any library you like.
- You must provide a Makefile with the usual rules.
- Any class that declares at least one attribute must be written in canonical 
form. Inheriting from a class that declares attributes does not count as 
declaring attributes.
- It’s forbidden to implement any function in a header file, except for 
templates and the virtual destructor of a base class.
- The “keyword” "using namespace" is forbidden.

### The IOperand interface

- Int8 : Representation of a signed integer coded on 8bits.
- Int16 : Representation of a signed integer coded on 16bits.
- Int32 : Representation of a signed integer coded on 32bits.
- Float : Representation of a float.
- Double : Representation of a double.

Each one of these operand classes **MUST** implement the following 
IOperand interface:

```
class IOperand {
public:
	virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
	virtual eOperandType getType( void ) const = 0; // Type of the instance
	virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
	virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
	virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
	virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
	virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo

	virtual std::string const & toString( void ) const = 0; // String representation of the instance
	virtual ~IOperand( void ) {}
};
```

### Creation of new Operand

New operands **MUST** be created via a "factory method". 
The member function must have this prototype:

```
IOperand const * createOperand( eOperandType type, std::string const & value ) const;
```

The ```eOperandType type``` is an enum defining the following values:
``` Int8, Int16, Int32, Float, Double```

Depending on the _enum_ value passed as a parameter, the member function 
createOperand creates a new IOperand by calling one of the following private 
member functions:

```
IOperand const * createInt8( std::string const & value ) const;
IOperand const * createInt16( std::string const & value ) const;
IOperand const * createInt32( std::string const & value ) const;
IOperand const * createFloat( std::string const & value ) const;
IOperand const * createDouble( std::string const & value ) const;
```

In order to choose the right member function for the creation of the new 
IOperand, you **MUST** create and use an array (here, a vector shows little 
interest) of pointers on member functions with enum values as index
