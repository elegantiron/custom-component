import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import core
from esphome.components import i2c, sensor
from esphome.const import (
    CONF_ID,
    CONF_ADDRESS
)

CODEOWNERS = ["@SmüB_Design"]
DEPENDENCIES = ["i2c"]
AUTO_LOAD = ["sensor", "text_sensor"]

CONF_BQ25895_ID = "ti_bq25895_id"
CONF_WATCHDOG_TIMER = "watchdog_timer"
CONF_CHARGE_VOLTAGE_LIMIT = "charge_voltage_limit"
CONF_VINDPM_FORCE = "vindpm_force"
CONF_AUTO_DPDM_ENABLE = "auto_dpdm_enable"
CONF_SYSTEM_MINIMUM_VOLTAGE = "system_minimum_voltage"
CONF_VINDPM_VOLTAGE = "vindpm_voltage"
CONF_CONTINUOUS_CONVERSION = "continuous_conversion"
CONF_USE_ILIM_PIN = "use_ilim_pin"
CONF_ILIM_CURRENT = "ilim_current"
CONF_ICO_ENABLED = "ico_enabled"
CONF_SWITCH_FREQUENCY = "high_freq_enabled"

ti_bq25895_ns = cg.esphome_ns.namespace("ti_bq25895")

ti_bq25895WatchdogTimer = ti_bq25895_ns.enum("ti_bq25895WatchdogTimer")
WATCHDOG_TIMER_OPTIONS = {
    "40S": ti_bq25895WatchdogTimer.WATCHDOG_TIMER_40S,
    "80S": ti_bq25895WatchdogTimer.WATCHDOG_TIMER_80S,
    "160S": ti_bq25895WatchdogTimer.WATCHDOG_TIMER_160S,
    "OFF": ti_bq25895WatchdogTimer.WATCHDOG_TIMER_OFF
}

ti_bq25895ChargeVoltageLimit = ti_bq25895_ns.enum("ti_bq25895ChargeVoltageLimit")
CHARGE_VOLTAGE_LIMIT = {
    "3840V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_3840,
    "3856V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_3856,
    "3872V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_3872,
    "3888V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_3888,
    "3904V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_3904,
    "3920V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_3920,
    "3936V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_3936,
    "3952V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_3952,
    "3968V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_3968,
    "3984V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_3984,
    "4000V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4000,
    "4016V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4016,
    "4032V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4032,
    "4048V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4048,
    "4064V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4064,
    "4080V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4080,
    "4096V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4096,
    "4112V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4112,
    "4128V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4128,
    "4144V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4144,
    "4160V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4160,
    "4176V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4176,
    "4192V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4192,
    "4208V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4208,
    "4224V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4224,
    "4240V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4240,
    "4256V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4256,
    "4272V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4272,
    "4288V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4288,
    "4304V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4304,
    "4320V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4320,
    "4336V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4336,
    "4352V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4352,
    "4368V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4368,
    "4384V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4384,
    "4400V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4400,
    "4416V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4416,
    "4432V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4432,
    "4448V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4448,
    "4464V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4464,
    "4480V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4480,
    "4496V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4496,
    "4512V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4512,
    "4528V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4528,
    "4544V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4544,
    "4560V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4560,
    "4576V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4576,
    "4592V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4592,
    "4608V": ti_bq25895ChargeVoltageLimit.VOLTAGE_LIMIT_4608
}

ti_bq25895SystemMinimumVoltage = ti_bq25895_ns.enum("ti_bq25895SystemMinimumVoltage")
SYSTEM_MINIMUM_VOLTAGE = {
    "3.0V": ti_bq25895SystemMinimumVoltage.SYSTEM_MINIMUM_30,
    "3.1V": ti_bq25895SystemMinimumVoltage.SYSTEM_MINIMUM_31,
    "3.2V": ti_bq25895SystemMinimumVoltage.SYSTEM_MINIMUM_32,
    "3.3V": ti_bq25895SystemMinimumVoltage.SYSTEM_MINIMUM_33,
    "3.4V": ti_bq25895SystemMinimumVoltage.SYSTEM_MINIMUM_34,
    "3.5V": ti_bq25895SystemMinimumVoltage.SYSTEM_MINIMUM_35,
    "3.6V": ti_bq25895SystemMinimumVoltage.SYSTEM_MINIMUM_36,
    "3.7V": ti_bq25895SystemMinimumVoltage.SYSTEM_MINIMUM_37
}

ti_bq25895VinDPMVoltage = ti_bq25895_ns.enum("ti_bq25895VinDPMVoltage")
DYNAMIC_POWER_VOLTAGE_MINIMUM = {
    "3.9V": ti_bq25895VinDPMVoltage.VINDPM_VOLTAGE_3900,
    "4.0V": ti_bq25895VinDPMVoltage.VINDPM_VOLTAGE_4000,
    "4.1V": ti_bq25895VinDPMVoltage.VINDPM_VOLTAGE_4100,
    "4.2V": ti_bq25895VinDPMVoltage.VINDPM_VOLTAGE_4200,
    "4.3V": ti_bq25895VinDPMVoltage.VINDPM_VOLTAGE_4300,
    "4.4V": ti_bq25895VinDPMVoltage.VINDPM_VOLTAGE_4400,
    "4.5V": ti_bq25895VinDPMVoltage.VINDPM_VOLTAGE_4500,
    "4.6V": ti_bq25895VinDPMVoltage.VINDPM_VOLTAGE_4600,
    "4.7V": ti_bq25895VinDPMVoltage.VINDPM_VOLTAGE_4700,
    "4.8V": ti_bq25895VinDPMVoltage.VINDPM_VOLTAGE_4800,
    "4.9V": ti_bq25895VinDPMVoltage.VINDPM_VOLTAGE_4900,
    "5.0V": ti_bq25895VinDPMVoltage.VINDPM_VOLTAGE_5000,
    "5.1V": ti_bq25895VinDPMVoltage.VINDPM_VOLTAGE_5100,
    "5.2V": ti_bq25895VinDPMVoltage.VINDPM_VOLTAGE_5200,
}

ti_bq25895InputCurrentLimit = ti_bq25895_ns.enum("ti_bq25895InputCurrentLimit")
INPUT_CURRENT_LIMIT = {
    "0.1A":  ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0100,
    "0.15A": ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0150,
    "0.2A":  ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0200,
    "0.25A": ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0250,
    "0.3A":  ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0300,
    "0.35A": ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0350,
    "0.4A":  ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0400,
    "0.45A": ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0450,
    "0.5A":  ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0500,
    "0.55A": ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0550,
    "0.6A":  ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0600,
    "0.65A": ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0650,
    "0.7A":  ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0700,
    "0.75A": ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0750,
    "O.8A":  ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0800,
    "0.85A": ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0850,
    "0.9A":  ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0900,
    "0.95A": ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_0950,
    "1A":    ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_1000,
    "1.05A": ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_1050,
    "1.1A":  ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_1100,
    "1.15A": ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_1150,
    "1.2A":  ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_1200,
    "5A":    ti_bq25895InputCurrentLimit.INPUT_CURRENT_LIMIT_5000,
}
TIBQ25895Component = ti_bq25895_ns.class_(
    "TIBQ25895Component", cg.PollingComponent, i2c.I2CDevice
)

CONFIG_SCHEMA = cv.All(
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(TIBQ25895Component),
            cv.Optional(CONF_ICO_ENABLED, default="enable"): cv.boolean,
            cv.Optional(CONF_SWITCH_FREQUENCY, default="disable"): cv.boolean,
            cv.Optional(CONF_WATCHDOG_TIMER, default="80s"): cv.enum(
                WATCHDOG_TIMER_OPTIONS, upper=True
            ),
            cv.Optional(CONF_CHARGE_VOLTAGE_LIMIT, default="4208v"): cv.enum(
                CHARGE_VOLTAGE_LIMIT, upper=True
            ),
            cv.Optional(CONF_VINDPM_FORCE, default = "disable"): cv.boolean,
            cv.Optional(CONF_AUTO_DPDM_ENABLE, default = "disable"): cv.boolean,
            cv.Optional(CONF_SYSTEM_MINIMUM_VOLTAGE, default = "3.6v"): cv.enum(
                SYSTEM_MINIMUM_VOLTAGE, upper=True
            ),
            cv.Optional(CONF_VINDPM_VOLTAGE, default = "4.4v"): cv.enum(
                DYNAMIC_POWER_VOLTAGE_MINIMUM, upper=True
            ),
            cv.Optional(CONF_CONTINUOUS_CONVERSION, default = "enable"): cv.boolean,
            cv.Optional(CONF_USE_ILIM_PIN, default = "no"): cv.boolean,
            cv.Optional(CONF_ILIM_CURRENT, default = "5a"): cv.enum(
                INPUT_CURRENT_LIMIT, upper=True
            )
           
        }
    )
    .extend(cv.polling_component_schema("60s"))
    .extend(i2c.i2c_device_schema(0x6A)),
)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await i2c.register_i2c_device(var, config)

    cg.add(var.set_device_id(str(config[CONF_ID])))
    cg.add(var.set_watchdog_time(config[CONF_WATCHDOG_TIMER]))
    cg.add(var.set_input_current_limit(config[CONF_ILIM_CURRENT]))
    cg.add(var.set_charge_voltage_limit(config[CONF_CHARGE_VOLTAGE_LIMIT]))
    cg.add(var.set_system_minimum_voltage(config[CONF_SYSTEM_MINIMUM_VOLTAGE]))
    cg.add(var.set_vindpm_voltage(config[CONF_VINDPM_VOLTAGE]))
    cg.add(var.set_vindpm(config[CONF_VINDPM_FORCE]))
    cg.add(var.set_continuous_conversion(config[CONF_CONTINUOUS_CONVERSION]))
    cg.add(var.set_input_current_pin_enabled(config[CONF_USE_ILIM_PIN]))
    cg.add(var.set_auto_dpm_enabled(config[CONF_AUTO_DPDM_ENABLE]))
    cg.add(var.set_ico_enabled(config[CONFIG_ICO_ENABLED]))
    cg.add(var.set_switch_frequency(config[CONFIG_SWITCH_FREQUENCY]))
    
    
