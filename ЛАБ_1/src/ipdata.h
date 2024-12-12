#ifndef IPDATA_H
#define IPDATA_H

// Внешнее связывание с константами предоставленных сетей
extern const short NETWORK_1[4];
extern const short MASK_1;

extern const short NETWORK_2[4];
extern const short MASK_2;

extern const short NETWORK_3[4];
extern const short MASK_3;

extern const short NETWORK_4[4];
extern const short MASK_4;

// Внешнее связывание переменных для хранения введенного IP-адреса и маски
extern short ip[4];
extern short mask;

#endif
