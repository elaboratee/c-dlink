// Определение предоставленных сетей
const short NETWORK_1[4] = {192, 168, 10, 0};
const short MASK_1 = 24;

const short NETWORK_2[4] = {192, 168, 160, 0};
const short MASK_2 = 19;

const short NETWORK_3[4] = {141, 127, 0, 0};
const short MASK_3 = 16;

const short NETWORK_4[4] = {195, 0, 172, 0};
const short MASK_4 = 22;

// Заготовка для хранения введенного IP-адреса и маски
short ip[4] = {0, 0, 0, 0};
short mask = 0;