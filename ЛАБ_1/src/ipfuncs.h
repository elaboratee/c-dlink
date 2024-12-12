#ifndef IPFUNCS_H
#define IPFUNCS_H

void get_network_address(const short *ip, const short mask, short *network);
int is_private_ip(const short *ip, const short mask);
int is_broadcasting_ip(const short *ip, const short mask);
int is_in_network(const short *ip, const short mask, const short *network, const short network_mask);

#endif