# 🐍 Monty Interpreter
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

The interpreter can be run as either a stack (LIFO) or queue (FIFO). Mode can be switched mid-script. The interpreter can handle a variety of Monty opcodes, including printing, mathematical operations, and more - all handled opcodes are listed below.

🏃‍♀️ Getting Started
Ubuntu 14.04 LTS - Operating system reqd.

GCC 4.8.4 - Compiler used
Welcome to the Monty Interpreter project! This project involves creating an interpreter for Monty ByteCodes files. Monty is a scripting language that utilizes a unique stack and specific instructions to manipulate it. In this project, you will implement various opcodes and build a functional interpreter.

## Table of Contents

- [Introduction](#introduction)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Monty Interpreter project aims to create a program that can read and execute Monty ByteCodes files. Monty ByteCodes files are text files with the .m extension, containing a series of instructions for manipulating the stack. The interpreter will execute these instructions and perform the required operations.

## Requirements

- Allowed editors: vi, vim, emacs
- All files will be compiled on Ubuntu 20.04 LTS using gcc, with the options -Wall -Werror -Wextra -pedantic -std=c89
- All files should end with a new line
- A README.md file at the root of the project folder is mandatory
- The code should use the Betty style and will be checked using betty-style.pl and betty-doc.pl
- Only a maximum of one global variable is allowed
- Each file should contain no more than 5 functions
- The C standard library is allowed to be used
- The prototypes of all functions should be included in a header file called `monty.h`
- All header files should have include guards

## Installation

To install and use the Monty Interpreter, follow these steps:

1. Clone the GitHub repository:

```bash
git clone https://github.com/your-username/monty.git
```

2. Navigate to the project directory:

```bash
cd monty
```

3. Compile the source code:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

4. The `monty` executable will be created. You can run the Monty Interpreter with a Monty ByteCodes file using the following command:

```bash
./monty file.m
```

Replace `file.m` with the path to your Monty ByteCodes file.

## Usage

To use the Monty Interpreter, you need to provide a valid Monty ByteCodes file as an argument when running the `monty` executable. The interpreter will read the file, execute the instructions, and perform the required operations on the stack.

If the file argument is missing or more than one argument is provided, the interpreter will print the following error message and exit with status `EXIT_FAILURE`:

```
USAGE: monty file
```

If the interpreter encounters any errors during execution, such as an unknown instruction or an empty stack, it will print an appropriate error message and exit with status `EXIT_FAILURE`.

## Contributing

Contributions to the Monty Interpreter project are welcome! If you would like to contribute, please follow the guidelines outlined in the [CONTRIBUTING.md](https://github.com/your-username/monty/blob/main/CONTRIBUTING.md) file. Whether it's reporting bugs, suggesting enhancements, or submitting pull requests, your contributions will be greatly appreciated.

## License

The Monty Interpreter is licensed under the [MIT License](https://opensource.org/licenses/MIT). You are free to use, modify, and distribute the code in accordance with the terms of the license.

Feel free to reach out to our team at [montyproject@example.com](mailto:montyproject@example.com) if you have any questions or need assistance. Happy coding with
# 🛠️: Monty Opcodes
push

Usage: push <int>
Pushes an element to the stack.
The parameter <int> must be an integer.
pall

Prints all values in the stack/queue, starting from the top.
If the stack is empty, doesn’t print anything
pint

Prints the top value of the stack/queue.
If the stack is empty, error message L<line_number>: can't pint, stack empty, is printed followed by a new line, and exit with the status EXIT_FAILURE
pop

Removes the top element of the stack/queue.
swap

Swaps the top two elements of the stack/queue.
nop

Does not do anything.
add

Adds the top two elements of the stack/queue.
The result is stored in the second element from the top and the top element is popped.
sub

Subtracts the top element of the stack/queue from the second element from the top.
The result is stored in the second element from the top and the top element is removed.
mul

Multiplies the top two elements of the stack/queue.
The result is stored in the second element from the top and the top element is removed.
div

Divides the second element from the top of the stack/queue by the top element.
The result is stored in the second element from the top and the top element is removed.
mod

Computes the modulus of the second element from the top of the stack/queue divided by the top element.
The result is stored in the second element from the top and the top element is removed.
pchar

Prints the character value of the top element of the stack/queue.
The integer at the top is treated as an ASCII value.
pstr

Prints the string contained in the stack/queue.
Prints characters element by element until the stack/queue is empty, a value is 0, or an error occurs.
rotl

Rotates the top element of the stack/queue to the bottom.
rotr

Rotates the bottom element of the stack/queue to the top.
stack

Switches a queue to stack mode.
queue

# Switches a stack to queue mode.
➡️: Opcodes preceeded by a # are treated as comments and the corresponding line is ignored.

: Lines can be empty and can contain any number of spaces before or after an opcode and its argument (only the first opcode and/or argument is taken into account).

 # 🗒️: Examples
Note, Monty Interpreter runs in the default mode of STACK mode. Meaning it uses a stack. To switch to queue mode, see examples below.

Push values onto the stack and print them all, or the top of the stack/front of queue.

$ cat push_pall_pint.m
push 1
push 2
push 3
pall
pint
$ ./monty push_pall_pint.m
3
2
1
3
Using mathmatical operations to add, multiply, divide, etc. Takes the second from the top and performs the operation on the top: second_from_top / top, second_from_top - top, etc. Then assigns that to the second_from_top and pops the top element off the stack.

$ cat math.m
push 3
push 2
push 1
pall
mul
pall
$ ./monty math.m
1
2
3
1
6
Entering queue mode to perform all operations in FIFO (queue) mode instead of default LIFO (stack) mode. Note: does not change current stack, sets front of queue to top of stack.

$ cat queue.m
queue
push 1
push 2
push 3
pall
stack
push 4
push 5
push 6
pall
$ ./monty queue.m
1
2
3
6
5
4
1
2
3
# 📚 Coding Style Tests
Strictly followed Betty style guide. To install

$ git clone https://github.com/holbertonschool/Betty.git

$ cd Betty; ./install.sh
