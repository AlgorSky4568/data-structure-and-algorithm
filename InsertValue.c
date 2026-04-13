#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int m = n + 1;
    int *nums1 = (int *) malloc(n * sizeof(int));
    int *nums2 = (int *) malloc(m * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums1[i]);
    }
    int val;
    scanf("%d", &val);
    int i,j;
    i = 0;
    j = 0;
    int inserted = 0;
    while (i < n) {
        if (!inserted && nums1[i] > val) {
            nums2[j++] = val;
            inserted = 1;
        } else {
            nums2[j++] = nums1[i++];
        }
    }

    // 如果val比所有元素都大
    if (!inserted) {
        nums2[j] = val;
    }
    
    for (j = 0 ;j < m; j++) {
        printf("%d",nums2[j]);
        if (j < m - 1) {
            printf(" ");
        }
    }

    return 0;
}