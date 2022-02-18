# ft_printf
printf in c 구현

## format specifier

### format specifier 사용 가능한 option
* char c   
'-': O, '0': X, '.': X, '#': X, ' ': X, '+': X, width: O

* string s   
'-': O, '0': X, '.': O, '#': X, ' ': X, '+': X, width: O

* address p   
'-': O, '0': X, '.': X, '#': X, ' ': X, '+': X, width: O

* integer d,i   
'-': O, '0': O, '.': O, '#': X, ' ': O, '+': O, width: O

* unsigned decimal u   
'-': O, '0': O, '.': O, '#': X, ' ': X, '+': X, width: O

* hexadecimal with lowercase x   
'-': O, '0': O, '.': O, '#': O, ' ': X, '+': X, width: O

* hexadecimal with uppercase X   
'-': O, '0': O, '.': O, '#': O, ' ': X, '+': X, width: O

* percent sign %   
'-': O, '0': O, '.': X, '#': X, ' ': X, '+': X, width: O