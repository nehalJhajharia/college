int binary_to_octal(int b)
{
    int temp, mul = 1, res = 0;
    while (b)
    {
        temp = b % 1000;
        temp = (temp / 100) * 4 + ((temp % 100) / 10) * 2 + (temp % 10) * 1;
        res += temp * mul;
        mul *= 10;
        b /= 1000;
    }
    return res;
}
