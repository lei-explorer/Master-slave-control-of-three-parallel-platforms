// Auto-generated. Do not edit!

// (in-package servo_drive.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Angle {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.angle_1 = null;
      this.angle_2 = null;
      this.angle_3 = null;
    }
    else {
      if (initObj.hasOwnProperty('angle_1')) {
        this.angle_1 = initObj.angle_1
      }
      else {
        this.angle_1 = 0.0;
      }
      if (initObj.hasOwnProperty('angle_2')) {
        this.angle_2 = initObj.angle_2
      }
      else {
        this.angle_2 = 0.0;
      }
      if (initObj.hasOwnProperty('angle_3')) {
        this.angle_3 = initObj.angle_3
      }
      else {
        this.angle_3 = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Angle
    // Serialize message field [angle_1]
    bufferOffset = _serializer.float32(obj.angle_1, buffer, bufferOffset);
    // Serialize message field [angle_2]
    bufferOffset = _serializer.float32(obj.angle_2, buffer, bufferOffset);
    // Serialize message field [angle_3]
    bufferOffset = _serializer.float32(obj.angle_3, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Angle
    let len;
    let data = new Angle(null);
    // Deserialize message field [angle_1]
    data.angle_1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [angle_2]
    data.angle_2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [angle_3]
    data.angle_3 = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'servo_drive/Angle';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '7023de6969abdb6bc7e604ee027fa612';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 angle_1
    float32 angle_2
    float32 angle_3
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Angle(null);
    if (msg.angle_1 !== undefined) {
      resolved.angle_1 = msg.angle_1;
    }
    else {
      resolved.angle_1 = 0.0
    }

    if (msg.angle_2 !== undefined) {
      resolved.angle_2 = msg.angle_2;
    }
    else {
      resolved.angle_2 = 0.0
    }

    if (msg.angle_3 !== undefined) {
      resolved.angle_3 = msg.angle_3;
    }
    else {
      resolved.angle_3 = 0.0
    }

    return resolved;
    }
};

module.exports = Angle;
