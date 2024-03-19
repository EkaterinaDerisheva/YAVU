//
// Created by deris on 10.03.2024.
//

#ifndef UNTITLED_OVERWEIGHTEXCEPTION_H
#define UNTITLED_OVERWEIGHTEXCEPTION_H


#include <exception>

class OverweightException: public std::exception{
    const char* message;
public:
    OverweightException(const char* theMessage): message(theMessage) {}
    const char* overweight() const noexcept {
        return message;
    }
};


#endif //UNTITLED_OVERWEIGHTEXCEPTION_H
