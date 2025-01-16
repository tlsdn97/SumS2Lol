#pragma once

// ���ø� Ŭ������ ���Ϻ����� �� �� ����.
template<typename T>
class Vector
{
public:
	class Iterator
	{
	public:
		Iterator() : _ptr(nullptr) {}
		Iterator(T* data) : _ptr(data) {}
		~Iterator() { _ptr = nullptr; }

		T& operator*() const // ����Լ� ������ ��������� �ٲ�������
		{
			return *_ptr;
		}

		bool operator==(const Iterator& other) const
		{
			return _ptr == other._ptr;
		}

		bool operator!=(const Iterator& other) const
		{
			return _ptr != other._ptr;
		}

		Iterator& operator++()
		{
			++_ptr;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator result = Iterator(*this);

			++_ptr;

			return result;
		}

	private:
		T* _ptr;
	};

	Vector() : _size(0), _capacity(0), _data(nullptr) {}
	~Vector()
	{
		_size = 0;
		_capacity = 0;
		delete _data;
	}

	void reserve(unsigned __int64 capacity)
	{
		// ������ ���뷮�� ũ�ų� ���Ҵ�.
		if (_capacity >= capacity)
			return;
		
		_capacity = capacity;

		T* newData = new T[capacity];

		// ������ ����
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		if (_data != nullptr)
			delete _data;

		_data = newData;
	}

	void push_back(const T& data)
	{
		// �����ִ� ���
		if (_size == _capacity)
		{
			if (_capacity <= 1)
			{
				reserve(_capacity + 1);
			}
			else
				reserve(_capacity * 1.5f);
		}

		_data[_size] = data;

		_size++;
	}

	void pop_back()
	{
		--_size;
	}

	T operator[](unsigned __int64 index)
	{
		if (index >= _size)
		{
			// ERROR
			int* temp = (int*)0xDEADBEEF;
			(*temp) = 1;
		}

		return _data[index];
	}

	void clear()
	{
		_size = 0;
	}

	void insert(T value, unsigned __int64 index)
	{
		// �����ִ� ���
		if (_size == _capacity)
		{
			if (_capacity <= 1)
			{
				reserve(++_capacity);
			}
			else
				reserve(_capacity * 1.5f);
		}

		for (int i = index + 1; i < _size; i++)
		{
			_data[i + 1] = _data[i];
		}

		_data[index + 1] = value;
		_size++;
	}

	Iterator begin() { return Iterator(_data); }
	Iterator end() { return Iterator(&_data[_size]); }

	unsigned __int64 size() { return _size; }
	unsigned __int64 capacity() { return _capacity; } 

private:
	unsigned __int64 _size;
	unsigned __int64 _capacity;
	T* _data;
};