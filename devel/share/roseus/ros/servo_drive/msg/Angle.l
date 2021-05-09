;; Auto-generated. Do not edit!


(when (boundp 'servo_drive::Angle)
  (if (not (find-package "SERVO_DRIVE"))
    (make-package "SERVO_DRIVE"))
  (shadow 'Angle (find-package "SERVO_DRIVE")))
(unless (find-package "SERVO_DRIVE::ANGLE")
  (make-package "SERVO_DRIVE::ANGLE"))

(in-package "ROS")
;;//! \htmlinclude Angle.msg.html


(defclass servo_drive::Angle
  :super ros::object
  :slots (_angle_1 _angle_2 _angle_3 ))

(defmethod servo_drive::Angle
  (:init
   (&key
    ((:angle_1 __angle_1) 0.0)
    ((:angle_2 __angle_2) 0.0)
    ((:angle_3 __angle_3) 0.0)
    )
   (send-super :init)
   (setq _angle_1 (float __angle_1))
   (setq _angle_2 (float __angle_2))
   (setq _angle_3 (float __angle_3))
   self)
  (:angle_1
   (&optional __angle_1)
   (if __angle_1 (setq _angle_1 __angle_1)) _angle_1)
  (:angle_2
   (&optional __angle_2)
   (if __angle_2 (setq _angle_2 __angle_2)) _angle_2)
  (:angle_3
   (&optional __angle_3)
   (if __angle_3 (setq _angle_3 __angle_3)) _angle_3)
  (:serialization-length
   ()
   (+
    ;; float32 _angle_1
    4
    ;; float32 _angle_2
    4
    ;; float32 _angle_3
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _angle_1
       (sys::poke _angle_1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _angle_2
       (sys::poke _angle_2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _angle_3
       (sys::poke _angle_3 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _angle_1
     (setq _angle_1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _angle_2
     (setq _angle_2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _angle_3
     (setq _angle_3 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get servo_drive::Angle :md5sum-) "7023de6969abdb6bc7e604ee027fa612")
(setf (get servo_drive::Angle :datatype-) "servo_drive/Angle")
(setf (get servo_drive::Angle :definition-)
      "float32 angle_1
float32 angle_2
float32 angle_3

")



(provide :servo_drive/Angle "7023de6969abdb6bc7e604ee027fa612")


