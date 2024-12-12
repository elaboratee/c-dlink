#include <stdio.h>
#include "ipdata.h"
#include "ipfuncs.h"

int get_ip_address(short *octets, short *mask)
{
    printf("Enter an IP-address and a mask (in X.X.X.X/Y format): ");

    // Ввод IP-адреса и маски и проверка соответствия формату
    if (scanf("%hd.%hd.%hd.%hd/%hd",
            &octets[0], &octets[1], &octets[2], &octets[3], mask) != 5)
    {
        printf("Incorrect input format!\n");
        for (int i = 0; i < 4; i++) octets[i] = 0;
        *mask = 0;
        return -1;
    }

    // Проверка корректности маски
    if (*mask < 0 || *mask > 30)
    {
        printf("Mask must be in range from 0 to 30!\n");
        for (int i = 0; i < 4; i++) octets[i] = 0;
        *mask = 0;
        return -1;
    }

    // Проверка корректности октетов
    for (int i = 0; i < 4; i++)
    {
        if (octets[i] < 0 || octets[i] > 255)
        {
            printf("Octets must be in range from 0 to 255!\n");
            for (int i = 0; i < 4; i++) octets[i] = 0;
            *mask = 0;
            return -1;
        }
    }

    return 0;
}

int main(void)
{
    // Ввод исходных IP-адреса и маски
    if (get_ip_address(ip, &mask) == -1)
    {
        return -1;
    }

    // Получение IP-адреса сети
    short network[4] = {0, 0, 0, 0};
    get_network_address(ip, mask, network);
    printf("\nNetwork IP-address: %hd.%hd.%hd.%hd\n",
        network[0], network[1], network[2], network[3]);

    // Проверка, является ли IP-адрес частным
    printf("\nIs private IP-address: %s\n", (is_private_ip(ip, mask)) ? "Yes" : "No");

    // Проверка, является ли IP-адрес широковещательным
    printf("Is broadcasting IP-address: %s\n", (is_broadcasting_ip(ip, mask)) ? "Yes" : "No");

    // Проверка принадлежности IP-адреса к заданным сетям
    if (is_in_network(ip, mask, NETWORK_1, MASK_1))
    {
        printf("\nIP-address is in NETWORK_1 (%hu.%hu.%hu.%hu/%hu)\n",
            NETWORK_1[0], NETWORK_1[1], NETWORK_1[2], NETWORK_1[3], MASK_1);
    }
    else if (is_in_network(ip, mask, NETWORK_2, MASK_2))
    {
        printf("\nIP-address is in NETWORK_2 (%hu.%hu.%hu.%hu/%hu)\n",
            NETWORK_2[0], NETWORK_2[1], NETWORK_2[2], NETWORK_2[3], MASK_2);
    }
    else if (is_in_network(ip, mask, NETWORK_3, MASK_3))
    {
        printf("\nIP-address is in NETWORK_3 (%hu.%hu.%hu.%hu/%hu)\n",
            NETWORK_3[0], NETWORK_3[1], NETWORK_3[2], NETWORK_3[3], MASK_3);
    }
    else if (is_in_network(ip, mask, NETWORK_4, MASK_4))
    {
        printf("\nIP-address is in NETWORK_4 (%hu.%hu.%hu.%hu/%hu)\n",
            NETWORK_4[0], NETWORK_4[1], NETWORK_4[2], NETWORK_4[3], MASK_4);
    }

    return 0;
}
