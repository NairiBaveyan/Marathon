#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H



template <typename T>
class List
{
	public:
	
		List();
		~List();
		List(const List& rhs);
		//List(List<T>&& rhs);
		List(int size,T value);
		//List<T>& operator=(const List& rhs)noexcept;
		//List<T>& operator=(List<T>&& rhs)noexcept;

	public:
		void push_back(T data);
		void push_front(T data);
		void pop_back();
		void pop_front();
		void insert(T value,int index);
		void removeAt(int index);
		void erase(int index);
		void clear();
		int getSize()const{return mSize;}
		T& operator[](const int index);

	private:
		template <typename N>
		class Node
		{
		    public:
			N mData;
			Node* mpNext;

			Node(N data =N(),Node* pNext = nullptr)
				:mData{data},mpNext{pNext}
			{}
		};

        private:

                int mSize;
                Node<T>* mHead;

};




template <typename T>
List<T>::List()
	:mHead{nullptr},mSize{}			//DEFAULT CTOR
{}

/*
template <typename T>					//DESTRUCTOR
List<T>::~List()
{
        while(mHead != nullptr)
        {
                Node<T>* current = mHead;
                mHead = current -> mpNext;
                delete current;
        }
}
*/
template <typename T>
List<T>::~List()
{
	//std::cout<<"Destructor";
	clear();
}

template<typename T>
void List<T>::clear()
{
	while(mSize)
	{
		pop_front();
	}
}


/*
template <typename T>
inline List<T>::List(List<T>&& rhs)
{
        this->mHead = rhs.mHead;
        this->mSize = rhs.mSize;
        rhs.mSize = 0;
        rhs.mHead = nullptr;
}
*/




template <typename T>
void List<T>::push_front(T data)
{
	mHead = new Node<T>(data,mHead);
	++mSize;
}



template<typename T>
void List<T>::push_back(T data)				//PUSH_BACK
{
        if(mHead == nullptr)
        {
                mHead = new Node<T>(data);
        }
        else
        {
		Node<T>* current = this->mHead;
                while(current->mpNext != nullptr)
                {
                        current = current->mpNext;
                }
                current->mpNext = new Node<T>(data);
        }
	++mSize;
}


template <typename T>                           //POP_Front()
void List<T>::pop_front()
{
        Node<T>* tmp = mHead;
        mHead = mHead->mpNext;
        delete tmp;
        --mSize;
}

template <typename T>
void List<T>::pop_back()
{
	removeAt(mSize-1);
}


template <typename T>
void List<T>::insert(T data,int index)
{
	if(index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->mHead;

		for(int i{};i<index-1;++i)
		{
			previous = previous->mpNext;
		}

		Node<T>*newNode = new Node<T>(data,previous->mpNext);

		previous->mpNext = newNode;
		++mSize;
	}
}


template <typename T>
void List<T>::removeAt(int index)
{
	if(index == 0)
	{
		pop_front();
	}
	else
	{	
		Node<T>* current = this->mHead;
		
		for(int i{};i < index;++i)
		{
			current = current -> mpNext;
		}
		Node<T>*del = current->npNext;
		current->mpNext = del->mpNext;
		delete del; 
		--mSize;

	}
}

template <typename T>				//OPERATOR []
T& List<T>::operator[](const int index)
{
        int counter = 0;

        Node<T>* current = this->mHead;

        while(current != nullptr)
        {
                if(counter == index)
                {
                        return current->mData;
                }
                current = current->mpNext;
                ++counter;
        }
	return current->mData; 		//for warning
}









#endif //FORWARD_LIST_H
