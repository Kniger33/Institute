#include <stdlib.h>

typedef unsigned char byte;

struct block_type
{
	size_t size_tags;
	block_type * next;
	block_type * prev;
};

static void * BUFFER_BEG = NULL;
static void * BUFFER_END = NULL;
static block_type * BLOCK_HEAD = NULL;

static const byte TAG_FREE = 0;
static const byte TAG_ALLOC = 1;

static const size_t WORD_SIZE = sizeof(size_t);
static const size_t MIN_BLOCK_SIZE = sizeof(block_type) + WORD_SIZE;

inline block_type * POINTER_ADD(void * ptr, size_t off)
{
	return (block_type *)((byte *)ptr + off);
}

inline block_type * POINTER_SUB(void * ptr, size_t off)
{
	return (block_type *)((byte *)ptr - off);
}

inline size_t SIZE(size_t value)
{
	return value >> 1;
}

inline byte TAG(size_t value)
{
	return value & 1;
}

inline size_t MAKE(size_t size, byte tag)
{
	return (size << 1) | tag;
}

static block_type * search_block(size_t size)
{
	block_type * block = BLOCK_HEAD;
	while (block)
	{
		if (SIZE(block->size_tags) >= size)
			return block;
		else
			block = block->next;
	}

	return NULL;
}

static void insert_block(block_type * block)
{
	block_type * head = BLOCK_HEAD;

	block->next = head;
	block->prev = NULL;

	if (head)
		head->prev = block;

	BLOCK_HEAD = block;
}

static void remove_block(block_type * block)
{
	block_type * next_block = block->next;
	block_type * prev_block = block->prev;

	if (next_block)
		next_block->prev = prev_block;

	if (block == BLOCK_HEAD)
		BLOCK_HEAD = next_block;
	else
		prev_block->next = next_block;
}

static void coalesce_block(block_type * block)
{
	size_t block_size = SIZE(block->size_tags);

	block_type * prev = NULL;
	byte prev_tag = TAG_ALLOC;
	if (block != BUFFER_BEG)
	{
		prev = POINTER_SUB(block, WORD_SIZE);
		prev_tag = TAG(prev->size_tags);
	}

	block_type * next = POINTER_ADD(block, block_size);
	byte next_tag = TAG_ALLOC;
	if (next != BUFFER_END)
		next_tag = TAG(next->size_tags);

	// case alloc alloc
	if (prev_tag == TAG_ALLOC && next_tag == TAG_ALLOC)
	{
		block_type * begin = block;
		block_type * end = POINTER_ADD(block, block_size - WORD_SIZE);

		begin->size_tags = MAKE(block_size, TAG_FREE);
		end->size_tags = MAKE(block_size, TAG_FREE);

		insert_block(block);
	}
	// case alloc free
	else if (prev_tag == TAG_ALLOC && next_tag == TAG_FREE)
	{
		size_t next_size = SIZE(next->size_tags);
		size_t new_size = block_size + next_size;
		
		block_type * begin = block;
		block_type * end = POINTER_ADD(next, next_size - WORD_SIZE);

		begin->size_tags = MAKE(new_size, TAG_FREE);
		end->size_tags = MAKE(new_size, TAG_FREE);

		insert_block(block);
		remove_block(next);
	}
	// case free alloc
	else if (prev_tag == TAG_FREE && next_tag == TAG_ALLOC)
	{
		size_t prev_size = SIZE(prev->size_tags);
		size_t new_size = block_size + prev_size;

		block_type * begin = POINTER_SUB(block, prev_size);
		block_type * end = POINTER_ADD(block, block_size - WORD_SIZE);

		begin->size_tags = MAKE(new_size, TAG_FREE);
		end->size_tags = MAKE(new_size, TAG_FREE);
	}
	// case free free
	else
	{
		size_t prev_size = SIZE(prev->size_tags);
		size_t next_size = SIZE(next->size_tags);
		size_t new_size = block_size + prev_size + next_size;

		block_type * begin = POINTER_SUB(block, prev_size);
		block_type * end = POINTER_ADD(next, next_size - WORD_SIZE);

		begin->size_tags = MAKE(new_size, TAG_FREE);
		end->size_tags = MAKE(new_size, TAG_FREE);

		remove_block(next);
	}
}

// Initialize allocator.
void mysetup(void * buf, size_t size)
{
	BUFFER_BEG = buf;
	BUFFER_END = POINTER_ADD(buf, size);

	block_type * first_block = (block_type *)buf;
	first_block->size_tags = MAKE(size, TAG_FREE);
	first_block->next = NULL;
	first_block->prev = NULL;

	block_type * end_block = POINTER_ADD(first_block, size - WORD_SIZE);
	end_block->size_tags = MAKE(size, TAG_FREE);

	BLOCK_HEAD = first_block;
}

// Allocate a block.
void * myalloc(size_t size)
{
	if (size == 0)
		return NULL;

	size_t req_size = size + 2 * WORD_SIZE;
	block_type * free_block = search_block(req_size);
	if (!free_block)
		return NULL;

	size_t block_size = SIZE(free_block->size_tags);
	if (block_size > req_size + MIN_BLOCK_SIZE)
	{
		block_type * split_block = POINTER_ADD(free_block, req_size);
		split_block->size_tags = MAKE(block_size - req_size, TAG_FREE);

		block_type * end_block = POINTER_ADD(free_block, block_size - WORD_SIZE);
		end_block->size_tags = MAKE(block_size - req_size, TAG_FREE);

		insert_block(split_block);
	}
	else
		req_size = block_size;

	block_type * end_block = POINTER_ADD(free_block, req_size - WORD_SIZE);
	free_block->size_tags = MAKE(req_size, TAG_ALLOC);
	end_block->size_tags = MAKE(req_size, TAG_ALLOC);

	remove_block(free_block);
	return POINTER_ADD(free_block, WORD_SIZE);
}

// Free the block.
void myfree(void * ptr)
{	
	block_type * block = POINTER_SUB(ptr, WORD_SIZE);
	coalesce_block(block);
}