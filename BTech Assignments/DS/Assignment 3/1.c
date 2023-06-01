#include <stdio.h>
#include "mystring.h"

int main()
{
    char fname[20];
    char lname[30];
    char name[50];
    char nameCopy[50];

    printf("Enter you first name: ");
    scanf("%s", fname);
    printf("Enter you last name: ");
    scanf("%s", lname);

    // find length of first name
    int fnameLength = strLength(fname);
    printf("Length of first name = %d\n", fnameLength);

    // concatenate first and last names in name
    concat(fname, lname, name);
    printf("Your name is %s.\n", name);


    // copy name into nameCopy
    copyString(name, nameCopy);
    printf("Copied string is \"%s\"\n", nameCopy);

    // compare 2 strings
    compareStrings(fname, lname);
    compareStrings(name, nameCopy);

    // check occurence of a character
    char c;
    printf("Enter the character to be checked: ");
    scanf(" %c", &c);
    firstOccurence(name, c);

    // check a substring
    char subString[10];
    printf("Enter the substring to be checked: ");
    scanf("%s", subString);
    checkSubString(name, subString);

    // reverse a string
    printf("Reverse of %s is: ", name);
    reverseString(name);
    printf("%s\n", name);

    // reverse it again for further solutions
    reverseString(name);

    // replace vowels & consonants with * and #
    star_hash(nameCopy);
    printf("Encoded name, '%s' is %s.\n", name, nameCopy);

    return 0;
}