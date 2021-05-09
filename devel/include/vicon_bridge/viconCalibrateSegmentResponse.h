// Generated by gencpp from file vicon_bridge/viconCalibrateSegmentResponse.msg
// DO NOT EDIT!


#ifndef VICON_BRIDGE_MESSAGE_VICONCALIBRATESEGMENTRESPONSE_H
#define VICON_BRIDGE_MESSAGE_VICONCALIBRATESEGMENTRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/PoseStamped.h>

namespace vicon_bridge
{
template <class ContainerAllocator>
struct viconCalibrateSegmentResponse_
{
  typedef viconCalibrateSegmentResponse_<ContainerAllocator> Type;

  viconCalibrateSegmentResponse_()
    : success(false)
    , status()
    , pose()  {
    }
  viconCalibrateSegmentResponse_(const ContainerAllocator& _alloc)
    : success(false)
    , status(_alloc)
    , pose(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _status_type;
  _status_type status;

   typedef  ::geometry_msgs::PoseStamped_<ContainerAllocator>  _pose_type;
  _pose_type pose;





  typedef boost::shared_ptr< ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> const> ConstPtr;

}; // struct viconCalibrateSegmentResponse_

typedef ::vicon_bridge::viconCalibrateSegmentResponse_<std::allocator<void> > viconCalibrateSegmentResponse;

typedef boost::shared_ptr< ::vicon_bridge::viconCalibrateSegmentResponse > viconCalibrateSegmentResponsePtr;
typedef boost::shared_ptr< ::vicon_bridge::viconCalibrateSegmentResponse const> viconCalibrateSegmentResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace vicon_bridge

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'vicon_bridge': ['/home/lzw/ding/src/vicon_bridge-master/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fd8b451f9e0c65ec25938e0acbd102d7";
  }

  static const char* value(const ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfd8b451f9e0c65ecULL;
  static const uint64_t static_value2 = 0x25938e0acbd102d7ULL;
};

template<class ContainerAllocator>
struct DataType< ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "vicon_bridge/viconCalibrateSegmentResponse";
  }

  static const char* value(const ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n\
string status\n\
geometry_msgs/PoseStamped pose\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
      stream.next(m.status);
      stream.next(m.pose);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct viconCalibrateSegmentResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::vicon_bridge::viconCalibrateSegmentResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "status: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.status);
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::PoseStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
  }
};

} // namespace message_operations
} // namespace ros

#endif // VICON_BRIDGE_MESSAGE_VICONCALIBRATESEGMENTRESPONSE_H
