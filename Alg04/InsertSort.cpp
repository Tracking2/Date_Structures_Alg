/*
 *直接插入排序
 *2019-04-20
 */
#include <iostream>

void insertSort(int *a, int n) {
    int i,j,k;
    for(i = 1; i < n; i++) {
        //在有序区间中找到合适的位置
        for(j = i - 1; j >= 0; j--) {
            if (a[j] < a[i]) {
                break;
            }
        }
        
        if(j != i - 1) {
            int temp = a[i];
            for(k = i-1; k>j; k--) {
                a[k+1] = a[k];
            }
            a[k+1] = temp;
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

    insertSort(a, ilen);

    std::cout << "after  sort:";
    for (i=0; i<ilen; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    return 0;
    
}

