// function to find the length of a given string
int strLength(char str[50])
{
    int n = 0;
    while (str[n] != '\0')
    {
        n++;
    }

    return n;
}

// function to concatenate two strings
void concat(char str1[], char str2[], char str3[])
{
    int i = 0;
    while (str1[i] != '\0')
    {
        str3[i] = str1[i];
        i++;
    }

    str3[i] = ' ';

    i++;

    int j = 0;
    while (str2[j] != 0)
    {
        str3[i] = str2[j];
        i++;
        j++;
    }
}

// function to copy one string to another
void copyString(char str[], char copy[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        copy[i] = str[i];
        i++;
    }

    copy[i] = '\0';
}

// function to compare 2 strings
void compareStrings(char str1[], char str2[])
{
    int n1 = strLength(str1);
    int n2 = strLength(str2);

    int i = 0;
    while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
    {
        i++;
    }

    printf("'%s' and '%s' are ", str1, str2);

    if (i == n1 && i == n2)
    {
        printf("\"EQUAL\" strings.\n");
    }
    else
    {
        printf("\"UNEQUAL\" strings.\n");
    }
}

// function to check the first occurence of a character in the string
void firstOccurence(char str[], char c)
{
    int n = strLength(str);

    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (str[i] == c)
        {
            break;
        }
    }

    if (i >= n)
    {
        printf("'%s' does not contain '%c'.\n", str, c);
    }
    else 
    {
        printf("'%c' occurs at the position '%d' in the string '%s' for the first time.\n", c, i, str);
    }

}

// function to check a substring in a string
void checkSubString(char str[], char sub[])
{
    int SL = strLength(str);
    int sl = strLength(sub);
    int count = 0;

    for (int i = 0; i < SL-sl; i++)
    {
        for (int j = 0; j < sl; j++)
        {
            if (str[i+j] == sub[j])
            {
                count++;
            }
        }

        if (count != sl)
        {
            count = 0;
        }
        else // count == sl
        {
            break;
        }
    }

    if (count == sl)
    {
        printf("'%s' does exist in '%s'.\n", sub, str);
    }

    else //(count != sl)
    {
        printf("'%s' does NOT exist in '%s'.\n", sub, str);
    }
}

// function to reverse a string
void reverseString(char str[])
{
    int n = strLength(str);

    for (int i = 0; i < (n/2); i++)
    {
        char temp = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = temp;
    }
}

// function to replace all vowels with star (*)
// and consonants with hash (#) of string
void star_hash(char str[])
{
    int n = strLength(str);

    for (int i = 0; i < n; i++)
    {
        if (((str[i] >= 65) && (str[i] <= 90)) || ((str[i] >= 97) && (str[i] <= 122)))
        {
            if ((str[i] == 65) || (str[i] == 69) || (str[i] == 73) || (str[i] == 79) || (str[i] == 85) || (str[i] == 97) || (str[i] == 101) || (str[i] == 105) || (str[i] == 111) || (str[i] == 117))
            {
                str[i] = '*';
            }
            else 
            {
                str[i] = '#';
            }
        }
    }
}