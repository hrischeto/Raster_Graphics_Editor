#pragma once
#include "Command.h"
class CommandQueue //not a queue
{
	public:
		CommandQueue();

		CommandQueue(const CommandQueue& other);
		CommandQueue& operator=(const CommandQueue& other) ;

		CommandQueue(CommandQueue&& other)noexcept;
		CommandQueue& operator=(CommandQueue&& other) noexcept;

		void push(Command* obj);
		void pop(int index);

		Command* getCommand(int index);

		bool isEmpty() const;

		~CommandQueue() noexcept;

		int getSize() const;
private:

	void moveFrom(CommandQueue&& other);
	void copyFrom(const CommandQueue& other);
	void free();
	void resize();

	Command** data = nullptr;
	size_t capacity=0;
	size_t size=0;

	size_t get;
	size_t put;

};

