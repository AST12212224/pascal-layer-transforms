#include <stdio.h>
#include <stdlib.h>

int main() {
    int l_min, l_max, d;

    printf("Enter min l: ");
    scanf("%d", &l_min);

    printf("Enter max l: ");
    scanf("%d", &l_max);

    printf("Enter p offset (p = l + offset): ");
    scanf("%d", &d);

    for (int l = l_min; l <= l_max; l++) {
        int p = l + d;

        char cmd[256];

        /* assumes executable is ./layer_triangle_tsv */
        sprintf(cmd, "printf \"%d\n%d\n\" | ./layer_gmp", l, p);

        printf("Running l=%d, p=%d\n", l, p);
        system(cmd);
    }

    printf("Automation complete.\n");
    return 0;
}

