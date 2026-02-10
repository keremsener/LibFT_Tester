# 📚 42 Libft (2026 Curriculum - Full Mandatory)

![Language](https://img.shields.io/badge/Language-C-blue)
![School](https://img.shields.io/badge/School-42-black)
![System](https://img.shields.io/badge/LinkedLists-MANDATORY-red)

## 💡 About The Project
This is the complete implementation of the **Libft** project for the modern 42 curriculum.

**IMPORTANT:** In this version of the curriculum, **Linked Lists are MANDATORY**. There is no "bonus" section; every function listed below is required to pass.

## 🛠️ The Ultimate Tester (`tester.c`)
This repository includes a standalone `tester.c` file designed to stress-test your library against **Moulinette's** strict edge cases.

### It tests for:
* **Strict Memory Management:** Checks for leaks in `ft_split` and `ft_substr`.
* **Moulinette Traps:** Verifies specific return values for `ft_strlcat` and `ft_atoi` (sign handling).
* **Mandatory Linked Lists:** Verifies `ft_lst*` functions as core requirements.

## 🚀 How to Run

You only need the `tester.c` file and your library.

### 1. Compile your library
```bash
make
gcc -Wall -Wextra -Werror tester.c libft.a -o tester
./tester
Memory & String,Linked Lists (Mandatory),Additional
ft_memset,ft_lstnew,ft_substr
ft_bzero,ft_lstadd_front,ft_strjoin
ft_memcpy,ft_lstsize,ft_strtrim
ft_memmove,ft_lstlast,ft_split
ft_memchr,ft_lstadd_back,ft_itoa
ft_memcmp,ft_lstdelone,ft_strmapi
ft_strlen,ft_lstclear,ft_striteri
ft_strlcpy,ft_lstiter,ft_putchar_fd
ft_strlcat,ft_lstmap,ft_putstr_fd
ft_strchr,,ft_putendl_fd
ft_strrchr,,ft_putnbr_fd
ft_strnstr,,
ft_strncmp,,
ft_atoi,,
ft_isalpha,,
ft_isdigit,,
ft_isalnum,,
ft_isascii,,
ft_isprint,,
ft_toupper,,
ft_tolower,,
ft_calloc,,
ft_strdup,,
⚠️ Disclaimer
This tester is a local development tool. While it mimics common evaluation pitfalls, passing these tests does not guarantee a 100% score on the actual Moulinette. Always verify your logic manually.
