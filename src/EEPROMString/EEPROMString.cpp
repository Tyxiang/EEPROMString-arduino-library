#include <EEPROMString.h>
#include <EEPROM.h>

EEPROMString::EEPROMString(int start, int size, int qty) { 
    _start = start;
    _size = size;
    _qty = qty;
}

void EEPROMString::begin() {
    _eeprom_size = _size * _qty;
    EEPROM.begin(_eeprom_size);
}

void EEPROMString::save(int index, String value) {
    int start = _start + _size * index;
    for (int i=0; i<_size; i++) {
        EEPROM.write(start + i, 0);
    }
    for (int i=0; i<value.length(); i++) {
        EEPROM.write(start + i, value[i]);
    }
    if (EEPROM.commit()) {
      Serial.print("save successfully ");
    } else {
      Serial.print("save failed ");
    }
}

String EEPROMString::read(int index) {
    int start = _start + _size * index;
    char value[_size];
    for (int i=0; i<_size; i++) {
        value[i] = EEPROM.read(start + i);
    }
    return String(value);
}

void EEPROMString::remove(int index) {
    int start = _start + _size * index;
    for (int i=0; i<_size; i++) {
        EEPROM.write(start + i, 0);
    }
    if (EEPROM.commit()) {
      Serial.print("remove successfully ");
    } else {
      Serial.print("remove failed ");
    }
}