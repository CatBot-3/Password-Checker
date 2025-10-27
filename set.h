// set.h [INTERFACE]
// A set ADT module

#include <stdbool.h>

struct Set {
  int *data;   // dynamically allocated array for set members
  int len;     // number of elements currently in the set
  int maxlen;  // capacity of set
};

// set_create(n) creates a newly allocated Set with space for n elements
// effects: A new set is allocated.  Caller must free with set_destroy
// time: O(1)
struct Set *set_create(int n);

// set_destroy(s) deletes the Set pointed to by s
// requires: s is not NULL
// effects: s is deallocated
// time: O(1)
void set_destroy(struct Set *s);

// set_length(s) retrieves the number of elements in s
// requires: s is not NULL
// time: O(1)
int set_length(const struct Set *s);

// set_add(s, v) adds v to the Set s, if it does not already contain v
// requires: s is not NULL, s must have space for v
// effects: v is added to s
// time: O(n) where n is set_size(s)
void set_add(struct Set *s, int v);

// set_remove(s, v) removes v from s. if v is not in s, s isn't changed
// requires: s is not NULL
// effects: s may have a member removed
// time: O(n) where n is set_size(s)
void set_remove(struct Set *s, int v);

// set_is_member(s, v) returns true if v is in set s and false if not
// requires: s is a valid Set.
// time: O(log n) where n is set_size(s)
bool set_is_member(const struct Set *s, int v);

// set_union(s1, s2) creates a new Set that is the union of s1 and s2; capacity
//   of the new Set must be sum of capacities of s1 and s2
// requires: s1, s2 are not NULL
// effects: returns a newly allocated Set.  caller must free using set_destroy
// time: O(n) where n is set_size(s1) + set_size(s2)
struct Set *set_union(const struct Set *s1, const struct Set *s2);

// set_intersect(s1, s2) creates a new Set that is the intersection of s1 and s2;
//   capacity of the new Set must be maximum of capacities of s1 and s2
// requires: s1, s2 are not NULL
// effects: returns a newly allocated Set.  caller must free using set_destroy
// time: O(n) where n is set_size(s1) + set_size(s2)
struct Set *set_intersect(const struct Set *s1, const struct Set *s2);

// set_subset(s1, s2) returns true if s1 is a subset of s2 and false if not
// requires: s1, s2 are not NULL
// time: O(n) where n is set_size(s1)
bool set_is_subset(const struct Set *s1, const struct Set *s2);

// set_difference(s1, s2) creates a new Set with all elements that are in s1
//   but not in s2; capacity of the new Set must be identical to capacity of s1
// requires: s1, s2 are not NULL
// effects: returns a newly allocated Set.  caller must free using set_destroy
// time: O(n) where n is set_size(s1) + set_size(s2)
struct Set *set_difference(const struct Set *s1, const struct Set *s2);

// set_print(s) prints the contents of the Set s to the screen.
// requires: s is not NULL
// effects: text is printed to the screen
// time: O(n) where n is set_size(s)
// examples:  If a Set s contains the values 1, 2, and 3, 
//   set_print(s) prints
// [1,2,3]
// For an empty set s, set_print(s) prints
// []
//
// (there is no whitespace other than the newline at the end).
void set_print(const struct Set *s);

