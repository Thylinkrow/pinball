#ifndef _ROS_turtlebot_arm_object_manipulation_PickAndPlaceGoal_h
#define _ROS_turtlebot_arm_object_manipulation_PickAndPlaceGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace turtlebot_arm_object_manipulation
{

  class PickAndPlaceGoal : public ros::Msg
  {
    public:
      typedef const char* _frame_type;
      _frame_type frame;
      typedef const char* _obj_name_type;
      _obj_name_type obj_name;
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Pose _pick_pose_type;
      _pick_pose_type pick_pose;
      typedef geometry_msgs::Pose _place_pose_type;
      _place_pose_type place_pose;

    PickAndPlaceGoal():
      frame(""),
      obj_name(""),
      header(),
      pick_pose(),
      place_pose()
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
      uint32_t length_obj_name = strlen(this->obj_name);
      varToArr(outbuffer + offset, length_obj_name);
      offset += 4;
      memcpy(outbuffer + offset, this->obj_name, length_obj_name);
      offset += length_obj_name;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pick_pose.serialize(outbuffer + offset);
      offset += this->place_pose.serialize(outbuffer + offset);
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
      uint32_t length_obj_name;
      arrToVar(length_obj_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_obj_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_obj_name-1]=0;
      this->obj_name = (char *)(inbuffer + offset-1);
      offset += length_obj_name;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pick_pose.deserialize(inbuffer + offset);
      offset += this->place_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "turtlebot_arm_object_manipulation/PickAndPlaceGoal"; };
    const char * getMD5(){ return "1bcb111268b41ca6dd486e805ddf52aa"; };

  };

}
#endif
