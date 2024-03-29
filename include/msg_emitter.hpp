//msg_emitter.hpp
#ifndef msg_emitter_H
#define msg_emitter_H
#include <list> 
#include <iterator> 
#include <iostream>
#include "msg_receiver.hpp"
using namespace std;
class msg_receiver;
class msg_emitter {
protected:
    list<msg_receiver*> _list_of_msg_receivers;
public:
    msg_emitter();
    void add_callback_msg_receiver(msg_receiver* _callback_msg_receiver);
    void emit_message(uint8_t _msg[],size_t len, msg_type _msg_type);
};
#endif