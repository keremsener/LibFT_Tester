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

⚠️ Disclaimer
This tester is a local development tool. While it mimics common evaluation pitfalls, passing these tests does not guarantee a 100% score on the actual Moulinette. Always verify your logic manually.

Developed by Kerem Şener at 42 Kocaeli.

### 1. Compile & Run
```bash
make
gcc -Wall -Wextra -Werror tester.c libft.a -o tester
./tester
You will see Green [OK] for passed tests and Red [FAIL] for errors.

📋 Mandatory Functions List
Plaintext
[Memory & String]
ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp, ft_strlen, ft_strlcpy, ft_strlcat, ft_strchr, ft_strrchr, ft_strnstr, ft_strncmp, ft_atoi, ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint, ft_toupper, ft_tolower, ft_calloc, ft_strdup

[Linked Lists (MANDATORY)]
ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap

[Additional]
ft_substr, ft_strjoin, ft_strtrim, ft_split, ft_itoa, ft_strmapi, ft_striteri, ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd
