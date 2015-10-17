/* FIXME: Implement! */

unsigned int maxSubArray(int value[], int size)
{
    static int temp;
    static int sum;
    if(size == 1)
        return temp = value[0];
    sum = maxSubArray(value, size-1);
    if(temp>0)
        temp += value[size-1];
    else
        temp = value[size-1];
    if(temp>sum)
        sum = temp;
    return sum;
}
