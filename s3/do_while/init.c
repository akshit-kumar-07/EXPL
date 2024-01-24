extern FILE *target_file;
void init()
{
    target_file = fopen("label_code.xsm", "w");
    fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n");
    fprintf(target_file, "ADD SP, 26\n");
    fprintf(target_file, "CALL MAIN\n");
    fprintf(target_file, "MOV R0,10\nPUSH R0\nINT 10\n");
    fprintf(target_file, "MAIN:\n");
}
