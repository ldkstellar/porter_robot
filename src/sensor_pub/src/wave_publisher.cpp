#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "wave_interfaces/msg/distance.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */
class WavePublisher : public rclcpp::Node
{
  public:
    WavePublisher()
    : Node("wave_publisher")
    {
      publisher_ = this->create_publisher<wave_interfaces::msg::Distance>("distance", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&WavePublisher::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      auto distance = wave_interfaces::msg::Distance();

      // 여기서 데이터 받아온다. gpio로직
      publisher_->publish(distance);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<wave_interfaces::msg::Distance>::SharedPtr publisher_;
    double sensor_distance;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<WavePublisher>());
  rclcpp::shutdown();
  return 0;
}