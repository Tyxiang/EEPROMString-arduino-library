#include <Arduino.h>

class EEPROMString {
  public:
    EEPROMString(int start, int size, int qty);
    void save(int index, String value);
    String read(int index);
    void remove(int index);
    void begin();
  private:
    int _start;
    int _size;
    int _qty;
    int _eeprom_size;
};
