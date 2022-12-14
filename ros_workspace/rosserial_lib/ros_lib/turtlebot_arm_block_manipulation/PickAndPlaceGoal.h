#ifndef _ROS_turtlebot_arm_block_manipulation_PickAndPlaceGoal_h
#define _ROS_turtlebot_arm_block_manipulation_PickAndPlaceGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace turtlebot_arm_block_manipulation
{

  class PickAndPlaceGoal : public ros::Msg
  {
    public:
      typedef const char* _frame_type;
      _frame_type frame;
      typedef float _z_up_type;
      _z_up_type z_up;
      typedef float _gripper_open_type;
      _gripper_open_type gripper_open;
      typedef float _gripper_closed_type;
      _gripper_closed_type gripper_closed;
      typedef geometry_msgs::Pose _pickup_pose_type;
      _pickup_pose_type pickup_pose;
      typedef geometry_msgs::Pose _place_pose_type;
      _place_pose_type place_pose;
      typedef const char* _topic_type;
      _topic_type topic;

    PickAndPlaceGoal():
      frame(""),
      z_up(0),
      gripper_open(0),
      gripper_closed(0),
      pickup_pose(),
      place_pose(),
      topic("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_frame = strlen(this->frame);
      varToArr(outbuffer + offset, length_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->frame, length_frame);
      offset += length_frame;
      union {
        float real;
        uint32_t base;
      } u_z_up;
      u_z_up.real = this->z_up;
      *(outbuffer + offset + 0) = (u_z_up.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z_up.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z_up.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z_up.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z_up);
      union {
        float real;
        uint32_t base;
      } u_gripper_open;
      u_gripper_open.real = this->gripper_open;
      *(outbuffer + offset + 0) = (u_gripper_open.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gripper_open.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gripper_open.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gripper_open.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gripper_open);
      union {
        float real;
        uint32_t base;
      } u_gripper_closed;
      u_gripper_closed.real = this->gripper_closed;
      *(outbuffer + offset + 0) = (u_gripper_closed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gripper_closed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gripper_closed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gripper_closed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gripper_closed);
      offset += this->pickup_pose.serialize(outbuffer + offset);
      offset += this->place_pose.serialize(outbuffer + offset);
      uint32_t length_topic = strlen(this->topic);
      varToArr(outbuffer + offset, length_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->topic, length_topic);
      offset += length_topic;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_frame;
      arrToVar(length_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame-1]=0;
      this->frame = (char *)(inbuffer + offset-1);
      offset += length_frame;
      union {
        float real;
        uint32_t base;
      } u_z_up;
      u_z_up.base = 0;
      u_z_up.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z_up.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z_up.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z_up.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z_up = u_z_up.real;
      offset += sizeof(this->z_up);
      union {
        float real;
        uint32_t base;
      } u_gripper_open;
      u_gripper_open.base = 0;
      u_gripper_open.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gripper_open.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gripper_open.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gripper_open.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gripper_open = u_gripper_open.real;
      offset += sizeof(this->gripper_open);
      union {
        float real;
        uint32_t base;
      } u_gripper_closed;
      u_gripper_closed.base = 0;
      u_gripper_closed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gripper_closed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gripper_closed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gripper_closed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gripper_closed = u_gripper_closed.real;
      offset += sizeof(this->gripper_closed);
      offset += this->pickup_pose.deserialize(inbuffer + offset);
      offset += this->place_pose.deserialize(inbuffer + offset);
      uint32_t length_topic;
      arrToVar(length_topic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic-1]=0;
      this->topic = (char *)(inbuffer + offset-1);
      offset += length_topic;
     return offset;
    }

    const char * getType(){ return "turtlebot_arm_block_manipulation/PickAndPlaceGoal"; };
    const char * getMD5(){ return "406b9d2b14d3c2ad49cf6e087a7292df"; };

  };

}
#endif
