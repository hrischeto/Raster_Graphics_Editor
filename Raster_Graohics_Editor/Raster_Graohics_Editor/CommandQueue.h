#pragma once
#include "Command.h"
class CommandQueue
{
	public:
		CommandQueue();

		CommandQueue(const CommandQueue& other);
		CommandQueue& operator=(const CommandQueue& other);

		CommandQueue(CommandQueue&& other);
		CommandQueue& operator=(CommandQueue&& other);

		void push(const CommandQueue& obj);
		void push(CommandQueue&& obj);
		void pop();

		const CommandQueue& peek() const;
		bool isEmpty() const;

		~CommandQueue();

private:

	void moveFrom(CommandQueue&& other);
	void copyFrom(const CommandQueue& other);
	void free();
	void resize();

	Command** data;
	size_t capacity;
	size_t size;

	size_t get;
	size_t put;

};

