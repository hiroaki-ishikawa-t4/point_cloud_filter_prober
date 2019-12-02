
#ifndef POINT_CLOUD_FILTER_PROBER_H_
#define POINT_CLOUD_FILTER_PROBER_H_

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <fstream>
#include <memory>
#include <ros/time.h>

namespace point_cloud_filter_prober
{

class PointCloudFilterProber
{
public:
  PointCloudFilterProber();
  void run();

private:
  ros::NodeHandle private_nh_;
  ros::Subscriber input_1_subscriber_;
  ros::Subscriber input_2_subscriber_;
  std::ofstream log_file_;
  sensor_msgs::PointCloud2 last_msg_;
  uint64_t last_msg_time_ = 0;

  void processCallback(const sensor_msgs::PointCloud2::ConstPtr& msg);
};

}

#endif // POINT_CLOUD_FILTER_PROBER_H_
