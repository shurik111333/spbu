#pragma once

#include <iostream>

typedef unsigned char byte;
typedef int SIZE_TYPE;

/// @brief Class for allocating memory
class Memory
{
public:
	Memory(size_t size);
	~Memory();

	/**
	 * @brief alloc Allocates input number of bytes
	 * @param size Number of bytes
	 * @return Pointer to the first byte of allocating memory, if succeed, or NULL otherwise
	 */
	byte *alloc(size_t size);
	void free(byte *block);

private:
	/**
	 * @param block Pointer to first byte in the block
	 * @return Pointer to size of block at the beginning of the block
	 */
	SIZE_TYPE *start(byte *block);
	/**
	 * @param block Pointer to first byte in the block. Input block must have correct size at the beginning
	 * @return Pointer to size of block at the end of the block
	 */
	SIZE_TYPE *end(byte *block);
	/**
	 * @param block Pointer to the first byte of the block
	 * @return size of the block
	 */
	SIZE_TYPE size(byte *block);
	/**
	 * @brief merge Merge free blocks at the left and right(if exist) with input block
	 * @param block Pointer to the first byte in free block
	 */
	void merge(byte *block);

	size_t memorySize;
	byte *memory;
};
