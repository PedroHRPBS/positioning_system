//msg_receiver.hpp
#ifndef msg_receiver_H
#define msg_receiver_H
#include <iostream>
#include "common_types.hpp"
class msg_receiver {
    private:
    msg_type _msg_type;
    public:
    msg_receiver();
    void assign_message_type_ID(msg_type i);
    msg_type get_message_type_ID();
    virtual void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type)=0;
};
#endif