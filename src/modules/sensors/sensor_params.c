/****************************************************************************
 *
 *   Copyright (c) 2012-2017 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * Primary baro ID
 *
 * @group Sensor Calibration
 */
PARAM_DEFINE_INT32(CAL_BARO_PRIME, 0);

/**
 * Airspeed sensor compensation model for the SDP3x
 *
 * Model with Pitot
 * 		CAL_AIR_TUBED_MM: Not used, 1.5 mm tubes assumed.
 * 		CAL_AIR_TUBELEN: Length of the tubes connecting the pitot to the sensor.
 * Model without Pitot (1.5 mm tubes)
 * 		CAL_AIR_TUBED_MM: Not used, 1.5 mm tubes assumed.
 * 		CAL_AIR_TUBELEN: Length of the tubes connecting the pitot to the sensor.
 * Tube Pressure Drop
 * 		CAL_AIR_TUBED_MM: Diameter in mm of the pitot and tubes, must have the same diameter.
 * 		CAL_AIR_TUBELEN: Length of the tubes connecting the pitot to the sensor and the static + dynamic port length of the pitot.
 *
 * @value 0 Model with Pitot
 * @value 1 Model without Pitot (1.5 mm tubes)
 * @value 2 Tube Pressure Drop
 * @group Sensor Calibration
 */
PARAM_DEFINE_INT32(CAL_AIR_CMODEL, 0);

/**
 * Airspeed sensor tube length.
 *
 * See the CAL_AIR_CMODEL explanation on how this parameter should be set.
 *
 * @min 0.01
 * @max 2.00
 * @unit meter
 *
 * @group Sensor Calibration
 */
PARAM_DEFINE_FLOAT(CAL_AIR_TUBELEN, 0.2f);

/**
 * Airspeed sensor tube diameter. Only used for the Tube Pressure Drop Compensation.
 *
 * @min 0.1
 * @max 100
 * @unit millimeter
 *
 * @group Sensor Calibration
 */
PARAM_DEFINE_FLOAT(CAL_AIR_TUBED_MM, 1.5f);

/**
 * Differential pressure sensor offset
 *
 * The offset (zero-reading) in Pascal
 *
 * @group Sensor Calibration
 */
PARAM_DEFINE_FLOAT(SENS_DPRES_OFF, 0.0f);

/**
 * Differential pressure sensor analog scaling
 *
 * Pick the appropriate scaling from the datasheet.
 * this number defines the (linear) conversion from voltage
 * to Pascal (pa). For the MPXV7002DP this is 1000.
 *
 * NOTE: If the sensor always registers zero, try switching
 * the static and dynamic tubes.
 *
 * @group Sensor Calibration
 */
PARAM_DEFINE_FLOAT(SENS_DPRES_ANSC, 0);

/**
 * QNH for barometer
 *
 * @min 500
 * @max 1500
 * @group Sensors
 * @unit hPa
 */
PARAM_DEFINE_FLOAT(SENS_BARO_QNH, 1013.25f);

/**
 * Board rotation
 *
 * This parameter defines the rotation of the FMU board relative to the platform.
 *
 * @value 0 No rotation
 * @value 1 Yaw 45??
 * @value 2 Yaw 90??
 * @value 3 Yaw 135??
 * @value 4 Yaw 180??
 * @value 5 Yaw 225??
 * @value 6 Yaw 270??
 * @value 7 Yaw 315??
 * @value 8 Roll 180??
 * @value 9 Roll 180??, Yaw 45??
 * @value 10 Roll 180??, Yaw 90??
 * @value 11 Roll 180??, Yaw 135??
 * @value 12 Pitch 180??
 * @value 13 Roll 180??, Yaw 225??
 * @value 14 Roll 180??, Yaw 270??
 * @value 15 Roll 180??, Yaw 315??
 * @value 16 Roll 90??
 * @value 17 Roll 90??, Yaw 45??
 * @value 18 Roll 90??, Yaw 90??
 * @value 19 Roll 90??, Yaw 135??
 * @value 20 Roll 270??
 * @value 21 Roll 270??, Yaw 45??
 * @value 22 Roll 270??, Yaw 90??
 * @value 23 Roll 270??, Yaw 135??
 * @value 24 Pitch 90??
 * @value 25 Pitch 270??
 * @value 26 Roll 270??, Yaw 270??
 * @value 27 Roll 180??, Pitch 270??
 * @value 28 Pitch 90??, Yaw 180
 * @value 29 Pitch 90??, Roll 90??
 * @value 30 Yaw 293??, Pitch 68??, Roll 90?? (Solo)
 * @value 31 Pitch 90??, Roll 270??
 * @value 32 Pitch 9??, Yaw 180??
 * @value 33 Pitch 45??
 * @value 34 Pitch 315??
 *
 * @reboot_required true
 *
 * @group Sensors
 */
PARAM_DEFINE_INT32(SENS_BOARD_ROT, 0);

/**
 * PX4Flow board rotation
 *
 * This parameter defines the yaw rotation of the PX4FLOW board relative to the vehicle body frame.
 * Zero rotation is defined as X on flow board pointing towards front of vehicle.
 * The recommneded installation default for the PX4FLOW board is with the Y axis forward (270 deg yaw).
 *
 * @value 0 No rotation
 * @value 1 Yaw 45??
 * @value 2 Yaw 90??
 * @value 3 Yaw 135??
 * @value 4 Yaw 180??
 * @value 5 Yaw 225??
 * @value 6 Yaw 270??
 * @value 7 Yaw 315??
 *
 * @reboot_required true
 *
 * @group Sensors
 */
PARAM_DEFINE_INT32(SENS_FLOW_ROT, 6);

/**
 * Optical Flow minimum focus distance
 *
 * This parameter defines the minimum distance from ground required for the optical flow sensor to operate reliably. The sensor may be usable below this height, but accuracy will progressively reduce to loss of focus.
 * *
 * @group Sensor Calibration
 */
PARAM_DEFINE_FLOAT(SENS_FLOW_MINRNG, 0.7f);

/**
 * Board rotation Y (Pitch) offset
 *
 * This parameter defines a rotational offset in degrees around the Y (Pitch) axis. It allows the user
 * to fine tune the board offset in the event of misalignment.
 *
 * @unit deg
 * @group Sensors
 */
PARAM_DEFINE_FLOAT(SENS_BOARD_Y_OFF, 0.0f);

/**
 * Board rotation X (Roll) offset
 *
 * This parameter defines a rotational offset in degrees around the X (Roll) axis It allows the user
 * to fine tune the board offset in the event of misalignment.
 *
 * @unit deg
 * @group Sensors
 */
PARAM_DEFINE_FLOAT(SENS_BOARD_X_OFF, 0.0f);

/**
 * Board rotation Z (YAW) offset
 *
 * This parameter defines a rotational offset in degrees around the Z (Yaw) axis. It allows the user
 * to fine tune the board offset in the event of misalignment.
 *
 * @unit deg
 * @group Sensors
 */
PARAM_DEFINE_FLOAT(SENS_BOARD_Z_OFF, 0.0f);

/**
 * Thermal control of sensor temperature
 *
 * @value -1 Thermal control unavailable
 * @value 0 Thermal control off
 * @group Sensors
 */
PARAM_DEFINE_INT32(SENS_EN_THERMAL, -1);

/**
* Driver level cutoff frequency for gyro
*
* The cutoff frequency for the 2nd order butterworth filter on the gyro driver. This features
* is currently supported by the mpu6000 and mpu9250. This only affects the signal sent to the
* controllers, not the estimators. 0 disables the filter.
*
* @min 0
* @max 1000
* @unit Hz
* @reboot_required true
* @group Sensors
*/
PARAM_DEFINE_FLOAT(IMU_GYRO_CUTOFF, 80.0f);

/**
* Driver level cutoff frequency for accel
*
* The cutoff frequency for the 2nd order butterworth filter on the accel driver. This features
* is currently supported by the mpu6000 and mpu9250. This only affects the signal sent to the
* controllers, not the estimators. 0 disables the filter.
*
* @min 0
* @max 1000
* @unit Hz
* @reboot_required true
* @group Sensors
*/
PARAM_DEFINE_FLOAT(IMU_ACCEL_CUTOFF, 30.0f);
