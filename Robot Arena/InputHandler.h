#pragma once
#include "Robot.h"
class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	bool hanldeInput(Robot &robot);
private:
	Keyboard keyboard;

};

