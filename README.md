# Numeration-automatic sequences
A simple implementation of substitutions in [general](subst.tgz)
used to verify the correctness of the constructed automata.

## Background
This project is related to the study of
[*k*-automata](https://www.fixedpoint.nl/study/dynsys/automata.pdf)
and
[Numeration-automatic sequences](https://arxiv.org/abs/cs/0605076).


## Installation
Retrieve the source code with Git.

    git clone https://github.com/jfjlaros/numauto.git

Compile the main program.

    cd numauto/src/sequence
    make


## Usage
The main program does not take any arguments, input is read from standard
input.

The substitution schema is supplied by giving a list of production rules. Each
production rule has one letter on the left hand side and one or more letters on
the right hand side, the parts are separated by the `>` sign.

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

To understand the output, it is probably necessary to read the
[paper](https://arxiv.org/abs/cs/0605076), in particular:

- Section 5: conversion from a substitution to "The matrix".
- Definition 2.0.7: "k" in this context.
- Definition 2.0.6: "The fixed point".
- Definition 2.0.8: "The numeration system".


## Related work
Some new insights were shared with the
[On-Line Encyclopedia of Integer Sequences](http://oeis.org/).

The Fibonacci sequence: [A000045](http://oeis.org/A000045).

Other sequences: [A101399](http://oeis.org/A101399),
[A101400](http://oeis.org/A101400), [A101169](http://oeis.org/A101169),
[A101197](http://oeis.org/A101197), [A101168](http://oeis.org/A101168).


## Acknowledgements
Prof.dr. Robert Tijdeman

Dr. Hendrik Jan Hoogeboom
