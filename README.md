# Tower of Hanoi

The Tower of Hanoi is a mathematical game consisting of three rods and a number of disks of various diameters, which can slide onto any rod. The puzzle begins with the disks stacked on one rod in order of decreasing size, the smallest at the top, thus approximating a conical shape. The objective of the puzzle is to move the entire stack to one of the other rods, obeying the following rules:

  • Only one disk may be moved at a time

  • Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod
  
  • No disk may be placed on top of a disk that is smaller than it.
  
The minimal number of moves required to solve a Tower of Hanoi puzzle is 2^n − 1, where n is the number of disks.

![image](https://github.com/user-attachments/assets/42c87262-748a-487d-8a75-800338cbf3e7)

An interactive code, where the user can define the number of disks, can be found here: [interactive_toh.cpp](https://github.com/aa6dcc/Tower-of-Hanoi/blob/main/src/interactive_toh.cpp)

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
![image](https://github.com/user-attachments/assets/a131e413-2ef6-4338-ad8b-91ffde556dec)

The full code can be found here [iterative_toh.cpp](https://github.com/aa6dcc/Tower-of-Hanoi/blob/main/src/iterative_toh.cpp), with time complexity O(2^n)

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

```C
towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
```
![image](https://github.com/user-attachments/assets/8f178855-cc5e-407b-b42f-c68d544f45b1)

The full code can be found here [recursive_toh.cpp](https://github.com/aa6dcc/Tower-of-Hanoi/blob/main/src/recursive_toh.cpp), with time complexity O(2^n).

## Binary solution

The Tower of Hanoi problem can be solved efficiently using the binary representation of the move number. Each move corresponds to a unique binary number, and the state of the disks at any move can be derived directly from the binary digits of that move number. This method eliminates the need for recursion or explicit simulation of prior moves, as all information can be inferred from the current move number.

Peg Assignment:

  • A 0 indicates that the disk is on the initial peg
  
  • A 1 indicates that the disk is on the final peg (the middle peg if the number of disks is even, or the right peg if the number of disks is odd)
  
  • Disks with consecutive binary digits that are identical (00 or 11) remain stacked on the same peg, while disks with alternating binary digits (01 or 10) move to a different peg.
  
Disk Movement Rule:

The peg to which a disk moves is determined by counting the number of trailing zeros in the binary representation of the move number. The disk corresponding to this count is moved the smallest possible distance to the left or right (wrapping around as needed).

For example, for move 9 in a 4-disk puzzle:

  - The binary representation is 1001
  - The largest disk (bit 1, farthest left) is 1, so it is on the final peg (peg 2)
  - The second-largest disk is 0, so it is on the initial peg (peg 0)
  - The third-largest disk is also 0, so it remains stacked on peg 0
  - The smallest disk (bit 4, farthest right) is 1, so it is on the final peg (peg 2), stacked on top of the largest disk

Thus, at move 9, the configuration is:

Peg 0: Disks 2 and 3

Peg 2: Disks 1 and 4

Peg 1: Empty

The binary approach can be implemented in two different ways:

Efficient and straightforward way relying on bitwise operations [binary_toh_1.cpp](https://github.com/aa6dcc/Tower-of-Hanoi/blob/main/src/binary_toh_1.cpp)

Detailed and state-aware, uses binary representation of the move number to determine the exact position of each disk at any given point [binary_toh_2.cpp](https://github.com/aa6dcc/Tower-of-Hanoi/blob/main/src/binary_toh_2.cpp)
