#ifndef VALUE_HPP
#define VALUE_HPP

#include<stdexcept>

class value_error : public std::exception {
    public:
        value_error(const char* msg) : message(msg) {};
        const char* what() const noexcept {return message.c_str();}
    private:
        std::string message;
};

#endif
