int nextLetter (unsigned char *l)
{
    if (*l == 'z' || *l == 'Z')
    {
        return 0;
    }
    *l += 1;
    return 1;
}