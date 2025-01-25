#include <iostream>
#include <cmath>
#include <bitset>

void towerOfHanoiBinaryEfficient(int numDisks, int totalMoves) {
    // Array to hold the positions of each disk (0 = initial peg, 1 = middle peg, 2 = final peg)
    int positions[numDisks] = {0};

    // Determine the final peg based on the parity of the number of disks
    int finalPeg = (numDisks % 2 == 0) ? 2 : 1;

    for (int move = 1; move <= totalMoves; ++move) {
        // Determine the disk to move by counting trailing zeros in the move number
        int diskToMove = __builtin_ctz(move);

        int currentPosition = positions[diskToMove];
        int newPosition = (currentPosition + (numDisks % 2 == 0 ? -1 : 1)) % 3; // Even: left; Odd: right

        // Handle wrap-around (e.g., -1 becomes 2, 3 becomes 0)
        if (newPosition < 0) newPosition += 3;

        positions[diskToMove] = newPosition;

        std::cout << "Move disk " << diskToMove + 1 << " from peg " 
                  << currentPosition + 1 << " to peg " << newPosition + 1 << "\n";
    }
}

int main() {
    int numDisks;
    std::cout << "Enter the number of disks: ";
    std::cin >> numDisks;

    if (numDisks < 1) {
        std::cout << "The number of disks must be at least 1.\n";
        return 1;
    }

    int totalMoves = (1 << numDisks) - 1; // 2^n - 1

    towerOfHanoiBinaryEfficient(numDisks, totalMoves);

    return 0;
}
