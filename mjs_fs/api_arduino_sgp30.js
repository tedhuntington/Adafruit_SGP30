// Arduino Adafruit_SGP30 library API. Source C API is defined at:
// [mgos_arduino_sgp30.h](https://github.com/mongoose-os-libs/arduino-adafruit-sgp30/blob/master/src/mgos_arduino_sgp30.h)

load('api_math.js');

let Adafruit_SGP30 = {
  // Error codes
  RES_FAIL: -100.0,

  _c_i2c: ffi('void *mgos_sgp30_create_i2c(void)'),
  _close: ffi('void mgos_sgp30_close(void *)'),
  _begin: ffi('int mgos_sgp30_begin(void *)'),
  _iaqi: ffi('void mgos_spg30_IAQinit(void *)'),
  _iaqm: ffi('void mgos_spg30_IAQmeasure(void *)'),
  _giacb: ffi('void mgos_spg30_getIAQBaseline(Adafruit_SGP30 *sgp,uint16_t *eco2_base, uint16_t *tvoc_base) {'),
  _siaqb: ffi('void mgos_setIAQBaseline(Adafruit_SGP30 *sgp,uint16_t eco2_base, uint16_t tvoc_base) {'),
  _sh: ffi('void mgos_setHumidity(Adafruit_SGP30 *sgp,uint32_t absolute_humidity) {'),
  
  // ## **`Adafruit_SGP30.createI2C(i2caddr)`**
  // Create a SGP30 instance on I2C bus with the given address `i2caddr`.
  // Return value: an object with the methods described below.
  createI2C: function(i2caddr) {
    let obj = Object.create(Adafruit_SGP30._proto);
    // Initialize Adafruit_SGP30 library.
    // Return value: handle opaque pointer.
    obj.sgp = Adafruit_SGP30._c_i2c();
    let b = Adafruit_SGP30._begin(obj.sgp);
    if (b === 0) {
      // Can't find a sensor
      return undefined;
    }
    return obj;
  },

  _proto: {
    // ## **`mySGE30.close()`**
    // Close Adafruit_SGP30 instance; no methods can be called on this instance
    // after that.
    // Return value: none.
    close: function() {
      return Adafruit_SGP30._close(this.sgp);
    },

    // ## **`mysgp.IAQinit()`**
    // Take a new measurement (only possible in forced mode).
    IAQinit: function() {
      return Adafruit_SGP30._iaqi(this.sgp);
    },

    // ## **`mysgp.readTemperature()`**
    // Return the temperature from the sensor in degrees C or
    // `Adafruit_SGP30.RES_FAIL` in case of a failure.
    IAQmeasure: function() {
      // C-functions output value of “1234” equals 12.34 Deg.
      return Adafruit_SGP30._iaqm(this.sgp) ;/// 100.0;
    },

    // ## **`mysgp.readPressure()`**
    // Returns the pressure from the sensor in hPa
    // or `Adafruit_SGP30.RES_FAIL` in case of a failure.
    getIAQBaseline: function(*eco2_base, *tvoc_base) {
      // C-functions output value of “1234” equals 12.34 hPa.
      return Adafruit_SGP30._giacb(this.sgp,base,tvoc_base);// / 10000.0;
    },

    // ## **`mysgp.readHumidity()`**
    // Returns the humidity from the sensor in %RH
    // or `Adafruit_SGP30.RES_FAIL` in case of a failure.
    setIAQBaseline: function(eco2_base, tvoc_base) {
      // C-functions output value of “1234” equals 12.34 %RH.
      return Adafruit_SGP30._siaqb(this.sgp,eco2_base,tvoc_base);// / 100.0;
    },

    // ## **`mysgp.readAltitude(seaLevel)`**
    // Returns the altitude in meters calculated from the specified
    // sea-level pressure `seaLevel` (in hPa)
    // or `Adafruit_SGP30.RES_FAIL` in case of a failure.
    // http://www.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf, P.16
    SetHumidity: function(absolute_humidity) {
      // C-functions input and output values of “1234” equals 12.34.
      return Adafruit_SGP30._sh(this.sgp, absolute_humidity);//Math.round(lvl * 100.0)) / 100.0;
    },

  },

};
