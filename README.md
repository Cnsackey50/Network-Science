# Network Science

This repository contains my Network Science coursework and C++ implementations of graph algorithms.

## Directed cycle detection

`Algorithm1.cc` checks whether a directed graph contains a directed cycle.

The algorithm:

1. Finds vertices with no incoming edges (sources).
2. Removes each source and its outgoing edges.
3. Repeats until no sources remain.
4. Reports a directed cycle if some vertices cannot be removed.

## Example

For the directed graph

```text
a → b → c → a
a → d
```

the program detects the cycle:

```text
a → b → c → a
```

## Compile and run

```bash
g++ Algorithm1.cc -o Algorithm1
./Algorithm1
```

## Author

Christopher Nii Sackey
