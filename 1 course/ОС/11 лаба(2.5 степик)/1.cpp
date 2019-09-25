	struct Node {
		Node *next;
		Node *prev;
	};

	void setup_list(Node *node)
	{
		node->next = node->prev = node;
	}

	void remove_node(Node *node)
	{
		Node *prev = node->prev;
		Node *next = node->next;

		prev->next = next;
		next->prev = prev;
	}

	void append_node(Node *node, Node *prev)
	{
		Node *next = prev->next;

		node->prev = prev;
		node->next = next;
		next->prev = node;
		prev->next = node;
	}

	struct BufHead {
		Node node;
		std::size_t size;
		bool free;
	};

	struct BufTail {
		std::size_t size;
		bool free;
	};

	BufHead *head_tag(BufTail *tail)
	{
		char *ptr = (char *)(tail + 1) - tail->size;

		return (BufHead *)ptr;
	}

	BufTail *tail_tag(BufHead *head)
	{
		char *ptr = (char *)head;

		return (BufTail *)(ptr + head->size - sizeof(BufTail));
	}


	Node head;

	void mysetup(void *buf, std::size_t size)
	{
		char *ptr = (char *)(buf);

		BufTail *first = (BufTail *)(ptr);
		BufHead *last = (BufHead *)(ptr + size - sizeof(BufHead));

		BufHead *free_start = (BufHead *)(first + 1);
		BufTail *free_end = (BufTail *)(last - 1);

		setup_list(&head);

		memset(first, 0, sizeof(*first));
		memset(last, 0, sizeof(*last));

		size -= sizeof(BufHead) + sizeof(BufTail);

		free_start->size = free_end->size = size;
		free_start->free = free_end->free = true;
		append_node(&free_start->node, &head);
	}

	void *myalloc(std::size_t size)
	{
		const std::size_t meta_size = sizeof(BufHead) + sizeof(BufTail);
		const std::size_t min_rem = 8 + meta_size;
		Node *end = &head;

		size += meta_size;
		for (Node *node = head.next; node != end; node = node->next) {
			char *ptr = (char *)node;
			BufHead *begin = (BufHead *)ptr;
			BufTail *end = tail_tag(begin);

			if (begin->size < size)
				continue;

			if (begin->size < size + min_rem) {
				remove_node(&begin->node);
				begin->free = end->free = false;
				return (void *)(begin + 1);
			}

			begin->size -= size;
			end = tail_tag(begin);
			end->size = begin->size;
			end->free = true;

			ptr = (char *)(end + 1);
			begin = (BufHead *)ptr;
			begin->size = size;
			begin->free = false;

			end = tail_tag(begin);
			end->size = size;
			end->free = false;
			return (void *)(begin + 1);
		}
		return NULL;
	}

	void myfree(void *p)
	{
		char *ptr = (char *)p;
		BufHead *begin = (BufHead *)(ptr - sizeof(BufHead));
		BufTail *end = tail_tag(begin);

		BufTail *prev = (BufTail *)begin - 1;
		BufHead *next = (BufHead *)(end + 1);

		if (next->free) {
			remove_node(&next->node);
			begin->size += next->size;
			end = tail_tag(begin);
			end->size = begin->size;
		}

		if (prev->free) {
			BufHead *head = head_tag(prev);

			remove_node(&head->node);
			end->size += head->size;
			begin = head_tag(end);
			begin->size = end->size;
		}

		begin->free = end->free = true;
		append_node(&begin->node, &head);
	}