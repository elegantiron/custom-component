#include "bq34z100.h"
#include "enums.h"

namespace esphome {
namespace bq34z100 {

void BQ34Z100Component::send_control_command_(bq34z100ControlCommand command) {
    this->write_byte(0x00, 0x00);
    this->write_byte(0x01, command);

}

void BQ34Z100Component::read_control_data_() {
    data_read_[0] = this->read_byte(0x00);
    data_read_[1] = this->read_byte(0x01);
}
}
}