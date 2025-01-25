#include <iostream>
#include <vector>
#include <cmath>

// Function to solve Tower of Hanoi for 3 rods
void hanoi3(int numDisks, char fromRod, char toRod, char auxRod, int &moveCount) {
    if (numDisks == 1) {
        std::cout << "Move disk 1 from rod " << fromRod << " to rod " << toRod << "\n";
        moveCount++;
        return;
    }

    hanoi3(numDisks - 1, fromRod, auxRod, toRod, moveCount);
    std::cout << "Move disk " << numDisks << " from rod " << fromRod << " to rod " << toRod << "\n";
    moveCount++;
    hanoi3(numDisks - 1, auxRod, toRod, fromRod, moveCount);
}

// Function to solve Tower of Hanoi for more than 3 rods
void hanoiGeneral(int numDisks, int numRods, char fromRod, char toRod, std::vector<char> &auxRods, int &moveCount) {
    if (numRods == 3) {
        // Fall back to standard 3-rod Hanoi if there are only 3 rods
        hanoi3(numDisks, fromRod, toRod, auxRods[0], moveCount);
        return;
    }

    if (numDisks == 1) {
        std::cout << "Move disk 1 from rod " << fromRod << " to rod " << toRod << "\n";
        moveCount++;
        return;
    }

    // Use Frame-Stewart algorithm for more than 3 rods
    int k = numDisks / 2; // Choose k disks to move first (heuristic)
    
    // Step 1: Move the top k disks to an auxiliary rod
    hanoiGeneral(k, numRods, fromRod, auxRods[0], auxRods, moveCount);

    // Step 2: Move the remaining disks to the target rod
    hanoiGeneral(numDisks - k, 3, fromRod, toRod, {auxRods[1], auxRods[2]}, moveCount);

    // Step 3: Move the k disks from the auxiliary rod to the target rod
    hanoiGeneral(k, numRods, auxRods[0], toRod, auxRods, moveCount);
}

int main() {
    int numDisks, numRods;

    std::cout << "Enter the number of disks: ";
    std::cin >> numDisks;
    std::cout << "Enter the number of rods (minimum 3): ";
    std::cin >> numRods;

    if (numRods < 3) {
        std::cout << "Number of rods must be at least 3.\n";
        return 1;
    }

    int moveCount = 0;
    char fromRod = 'A'; // Initial rod
    char toRod = 'B';   // Final rod

    // Generate auxiliary rods
    std::vector<char> auxRods;
    for (int i = 0; i < numRods - 2; ++i) {
        auxRods.push_back('C' + i); // C, D, E, etc.
    }

    std::cout << "\nSteps to solve the Tower of Hanoi:\n";
    hanoiGeneral(numDisks, numRods, fromRod, toRod, auxRods, moveCount);

    std::cout << "\nTotal moves: " << moveCount << "\n";

    return 0;
}
