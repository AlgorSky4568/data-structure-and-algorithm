#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BLOOM_SIZE 10000  // 布隆过滤器位数组大小
#define NUM_HASHES 3      // 使用的哈希函数数量

typedef struct {
    unsigned char *bit_array;
    int size;
} BloomFilter;

// 初始化布隆过滤器
BloomFilter* bloom_init(int size) {
    BloomFilter *filter = (BloomFilter*)malloc(sizeof(BloomFilter));
    filter->size = size;
    filter->bit_array = (unsigned char*)calloc((size + 7) / 8, sizeof(unsigned char));
    return filter;
}

// 释放布隆过滤器
void bloom_free(BloomFilter *filter) {
    free(filter->bit_array);
    free(filter);
}

// 设置位数组中的某一位
void set_bit(BloomFilter *filter, unsigned int index) {
    filter->bit_array[index / 8] |= (1 << (index % 8));
}

// 检查位数组中的某一位
int get_bit(BloomFilter *filter, unsigned int index) {
    return (filter->bit_array[index / 8] >> (index % 8)) & 1;
}

// 哈希函数1
unsigned int hash1(const char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

// 哈希函数2
unsigned int hash2(const char *str) {
    unsigned int hash = 0;
    int c;
    while ((c = *str++)) {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}

// 哈希函数3
unsigned int hash3(const char *str) {
    unsigned int hash = 0;
    int c;
    const unsigned int seed = 131;
    while ((c = *str++)) {
        hash = hash * seed + c;
    }
    return hash;
}

// 添加元素到布隆过滤器
void bloom_add(BloomFilter *filter, const char *item) {
    set_bit(filter, hash1(item) % filter->size);
    set_bit(filter, hash2(item) % filter->size);
    set_bit(filter, hash3(item) % filter->size);
}

// 检查元素是否可能在布隆过滤器中
int bloom_check(BloomFilter *filter, const char *item) {
    int flag1 = get_bit(filter,hash1(item) % filter->size);
    int flag2 = get_bit(filter,hash2(item) % filter->size);
    int flag3 = get_bit(filter,hash3(item) % filter->size);
    if (!flag1 || !flag2 || !flag3)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main() {
    // 创建布隆过滤器
    BloomFilter *filter = bloom_init(BLOOM_SIZE);
    
    int m;
    char str_add[100];
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%s", str_add);
        bloom_add(filter, str_add);
    }

    int n;
    char str_check[100];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", str_check);
        printf("%d\n", bloom_check(filter, str_check));
    }
    
    // 释放过滤器
    bloom_free(filter);
    
    return 0;
}