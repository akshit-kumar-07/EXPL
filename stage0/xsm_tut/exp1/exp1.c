#include <stdio.h>
#include <stdlib.h>
#define target_file "exp1.xsm"

int main()
{
    FILE *fp;
    fp = fopen(target_file, "w");
    
    fprintf(fp, " %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ", 0, 2056, 0, 0, 0, 0, 0, 0);
    fprintf(fp, "BRKP\n");
    fprintf(fp, "MOV R0, 3\n");
    fprintf(fp, "MOV R1, 2\n");
    fprintf(fp, "ADD R0, R1\n");

    fclose(fp); // Close the file when done
    return 0;
}

