#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structures definition
typedef enum {
	REJECT,
	ACCEPT
} status;

typedef struct state_s {
	char desc;
	status stat;
	struct state_s **to;
} state_t;

state_t *create_state(char, status);
void setup_transition_lists(state_t **);
void create_multistate_lists(void);

#endif
