# Tower of Hanoi

The Tower of Hanoi is a mathematical game consisting of three rods and a number of disks of various diameters, which can slide onto any rod. The puzzle begins with the disks stacked on one rod in order of decreasing size, the smallest at the top, thus approximating a conical shape. The objective of the puzzle is to move the entire stack to one of the other rods, obeying the following rules:

  • Only one disk may be moved at a time

  • Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod
  
  • No disk may be placed on top of a disk that is smaller than it.
  
The minimal number of moves required to solve a Tower of Hanoi puzzle is 2^n − 1, where n is the number of disks.

![image](https://github.com/user-attachments/assets/42c87262-748a-487d-8a75-800338cbf3e7)

## Iterative solution

A simple solution for the toy puzzle is to alternate moves between the smallest piece and a non-smallest piece.
We can implement this using a trivial algorithm:

```C
for (int i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 0)
            moveDisk(aux, dest);
        else if (i % 3 == 1)
            moveDisk(src, dest);
        else
            moveDisk(src, aux);
    }
```

The full code can be found here [iterative_toh.cpp](https://github.com/aa6dcc/Tower-of-Hanoi/blob/main/iterative_toh.cpp), with time complexity O(2^n)

## Recursive solution

The key to solving a problem recursively is to recognize that it can be broken down into a collection of smaller sub-problems, to each of which that same general solving procedure that we are seeking applies, and the total solution is then found in some simple way from those sub-problems' solutions. Each of these created sub-problems being "smaller" guarantees that the base case(s) will eventually be reached. 

For the Towers of Hanoi:

  1) label the pegs A, B, C,
  2) let n be the total number of disks, and
  3) number the disks from 1 (smallest, topmost) to n (largest, bottom-most)

Assuming all n disks are distributed in valid arrangements among the pegs; assuming there are m top disks on a source peg, and all the rest of the disks are larger than m, so they can be safely ignored; to move m disks from a source peg to a target peg using a spare peg, without violating the rules:

  • Move m − 1 disks from the source to the spare peg, by the same general solving procedure. Rules are not violated, by assumption. This leaves the disk m as a top disk on the source peg
  
  • Move the disk m from the source to the target peg, which is guaranteed to be a valid move, by the assumptions — a simple step
  
  • Move the m − 1 disk that we have just placed on the spare, from the spare to the target peg by the same general solving procedure, so they are placed on top of the disk m without violating the rules
  
  • The base case is to move 0 disks, that is, do nothing — which does not violate the rules
  
The full Tower of Hanoi solution then moves n disks from the source peg A to the target peg C, using B as the spare peg.

The full code can be found here [recursive_toh.cpp](https://github.com/aa6dcc/Tower-of-Hanoi/blob/main/recursive_toh.cpp), with time complexity O(2^n).

## Binary solution
