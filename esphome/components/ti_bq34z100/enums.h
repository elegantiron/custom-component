#pragma once

#include "esphome/components/i2c/i2c.h"

enum bq34z100ControlCommand : uint8_t {
    get_status = 0x00,
    get_device_type = 0x01,
    get_fw_version = 0x02,
    get_hw_version = 0x03,
    get_reset_data = 0x05,
    get_prev_macwrite = 0x07,
    get_chem_id = 0x08,
    measure_board_offset = 0x09,
    measure_cc_offset = 0x0A,
    save_cc_offset = 0x0B,
    get_df_version = 0x0C,
    set_fullsleep = 0x10,
    calculate_chem_checksum = 0x17,
    set_sealed = 0x20,
    enable_impedance_track = 0x21,
    toggle_calibration_mode = 0x2D,
    full_reset = 0x41,
    exit_calibration_mode = 0x80,
    enter_calibration_mode = 0x81,
    report_cc_offset = 0x82
};