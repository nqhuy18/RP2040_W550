#include "opt3101.h"
#include "pico/stdlib.h"
static opt3101_dev opt3101;
static uint8_t opt3101_addr = OPT3101_CHIP_ADDR;

int main(void) {
  i2c_init_default();

  int8_t rslt = 0;
  opt3101.intf_ptr = &opt3101_addr;
  opt3101.read = &i2cSensorsRead;
  opt3101.write = &i2cSensorsWrite;
  opt3101.millis = pico_millis;
  opt3101.delay = sleep_ms;
  int rslt = opt3101Init(&opt3101);
  
  rslt |= opt3101SetFrameTiming(&opt3101, 256);
  rslt |= opt3101SetChannel(&opt3101, 1);
  rslt |= opt3101SetBrightness(&opt3101, BR_HIGH);
  //...
  while (1)
  {
    rslt = opt3101Sample(&opt3101);
    DEBUG_PRINT("%d %d\n", rslt, opt3101.distanceMillimeters);
    sleep_ms(1000);
  }
  //...
}