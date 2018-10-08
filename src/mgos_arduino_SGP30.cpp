/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 *
 * Arduino Adafruit_SGP30 library API wrapper
 */

#include <math.h>
#include "mgos_arduino_SGP30.h"

Adafruit_SGP30 *mgos_sgp30_create_i2c() {
  return new Adafruit_SGP30();
}

void mgos_sgp30_close(Adafruit_SGP30 *sgp) {
  if (sgp != nullptr) {
    delete sgp;
    sgp = nullptr;
  }
}

int mgos_sgp30_begin(Adafruit_SGP30 *sgp) {
  if (sgp == nullptr) return 0;
  return sgp->begin();
}

void mgos_spg30_IAQinit(Adafruit_SGP30 *sgp) {
  if (sgp == nullptr) return;
  sgp->IAQinit();
}

void mgos_spg30_IAQmeasure(Adafruit_SGP30 *sgp) {
  if (sgp == nullptr) return;
  sgp->IAQmeasure();
}

void mgos_spg30_getIAQBaseline(Adafruit_SGP30 *sgp,uint16_t *eco2_base, uint16_t *tvoc_base) {
  if (sgp == nullptr) return;
  sgp->getIAQBaseline(eco2_base, tvoc_base);
}

void mgos_setIAQBaseline(Adafruit_SGP30 *sgp,uint16_t eco2_base, uint16_t tvoc_base) {
  if (sgp == nullptr) return;
  sgp->setIAQBaseline(eco2_base,tvoc_base);
}

void mgos_setHumidity(Adafruit_SGP30 *sgp,uint32_t absolute_humidity) {
  if (sgp == nullptr) return;
  sgp->setHumidity(absolute_humidity);
}

