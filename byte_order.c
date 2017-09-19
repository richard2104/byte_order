#include <stdint.h>
#include <stdio.h>

int main() {
  uint8_t buf[] = { 0x00, 0x50 };
  uint16_t* port = (uint16_t*)buf;
  printf("port number is 0x%x\n", *port);
  return 0;
}

