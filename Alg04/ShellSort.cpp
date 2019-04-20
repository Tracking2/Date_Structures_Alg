/*
 *希尔排序
 *2019-04-20
 */

#include <iostream>

void shellSort(int *a, int n)
{
    int i, j, gap;
    //gap 为步长，每次减为原来一半
    for(gap = n; gap > 0; gap /= 2) {
        //共gap个组，对每一组执行直接插入排序
        for(i = 0; i < gap; i++) {
            for(j = i + gap; j < n; j += gap) {
                //如果a[j] < a[j-gap]， 则寻找a[j]位置，并将后面数据位置向后移动
                if(a[j] < a[j - gap]) {
                    int temp = a[j];
                    int k = j - gap;
                    while(k >= 0 && a[k] > temp) {
                        a[k+gap] = a[k];
                        k -= gap;
                    }
                    a[k+gap] = temp;
                    
                }
                
            }
            
        }
        
    }
    
}

int main() {
    int i;
    int a[] = {20,40,30,10,60,50};
    int ilen = (sizeof(a)) / (sizeof(a[0]));

    std::cout << "before sort:";
    for (i=0; i<ilen; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    shellSort(a, ilen);

    std::cout << "after  sort:";
    for (i=0; i<ilen; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    return 0;
    
}














