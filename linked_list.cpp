#include "linked_list.h"

template <typename T>
LinkedList::LinkedList()
{
	mHead = nullptr;
	mTail = nullptr;
	mCount = 0;
}

template <typename T>
LinkedList::~LinkedList() 
{

}

template <typename T>
int LinkedList::getCount() 
{
	return mCount;
}

template <typename T>
T LinkedList::getData(int index) 
{
	Node* tmp = mHead;
	
	for (int i = 0; i < index; i++) {
		tmp = tmp->mNext;
	}

	return tmp->mData;
}

template <typename T>
void LinkedList::setData(int index, T data) 
{
	Node* tmp = mHead;

	for (int i = 0; i < index; i++) {
		tmp = tmp->mNext;
	}

	temp->mData = data;
}

template <typename T>
void LinkedList::display() 
{

}

template <typename T>
void LinkedList::insert(T data) 
{
	//Partially Sourced from Wei's linkedList.cpp
	Node *tmp, *oneBefore, *newNode;

	newNode = new Node(data);

	if (mHead == nullptr) {
		mHead = newNode;
		mTail = newNode;
	}
	else {
		if (data >= mHead->mData) {
			newNode->mNext = mHead;
			mHead = newNode;
		}
		else if (data <= mTail->mData) {
			mTail->mNext = newNode;
			mTail = newNode;
		}
		else {
			tmp = mHead;
			oneBefore = mHead;

			while (tmp != nullptr && tmp->mData > data) {
				oneBefore = tmp;
				tmp = tmp->mNext;
			}

			newNode->mNext = tmp;
			oneBefore->mNext = newNode;
		}
	}

	mCount++;
}

template <typename T>
bool LinkedList::isExist(T searchKey) 
{
	Node *tmp = mHead;
	bool exist = false;

	if (mHead->mData == searchKey || mTail->mData == searchKey) {
		exist = true;
	}
	else {
		while (tmp != nullptr && !exist) {
			if (tmp->mData == searchKey) {
				exist = true;
			}
			else {
				tmp = tmp->mNext;
			}
		}
	}

	return exist;
}

template <typename T>
T LinkedList::remove() 
{
	Node *tmp, *toBeDeleted;
	T data;

	if (mHead != nullptr) 
	{
		if (mHead == mTail) 
		{
			toBeDeleted = mTail;
			data = toBeDeleted->mData;
			mHead = nullptr;
			mTail = nullptr;
		}
		else
		{
			toBeDeleted = mTail;
			tmp = mHead;
			while (tmp->mNext != mTail)
			{
				tmp = tmp->mNext;
			}
			tmp->mNext = nullptr;
			mTail = tmp;

			data = toBeDeleted->mData;
		}

		delete toBeDeleted;
		mCount--;
	}

	return data;
}

template <typename T>
T LinkedList::remove(T searchKey){
	Node *tmp, *oneBefore, *toBeDeleted; 

	if (mHead->mData == searchKey) {
		tmp = mHead;
		
	}
}
