#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

class ROS2Node(Node):
    
    def __init__(self):
        super().__init__("py_test")
        self.counter = 0
        self.get_logger().info("Hello ROS2")
        self.create_timer(0.5, self.timer_callback)

    def timer_callback(self):
        self.counter += 1
        self.get_logger().info("Hello ROS2 !! " + str(self.counter))

def main(args=None):
    rclpy.init(args=args)
    node = ROS2Node()
    rclpy.spin(node)
    rclpy.shutdown

if __name__ == "__main__":
    main()


# --- Minimal example ---
#   def main(args=None):
#  rclpy.init(args=args)
#   node = Node("py_test")
#   node.get_logger().info("Hello ROS2")
#   rclpy.spin(node)
#   rclpy.shutdown