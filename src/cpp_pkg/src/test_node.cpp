#include "rclcpp/rclcpp.hpp"

class ROS2Node : public rclcpp::Node
{
public:
    ROS2Node() : Node("cpp_test")
    {
        RCLCPP_INFO(this->get_logger(), "Hello CPP Node");
        timer_ = this->create_wall_timer(std::chrono::seconds(1),
                                         std::bind(&ROS2Node::timerCallback, this));
    }

private:
    void timerCallback()
    {
        counter_++;
        RCLCPP_INFO(this->get_logger(), "Hello CPP Node %d", counter_);
    }

    rclcpp::TimerBase::SharedPtr timer_ ;
    int counter_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ROS2Node>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}