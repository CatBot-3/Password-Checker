#include <stdlib.h>
#include <assert.h>  
#include <stdio.h>
#include <stdbool.h>
#include "set.h"

// see set.h for documentation
struct Set *set_create(int n) {
  struct Set *s = malloc (sizeof (struct Set));
  s->data = malloc (n * sizeof (int));
  s->len = 0;
  s->maxlen = n;
  return s;
}

// see set.h for documentation
void set_destroy(struct Set *s) {
  assert (s);
  free (s->data);
  free (s);
}

// see set.h for documentation
int set_length(const struct Set *s) {
  return s->len;
}

// see set.h for documentation
// why I belive this is O(n) :
// O(n) + O(n) + O(n) = O(n)
void set_add(struct Set *s, int v) {
  assert(s);
  assert(set_length(s) < s->maxlen);

  for (int i = 0; i < s->len; ++i) {
    if (s->data[i] == v) {
      return; // Do not add if it already exists
    }
  }
  // Find the insertion index
  int add_index = s->len; // Default
  for (int i = 0; i < s->len; ++i) {
    if (s->data[i] > v) {
      add_index = i;
      break;
    }
  }
  // Shift elements to make space for v
  for (int i = s->len; i > add_index; --i) {
    s->data[i] = s->data[i - 1];
  }
  s->data[add_index] = v;
  s->len++;
}

// see set.h for documentation
void set_remove(struct Set *s, int v) {
  assert (s);
  int remove_index = -1;
  for (int i = 0; i < set_length(s); ++i) {
    if (s->data[i] == v) {
      remove_index = i;
      break;
    }
  }
  if (remove_index == -1) {
    return; // v does not exist in s
  }
  for (int i = remove_index; i < (set_length(s) - 1); ++i) {
    s->data[i] = s->data[i + 1]; //shift to fill the gap
  }
  // position beyond the s->len will not be used anyway
  s->len--;
}

// see set.h for documentation
// why I believe this is O(logn):
// constant time operation (which is O(1)) + T(n/2) = O(logn)
bool set_is_member(const struct Set *s, int v) {
  // add your implementation
  assert (s);
  // hopefully the set is sorted by previous functions, lets bisect the set in half
  // and see if v is in the first or second half
  if (set_length(s) == 0) {
    return false;
  }
  if (set_length(s) == 1) {
    return s->data[0] == v;
  } // two base cases, because in these case, s->len / 2 = 0
  int mid = s->data[set_length(s) / 2];
  if (mid == v) {
    return true;
  }
  if (mid < v) { // on the right half
    for (int i = mid + 1; i < set_length(s); ++i) {
      if (s->data[i] == v) {
        return true;
      }
    }
  } else { // on the left half
    for (int i = 0; i < mid; ++i) {
      if (s->data[i] == v) {
        return true;
      }
    }
  }

  return false;
}

// see set.h for documentation
struct Set *set_union(const struct Set *s1, const struct Set *s2) {
  // add your implementation
  assert (s1);
  assert (s2);
  struct Set *s = set_create(set_length(s1) + set_length(s2));
  for (int i = 0; i < set_length(s1); ++i) {
    set_add(s, s1->data[i]);
  }
  for (int i = 0; i < set_length(s2); ++i) {
    set_add(s, s2->data[i]);
  }

  return s;
}

// see set.h for documentation
struct Set *set_intersect(const struct Set *s1, const struct Set *s2) {
  assert (s1);
  assert (s2);
  int len = 0;
  if (set_length(s1) > set_length(s2)) {
    len = set_length(s1);
  } else {
    len = set_length(s2);
  }
  struct Set *s = set_create(len);
  int s1_index = 0;
  int s2_index = 0;
  // since the set is sorted by add and remove
  // I hope I can compare from start and increment the index base on comparing values
  while ((s1_index < set_length(s1)) && (s2_index < set_length(s2))) {
    if (s1->data[s1_index] == s2->data[s2_index]) {
      set_add(s, s1->data[s1_index]);
      s1_index++;
      s2_index++;
    } else if (s1->data[s1_index] < s2->data[s2_index]) {
      s1_index++;
    } else {
      s2_index++;
    }
  }
  return s;
}

// see set.h for documentation
bool set_is_subset(const struct Set *s1, const struct Set *s2) {
  assert (s1);
  assert (s2);
  if (set_length(s1) > set_length(s2)) {
    return false;
  }
  int s1_index = 0;
  for (int i = 0; i < set_length(s2); ++i) {
    if (s2->data[i] == s1->data[s1_index]) {
      s1_index++;
    }
    if (s1_index == set_length(s1)) {
      return true;
    }
  }
  return false;
}

// see set.h for documentation
struct Set *set_difference(const struct Set *s1, const struct Set *s2) {
  assert (s1);
  assert (s2);
  struct Set *s = set_create(set_length(s1));
  int s2_index = 0;
  int s1_index = 0;
  while (s1_index < set_length(s1)) {
    if (s1->data[s1_index] == s2->data[s2_index]) {
      s1_index++;
      s2_index++;
    } else if (s1->data[s1_index] < s2->data[s2_index]) {
      set_add(s, s1->data[s1_index]);
      s1_index++;
    } else {
      s2_index++;
    }
    if (s2_index >= set_length(s2)) {
      break;
    }
  }
  while (s1_index < set_length(s1)) {
    set_add(s, s1->data[s1_index]);
    s1_index++;
  }
  return s;
}

// see set.h for documentation
void set_print(const struct Set *s) {
  // add your implementation
  assert (s);
  printf ("[");
  for (int i = 0; i < set_length(s); ++i) {
    printf ("%d", s->data[i]);
    if (i != set_length(s) - 1) { // current i is the last term
      printf (",");
    }
  }
  printf ("]\n");
}

