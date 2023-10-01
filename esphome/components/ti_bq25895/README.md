# TI BQ25895 Li-Ion Battery Management IC
A compontent for configuring and tracking a BQ25895 IC. If you reduce the watchdog timer to 40s, be sure you also set the component to update fast enough to catch it. 

All sensors are optional.


## Example YAML
```yaml
ti_bq25895:
  id: bq25895_charger
  address: 0x6A
  watchdog_timer: 80s
  charge_voltage_limit: 4208v
  vindpm_force: no
  auto_dpdm_enable: no
  system_minimum_voltage: 3.6v
  vindpm_voltage: 4.4v
  continuous_conversion: yes
  use_ilim_pin: no
  ilim_current: 5A
  ico_enabled: yes

sensor:
    - platform: ti_bq25895
      battery_voltage:
        id: batt_voltage
        name: Battery Voltage
      charge_current:
        id: batt_current
        name: Charge Current
      supply_voltage:
        id: supp_voltage
        name: Supply Voltage
      idpm_limit:
        id: idpm_lim
        name: IDPM Limit
```