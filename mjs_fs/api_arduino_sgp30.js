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
  _giacb: ffi('void mgos_spg30_getIAQBaseline(void *,int, int)'),
  _siaqb: ffi('void mgos_setIAQBaseline(void *,int, int)'),
  _sh: ffi('void mgos_setHumidity(void *,int)'),
  
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
/*! 
    @brief  Commands the sensor to begin the IAQ algorithm. Must be called after startup.
    @returns True if command completed successfully, false if something went wrong!
*/
    IAQinit: function() {
      return Adafruit_SGP30._iaqi(this.sgp);
    },

	//IAQMeasure
/*! 
    @brief  Commands the sensor to take a single eCO2/VOC measurement. Places results in {@link TVOC} and {@link eCO2}
    @returns True if command completed successfully, false if something went wrong!
*/
    // `Adafruit_SGP30.RES_FAIL` in case of a failure.
    IAQmeasure: function() {
      // C-functions output value of “1234” equals 12.34 Deg.
      return Adafruit_SGP30._iaqm(this.sgp) ;/// 100.0;
    },

    // ## **`getIAQBaseline()`**
/*! 
    @brief Request baseline calibration values for both CO2 and TVOC IAQ calculations. Places results in parameter memory locaitons.
    @param eco2_base A pointer to a uint16_t which we will save the calibration value to
    @param tvoc_base A pointer to a uint16_t which we will save the calibration value to
    @returns True if command completed successfully, false if something went wrong!
*/    getIAQBaseline: function(*eco2_base, *tvoc_base) {
      // C-functions output value of “1234” equals 12.34 hPa.
      return Adafruit_SGP30._giacb(this.sgp,base,tvoc_base);// / 10000.0;
    },

    // ## **`setIAQBaseline()`**

/*! 
    @brief Assign baseline calibration values for both CO2 and TVOC IAQ calculations.
    @param eco2_base A uint16_t which we will save the calibration value from
    @param tvoc_base A uint16_t which we will save the calibration value from
    @returns True if command completed successfully, false if something went wrong!
*/
    setIAQBaseline: function(eco2_base, tvoc_base) {
      // C-functions output value of “1234” equals 12.34 %RH.
      return Adafruit_SGP30._siaqb(this.sgp,eco2_base,tvoc_base);// / 100.0;
    },

    // ## **`mysgp.SetHumidity(absolute_humidity)`**
/*!
    @brief Set the absolute humidity value [mg/m^3] for compensation to increase precision of TVOC and eCO2.
    @param absolute_humidity A uint32_t [mg/m^3] which we will be used for compensation. If the absolute humidity is set to zero, humidity compensation will be disabled.
    @returns True if command completed successfully, false if something went wrong!
*/  
  setHumidity: function(absolute_humidity) {
      // C-functions input and output values of “1234” equals 12.34.
      return Adafruit_SGP30._sh(this.sgp, absolute_humidity);//Math.round(lvl * 100.0)) / 100.0;
    },

  },

};
