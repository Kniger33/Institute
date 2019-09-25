#include <iostream>

#define nullptr 0

/*Описание выделенных фрагментов памяти (узлы двусвязного списка)*/
struct Record {
	struct Record *next, *prev; //указатели на следующее и предыдущее описание
	bool          used;         //признак занятости блока
} * B, *E;          //начало и конец распределяемой области
std::size_t total;


// Эта функция будет вызвана перед тем как вызывать myalloc и myfree
// используйте ее чтобы инициализировать ваш аллокатор перед началом
// работы.
//
// buf - указатель на участок логической памяти, который ваш аллокатор
//       должен распределять, все возвращаемые указатели должны быть
//       либо равны NULL, либо быть из этого участка памяти
// size - размер участка памяти, на который указывает buf
void mysetup(void *buf, std::size_t size) {
	B = (struct Record *)buf;
	E = (struct Record *)((char*)buf + size);
	B->used = false;
	B->prev = nullptr;
	B->next = E;
	
	total = size;	
}

void chek(void * p, std::size_t size) {
	if (p == nullptr);
	else if ((struct Record*)p < B)
		std::cerr << "<--" << std::endl;
	else if ((struct Record*)p >= E)
		std::cerr << "-->" << std::endl;
	else if ((char*)p + size >(char*)E)
		std::cerr << total << "/" << size << "[" << B << " , " << E << ") " << p << " " << ((char*)p + size) << "|-->" << std::endl;
	else
		std::cerr << total << "/" << size << "[" << B << " , " << E << ") " << p  << " ok "<< std::endl;
	std::cerr << std::flush;
}

// Функция аллокации
void *myalloc(std::size_t size) {
	//найдем свободную область нужного размера
	struct Record * c = B;
	while (c != E && (c->used || ((char*)c->next - (char*)c - sizeof(struct Record) < size)))
		c = c->next;

	if (c != E) {
		if ((char*)c->next - (char*)c - sizeof(struct Record) >= size
			&& (char*)c->next - (char*)c - 2 * sizeof(struct Record) <= size) {
			//найдена область и её нельзя поделить на два фрагмента
			c->used = true;
			return (char*)c + sizeof(struct Record); //возвращаем адрес начала области
		}
		else {
			//разделим область на два фрагмента
			struct Record * n = (struct Record *)((char*)c->next - sizeof(struct Record) - size);
			n->used = true;
			n->next = c->next;
			n->prev = c;
			c->next = n;
			if (n->next != E)
				n->next->prev = n;

			return (char*)n + sizeof(struct Record); //возвращаем адрес начала области
		}
	}

	return nullptr;
}

// Функция освобождения
void myfree(void *p) {
	std::cerr << "del " << p;//<< std::endl;
	if (p == nullptr)
		return;

	//найдем описание нашего фрагмента
	struct Record * c = B;
	while (c != E && (char*)c + sizeof(struct Record) != (char*)p)
		c = c->next;

	//помечаем фрагмент как освободный 
	c->used = false;

	//объединим со следующим
	if (c->next != E && !c->next->used) {
		c->next = c->next->next;
		if (c->next != E)
			c->next->prev = c;		
	}

	//объединим с предыдущим
	if (c->prev != nullptr && !c->prev->used) {
		c->prev->next=c->next;
		if (c->next != E)
			c->next->prev = c->prev;
	}
}
