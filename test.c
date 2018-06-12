#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IP_LEN (4)

int parse_str_2_ip(char *str, unsigned char *buf)
{
    int i = 0;
    int len = 0;
    char *tmp;
    char local_buf[MAX_IP_LEN] = {0};
    int ret = 0;

    while(*str == ' ')
    {
        str++;
    }

    tmp = str;

    while (1)
    {
        if (*str == '\0')
        {
            len = str - tmp;
            strncpy(local_buf, tmp, len);
            ret = atoi(local_buf);
            buf[i] = ret;
            break;
        }

        if (*str == '.')
        {
            len = str - tmp;
            strncpy(local_buf, tmp, len);
            str++;
            tmp = str;
            ret = atoi(local_buf);
            buf[i] = ret;
            memset(local_buf, 0, 4);
            i++;
        }

        str++;
    }
 
    return 0;
}

void help(void)
{
    printf("usage:./test 192.168.0.199\r\n");
}

int main(int argc, char *argv[])
{
    int ret;
    unsigned char buf[MAX_IP_LEN] = {0};

    if (argc != 2)
    {
        help();
        return -1;
    }
    
    ret = parse_str_2_ip(argv[1], buf);
    if (ret != 0)
    {
        printf("convert ip failed.\r\n");
        return -1;
    }
    
    printf("%d.%d.%d.%d\r\n", buf[0], buf[1], buf[2], buf[3]);

    return 0;
}
