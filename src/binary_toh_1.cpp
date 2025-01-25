#include <iostream>
#include <cmath>

void towerOfHanoiBinary(int numDisks) {
    int totalMoves = (1 << numDisks) - 1; // Total moves: 2^n - 1
    char rods[3] = {'A', 'B', 'C'}; // Names of rods

    for (int i = 1; i <= totalMoves; ++i) {
        int fromRod = (i & i - 1) % 3;          // Source rod index
        int toRod = ((i | i - 1) + 1) % 3;      // Destination rod index

        std::cout << "Move disk from " << rods[fromRod] 
                  << " to " << rods[toRod] << "\n";
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

    towerOfHanoiBinary(numDisks);
    return 0;
}
