int my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int written = 0;
    const char *p = format;

    while (*p)
    {
        if (*p == '%')
        {
            switch (*(++p))
            {
                case 'c':
                    written += printf("%c", va_arg(args, int));
                    break;

                case 's':
                    written += printf("%s", va_arg(args, char *));
                    break;

                case '%':
                    written += printf("%%");
                    break;

                case 'd':
                    written += printf("%d", va_arg(args, int));
                    break;

                case 'b':
                    {
                        int n = va_arg(args, int);
                        char binary[33];
                        binary[32] = '\0';
                        for (int i = 31; i >= 0; i--)
                        {
                            binary[i] = (n & 1) ? '1' : '0';
                            n >>= 1;
                        }
                        written += printf("%s", binary);
                    }
                    break;

                default:
                    written += printf("%%%c", *p);
                    break;
            }
        }
        else
        {
            putchar(*p);
            written++;
        }

        p++;
    }

    va_end(args);
    return written;
}
