# add_nob
add_nob feat. gilgil Mentor

먼저 파일에 바이트를 파일에 저장합니다.
 - 파일에 쓰인 값 0x12345678 (4바이트, 빅 엔디안)

리틀 엔디안 시스템인 컴퓨터에서 프로그램을 실행하여 위의 파일을 읽으 해당 값들을 바이트 단위로 나누어서 리틀 엔디안 형식으로 메모리에 저장합니다.
 - 메모리에 쌓인 값 0x78563412 (4바이트, 리틀 엔디안)

과제에서는 바이너리 파일에 빅엔디안 방식으로 저장된 값을 byteswap을 하여 더한 후 출력하는게 목표입니다.

`uint32_t` 변수(32비트,4바이트)를 사용하였으므로 `ntohl()` 또는 `htonl()`를 사용하여 스왑했습니다. 만약 16비트(2바이트) 였다면 `ntohs()` 또는 `htons()`를 사용해야합니다.

그렇게 입력 받은 값을 위 함수를 사용하여 변환한 뒤 더하면 원하는 결과값을 출력할 수 있습니다.

`htonl()함수` 같은 경우는 4바이트를 호스트(리틀 엔디안)에서 네트워크(빅 엔디안)로 보낼때 사용되고,
`ntohl()함수` 는 네트워크(빅 엔디안)에서 호스트(리틀 엔디안)으로 받는다는것을 가정하면서 사용됩니다.

위의 함수들은 x86 아키텍처에서 제공하는 내장 함수 bswap_32를 사용하여 지원합니다.
bswap_32는 x86에서 특화된 함수로 이 명령어는 하드웨어 레벨에서의 바이트 스왑을 지원하므로 비트연산(shift , and, or)등을 사용하는 수동 스왑보다 훨씬 빠르게 실행됩니다.

과제에서는 주어진 파일의 값들을 byteswap을 하여 더하는것이 목표이므로, 프로그램에서는 네트워크나 호스트를 고려하지 않고 `htonl()`과 `ntohl()` 둘 중 아무거나 사용해도 상관 없습니다.



PS. `uint32_t` 변수의 특징은 정확히 32비트(4바이트)의 크기를 가지고, uint32_t는 부호 없이 양수값만 저장합니다.
Network Master gilgil 멘토님의 수업에서 int, long 자료형 대신 uint32_t와 같이 고정된 크기를 가진 변수를 사용하는 이유는 각 시스템에서 통일된 크기를 가졌고, 네트워크 프로그래밍 분야에서는 프로토콜에서 데이터의 크기가 명확해야 하므로 사용됩니다.
