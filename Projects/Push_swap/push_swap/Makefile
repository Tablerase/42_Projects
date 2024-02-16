# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 17:51:05 by rcutte            #+#    #+#              #
#    Updated: 2024/01/14 23:56:10 by rcutte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################### Program ######################

NAME = push_swap

all: $(NAME)

####################### FLAGS #######################

CC = cc
CFLAGS = -Wextra -Wall -Werror -g

###################### Libft ########################

LIB_PATH = ./libft
LIB_Includes = ./libft/Includes
LIBFT = $(LIB_PATH)/libft.a

lib_setup:
	@if [ ! -f $(LIB_PATH)/libft.a ]; then \
		make -sC $(LIB_PATH) ; \
		echo "$(GREEN)Libft Library Created$(RESET)"; \
	fi
	
lib_clean:
	@if [ -f $(LIB_PATH)/Libft/ft_tolower.o ]; then \
		make -sC $(LIB_PATH) clean; \
		echo "$(ORANGE)Libft Objects Cleaned$(RESET)"; \
	fi

lib_fclean:
	@make -sC $(LIB_PATH) fclean
	@echo "$(ORANGE)Libft Library Cleaned$(RESET)"

###################### Files ########################

# header path
INCLUDES = ./Includes
# source path
SRC_PATH = ./Sources/mandatory/

# files
SRC = main.c \
		check_args.c	split.c\
		init.c	duplicate_stacks.c\
		node.c	node_utils.c	node_delone.c\
		sorters_swap.c	sorters_push.c	sorters_rotate.c\
		sorters.c\
		sort_few.c\
		sort_algo.c\
		sort_big.c\
		sort_array.c\
		mem_manager.c\
		debug.c\
		print_sequence.c	sanitize_sequence.c\
		math.c\

# objet libft
OBJ = $(addprefix $(SRC_PATH)/,$(SRC:.c=.o))

###################### Bonus ########################

NAME_BONUS = checker
SRC_BONUS_PATH = ./Sources/bonus
SRC_BONUS = main_bonus.c\

OBJ_BONUS = $(addprefix $(SRC_BONUS_PATH)/,$(SRC_BONUS:.c=.o))

bonus: lib_setup $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@if [ -f $(NAME_BONUS) ]; then \
		echo "$(GREEN)Program bonus Compiled$(RESET)"; \
	fi
	@if [ ! -f $(NAME_BONUS) ]; then \
		echo "$(RED)Program bonus Compilation Failed$(RESET)"; \
	fi

rebonus: re_msg fclean bonus

##################### Commands ######################

$(NAME): lib_setup $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@if [ -f $(NAME) ]; then \
		echo "$(COMPILED)\
╭──────────────────────────────────────────────────╮\n\
│                  Program Compiled                │\n\
╰──────────────────────────────────────────────────╯\
		$(RESET)";\
	fi
	@if [ ! -f $(NAME) ]; then \
		echo "$(RED)$(RESET)"; \
		@echo "$(FAILED)\
╭──────────────────────────────────────────────────╮\n\
│            Program Compilation Failed            │\n\
╰──────────────────────────────────────────────────╯\
		$(RESET)";\
	fi

%.o : %.c
	$(CC) -c $(CFLAGS) -I$(INCLUDES) -I$(LIB_Includes) $< -o $@

clean: clean_msg lib_clean
	@rm -f $(OBJ) $(OBJ_BONUS)
	
fclean: clean lib_fclean
	@rm -f $(NAME)
	
re: re_msg fclean all

re_program: re_program_msg clean all

####################### Tests ########################

ARGS_500 = 267 246 158 151 251 83 101 361 234 135 244 43 162 419 154 245 232 491 247 302 132 493 160 25 270 326 105 305 285 495 148 293 446 288 254 3 484 131 310 243 483 460 222 387 405 395 317 413 178 40 410 236 435 107 235 33 42 473 173 448 327 11 19 164 385 123 192 169 227 468 226 459 442 404 343 125 34 91 346 438 297 9 133 337 62 82 406 411 155 323 58 15 128 427 230 141 143 176 7 14 390 499 486 183 321 431 18 220 308 472 32 281 206 369 190 65 263 275 51 44 397 228 196 463 342 67 171 328 469 433 87 367 92 193 471 233 239 63 314 355 357 68 388 485 205 217 76 144 50 1 156 139 457 248 259 451 100 182 329 415 458 380 412 316 298 324 211 330 29 268 199 126 5 345 30 470 249 70 10 488 465 284 443 450 184 59 53 335 194 299 393 339 31 360 86 352 462 449 175 333 168 122 331 356 253 306 250 121 109 429 170 90 113 286 110 23 187 140 477 89 142 313 35 318 61 120 207 129 181 264 439 482 283 307 188 172 492 97 366 353 362 117 478 368 280 432 461 490 454 212 291 409 265 257 94 219 57 422 208 494 27 277 80 372 407 312 231 159 272 279 54 481 358 124 256 273 301 213 75 69 400 166 165 398 382 374 282 340 428 437 153 376 221 262 149 455 394 28 138 108 424 73 99 24 84 370 2 399 186 201 200 102 119 241 237 322 66 4 38 56 421 287 349 474 416 179 52 204 381 344 389 496 163 6 261 16 479 218 130 210 414 96 292 111 203 338 185 500 39 403 71 41 359 364 195 115 145 466 197 12 88 420 445 436 127 95 402 278 464 497 300 295 137 334 401 371 209 311 294 408 434 202 36 418 20 325 303 223 198 74 423 274 365 377 456 77 85 350 72 225 114 224 238 430 48 134 78 487 93 332 146 116 189 17 258 8 150 391 215 252 147 386 315 104 475 480 242 354 22 379 489 136 320 167 417 319 45 441 296 289 152 351 453 79 214 363 47 396 378 269 309 46 112 180 49 392 81 440 348 341 103 271 467 276 336 260 447 452 383 425 240 64 161 476 174 426 373 384 304 375 21 177 347 191 444 255 229 98 106 60 498 216 118 37 26 266 157 55 13 290

ARGS_10 =  5 8 1 3 2 6 7 10 9 4

ARGS_5 = 2 1 3 6 5

exec_5: clean all exec_msg
	@./$(NAME) $(ARGS_5)

exec_10: clean all exec_msg
	@./$(NAME) $(ARGS_10)

exec_500: clean all exec_msg
	@./$(NAME) $(ARGS_500)

###################### Valgrind/Debug ######################

valgrind: clean all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s \
	./$(NAME) $(ARGS_10)

lldb: clean all
	@lldb ./$(NAME) $(ARGS_10)

################### Special Target ###################

.PHONY: all clean fclean re re_program bonus rebonus exec valgrind

.SILENT: $(NAME) $(OBJ) $(OBJ_BONUS)

###################### Messages ######################
compile_msg:
	@echo "$(COMPILED)\
	╭──────────────────────────────────────────────────╮\n\
	│                  Program Compiled                │\n\
	╰──────────────────────────────────────────────────╯\
	$(RESET)"

clean_msg:
	@echo "$(GREY)\
	╭──────────────────────────────────────────────────╮\n\
	│                  Cleaning Objects                │\n\
	╰──────────────────────────────────────────────────╯\
	$(RESET)"

re_msg:
	@echo "$(PROGRAM)\
	╭──────────────────────────────────────────────────╮\n\
	│        Recreation of Program and Libraries       │\n\
	╰──────────────────────────────────────────────────╯\
	$(RESET)"

re_program_msg:
	@echo "$(PROGRAM)\
	╭──────────────────────────────────────────────────╮\n\
	│                 Recreating Program               │\n\
	╰──────────────────────────────────────────────────╯\
	$(RESET)"

exec_msg:
	@echo "$(EXEC)\
	╭──────────────────────────────────────────────────╮\n\
	│                 Executing Program                │\n\
	╰──────────────────────────────────────────────────╯\
	$(RESET)"

###################### Colors #######################

# ANSI escape codes for colors and formatting
# Format: \033[<attribute>;<foreground>;<background>m

EXEC = \033[1;94m
PROGRAM = \033[1;95m
COMPILED = \033[1;92m
FAILED = \033[0;31m

# Attributes (0 to 7)
RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
UNDERLINE = \033[4m
REVERSED = \033[7m

# Foreground Colors (30 to 37)
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

GREY = \033[38;5;240m

# Highlight (Bright) Foreground Colors (90 to 97)
BRIGHT_BLACK = \033[0;90m
BRIGHT_RED = \033[0;91m
BRIGHT_GREEN = \033[0;92m
BRIGHT_YELLOW = \033[0;93m
BRIGHT_BLUE = \033[0;94m
BRIGHT_PURPLE = \033[0;95m
BRIGHT_CYAN = \033[0;96m
BRIGHT_WHITE = \033[0;97m

# Background Colors (40 to 47)
BG_BLACK = \033[0;40m
BG_RED = \033[0;41m
BG_GREEN = \033[0;42m
BG_YELLOW = \033[0;43m
BG_BLUE = \033[0;44m
BG_PURPLE = \033[0;45m
BG_CYAN = \033[0;46m
BG_WHITE = \033[0;47m

# Highlight (Bright) Background Colors (100 to 107)
BG_BRIGHT_BLACK = \033[0;100m
BG_BRIGHT_RED = \033[0;101m
BG_BRIGHT_GREEN = \033[0;102m
BG_BRIGHT_YELLOW = \033[0;103m
BG_BRIGHT_BLUE = \033[0;104m
BG_BRIGHT_PURPLE = \033[0;105m
BG_BRIGHT_CYAN = \033[0;106m
BG_BRIGHT_WHITE = \033[0;107m
