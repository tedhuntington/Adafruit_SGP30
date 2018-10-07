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

Adafruit_SGP30 *mgos_sgp30_create_spi(int cspin) {
  return new Adafruit_SGP30(cspin);
}

Adafruit_SGP30 *mgos_sgp30_create_spi_full(int cspin, int mosipin,
                                             int misopin, int sckpin) {
  return new Adafruit_SGP30(cspin, mosipin, misopin, sckpin);
}

void mgos_sgp30_close(Adafruit_SGP30 *sgp) {
  if (sgp != nullptr) {
    delete sgp;
    sgp = nullptr;
  }
}

int mgos_sgp30_begin(Adafruit_SGP30 *sgp, int addr) {
  if (sgp == nullptr) return 0;
  return sgp->begin(addr);
}

void mos_spg30_IAQinit(Adafruit_SGP30 *sgp) {
  if (sgp == nullptr) return;
  sgp->IAQinit();
}

void mos_spg30_IAQmeasure(Adafruit_SGP30 *sgp) {
  if (sgp == nullptr) return;
  sgp->IAQmeasure();
}

void mos_spg30_getIAQBaseline(Adafruit_SGP30 *sgp,uint16_t *eco2_base, uint16_t *tvoc_base) {
  if (sgp == nullptr) return;
  sgp->getIAQBaseline(eco2_base, tvoc_base);
}

void mos_setIAQBaseline(Adafruit_SGP30 *sgp,uint16_t eco2_base, uint16_t tvoc_base) {
  if (sgp == nullptr) return;
  sgp->setIAQBaseline(eco2_base,tvoc_base);
}

void mos_setHumidity(Adafruit_SGP30 *sgp,uint32_t absolute_humidity) {
  if (sgp == nullptr) return;
  sgp->setHumidity(absolute_humidity);
}

