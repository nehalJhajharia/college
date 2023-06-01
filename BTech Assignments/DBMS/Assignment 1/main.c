#include <stdio.h>

int main()
{
    char fname[10] = {'\0'};
    printf("Enter first name : ");
    scanf("%s", fname);

    FILE *fp;

    fp = fopen("MyFile.txt", "w");
    fputs(fname, fp);
    fclose(fp);

    char str[10] = {'\0'};
    fp = fopen("MyFile.txt", "r");
    fscanf(fp, "%s", str);
    fclose(fp);
    printf("String is %s.\n", str);

    char lname[10] = {'\0'};
    printf("Enter last name : ");
    scanf("%s", lname);

    fp = fopen("MyFile.txt", "a");
    fputs(" ", fp);
    fputs(lname, fp);
    fclose(fp);

    return 0;
}