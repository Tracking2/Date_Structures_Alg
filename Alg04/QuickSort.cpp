/*
 *快速排序
 *2019-04-19
 */

#include <iostream>

/*
 *
 *参数说明：
 *      a - 待排序数组
 *      l - 数组左边界
 *      r - 数组右边界
 */
void quickSort(int *a, int l, int r) {
    if (l < r) {
        int i = l;
        int j = r;
        int x = a[i];
        while (i < j) {
            while(i < j && a[j] > x)
                j--; //从右向左找第一个小于x的数
            if(i < j)
                a[i++] = a[j];
            while(i < j && a[i] < x)
                i++; //从左向右找第一个大于x的数
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        quickSort(a, l, i-1); //递归调用
        quickSort(a, i+1, r);
    }
}
int main()
{
    int i;
    int a[] = {30,40,60,10,20,50};
    int ilen = (sizeof(a)) / (sizeof(a[0]));

    std::cout << "before sort:";
    for (i=0; i<ilen; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    quickSort(a, 0, ilen-1);

    std::cout << "after  sort:";
    for (i=0; i<ilen; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    return 0;
}


