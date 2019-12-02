#include "point_cloud_filter_prober/point_cloud_filter_prober.h"
#include <ros/ros.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "point_cloud_filter_prober");
  point_cloud_filter_prober::PointCloudFilterProber prober;
  prober.run();
}