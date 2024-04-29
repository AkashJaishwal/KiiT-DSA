#include <stdio.h>
void swap935(int *a935, int *b935)
{
    *a935 = *a935 + *b935;
    *b935 = *a935 - *b935;
    *a935 = *a935 - *b935;
}
void minHeapify935(int a935[], int size, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;
    if (l < size && a935[l] < a935[smallest])
        smallest = l;
    if (r < size && a935[r] < a935[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap935(&a935[i], &a935[smallest]);
        minHeapify935(a935, size, smallest);
    }
}
void buildMinHeap(int a935[], int size)
{
    for (int i = size / 2; i >= 0; i--)
        minHeapify935(a935, size, i);
}
int kthLargest(int a935[], int size, int k)
{
    int minHeap[k];
    int i;
    for (i = 0; i < k; i++)
        minHeap[i] = a935[i];
    buildMinHeap(minHeap, k);
    for (i = k; i < size; i++)
    {
        if (a935[i] > minHeap[0])
        {
            minHeap[0] = a935[i];
            minHeapify935(minHeap, k, 0);
        }
    }
    return minHeap[0];
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int a935[n + 1];
        for (int i = 0; i < n; i++)
            scanf("%d", &a935[i]);
        printf("%d\n", kthLargest(a935, n, k));
    }
    return 0;
}