#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <iostream>
#include <string>

template <typename T>
class LinkedList {
private:

	template <typename N>
	struct Node {
		Node *mNext;
		N mData;

		Node<N>() {
			mData = NULL;
			mNext = nullptr;
		}

		Node<N>(N data) {
			mData = data;
			mNext = nullptr;
		}
	};

	Node<T> *mHead, *mTail;
	int mCount;
public:

	LinkedList<T>();
	~LinkedList<T>();

	int getCount();
	T getData(int index);
	void setData(int index, T data);
	void display();
	void insert(T data);
	bool isExist(T searchKey);
	T remove();
	T remove(T searchKey);
};

#endif // !_LINKED_LIST_

