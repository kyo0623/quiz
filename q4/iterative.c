/* FIXME: Implement! */

unsigned int maxSubArray(int value[], int size)
{
    int i;
    int temp = 0;
    int sum =value[0];
    for(i=0; i < size; i++) {
        if(temp>0)
            temp += value[i];
        else
            temp = value[i];
        if(temp>sum)
            sum = temp;
    }
    return sum;
}
