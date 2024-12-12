#include <stdio.h>

void get_network_address(const short *ip, const short mask, short *network)
{
    for (int i = 0; i < (mask / 8); i++)
    {
        network[i] = ip[i] & 255;
    }
    if (mask % 8 != 0)
    {
        network[mask / 8] = ip[mask / 8] & (unsigned char)(255 << (8 - (mask % 8)));
    }
}

int is_private_ip(const short *ip, const short mask)
{
    if (mask == 8 | mask == 10 | mask == 12 | mask == 16)
    {
        // Получаем IP-адрес сети
        short network[4];
        get_network_address(ip, mask, network);

        // Определяем, является ли IP-адрес частным
        int is_private = 0;
        switch (mask)
        {
            case 8:
                if (network[0] == 10) is_private = 1;
                break;
            
            case 10:
                if (network[0] == 100 & network[1] == 64) is_private = 1;
                break;

            case 12:
                if (network[0] == 172 & network[1] == 16) is_private = 1;
                break;

            case 16:
                if (network[0] == 192 & network[1] == 168) is_private = 1;
                break;
        }
        return is_private;
    }
    return 0;
}

int is_broadcasting_ip(const short *ip, const short mask)
{
    // Инвертированная маска для переданного IP
    short inverted_mask[4] = {0, 0, 0, 0};

    // Формируем инвертированную маску подсети
    if (mask % 8 == 0)
    {
        for (int i = 0; i <= (4 - mask / 8); i++)
        {
            inverted_mask[4 - i] = 255;
        }
    }
    else
    {
        for (int i = 0; i <= (4 - mask / 8); i++)
        {
            if (i == (4 - mask / 8))
            {
                inverted_mask[4 - i] = (unsigned char)(~(255 << (8 - mask % 8)));
            }
            else
            {
                inverted_mask[4 - i] = 255;
            }
        }
    }

    // Проверяем, является ли IP-адрес широковещательным
    for (int i = 0; i < 4; i++)
    {
        if (ip[i] != (inverted_mask[i] | ip[i]))
        {
            return 0;
        }
    }

    return 1;
}

int is_in_network(const short *ip, const short mask, const short *network, const short network_mask)
{
    if (mask != network_mask) return 0;

    short ip_network[4] = {0, 0, 0, 0};
    get_network_address(ip, mask, ip_network);

    for (int i = 0; i < 4; i++)
    {
        if (ip_network[i] != network[i]) return 0;
    }

    return 1;
}