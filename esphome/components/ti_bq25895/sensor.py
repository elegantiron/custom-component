import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import (
    UNIT_VOLT,
    DEVICE_CLASS_VOLTAGE,
    DEVICE_CLASS_CURRENT,
    STATE_CLASS_MEASUREMENT
)
from . import (
    CONF_BQ25895_ID,
    TIBQ25895Component
)

DEPENDENCIES = ["ti_bq25895"]

CONF_BATT_VOLTAGE = "battery_voltage"
CONF_CHARGE_CURRENT = "charge_current"
CONF_SUPPLY_VOLTAGE = "supply_voltage"
CONF_IDPM_LIMIT = "idpm_limit"
UNIT_MILLIAMPERE = "mA"

TYPES = [
    CONF_BATT_VOLTAGE,
    CONF_CHARGE_CURRENT,
    CONF_SUPPLY_VOLTAGE,
    CONF_IDPM_LIMIT
]

CONFIG_SCHEMA = cv.All(
    cv.Schema(
        {
            cv.GenerateID(CONF_BQ25895_ID): cv.use_id(TIBQ25895Component),
            cv.Optional(CONF_BATT_VOLTAGE): sensor.sensor_schema(
                unit_of_measurement=UNIT_VOLT,
                accuracy_decimals=3,
                device_class=DEVICE_CLASS_VOLTAGE,
                state_class=STATE_CLASS_MEASUREMENT
            ),
            cv.Optional(CONF_CHARGE_CURRENT): sensor.sensor_schema(
                unit_of_measurement=UNIT_MILLIAMPERE,
                accuracy_decimals=0,
                device_class=DEVICE_CLASS_CURRENT,
                state_class=STATE_CLASS_MEASUREMENT
            ),
            cv.Optional(CONF_SUPPLY_VOLTAGE): sensor.sensor_schema(
                unit_of_measurement=UNIT_VOLT,
                accuracy_decimals=1,
                device_class=DEVICE_CLASS_VOLTAGE,
                state_class=STATE_CLASS_MEASUREMENT
            ),
            cv.Optional(CONF_IDPM_LIMIT): sensor.sensor_schema(
                unit_of_measurement=UNIT_MILLIAMPERE,
                accuracy_decimals=0,
                device_class=DEVICE_CLASS_CURRENT,
                state_class=STATE_CLASS_MEASUREMENT
            )
        }
    )
    .extend(cv.polling_component_schema("60s"))
)

async def setup_conf(config, key, hub):
    if sensor_config := config.get(key):
        sens = await sensor.new_sensor(sensor_config)
        cg.add(getattr(hub, f"set_{key}_sensor")(sens))


async def to_code(config):
    hub = await cg.get_variable(config[CONF_BQ25895_ID])
    for key in TYPES:
        await setup_conf(config, key, hub)