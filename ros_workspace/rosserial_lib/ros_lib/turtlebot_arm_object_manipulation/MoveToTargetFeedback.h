#ifndef _ROS_turtlebot_arm_object_manipulation_MoveToTargetFeedback_h
#define _ROS_turtlebot_arm_object_manipulation_MoveToTargetFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace turtlebot_arm_object_manipulation
{

  class MoveToTargetFeedback : public ros::Msg
  {
    public:

    MoveToTargetFeedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "turtlebot_arm_object_manipulation/MoveToTargetFeedback"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
