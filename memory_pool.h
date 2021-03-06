#pragma once

typedef struct _chunk{
    struct _chunk *next;
    int chunk_size;
    char buf[];  //柔性数组
}Chunk;

typedef struct _block{
    int chunk_cnt;
    int chunk_size;  //记录chunk的size，回收的时候方便找到指定的block回收
    struct _block *next;
    struct _chunk *chunk_list;
}Block;

typedef struct _memory_pool{
    int block_cnt;  //block的个数
    struct _block *next;
}MemoryPool;

MemoryPool* mem_pool_create(int chunk_size, int factor);  //factor增长因子
void* mem_pool_alloc(MemoryPool* pool, int size);  //需要的内存大小
void mem_pool_free(MemoryPool* pool, void* memory);
void mem_pool_destroy(MemoryPool* pool);