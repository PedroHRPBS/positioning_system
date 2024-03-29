#include "ROSUnit_Positioning.hpp"
#include <iostream>
ROSUnit_Positioning* ROSUnit_Positioning::instance_ptr = NULL;

ROSUnit_Positioning::ROSUnit_Positioning(ros::NodeHandle&) {

    sub_positioning = main_handler.subscribe("/Robot_1/pose", 10, callbackPositioning);
    instance_ptr = this;
}


ROSUnit_Positioning::~ROSUnit_Positioning(){

}

void ROSUnit_Positioning::callbackPositioning(const geometry_msgs::PoseStamped& msg){

    double data[3];
    data[0] = msg.pose.position.x;
    data[1] = msg.pose.position.y;
    data[2] = msg.pose.position.z;
    //std::cout << sizeof(data) << std::endl;
    uint8_t serializedData[sizeof(data)];
    const int numVariables = sizeof(data) / sizeof(data[0]);

    //instance_ptr is a workaround for accessing non-static function inside static
    instance_ptr->serializeData(data, numVariables, serializedData);
    instance_ptr->emit_message(serializedData, sizeof(data), msg_type::position);    
}

void ROSUnit_Positioning::receive_msg_data(uint8_t data[], std::size_t len, msg_type _msg_type){


}
