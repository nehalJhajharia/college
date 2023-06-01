int binary_to_decimal(int b)
{
    int res = 0, temp, mul = 1;
    while (b > 0)
    {
        temp = b % 10;
        res += mul * temp;
        mul *= 2;
        b /= 10;
    }
    return res;
}
int decimal_to_unsigned_binary(int d)
{
    int mul = 1, res = 0;
    while (d > 0)
    {
        res += mul * (d % 2);
        mul *= 10;
        d /= 2;
    }
    return res;
}
int subtraction_unsigned_binary_numbers_U20CS093(int b1, int b2)
{
    int d1 = binary_to_decimal(b1);
    int d2 = binary_to_decimal(b2);
    int res;
    if (d1 > d2)
    {
        res = d1 - d2;
    }
    else
    {
        res = 0;
    }

    res  = decimal_to_unsigned_binary(res);
    return res;
}