/**
 * SetPHSetPoint.h
 *
 * Set the target pH
 */
#pragma once
#include "NumberCollectorState.h"

class SetPHSetPoint : public NumCollectorState {
public:
  SetPHSetPoint(TankController* tc);
  const __FlashStringHelper* name() {
    return F("SetPHSetPoint");
  }
  float getCurrentValue();
  uint16_t getCurrentValuePrecision() {
    return precision[subState];
  }
  const __FlashStringHelper* prompt() {
    return prompts[subState];
  };
  void setValue(float value);

private:
  static const uint16_t NUM_VALUES = 2;
  uint16_t subState = 0;
  float values[NUM_VALUES] = {0, 0};
  const uint16_t precision[NUM_VALUES] = {3, 1};
  const __FlashStringHelper* prompts[NUM_VALUES];
};
