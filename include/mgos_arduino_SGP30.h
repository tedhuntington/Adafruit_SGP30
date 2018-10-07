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
 * Initialize Adafruit_SGP30 library for spi with the given `cspin`.
 * Return value: OneWire handle opaque pointer.
 */
Adafruit_SGP30 *mgos_SGP30_create_spi(int cspin);

/*
 * Initialize Adafruit_SGP30 library for spi with the given pins `cspin`,
 * `mosipin`, `misopin`, `sckpin`.
 * Return value: OneWire handle opaque pointer.
 */
Adafruit_SGP30 *mgos_SGP30_create_spi_full(int cspin, int mosipin,
                                             int misopin, int sckpin);

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

/*
 * Take a new measurement (only possible in forced mode).
 */
void mgos_SGP30_take_forced_measurement(Adafruit_SGP30 *sgp);

/*
 * Returns the temperature from the sensor in degrees C * 100
 * or MGOS_SGP30_RES_FAIL if an operation failed.
 */
int mgos_SGP30_read_temperature(Adafruit_SGP30 *sgp);

/*
 * Returns the pressure from the sensor in hPa * 100
 * or MGOS_SGP30_RES_FAIL if an operation failed.
 */
int mgos_SGP30_read_pressure(Adafruit_SGP30 *sgp);

/*
 * Returns the humidity from the sensor in %RH * 100
 * or MGOS_SGP30_RES_FAIL if an operation failed.
 */
int mgos_SGP30_read_humidity(Adafruit_SGP30 *sgp);

/*
 * Returns the altitude in meters * 100 calculated from the specified
 * atmospheric pressure (in hPa), and sea-level pressure (in hPa * 100)
 * or MGOS_SGP30_RES_FAIL if an operation failed.
 * http: *www.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf, P.16
 */
int mgos_SGP30_read_altitude(Adafruit_SGP30 *sgp, int seaLevel);

/*
 * Returns the pressure at sea level in hPa * 100
 * calculated from the specified altitude (in meters * 100),
 * and atmospheric pressure (in hPa * 100)
 * or MGOS_SGP30_RES_FAIL if an operation failed.
 * http: *www.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf, P.17
 */
int mgos_SGP30_sea_level_for_altitude(Adafruit_SGP30 *sgp, int altitude,
                                       int pressure);

#ifdef __cplusplus
}
#endif

#endif /* CS_MOS_LIBS_ARDUINO_ADAFRUIT_SGP30_SRC_MGOS_ARDUINO_SGP30_H_ */
