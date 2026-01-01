## Postfix-convertor
### Expression Conversion in C

This repository contains C programs for converting mathematical expressions to Postfix notation using stacks.

####  Programs Included

##### 1. Infix to Postfix Conversion

* Converts an infix expression (e.g., `A+B`) into a postfix expression (e.g., `AB+`)
* Uses:

  * Character stack
  * Operator precedence rules
  * Parentheses handling

##### 2. Prefix to Postfix Conversion

* Converts a prefix expression (e.g., `+AB`) into a postfix expression (e.g., `AB+`)
* Uses:

  * Stack of strings
  * Right-to-left traversal
  * Operator detection

####  Concepts Used

* Stack data structure
* Operator precedence
* Expression parsing
* String manipulation

#### How to Compile

Use **GCC** to compile the programs:

```bash
gcc infix.c -o infix
gcc prefix.c -o prefix
```

####  How to Run

##### Infix to Postfix

```bash
./infix
```

**Input:**

```
A+B*C
```

**Output:**

```
Postfix Expression: ABC*+
```

##### Prefix to Postfix

```bash
./prefix
```

**Input:**

```
+AB
```

**Output:**

```
Postfix Expression: AB+
```

---

#### Notes & Limitations

* Operands are assumed to be **single characters** (A–Z, a–z, 0–9)
* No error handling for invalid expressions
* Stack size is fixed (`MAX = 100`)
* Designed for **learning and academic purposes**


####  Applications

* Compiler design
* Expression evaluation
* Data structure practice
* Stack-based algorithms


