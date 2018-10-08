/*
 * Copyright (c) 2014-2018 Cesanta Software Limited
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CS_MOS_LIBS_ARDUINO_ADAFRUIT_SGP30_SRC_MGOS_ARDUINO_SGP30_H_
#define CS_MOS_LIBS_ARDUINO_ADAFRUIT_SGP30_SRC_MGOS_ARDUINO_SGP30_H_

#ifdef __cplusplus
#include "Adafruit_SGP30.h"
#else
typedef struct Adafruit_SGP30Tag Adafruit_SGP30;
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define MGOS_SGP30_RES_FAIL -10000

/*
 * Initialize Adafruit_SGP30 library for i2c.
 * Return value: OneWire handle opaque pointer.
 */
Adafruit_SGP30 *mgos_SGP30_create_i2c();

/*
 * Close Adafruit_SGP30 handle. Return value: none.
 */
void mgos_SGP30_close(Adafruit_SGP30 *sgp);

/*
 * Initialize the sensor with given parameters/settings.
 * Returns 0 if the sensor not plugged or a checking failed,
 * i.e. the chip ID is incorrect.
 * Returns 1 otherwise.
 */
int mgos_SGP30_begin(Adafruit_SGP30 *sgp);

void mgos_spg30_IAQinit(Adafruit_SGP30 *sgp);

void mgos_spg30_IAQmeasure(Adafruit_SGP30 *sgp);

void mgos_spg30_getIAQBaseline(Adafruit_SGP30 *sgp,uint16_t *eco2_base, uint16_t *tvoc_base);

void mgos_setIAQBaseline(Adafruit_SGP30 *sgp,uint16_t eco2_base, uint16_t tvoc_base);

void mgos_setHumidity(Adafruit_SGP30 *sgp,uint32_t absolute_humidity);

#ifdef __cplusplus
}
#endif

#endif /* CS_MOS_LIBS_ARDUINO_ADAFRUIT_SGP30_SRC_MGOS_ARDUINO_SGP30_H_ */
