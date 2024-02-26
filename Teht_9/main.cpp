#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int* i;
    while (true) {

        // Sain varattua noin 56 GB tällä, kun suljin kaiken muun. Aniakin niin paljon näytti debugger
        i = (int*)malloc(1000000 * sizeof(int));

        // Sain varattua tällä 56,3 GB ja se aiheutti useita erroreja sulkeutuessaan. Pelotti, että kone hajosi D:
        i = new int[1000000];

        if (i == NULL) {
            cout << "failed\n";
            break;
        }
    }

    return 0;
}
