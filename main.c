// An I/O test program for the set ADT

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "set.h"

const char ERR_INVALID[] = "Invalid command.\n";
const char ERR_CREATE[] = "Free current Set before creating a new one.\n";
const char ERR_NO_SET[] = "You must create a Set first.\n";
const char ERR_REMOVE[] = "You cannot remove %d of '%s', the Set only contains %d.\n";
const char ERR_TUT[] = "Tut tut, you forgot to free the Set!\n";
const char ERR_ID[] = "Could not read in set ID.\n";
const char ERR_READ[] = "Error during read.\n";

// gobble_line() reads input until an \n is reached in the event of 
//   an error
void gobble_line(void) {
  char c;
  while (1) {
    scanf("%c", &c);
    if (c == '\n') {
      return;
    }
  }
}

// set_id() verifies that the set ID is either 0 or 1
int set_id(void) {
  int id;
  scanf("%d", &id);
  if (id != 0 && id != 1) {
    printf(ERR_ID);
    gobble_line();
    return -1;
  }
  return id;
}

// set_valid(s, id) verifies that the set is valid
bool set_valid(struct Set *s, int id) {
  if (s == NULL) {
    printf(ERR_NO_SET); 
    gobble_line();
    return false;
  }
  return true;
}

int main(void) {
  void *sets[4] = {NULL, NULL, NULL, NULL};
  char cmd;
  int id;
  while (1) {
    int res = scanf(" %c", &cmd);
    if (cmd == 'q' || res != 1) {
      for (int i = 0; i < 2; i++) {
        if (sets[i]) {
          printf(ERR_TUT);
          set_destroy(sets[i]);
          sets[i] = NULL;
        }
      }
      break;
    }

    id = set_id();
    if (id == -1) continue;
    
    if (cmd == 'n') {
      if (sets[id]) {
        printf(ERR_CREATE);
        gobble_line();
        printf("%d\n", res);
        continue;
      }
      int num;
      res = scanf("%d", &num);
      sets[id] = set_create(num); 
    } else if (cmd == 'd') {
        set_destroy(sets[id]);
        sets[id] = NULL;
    } else if (cmd == 'a') {
      if (set_valid(sets[id], id)) {
        int num;
        res = scanf("%d", &num);
        set_add(sets[id], num);
      }
    } else if (cmd == 'r') {
      if (set_valid(sets[id], id)) {
        int num;
        res = scanf("%d", &num);
        set_remove(sets[id], num);
      }
    } else if (cmd == 'm') {
       if (set_valid(sets[id], id)) {
         int num;
         res = scanf("%d", &num);
	 if (set_is_member(sets[id], num)) {
           printf("%d is in set\n", num);
	 } else {
           printf("%d is not in set\n", num);
	 }
       }
    } else if (cmd == 'l') {
      if (set_valid(sets[id], id)) {
        printf("The length is %d.\n", set_length(sets[id]));
      }
    } else if (cmd == 'u') {
      int id2 = set_id();
      if (id2 == -1) continue;
      if (set_valid(sets[id], id) && set_valid(sets[id2], id2)) {
        struct Set *un = set_union(sets[id], sets[id2]);
        set_print(un);
        set_destroy(un);
      }
    } else if (cmd == 'i') {
      int id2 = set_id();
      if (id2 == -1) continue;
      if (set_valid(sets[id], id) && set_valid(sets[id2], id2)) {
        struct Set *in = set_intersect(sets[id], sets[id2]);
        set_print(in);
        set_destroy(in);
      }
    } else if (cmd == 's') {
      int id2 = set_id();
      if (id2 == -1) continue;
      if (set_valid(sets[id], id) && set_valid(sets[id2], id2)) {
	if (set_is_subset(sets[id], sets[id2])) {
           printf("is subset\n");
	 } else {
           printf("is not subset\n");
	 }
      }
    } else if (cmd == 'e') {
      int id2 = set_id();
      if (id2 == -1) continue;
      if (set_valid(sets[id], id) && set_valid(sets[id2], id2)) {
        struct Set *diff = set_difference(sets[id], sets[id2]);
        set_print(diff);
        set_destroy(diff);
      }
    } else if (cmd == 'p') {
      if (set_valid(sets[id], id)) {
        set_print(sets[id]);
      }
    } else if (cmd == 'A') {
      if (set_valid(sets[id], id)) {
        while (1) {
          char num[1024];
          res = scanf("%s", num);
          if (res != 1) {
            printf(ERR_READ);
            exit(0);
          }
          if (strcmp(num, "end") == 0) break;
          int readnum;
          res = sscanf(num, "%d", &readnum);
          if (res != 1) {
            printf(ERR_READ);
            exit(0);
          }
          set_add(sets[id], readnum);
        }
      }
    }
  }
}

