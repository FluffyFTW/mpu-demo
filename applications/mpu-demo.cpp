#include <libhal-sensor/imu/mpu6050.hpp>
#include <libhal-util/serial.hpp>

#include "../include/resource_list.hpp"

void application(resource_list const& p_list)
{
  auto& serial = *p_list.console.value();
  auto& i2c = *p_list.i2c.value();
  hal::sensor::mpu6050 mpu(i2c);
  while (true) {
    auto acc = mpu.read();
    hal::print<1024>(serial, "x: %fg, y: %fg, z: %fg \n", acc.x, acc.y, acc.z);
  }
}