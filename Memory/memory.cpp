#include "memory.h"

#include <cassert>

Memory::Memory(size_t size)
    :memorySize(size)
{
	memory = new byte[size + 2 * sizeof(SIZE_TYPE)];
	*(int*)(memory) = -size;
	*(int*)(memory + memorySize - sizeof(SIZE_TYPE)) = -size;
}

Memory::~Memory()
{
	delete[] memory;
}

byte *Memory::alloc(size_t size)
{
	byte *block = memory + sizeof(SIZE_TYPE);
	while (block - memory < memorySize)
	{
		SIZE_TYPE curSize = this->size(block);
		if (curSize < 0 && abs(curSize) >= size)
		{
			curSize = -curSize;
			SIZE_TYPE rest = curSize - size;
			if (rest <= 2 * sizeof(SIZE_TYPE)) // if rest is too small, add it to allocating memory
				size += rest;
			if (curSize > size)
			{
				SIZE_TYPE freeSize = curSize - size - 2 * sizeof(SIZE_TYPE);
				byte *freeBlock = block + size + 2 * sizeof(SIZE_TYPE);
				*start(freeBlock) = -freeSize;
				*end(freeBlock) = -freeSize;
			}
			*start(block) = size;
			*end(block) = size;
			return block;
		}
		block += abs(curSize) + 2 * sizeof(SIZE_TYPE);
	}
	return NULL;
}

void Memory::free(byte *block)
{
	if (block == NULL)
		return;
	SIZE_TYPE blockSize = *start(block);
	assert(blockSize > 0);
	*start(block) = -blockSize;
	*end(block) = -blockSize;
	merge(block);
}

SIZE_TYPE *Memory::start(byte *block)
{
	return (SIZE_TYPE*)(block - sizeof(SIZE_TYPE));
}

SIZE_TYPE *Memory::end(byte *block)
{
	SIZE_TYPE blockSize = *start(block);
	return (SIZE_TYPE*)(block + abs(blockSize));
}

SIZE_TYPE Memory::size(byte *block)
{
	return *start(block);
}

void Memory::merge(byte *block)
{
	byte *left = block;
	byte *right = block + abs(size(block));
	if (block - memory > sizeof(SIZE_TYPE))
	{
		SIZE_TYPE sizeLeft = *((SIZE_TYPE*)(left - 2 * sizeof(SIZE_TYPE))); // lloks at the left block
		if (sizeLeft < 0)
			left -= abs(sizeLeft) + 2 * sizeof(SIZE_TYPE);
	}
	if (block - memory < memorySize - sizeof(SIZE_TYPE))
	{
		SIZE_TYPE sizeRight = *((SIZE_TYPE*)(right + sizeof(SIZE_TYPE))); // looks to the right block
		if (sizeRight < 0)
			right += abs(sizeRight) + 2 * sizeof(SIZE_TYPE);
	}

	SIZE_TYPE freeSize = right - left;
	*start(left) = -freeSize;
	*end(left) = -freeSize;
}
