# Monty Interpreter

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
