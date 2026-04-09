\#include &lt;stdio.h&gt;
// Function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
// Partition function (pivot = A[lb])
int partition(int A[], int lb, int ub)
{
    int pivot = A[lb];
    int start = lb;
    int end = ub;
    while (start &lt; end)
    {
        while (A[start] &lt;= pivot &amp;&amp; start &lt;= ub)
        {
            start++;
        }
        while (A[end] &gt; pivot &amp;&amp; end &gt;= lb)
        {
            end--;
        }
        if (start &lt; end)
        {
            swap(&amp;A[start], &amp;A[end]);
        }
    }
    swap(&amp;A[lb], &amp;A[end]);
    return end;
}

// Recursive quicksort function
void quickSort(int A[], int lb, int ub)
{
    if (lb &lt; ub)
    {
        int loc = partition(A, lb, ub);
        quickSort(A, lb, loc - 1);
        quickSort(A, loc + 1, ub);
    }
}
// Function to print array
void printArray(int A[], int n)
{
    for (int i = 0; i &lt; n; i++)
    {
        printf(&quot;%d &quot;, A[i]);
    }
    printf(&quot;\n&quot;);
}
// Main function
int main()
{
    int A[] = {15, 10, 80, 90, 12, 5, 31};
    int n = sizeof(A) / sizeof(A[0]);
    printf(&quot;Original array: &quot;);
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printf(&quot;Sorted array: &quot;);
    printArray(A, n);
    return 0;
}
