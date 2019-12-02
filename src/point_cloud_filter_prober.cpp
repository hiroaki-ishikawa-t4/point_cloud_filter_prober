#include "point_cloud_filter_prober/point_cloud_filter_prober.h"

namespace point_cloud_filter_prober
{

PointCloudFilterProber::PointCloudFilterProber()
: private_nh_("~")
{
  std::string filename = private_nh_.param<std::string>("filename", "/tmp/output.csv");
  log_file_.open(filename, std::ios::out);
  input_1_subscriber_ = private_nh_.subscribe("/input_1", 1, &PointCloudFilterProber::processCallback, this);
  input_2_subscriber_ = private_nh_.subscribe("/input_2", 1, &PointCloudFilterProber::processCallback, this);
}

void PointCloudFilterProber::processCallback(const sensor_msgs::PointCloud2::ConstPtr& msg)
{
  uint64_t now = ros::Time::now().toNSec();
  if(last_msg_time_ > 0)
  {
    if(last_msg_.header.stamp == msg->header.stamp)
    {
      ROS_INFO("Same stamp found.");
      log_file_ << msg->header.stamp.toNSec() << ", " << now - last_msg_time_ << ", " << last_msg_.height * last_msg_.width  << ", " << msg->height * msg->width << std::endl;
    }
  }
  last_msg_time_ = now;
  last_msg_ = *msg;
}

void PointCloudFilterProber::run()
{
  ros::spin();

  log_file_.close();
}

}