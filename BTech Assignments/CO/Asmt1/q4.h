int bin_to_dec(int b)
{
    int res = 0, temp, mul = 1;
    while (b > 0)
    {
        temp = b % 10;
        res += (mul * temp);
        mul *= 2;
        b /= 10;
    }
    return res;
}
int decimal_to_binary(int d)
{
    int mul = 1, res = 0;
    while (d > 0)
    {
        res += (mul * (d % 2));
        mul *= 10;
        d /= 2;
    }
    return res;
}
int subtraction_signed_binary_numbers_U20CS093(int b1, int b2)
{
    int diff = 0;
    int check_b1 = 0;
    int check_b2 = 0;
    int check_diff = 0;

    if (b1 > 1111111)
    {
        b1 -= 10000000;
        check_b1 = 1;
    }
    if (b2 > 1111111)
    {
        b2 -= 10000000;
        check_b2 = 1;
    }

    b1 = bin_to_dec(b1);
    b2 = bin_to_dec(b2);

    if (check_b1 == 1 || check_b2 == 0)
    {
        diff = b1 + b2;
        diff *= (-1);
    }
    else if (check_b1 == 1 || check_b2 == 1)
    {
        diff = b2 - b1;
    }
    else if (check_b1 == 0 || check_b2 == 1)
    {
        diff = b1 + b2;
    }
    else 
    {
        diff = b1 - b2;
    }

    if (diff < 0)
    {
        diff *= (-1);
        check_diff = 1;
    }

    diff = decimal_to_binary(diff);

    if (check_diff == 1)
    {
        diff += 10000000;
    }

    return diff;
}