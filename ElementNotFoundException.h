/* 
 * File:   ElementNotFoundException.h
 * Author: amdiaz
 *
 * Created on 7 de febrero de 2015, 16:43
 */

#ifndef ELEMENTNOTFOUNDEXCEPTION_H
#define	ELEMENTNOTFOUNDEXCEPTION_H

#include <iostream>
#include <exception>

using namespace std;

class ElementNotFoundException {
private:
    const char* errorMessage;
public:
    ElementNotFoundException() : errorMessage("ElementNotFoundException: not found such element."){};
    ElementNotFoundException(const char* errorMessage) : errorMessage(errorMessage){}
    const char* what() const throw() { return errorMessage; }
};

#endif	/* ELEMENTNOTFOUNDEXCEPTION_H */

