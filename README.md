# Numeration-automatic sequences
This project contains code used in a study of
[*k*-automata](https://www.fixedpoint.nl/study/dynsys/automata.pdf)
and
[numeration-automatic sequences](https://arxiv.org/abs/cs/0605076).


## Installation
Retrieve the source code with Git.

    git clone https://github.com/jfjlaros/numauto.git

Compile the main program.

    cd numauto/src/sequence
    make


## Usage
The substitution schema is supplied by entering a list of production rules via
standard input. Each production rule has one letter on the left hand side and
one or more letters on the right hand side, the parts are separated by the `>`
sign.

The input can be supplied while the program is running. Press `Control-d` when
the substitution schema is fully entered.

    ./sequence

Alternatively, the substitution schema can be supplied beforehand and piped
into the program as follows:

    cat << EOF | ./sequence
    a>abc
    b>aac
    c>a
    EOF

The output for the example given above, will look like this:

```
The matrix:
1 2 1 
1 0 0 
1 1 0 

k = 3

The fixed point:
abcaacaabcabcaabcabcaacaabcaacaabcabcaacaabcaacaabcabcaabcabcaacaabcabcaabcabcaa
caabcaacaabcabcaabcabcaacaabcabcaabcabcaacaabcaacaabcabcaacaabcaacaabcabcaabcabc
aacaabcaacaabcabcaacaabcaacaabcabcaabcabcaacaabcabcaabcabcaacaabcaacaabcabcaacaa
bcaacaabcabcaabcabcaacaabcaacaabcabcaacaabcaacaabcabcaabcabcaacaabcabcaabcabcaac
aabcaacaabcabcaabcabcaacaabcabcaabcabcaacaabcaacaabcabcaacaabcaacaabcabcaabcabca
acaabcabcaabcabcaacaabcaacaabcabcaabcabcaacaabcabcaabcabcaacaabcaacaabcabcaacaab
caacaabcabcaabcabcaacaabcaacaabcabcaacaabcaacaabcabcaabcabcaacaabcabcaabcabcaaca
abcaacaabcabcaabcabcaacaabcabcaabcabcaacaabcaacaabcabcaacaabcaacaabcabcaabcabcaa
caabcabcaabcabcaacaabcaacaabcabcaabcabcaacaabcabcaabcabcaacaabcaacaabcabcaacaabc
aacaabcabcaabcabcaacaabcaacaabcabcaacaabcaacaabcabcaabcabcaacaabcabcaabcabcaacaa
bcaacaabcabcaacaabcaacaabcabcaabcabcaacaabcaacaabcabcaacaabcaacaabcabcaabcabcaac
aabcabcaabcabcaacaabcaacaabcabcaabcabcaacaabcabcaabcabcaacaabcaacaabcabcaacaabca
acaabcabcaabcabcaacaabcaacaabcabcaacaabcaacaabcabcaabcabcaacaabcabcaabcabcaacaab
caacaabcabcaacaabcaacaabcabcaabcabcaacaabcaacaabcabcaacaabcaacaabcabcaabcabcaaca
abcabcaabcabcaacaabcaacaabcabcaabcabcaacaabcabcaabcabcaacaabcaacaabcabcaacaabcaa
caabcabcaabcabcaacaabcabcaabcabcaacaabcaacaabcabcaabcabcaacaabcabcaabcabcaacaabc

The numeration system:
1 3 7 17 41 99 239 577
```

The following sections of the [paper](https://arxiv.org/abs/cs/0605076) are
particularly relevant for the interpretation of the results:

- Section 5: conversion from a substitution to `The matrix`.
- Definition 2.0.7: `k` in this context.
- Definition 2.0.6: `The fixed point`.
- Definition 2.0.8: `The numeration system`.


## Additional programs
This project contains some additional code that was used during the study. Most
of the functionality is present in the main program described above.

- A programming library for [*k*-automata](src/k_autom) including examples.
- A programming library for [Fibonacci automaton](src/fib_autom) including
  examples.
- An implementation of substitutions in [general](src/subst) which can be used
  to verify the correctness of the constructed automata.


## Related work
Some new insights gained during the study were shared with the
[On-Line Encyclopedia of Integer Sequences](http://oeis.org/):

- The Fibonacci sequence ([A000045](http://oeis.org/A000045)).
- Other sequences: [A101399](http://oeis.org/A101399),
  [A101400](http://oeis.org/A101400), [A101169](http://oeis.org/A101169),
  [A101197](http://oeis.org/A101197), [A101168](http://oeis.org/A101168).


## Acknowledgements
The author would like to thank Prof.dr. Robert Tijdeman and Dr. Hendrik Jan
Hoogeboom for their numerous comments and insightful ideas.
