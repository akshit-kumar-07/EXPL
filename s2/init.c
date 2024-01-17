extern FILE *target_file;
void init()
{
    target_file = fopen("target_file.xsm", "w");
    fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n");
    fprintf(target_file, "ADD SP, 26\n");
}
