#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"
#include "esphome/core/preferences.h"
#include "esphome/core/defines.h"
#include "enums.h"
#include <cstdint>

namespace esphome {
namespace bq34z100 {

class BQ34Z100Component : public PollingComponent, public i2c::I2CDevice {
    public:

    protected:
        void get_state_of_charge_();
        void get_remaining_capacity_();
        void get_full_charge_capacity_();
        void get_voltage_();
        void get_average_current_();
        void get_flags_();
        void get_flags_b_();

        void send_control_command_(bq34z100ControlCommand command);
        void read_control_data_();


        optional<uint8_t> data_read_[2];

        uint16_t state_of_charge_,
                 remaining_capacity_,
                 full_charge_capacity,
                 voltage_,
                 average_current_,
                 flags_,
                 flags_b_;

};



}
}