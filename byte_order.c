#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

int main() {
  uint8_t buf[] = { 0x01, 0x50 }; // Little Endian: 0x5001, Big Endian: 0x0150
  uint16_t host_byte = 0x3412; // 0x3412

  uint16_t* port = (uint16_t*)buf;
  
  printf( "%x to %x\n", host_byte, ntohs(host_byte));
  printf("port number is 0x%x\n", *port); //0x5000
  printf("(function) port number: 0x%x\n", ntohs(*port)); //0x5000
  return 0;
}

