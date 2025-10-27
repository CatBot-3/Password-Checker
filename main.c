#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

const int MAX_PW_LEN = 100;
const int MAX_HELP_LEN = 30;

// check_length(str) returns  true if str has at least the minimum length
//   required for a valid password, and false otherwise.
// requires: str is a valid string
bool check_length(const char *str) {
	// TODO: your implementation here
	assert(str);
	int min_len = 5;
	int len = strlen (str);
	if (len < min_len) {
		return false;
	}
	else return true;
}


// check_capital(str) returns  true if str contains at least one capital
//   letter, and false otherwise.
// requires: str is a valid string
bool check_capital(const char *str) {
	// TODO: your implementation here
	assert (str);
	int len = strlen (str);
	for (int i = 0; i < len; ++i) {
		if ((*(str + i) >= 'A') && (*(str + i) <= 'Z')) {
			return true;
		}
	}
	return false;
}


// check_num(str) returns true if str contains at least one number,
//   and false otherwise.
// requires: str is a valid string
bool check_num(const char *str) {
	// TODO: your implementation here
	assert (str);
	int len = strlen(str);
	for (int i = 0; i < len; ++i) {
		if ((*(str + i) >= '0') && (*(str + i) <= '9')) {
			return true;
		}
	}
	return false;
}


// check_symbol(str) returns  true if str contains at least one,
//   non-alphanumeric character, and false otherwise.
// requires: str is a valid string
bool check_symbol(const char *str) {
	// TODO: your implementation here
	assert (str);
	int len = strlen(str);
	for (int i = 0; i < len; ++i) {
		if (!(((*(str + i) >= '0') && (*(str + i) <= '9')) ||
			((*(str + i) >= 'a') && (*(str + i) <= 'z')) ||
			((*(str + i) >= 'A') && (*(str + i) <= 'Z')))) {
			return true;
		}
	}
	return false;
}


// str_contains(str, fragment) returns true if str contains the sequence
//   given by fragment, and false otherwise.
// requires: str is a valid string
//           fragment is a valid string
bool str_contains(const char *str, const char *fragment) {
	// TODO: your implementation here
	assert(str);
	int frag_len = strlen(fragment);
	int str_len = strlen(str);
	int counter = 0;
	for (int i = 0; i < str_len; ++i) {
		if (*(str + i) == *(fragment + counter)) {
			++counter; //compare next char
		} else counter = 0; //re-initialize for recompare
		if (counter == frag_len - 1) { // all contains
			return true;
		}
	}
	return false;
}


// check_positivity(str) returns true if str contains the sequence "(^_^)",
//   and false otherwise.
// requires: str is a valid string
bool check_positivity(const char *str) {
	// TODO: your implementation here
	assert(str);
	const char smile[] = "(^_^)"; // (.'w'.)
	bool positive_check = str_contains (str, smile);
	return positive_check;
}


// check_sum(str) returns true if all digits in str have a valid sum,
//   and false otherwise.
// requires: str is a valid string
bool check_sum(const char *str) {
	// TODO: your implementation here
	assert(str);
	int target_sum = 25; // our target is 25
	int sum = 0; // initialize
	int len = strlen(str);
	for (int i = 0; i < len; ++i) {
		if ((*(str + i) >= '0') && (*(str + i) <= '9')) { // a char number
			sum += *(str + i) - '0'; // sum up all numerical digits
		}
	}
	return (target_sum == sum);
}


// check_palindrome(str) returns  true if str is a palindrome,
//   and false otherwise.
// requires: str is a valid string
bool check_palindrome(const char *str) {
    int str_len = strlen(str);
    int left = 0;
    int right = str_len - 1;
    char left_char = 0;
    char right_char = 0;
    while (left < right) {
        while (left < right && !((str[left] >= 'a' && str[left] <= 'z') ||
                                 (str[left] >= 'A' && str[left] <= 'Z') ||
                                 (str[left] >= '0' && str[left] <= '9'))) {
            ++left;
        }
        while (left < right && !((str[right] >= 'a' && str[right] <= 'z') ||
                                 (str[right] >= 'A' && str[right] <= 'Z') ||
                                 (str[right] >= '0' && str[right] <= '9'))) {
            --right;
        } // Skip non-alphanumeric characters
        
        if (str[left] >= 'A' && str[left] <= 'Z') {
            left_char = str[left] - 'A' + 'a';
        } else {
            left_char = str[left];
        }
        if (str[right] >= 'A' && str[right] <= 'Z') {
            right_char = str[right] - 'A' + 'a';
        } else {
            right_char = str[right];
        } // Convert uppercase letters to lowercase
        
        if (left_char != right_char) { // Compare characters
            return false;
        }
        ++left;
        --right;
    }
    
    return true;
}

// password_reverse(str) reverses the string str
// requires: str is not NULL
// effects: might mutate *str
void password_reverse (char *str) {
	assert(str);
	int len = strlen(str);
	char temp = 0;
	for (int i = 0; i < len / 2; ++i) {
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

// password_help(in_str, out_str) stores in out_str a valid password
//   containing the sequence in_str
// requires: in_str is a valid string
//           out_str points to a valid char[]
//           in_str contains only letter characters (not asserted)
// effects: mutates the char[] pointed to by out_str
void password_help(const char *in_str, char *out_str) {
	// TODO: your implementation here
	assert (in_str);
	assert (out_str);
	assert (strlen(in_str) <= MAX_HELP_LEN);
	strcpy(out_str, in_str);
	char magic_str[] = "A979A(^_^)";
	strcat(out_str, magic_str);

	char temp_str[31];
	strcpy(temp_str, in_str);
	password_reverse(temp_str);
	strcat(out_str, temp_str); // reverse the password and concat it to the end
}


// test_str(result) produces a string to be printed for a boolean test result
char* test_str(const bool result) {
	if(result) {
		return "Passed";
	} else {
		return "Failed";
	}
}


int main(void) {
	char pw[101];
	char help_str[31];
	char command = '\0';

	// read in commands
	while (scanf(" %c", &command) == 1) {
		if (command == 'c') {
			if (scanf("%100s", pw) == 1) {
				printf("Testing candidate password: %s\n", pw);
				printf("Length check: %s\n", test_str(check_length(pw)));
				printf("Capital check: %s\n", test_str(check_capital(pw)));
				printf("Number check: %s\n", test_str(check_num(pw)));
				printf("Symbol check: %s\n", test_str(check_symbol(pw)));
				printf("Digit sum check: %s\n", test_str(check_sum(pw)));
				printf("Positivity check: %s\n",
				       test_str(check_positivity(pw)));
				printf("Palindrome check: %s\n",
				       test_str(check_palindrome(pw)));
			} else {
				printf("Failed to read string.\n");
				return 0;
			}
		} else if (command == 'h') {
			if (scanf("%30s", help_str) == 1) {
				printf("Word to convert to password: %s\n", help_str);
				password_help(help_str, pw);
				printf("Resulting password: %s\n", pw);
			} else {
				printf("Failed to read string.\n");
				return 0;
			}
		} else {
			printf("Exiting.\n");
			return 0;
		}
	}
}
