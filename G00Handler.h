/*
 * G00Handler.h
 *
 *  Created on: 15 maj 2014
 *      Author: MattLech
 */

#ifndef G00HANDLER_H_
#define G00HANDLER_H_
#include "GCodeHandler.h"

class G00Handler : public GCodeHandler {
public:
	static G00Handler* getInstance();
private:
	G00Handler();
	G00Handler(G00Handler const&);
	void operator=(G00Handler const&);

};

#endif /* G00HANDLER_H_ */
