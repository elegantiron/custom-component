#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "esphome/components/i2c/i2c.h"
#include "esphome/core/preferences.h"
#include "esphome/core/defines.h"
#include <map>

namespace esphome {
namespace ti_bq25895 {

enum ti_bq25895WatchdogTimer {
    WATCHDOG_TIMER_OFF,
    WATCHDOG_TIMER_40S,
    WATCHDOG_TIMER_80S,
    WATCHDOG_TIMER_160S
};

enum ti_bq25895ChargeVoltageLimit {
    VOLTAGE_LIMIT_3840,
    VOLTAGE_LIMIT_3856,
    VOLTAGE_LIMIT_3872,
    VOLTAGE_LIMIT_3888,
    VOLTAGE_LIMIT_3904,
    VOLTAGE_LIMIT_3920,
    VOLTAGE_LIMIT_3936,
    VOLTAGE_LIMIT_3952,
    VOLTAGE_LIMIT_3968,
    VOLTAGE_LIMIT_3984,
    VOLTAGE_LIMIT_4000,
    VOLTAGE_LIMIT_4016,
    VOLTAGE_LIMIT_4032,
    VOLTAGE_LIMIT_4048,
    VOLTAGE_LIMIT_4064,
    VOLTAGE_LIMIT_4080,
    VOLTAGE_LIMIT_4096,
    VOLTAGE_LIMIT_4112,
    VOLTAGE_LIMIT_4128,
    VOLTAGE_LIMIT_4144,
    VOLTAGE_LIMIT_4160,
    VOLTAGE_LIMIT_4176,
    VOLTAGE_LIMIT_4192,
    VOLTAGE_LIMIT_4208,
    VOLTAGE_LIMIT_4224,
    VOLTAGE_LIMIT_4240,
    VOLTAGE_LIMIT_4256,
    VOLTAGE_LIMIT_4272,
    VOLTAGE_LIMIT_4288,
    VOLTAGE_LIMIT_4304,
    VOLTAGE_LIMIT_4320,
    VOLTAGE_LIMIT_4336,
    VOLTAGE_LIMIT_4352,
    VOLTAGE_LIMIT_4368,
    VOLTAGE_LIMIT_4384,
    VOLTAGE_LIMIT_4400,
    VOLTAGE_LIMIT_4416,
    VOLTAGE_LIMIT_4432,
    VOLTAGE_LIMIT_4448,
    VOLTAGE_LIMIT_4464,
    VOLTAGE_LIMIT_4480,
    VOLTAGE_LIMIT_4496,
    VOLTAGE_LIMIT_4512,
    VOLTAGE_LIMIT_4528,
    VOLTAGE_LIMIT_4544,
    VOLTAGE_LIMIT_4560,
    VOLTAGE_LIMIT_4576,
    VOLTAGE_LIMIT_4592,
    VOLTAGE_LIMIT_4608
};

enum ti_bq25895SystemMinimumVoltage {
    SYSTEM_MINIMUM_30,
    SYSTEM_MINIMUM_31,
    SYSTEM_MINIMUM_32,
    SYSTEM_MINIMUM_33,
    SYSTEM_MINIMUM_34,
    SYSTEM_MINIMUM_35,
    SYSTEM_MINIMUM_36,
    SYSTEM_MINIMUM_37
};

enum ti_bq25895VinDPMVoltage {
    VINDPM_VOLTAGE_3900,
    VINDPM_VOLTAGE_4000,
    VINDPM_VOLTAGE_4100,
    VINDPM_VOLTAGE_4200,
    VINDPM_VOLTAGE_4300,
    VINDPM_VOLTAGE_4400,
    VINDPM_VOLTAGE_4500,
    VINDPM_VOLTAGE_4600,
    VINDPM_VOLTAGE_4700,
    VINDPM_VOLTAGE_4800,
    VINDPM_VOLTAGE_4900,
    VINDPM_VOLTAGE_5000,
    VINDPM_VOLTAGE_5100,
    VINDPM_VOLTAGE_5200
};

enum ti_bq25895InputCurrentLimit {
    INPUT_CURRENT_LIMIT_0100,
    INPUT_CURRENT_LIMIT_0150,
    INPUT_CURRENT_LIMIT_0200,
    INPUT_CURRENT_LIMIT_0250,
    INPUT_CURRENT_LIMIT_0300,
    INPUT_CURRENT_LIMIT_0350,
    INPUT_CURRENT_LIMIT_0400,
    INPUT_CURRENT_LIMIT_0450,
    INPUT_CURRENT_LIMIT_0500,
    INPUT_CURRENT_LIMIT_0550,
    INPUT_CURRENT_LIMIT_0600,
    INPUT_CURRENT_LIMIT_0650,
    INPUT_CURRENT_LIMIT_0700,
    INPUT_CURRENT_LIMIT_0750,
    INPUT_CURRENT_LIMIT_0800,
    INPUT_CURRENT_LIMIT_0850,
    INPUT_CURRENT_LIMIT_0900,
    INPUT_CURRENT_LIMIT_0950,
    INPUT_CURRENT_LIMIT_1000,
    INPUT_CURRENT_LIMIT_1050,
    INPUT_CURRENT_LIMIT_1100,
    INPUT_CURRENT_LIMIT_1150,
    INPUT_CURRENT_LIMIT_1200,
    INPUT_CURRENT_LIMIT_1250,
    INPUT_CURRENT_LIMIT_1300,
    INPUT_CURRENT_LIMIT_1350,
    INPUT_CURRENT_LIMIT_1400,
    INPUT_CURRENT_LIMIT_1450,
    INPUT_CURRENT_LIMIT_1500,
    INPUT_CURRENT_LIMIT_1550,
    INPUT_CURRENT_LIMIT_1600,
    INPUT_CURRENT_LIMIT_1650,
    INPUT_CURRENT_LIMIT_1700,
    INPUT_CURRENT_LIMIT_1750,
    INPUT_CURRENT_LIMIT_1800,
    INPUT_CURRENT_LIMIT_1850,
    INPUT_CURRENT_LIMIT_1900,
    INPUT_CURRENT_LIMIT_1950,
    INPUT_CURRENT_LIMIT_2000,
    INPUT_CURRENT_LIMIT_2050,
    INPUT_CURRENT_LIMIT_2100,
    INPUT_CURRENT_LIMIT_2150,
    INPUT_CURRENT_LIMIT_2200,
    INPUT_CURRENT_LIMIT_2250,
    INPUT_CURRENT_LIMIT_2300,
    INPUT_CURRENT_LIMIT_2350,
    INPUT_CURRENT_LIMIT_2400,
    INPUT_CURRENT_LIMIT_2450,
    INPUT_CURRENT_LIMIT_2500,
    INPUT_CURRENT_LIMIT_2550,
    INPUT_CURRENT_LIMIT_2600,
    INPUT_CURRENT_LIMIT_2650,
    INPUT_CURRENT_LIMIT_2700,
    INPUT_CURRENT_LIMIT_2750,
    INPUT_CURRENT_LIMIT_2800,
    INPUT_CURRENT_LIMIT_2850,
    INPUT_CURRENT_LIMIT_2900,
    INPUT_CURRENT_LIMIT_2950,
    INPUT_CURRENT_LIMIT_3000,
    INPUT_CURRENT_LIMIT_3050,
    INPUT_CURRENT_LIMIT_3100,
    INPUT_CURRENT_LIMIT_3150,
    INPUT_CURRENT_LIMIT_3200,
    INPUT_CURRENT_LIMIT_3250,
    INPUT_CURRENT_LIMIT_3300,
    INPUT_CURRENT_LIMIT_3350,
    INPUT_CURRENT_LIMIT_3400,
    INPUT_CURRENT_LIMIT_3450,
    INPUT_CURRENT_LIMIT_3500,
    INPUT_CURRENT_LIMIT_3550,
    INPUT_CURRENT_LIMIT_3600,
    INPUT_CURRENT_LIMIT_3650,
    INPUT_CURRENT_LIMIT_3700,
    INPUT_CURRENT_LIMIT_3750,
    INPUT_CURRENT_LIMIT_3800,
    INPUT_CURRENT_LIMIT_3850,
    INPUT_CURRENT_LIMIT_3900,
    INPUT_CURRENT_LIMIT_3950,
    INPUT_CURRENT_LIMIT_4000,
    INPUT_CURRENT_LIMIT_4050,
    INPUT_CURRENT_LIMIT_4100,
    INPUT_CURRENT_LIMIT_4150,
    INPUT_CURRENT_LIMIT_4200,
    INPUT_CURRENT_LIMIT_4250,
    INPUT_CURRENT_LIMIT_4300,
    INPUT_CURRENT_LIMIT_4350,
    INPUT_CURRENT_LIMIT_4400,
    INPUT_CURRENT_LIMIT_4450,
    INPUT_CURRENT_LIMIT_4500,
    INPUT_CURRENT_LIMIT_4550,
    INPUT_CURRENT_LIMIT_4600,
    INPUT_CURRENT_LIMIT_4650,
    INPUT_CURRENT_LIMIT_4700,
    INPUT_CURRENT_LIMIT_4750,
    INPUT_CURRENT_LIMIT_4800,
    INPUT_CURRENT_LIMIT_4850,
    INPUT_CURRENT_LIMIT_4900,
    INPUT_CURRENT_LIMIT_4950,
    INPUT_CURRENT_LIMIT_5000
};

class TIBQ25895Component : public PollingComponent, public i2c::I2CDevice {
    public:
        void set_device_id(const std::string &devid) { this->device_id_.assign(devid); }
        void set_watchdog_time(ti_bq25895WatchdogTimer interval) { this->watchdog_interval_ = interval; }
        void set_input_current_limit(ti_bq25895InputCurrentLimit limit) { this->input_current_limit_ = limit; }
        void set_charge_voltage_limit(ti_bq25895ChargeVoltageLimit limit) {this->charge_voltage_limit_ = limit; }
        void set_system_minimum_voltage(ti_bq25895SystemMinimumVoltage minimum) { this->system_minimum_voltage_ = minimum; }
        void set_vindpm_voltage(ti_bq25895VinDPMVoltage voltage) { this->vindpm_voltage_ = voltage; }
        void set_vindpm(bool enabled) { this->force_vindpm_ = enabled; }
        void set_switch_frequency(bool enabled) { this->use_high_frequency_ = enabled; }
        void set_ico_enabled(bool enabled) {this->input_current_optimization_enabled_ = enabled; }
        void set_continuous_conversion(bool enabled) { this->continuous_conversion_ = enabled; }
        void set_input_current_pin_enabled(bool enabled) { this->input_current_pin_enabled_ = enabled; }
        void set_input_voltage_dpm_enabled(bool enabled) { this->input_voltage_dpm_enabled_ = enabled; }
        void set_auto_dpm_enabled(bool enabled) { this->auto_dpm_enabled_ = enabled; }
        void set_battery_voltage_sensor(sensor::Sensor *sensor) { this->batt_voltage_sensor_ = sensor; }
        void set_charge_current_sensor(sensor::Sensor *sensor) {this->charge_current_sensor_ = sensor; }
        void set_supply_voltage_sensor(sensor::Sensor *sensor) {this->supply_voltage_sensor_ = sensor; }
        void set_idpm_limit_sensor(sensor::Sensor *sensor) {this->idpm_limit_sensor_ = sensor; }
        void enable_charging() {this->enable_charging_();}
        void disable_charging() {this->disable_charging_();}


        void setup() override;
        void update() override;

        static std::vector<TIBQ25895Component *> instances;
    protected:
        void pet_dog_() { this->set_bit_(0x03, 6, true); }
        void set_bit_(uint8_t reg, uint8_t pos, bool bit);
        void set_continuous_conversion_(bool enabled) { this->set_bit_(0x02, 6, enabled); }
        void set_input_current_pin_enabled_(bool enabled) { this->set_bit_(0x00, 6, enabled); }
        void set_input_voltage_dpm_enabled_(bool enabled) { this->set_bit_(0x0D, 7, enabled); }
        void set_auto_dpm_enabled_(bool enabled) { this->set_bit_(0x02, 0, enabled); }
        void set_input_current_optimization_enabled_(bool enabled) { this->set_bit_(0x02, 4, enabled); }
        void set_input_limit_current_(ti_bq25895InputCurrentLimit setting);
        void set_vin_dpm_voltage_(ti_bq25895VinDPMVoltage voltage);
        void set_charge_voltage_limit_(ti_bq25895ChargeVoltageLimit setting);
        void set_system_minimum_voltage_(ti_bq25895SystemMinimumVoltage setting);
        void set_watchdog_timer_(ti_bq25895WatchdogTimer setting);
        void set_switch_frequency_(bool enabled);
        void enable_charging_() {this->set_bit_(0x03, 4, true);}
        void disable_charging_() {this->set_bit_(0x03, 4, false);}
        float get_battery_voltage_();
        int get_charge_current_();
        uint get_idpm_limit_();
        float get_supply_voltage_();
        bool get_watchdog_fault_();
        uint8_t get_vbus_status_();
        std::string device_id_;
        ti_bq25895WatchdogTimer watchdog_interval_;
        ti_bq25895InputCurrentLimit input_current_limit_;
        ti_bq25895ChargeVoltageLimit charge_voltage_limit_;
        ti_bq25895SystemMinimumVoltage system_minimum_voltage_;
        ti_bq25895VinDPMVoltage vindpm_voltage_;
        bool force_vindpm_,
             continuous_conversion_,
             input_current_pin_enabled_,
             input_voltage_dpm_enabled_,
             auto_dpm_enabled_,
             input_current_optimization_enabled_,
             use_high_frequency_,
             run_ico_algorithm_ = false;
        
        sensor::Sensor *batt_voltage_sensor_{nullptr};
        sensor::Sensor *charge_current_sensor_{nullptr};
        sensor::Sensor *supply_voltage_sensor_{nullptr};
        sensor::Sensor *idpm_limit_sensor_{nullptr};
};

}
}