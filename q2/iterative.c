/* FIXME: Implement! */

char smallest_character ( char str[], char c )
{
    int i = 0;
    while (str[i] != '\t') {
        if(str[i] > c)
            return str[i];
        i++;
    }
    return str[0];
}
