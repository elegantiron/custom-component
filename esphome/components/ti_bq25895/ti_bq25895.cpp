#include "ti_bq25895.h"
#include "esphome/core/hal.h"
#include "esphome/core/log.h"

namespace esphome {
namespace ti_bq25895 {

static const char *const TAG = "bq25895.sensor";

std::vector<TIBQ25895Component *> TIBQ25895Component::instances;

void TIBQ25895Component::setup() {
    ESP_LOGCONFIG(TAG, "Setting up BQ25895...");

    uint8_t new_idx = TIBQ25895Component::instances.size();
    TIBQ25895Component::instances.push_back(this);

    this->set_bit_(0x14, 7, true);
    this->pet_dog_();
    this->set_continuous_conversion_(this->continuous_conversion_);
    this->set_input_current_pin_enabled_(this->input_current_pin_enabled_);
    this->set_input_voltage_dpm_enabled_(this->input_voltage_dpm_enabled_);
    this->set_auto_dpm_enabled_(this->auto_dpm_enabled_);
    this->set_input_limit_current_(this->input_current_limit_);
    this->set_vin_dpm_voltage_(this->vindpm_voltage_);
    this->set_system_minimum_voltage_(this->system_minimum_voltage_);
    this->set_charge_voltage_limit_(this->charge_voltage_limit_);
    this->set_watchdog_timer_(this->watchdog_interval_);
}

void TIBQ25895Component::set_bit_(uint8_t reg, uint8_t pos, bool bit) {
    // uint8_t data = uint8_t(bit) << pos;
    uint8_t temp;
    this->read_byte(reg, &temp);
    temp &= ~(0b1 << pos);
    temp |= (uint8_t(bit) << pos);
    this->write_byte(reg, temp);
}

void TIBQ25895Component::set_input_limit_current_(ti_bq25895InputCurrentLimit setting) {
    uint8_t data;
    this->read_byte(0x00, &data);
    data &= 0b11000000;
    data |= uint8_t(setting);
    this->write_byte(0x00, data);
}

void TIBQ25895Component::set_vin_dpm_voltage_(ti_bq25895VinDPMVoltage voltage) {
    uint8_t data;
    this->read_byte(0x0D, &data);
    data &= 0b10000000;
    data |= uint8_t(voltage);
    this->write_byte(0x0D, data);
}

void TIBQ25895Component::set_system_minimum_voltage_(ti_bq25895SystemMinimumVoltage setting) {
    uint8_t data;
    this->read_byte(0x03, &data);
    data &= 0b00001110;
    data |= (uint8_t(setting)<<1);
    this->write_byte(0x03, data);
}

void TIBQ25895Component::set_charge_voltage_limit_(ti_bq25895ChargeVoltageLimit setting) {
    uint8_t data;
    this->read_byte(0x06, &data);
    data &= 0b00000011;
    data |= (uint8_t(setting)<<2);
    this->write_byte(0x06, data);
}

void TIBQ25895Component::set_watchdog_timer_(ti_bq25895WatchdogTimer setting) {
    uint8_t data;
    this->read_byte(0x07, &data);
    data &= 0b11001111;
    data |= (uint8_t(setting)<<4);
    this->write_byte(0x07, data);
}

float TIBQ25895Component::get_battery_voltage_() {
    uint8_t raw;
    this->read_byte(0x0E, &raw);
    raw &= 0b01111111;
    float ret = float(raw);
    return (ret * 0.02) + 2.304;
}

int TIBQ25895Component::get_charge_current_() {
    uint8_t raw;
    this->read_byte(0x12, &raw);
    int ret = int(raw);
    return (ret * 50);
}

float TIBQ25895Component::get_supply_voltage_() {
    uint8_t raw;
    this->read_byte(0x11, &raw);
    raw &= 0b01111111;
    float ret = float(raw);
    return (( ret * 0.1 ) + 2.6);
}

bool TIBQ25895Component::get_watchdog_fault_() {
    uint8_t raw;
    this->read_byte(0x0C, &raw);
    raw >>= 7;
    return bool(raw);
}

uint8_t TIBQ25895Component::get_vbus_status_() {
    uint8_t status;
    this->read_byte(0x0B, &status);
    status &= 0b11100000;
    status >>= 5;
    return status;
}

int TIBQ25895Component::get_idpm_limit_() {
    uint8_t raw;
    this->read_byte(0x13, &raw);
    raw &= 0b00111111;
    int limit = int(raw) * 50;
    return limit;
}

void TIBQ25895Component::update() {
    if (this->input_current_optimization_enabled_) {
        this->set_bit_(0x03, 4, true);
    }
    ESP_LOGV(TAG, "reading stats");

    this->read_byte(0x14, &raw);
    bool ico_optimized = raw & 0b01000000;
    ESP_LOGI(TAG, "ICO_OPTIMIZED: %s", ico_optimized ? "yes" : "no");
    this->set_bit_(0x09, 7, true);
    // ESP_LOGW(TAG, "Got batt=%.3fV current=%.0fmA supply=%.3fV", batt_voltage, charge_current, supply_voltage);
    this->pet_dog_();
    if (this->batt_voltage_sensor_ != nullptr) {
        float batt_voltage = this->get_battery_voltage_();
        this->batt_voltage_sensor_->publish_state(batt_voltage);
    }
    if (this->charge_current_sensor_ != nullptr) {
        int charge_current = this->get_charge_current_();
        this->charge_current_sensor_->publish_state(charge_current);
    }
    if (this->supply_voltage_sensor_ != nullptr) {
        float supply_voltage = this->get_supply_voltage_();
        this->supply_voltage_sensor_->publish_state(supply_voltage);
}

}
}