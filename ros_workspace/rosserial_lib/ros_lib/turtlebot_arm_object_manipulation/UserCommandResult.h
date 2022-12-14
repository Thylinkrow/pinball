#ifndef _ROS_turtlebot_arm_object_manipulation_UserCommandResult_h
#define _ROS_turtlebot_arm_object_manipulation_UserCommandResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace turtlebot_arm_object_manipulation
{

  class UserCommandResult : public ros::Msg
  {
    public:
      typedef const char* _outcome_type;
      _outcome_type outcome;

    UserCommandResult():
      outcome("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_outcome = strlen(this->outcome);
      varToArr(outbuffer + offset, length_outcome);
      offset += 4;
      memcpy(outbuffer + offset, this->outcome, length_outcome);
      offset += length_outcome;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_outcome;
      arrToVar(length_outcome, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_outcome; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_outcome-1]=0;
      this->outcome = (char *)(inbuffer + offset-1);
      offset += length_outcome;
     return offset;
    }

    const char * getType(){ return "turtlebot_arm_object_manipulation/UserCommandResult"; };
    const char * getMD5(){ return "2b95071cca675b3d5b80ad0bdaf20389"; };

  };

}
#endif
