#include <stdlib.h>
#include <string.h>
#include <assert.h>

void *realloc1(void *memblock, unsigned size_old, unsigned size_new) {
    if (size_new == 0) { // If new size is 0, free the old block and return NULL
        free(memblock);
        return NULL;
    }

    if (memblock == NULL) { // If old block is NULL, allocate new memory
        return malloc(size_new);
    }

    void *new_block = malloc(size_new); // Allocate new memory block
    assert(new_block); // Check if allocation was successful

    // Copy the contents from the old block to the new block
    // Use the smaller of the old and new sizes to avoid accessing invalid memory
    size_t min_size = (size_old < size_new) ? size_old : size_new;
    memcpy(new_block, memblock, min_size);

    free(memblock); // Free the old memory block

    return new_block; // Return the pointer to the new memory block
}
