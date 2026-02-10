# 📚 42 Libft (2026 Edition)

![Language](https://img.shields.io/badge/Language-C-blue)
![School](https://img.shields.io/badge/School-42-black)
![Score](https://img.shields.io/badge/Score-125%2F100-success)

## 💡 About The Project
This repository contains my implementation of the **Libft** project, the very first project of the 42 School curriculum. The goal is to recreate essential C library functions from scratch to understand low-level memory management and algorithm design.

Unlike standard implementations, this repository includes a **Custom Ultimate Tester** designed to mimic **Moulinette's** strict grading criteria, covering specific edge cases that often cause failures.

## 🛠️ Features
* **Memory Manipulation:** `memset`, `memcpy`, `memmove` (handles overlap), etc.
* **String Manipulation:** `strlen`, `strlcpy`, `strnstr`, `split` (robust), etc.
* **Linked Lists:** Full bonus part implementation (`t_list`).
* **Strict Error Handling:** Defense against NULL pointers and segmentation faults.

## 🧪 The Ultimate Tester
I have developed a custom `main.c` tester included in this repo. It is designed to be **stricter than usual** to ensure stability.

### Key Test Scenarios:
* **Moulinette Traps:** specifically tests `ft_strlcat` return values and `ft_substr` allocations.
* **Edge Cases:** Handles empty strings, consecutive delimiters in `ft_split`, and sign handling in `ft_atoi`.
* **Visual Feedback:** Color-coded output (Green for PASS, Red for FAIL).

## 🚀 How to Run

### 1. Clone the Repository
```bash
git clone [https://github.com/YOUR_USERNAME/42-libft-ultimate.git](https://github.com/YOUR_USERNAME/42-libft-ultimate.git)
cd 42-libft-ultimate
