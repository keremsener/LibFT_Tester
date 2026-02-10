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
2. Compile and Run the TesterBashgcc -Wall -Wextra -Werror tester.c libft.a -o tester
./tester
You will see Green [OK] for passed tests and Red [FAIL] for errors.📋 Mandatory Functions ListAll functions below are required.Memory & StringLinked Lists (Mandatory)Additionalft_memsetft_lstnewft_substrft_bzeroft_lstadd_frontft_strjoinft_memcpyft_lstsizeft_strtrimft_memmoveft_lstlastft_splitft_memchrft_lstadd_backft_itoaft_memcmpft_lstdeloneft_strmapift_strlenft_lstclearft_striterift_strlcpyft_lstiterft_putchar_fdft_strlcatft_lstmapft_putstr_fdft_strchrft_putendl_fdft_strrchrft_putnbr_fdft_strnstrft_strncmpft_atoift_isalphaft_isdigitft_isalnumft_isasciift_isprintft_toupperft_tolowerft_callocft_strdup⚠️ DisclaimerThis tester is a local development tool. While it mimics common evaluation pitfalls, passing these tests does not guarantee a 100% score on the actual Moulinette. Always verify your logic manually.
