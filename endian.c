#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>

// port에 0x1234로 나오게 하고 싶은대ㅠ 어케 함?
uint16_t reverse16(uint16_t n) {
	uint16_t low = n & 0x00ff; // 뒤에 두개만 남아 0x12
	uint16_t high = n & 0xff00; // 앞에 두개만 남아 0x3400
	uint16_t resol = (low << 8) | (high >> 8); //하위뽑아서 왼쪽으로 밀고, 상위뽑아서 오른쪽으로 밀어
	return resol;
}

uint32_t reverse32(uint32_t n) {
	return
		((n & 0x000000ff) << 24) |
		((n & 0x0000ff00) << 8) |
		((n & 0x00ff0000) >> 8) |
		((n & 0xff000000) >> 24);
}

int main() {
	uint8_t packet[] = { 0x12,0x34 }; // 메모리상 이렇게 저장될 듯
									  //바이트 단위의 0x1234이 있는데 포인터가 가리킴
	uint16_t *p = (uint16_t *)packet;
	uint16_t type = *p; //0x3412로 들어가있어
	//메모리 상 0800이 있고 *p 이게 가리키고 port에 이걸 저장

	printf("type = %x\n", type);
	printf("After Reverse\n");
	printf("type = %x\n", reverse16(type));


	return 0;
}

