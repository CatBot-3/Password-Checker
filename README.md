# Password-Checker

The Password Game (C)
A small C program that validates passwords against a set of rules and provides an optional helper to construct a valid password from a plain word.

## Overview
A simplified version of “The Password Game,” validating candidate passwords against the following checks:

check_length: length ≥ 5

check_capital: contains at least one capital letter A–Z

check_num: contains at least one digit 0–9

check_symbol: contains at least one non-alphanumeric character

str_contains: substring search (no strstr; implement manually)

check_positivity: contains "(^_^)"

check_sum: sum of digits equals exactly 25

check_palindrome: palindrome ignoring non-alphanumerics and case

password_help(in_str, out_str): build a valid password containing in_str unmodified
