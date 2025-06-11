#pragma once

class Example
{
public:
	Example() {}
	virtual ~Example() = default;

	virtual void on_created() {}
	virtual void on_exit() {}
	virtual void on_input() {}
	virtual void on_update(float delta) {}
	virtual void on_render() {}
};
