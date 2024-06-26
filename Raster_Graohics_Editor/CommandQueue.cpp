#pragma once
#include "CommandQueue.h"
#include <iostream>
#include <exception>

CommandQueue::CommandQueue()
{
	capacity = 4;
	data = new Command*[capacity];
	size = 0;
	get = put = 0;
}


void CommandQueue::push(Command* obj)
{
	if (size == capacity)
		resize();

	data[put] = std::move(obj); 
	(++put) %= capacity;
	size++;
}


bool CommandQueue::isEmpty() const
{
	return size == 0;
}



Command* CommandQueue:: getCommand(int index)
{
	if (isEmpty())
		throw std::logic_error("Empty queue!");

	return data[get];
}

void CommandQueue::pop(int index)
{
	if (isEmpty())
		throw std::logic_error("Empty queue!");

	if (index > capacity)
		throw std::invalid_argument("No such index.");

		delete[] data[index];

		for (int i = index;i < size;i++)
			data[i] = data[i + 1];
	size--;
}


void CommandQueue::resize()
{
	Command** resizedData = new Command * [capacity * 2];
	for (size_t i = 0; i < size; i++)
	{
		resizedData[i] = data[get];
		(++get) %= capacity;
	}
	capacity *= 2;
	delete[] data;
	data = resizedData;
	get = 0;
	put = size;
}



void CommandQueue::copyFrom(const CommandQueue& other)
{
	data = new Command * [other.capacity];
	for (int i = 0; i < other.capacity; i++)
		data[i] = other.data[i];

	get = other.get;
	put = other.put;

	size = other.size;
	capacity = other.capacity;

}

void CommandQueue::moveFrom(CommandQueue&& other)
{
	get = other.get;
	put = other.put;

	size = other.size;
	capacity = other.capacity;

	data = other.data;
	other.data = nullptr;

	other.size = other.capacity = 0;
}

void CommandQueue::free()
{
	for (int i = 0;i < size;i++)
	{
		delete[] data[i];
	}

	delete[] data;
}

CommandQueue::CommandQueue(const CommandQueue& other)
{
	copyFrom(other);

}

CommandQueue& CommandQueue::operator=(const CommandQueue& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

CommandQueue::CommandQueue(CommandQueue&& other) noexcept
{
	moveFrom(std::move(other));
}

CommandQueue& CommandQueue::operator=(CommandQueue&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

CommandQueue::~CommandQueue() noexcept
{
	free();
}