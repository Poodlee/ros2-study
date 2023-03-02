#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;


class HellodongjunSubscriber : public rclcpp::Node
{
public:
  HellodongjunSubscriber()
  : Node("Hellodongjun_subscriber")
  {
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    Hellodongjun_subscriber_ = this->create_subscription<std_msgs::msg::String>(
      "Hellodongjun",
      qos_profile,
      std::bind(&HellodongjunSubscriber::subscribe_topic_message, this, _1));
  }

private:
  void subscribe_topic_message(const std_msgs::msg::String::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "Received message: '%s'", msg->data.c_str());
  }
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr Hellodongjun_subscriber_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<HellodongjunSubscriber>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
