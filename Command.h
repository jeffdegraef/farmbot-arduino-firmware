#ifndef COMMAND_H_
#define COMMAND_H_

#include "Arduino.h"
//#include "string.h"

enum CommandCodeEnum
{
  CODE_UNDEFINED = -1,
  G0 = 0,
  G1,
  G2,
  G3,
  G4
};

#define NULL 0

class Command {
	CommandCodeEnum codeEnum;
public:
	Command(String);
	void print();
	CommandCodeEnum getCodeEnum();
	double getX();
	double getY();
	double getZ();
	double getFeedRate();
	double getE();
private:
	CommandCodeEnum getGCodeEnum(char* code);
	void getParameter(char* charPointer);
};

#endif /* COMMAND_H_ */
