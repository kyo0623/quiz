/* FIXME: Implement! */

char smallest_character ( char str[], char c )
{
    if(str[0] != '\t') {
        if(str[0] > c)
            return str[0];
        else
            return ((smallest_character(str + 1, c) > c) ? smallest_character(str + 1, c) : str[0]);
    } else
        return str[0];
}
