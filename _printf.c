#include <stdio.h>
#include "main.h"
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - like printf
 * Return: 0 always
 * @format: list
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (str)
				{
					write(1, str, strlen(str));
					count += strlen(str);
				}
				else
				{
					write(1, "(null)", 6);
					count += 6;
				}
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (*format == 'd' || *format == 'i' || *format == 'u' || *format == 'o' || *format == 'x' || *format == 'X')
			{
				int num = va_arg(args, int);
				char buffer[100];
				int len = sprintf(buffer, format, num);

				write(1, buffer, len);
				count += len;
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				count += 2;
			}
			format++;
		}

		va_end(args);

		return (count);
	}
	return (0);
}
