#include "language.h"

// Constants
state_t *A;
state_t *B;
state_t *C;
state_t *D;
state_t *E;
state_t *F;
state_t *G;
state_t *H;
state_t *I;
state_t *J;

// List of states
state_t **S = NULL;
state_t **T = NULL;
state_t **U = NULL;

// Main Programme
int main(int argc, char **argv)
{
	//variable declaration and initialization
	int i = 0;
	int k = 0;
	A = create_state('A', REJECT);
	B = create_state('B', REJECT);
	C = create_state('C', REJECT);
	D = create_state('D', REJECT);
	E = create_state('E', REJECT);
	F = create_state('F', REJECT);
	G = create_state('G', REJECT);
	H = create_state('H', REJECT);
	I = create_state('I', REJECT);
	J = create_state('J', ACCEPT);
	// Init states
	state_t *arrs[9] = { A, B, C, D, E, F, G, H, I };
	setup_transition_lists(arrs);

	create_multistate_lists();
	state_t **rstate = S;
	char *input_string;
	
	if (argc != 2)
	{
		printf("Usage: %s <arg1>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	input_string = argv[1];
	
	while (input_string[k])
	{
		if (input_string[k] != '0' && input_string[k] != '1')
			break;
		
		if (input_string[k] == '0') 
		{
			rstate = T;
		}
		else if (input_string[k] == '1')
		{
			rstate = U;
		}
		k++;
	}
	
	if (rstate == U)
		printf("String belongs to the Language\n");
	else
		printf("String does not belong to the Language\n");
	return 0;
}

state_t *create_state(char description, status stat)
{
	int x;
	struct state_s *init = NULL;

	init = (state_t *) malloc(sizeof(*init));
	if (init == NULL)
		exit(9);
	init->to = NULL;
	init->to = malloc(sizeof(state_t **));
	if (!init->to)
		exit(9);
	for (x = 0; x < 4; x++)
	{
		*(init->to + x) = malloc(sizeof(state_t *));
		if (*(init->to + x) == NULL)
		{
			int i = 0;
			for ( ; i < x; i++)
			{
				free(*(init->to + i));
			}
			free(init);
			exit(9);
		}
	}
	init->desc = description;
	init->stat = stat;
	return init;
}

void setup_transition_lists(state_t **s)
{
	int a;
	
	if (s == NULL || *s == NULL)
		return;
		
	
	*((*s)->to) = A;
	*((*s)->to + 1) = NULL;
	*((*(s+1))->to) = C;
	*(((*(s+1))->to) + 1) = D;
	*(((*(s+1))->to) + 2) = H;
	*(((*(s+1))->to) + 3) = NULL;
	*((*(s+2))->to) = E;
	*((*(s+2))->to + 1) = NULL;
	*((*(s+3))->to) = F;
	*((*(s+3))->to + 1) = NULL;
	*((*(s+4))->to) = G;
	*((*(s+4))->to + 1) = NULL;
	*((*(s+5))->to) = G;
	*((*(s+5))->to + 1) = NULL;
	*((*(s+6))->to) = H;
	*((*(s+6))->to + 1) = NULL;
	*((*(s+7))->to) = I;
	*((*(s+7))->to) = A;
	*((*(s+7))->to + 1) = NULL;
	*((*(s+8))->to) = J;
	*((*(s+8))->to + 1) = NULL;
}

void create_multistate_lists()
{
	state_t *s[7] = { A, B, C, D, H, I, NULL};
	state_t *t[10] = { F, G, H, I, A, B, C, D, J, NULL };
	state_t *u[9] = { E, G, H, I, A, B, C, D, NULL };
	
	S = s;
	T = t;
	U = u;
}
