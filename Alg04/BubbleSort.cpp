/*
 * 冒泡排序
 * 2019-04-19
 * 
 */

#include <iostream>

void bubbleSort(int *a, int n) {
    for (int i = n-1; i > 0; i-- ) {
        for(int j = 0; j < i; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}


int main() {
    int a[] = {20, 40, 30, 10, 60, 50};
    int ilen = (sizeof(a) / sizeof(a[0]));
    
    std::cout << "before sort:" ;
    for (int i = 0; i < ilen; i++) 
        std::cout << a[i] << " ";
    std::cout << std::endl;
    
    bubbleSort(a, ilen);
    
    std::cout << "after sort:" ;
    for (int i = 0; i < ilen; i++) 
        std::cout << a[i] << " ";
    std::cout << std::endl;
    
    return 0;
}
