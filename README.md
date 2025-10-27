# Password-Checker

The Password Game (C)
A small C program that validates passwords against a set of rules and provides an optional helper to construct a valid password from a plain word.

#Overview
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


An interactive test harness (in main.c) lets you:

Enter c to test a candidate password,
Enter h to generate a valid password from a plain word,
Enter e to exit.
Constraints and Rules
Allowed string.h functions: strlen, strcmp, strcpy, strcat only (as per Section 5 materials).
Input assumptions for all predicates:
Password strings are valid, null-terminated C strings with no whitespace.
Palindrome rule ignores:
Non-alphanumeric characters
Letter casing (case-insensitive comparison)
password_help:
in_str: alphabetic only (A–Z, a–z), length ≤ 30 (excluding null)
out_str: points to a buffer large enough for the result (assume ~100 chars)
Must include in_str as an uninterrupted substring (unchanged), and overall satisfy all checks
Must not mutate in_str
ASCII-only (no Unicode)



#Set I/O Command Guide:
======================

##SYNTAX:
------

<set id> - An integer between 0 and 1, which specifies a Set

<number> - A single integer number

<list of numbers> - A list of integer numbers

<capacity> - A single integer number


##COMMANDS:
--------

n <set id> <capacity>
Calls set_create with the specified Set and capacity

d <set id>
Calls set_destroy with the specified Set

a <set id> <number>
Calls set_add on the specified Set with the <number>

A <set id> <list of numbers> end
Adds each number in a list of numbers into a set in any order

m <set id> <number>
Calls set_is_member on the specified Set with the <number>

r <set id> <number>
Removes the <number> from the specified Set with the set_remove function

l <set id>
Calls set_length on the specified Set

u <set id> <set id>
Calls set_union with the two specified Sets

i <set id> <set id>
Calls set_intersect with the two specified sets

s <set id> <set id>
Calls set_is_subset with the two specified sets

e <set id> <set id>
Calls set_difference with the two specified sets

p <set id>
Prints the specified set

q
quits the program
