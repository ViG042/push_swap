# Nom de l'exécutable
NAME = push_swap

# Fichiers source
SRC = push_cost_a_to_b.c sb_rb_rrb.c target_node_a.c create_deck.c \
      opti_move.c push_cost_b_to_a.c show_decks.c target_node_b.c \
      create_deck_utils.c opti_push_cost.c smaller_bigger.c decklen.c \
      pa_pb.c sort3.c free_deck.c push_a_to_b.c \
      s_r_rr.c main.c push_b_to_a.c sa_ra_rra.c ss_rr_rrr.c

# Objets générés
OBJS = ${SRC:.c=.o}

# En-têtes
HEAD = push_swap.h

# Compilateur et flags
CC = cc
FLAGS = -Wall -Wextra -Werror -g3

# Règles de compilation
all: ${NAME}

# Compilation des fichiers objets
%.o: %.c ${HEAD}
	${CC} ${FLAGS} -I. -c $< -o $@

# Création de l'exécutable
${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

# Nettoyage des fichiers objets
clean:
	rm -f ${OBJS}

# Nettoyage complet (fichiers objets + exécutable)
fclean: clean
	rm -f ${NAME}

# Reconstruction complète
re: fclean all

# Cibles phony
.PHONY: all clean fclean re
