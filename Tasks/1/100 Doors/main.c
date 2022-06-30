#include <stdio.h>

int main()
{
    // Create an array of 100 zeros.
    int door[100] = {0};
    int pass, check;
    int i;

    for (pass = 0; pass < 100; ++pass)
    {
        // Start at pass, this way we will not keep toggling 0
        for (check = pass; check < 100; check += pass + 1)
        {
            // Since it is a 0 or 1 we can invert them similar to bools
            door[check] = !door[check];
        }
    }

    // Print the answer that we get from above
    printf("\nAnswer:   ");
    for (i = 0; i < 100; i++)
    {
        printf("%d", door[i]);
    }

    // This is the intended solution, printing so I can do a comparison
    printf("\nSolution: 1001000010000001000000001000000000010000000000001000000000000001000000000000000010000000000000000001\n");

    return 0;
}