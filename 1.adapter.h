#pragma once
#include "example.h"
#include <iostream>

namespace _AdapterPattern
{
	class InputDevice
	{
	public:
		virtual void pressButton() = 0; // 按钮按下
		virtual void releaseButton() = 0; // 按钮释放
		virtual ~InputDevice() {}
	};

	class Keyboard : public InputDevice
	{
	public:
		void pressButton() override
		{
			std::cout << "Keyboard button pressed." << std::endl;
		}
		void releaseButton() override
		{
			std::cout << "Keyboard button released." << std::endl;
		}
	};

	class Mouse : public InputDevice
	{
	public:
		void pressButton() override
		{
			std::cout << "Mouse button pressed." << std::endl;
		}
		void releaseButton() override
		{
			std::cout << "Mouse button released." << std::endl;
		}
	};

	class GameController : public InputDevice
	{
	public:
		void pressButton() override
		{
			std::cout << "Game controller button pressed." << std::endl;
		}
		void releaseButton() override
		{
			std::cout << "Game controller button released." << std::endl;
		}
	};

	class InputAdapter
	{
	public:
		InputAdapter(InputDevice* device) : device(device) {}

		void press() {
			if (device) {
				device->pressButton();
			}
		}

		void release() {
			if (device) {
				device->releaseButton();
			}
		}
	private:
		InputDevice* device;
	};
}

class AdapterPattern : public Example
{
public:
	AdapterPattern() {}
	~AdapterPattern() = default;
	void on_created() override;
};