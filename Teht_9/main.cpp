#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int* i;
    while (true) {

        // Sain varattua noin 56 GB t�ll�, kun suljin kaiken muun. Aniakin niin paljon n�ytti debugger
        i = (int*)malloc(1000000 * sizeof(int));

        // Sain varattua t�ll� 56,3 GB ja se aiheutti useita erroreja sulkeutuessaan. Pelotti, ett� kone hajosi D:
        i = new int[1000000];

        if (i == NULL) {
            cout << "failed\n";
            break;
        }
    }

    return 0;
}
