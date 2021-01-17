#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <libft.h>
#define false 0
#define true 1
#define BUF_SIZE 42
#define T_TRUE 0
#define T_FALSE 1
#define T_IF 2
#define T_THEN 3
#define T_ELSE 4
#define T_SEMICOLON 5
#define T_LP 6
#define T_RP 7
#define T_BEGIN 8
#define T_END 9
#define T_LOG_OR 10
#define T_LOG_XOR 11
#define T_LOG_AND 12
#define T_COM_NE 13
#define T_COM_LO 14
#define T_COM_HI 15
#define T_COM_EQ 16
#define T_ENDLINE 17
#define T_ASSIGN 18
#define T_IDENT 100
#define T_LINE_OPERATOR 99
#define F_PRINT_CALLS (1<<0)
#define F_PRINT_LEXEMS (1<<1)
int	flags;

typedef struct
{
	char	*value;
	int	len;
	int	token;
}	t_term;

typedef struct
{
	int		cap;
	int		size;
	t_term		**terms;
}	t_term_table;

int	if_nonterm(t_list **lexems);

t_term	*new_term(char *value, int token)
{
	t_term *res;

	res = malloc(sizeof(t_term));
	res->value = value;
	res->token = token;
	res->len = strlen(value);
	return (res);
}

void	add_term(t_term_table *table, char *value,  int token)
{
	table->terms[token] = new_term(value, token);
}

void	init_term_table(t_term_table **table)
{
	t_term_table *res;
	int i = 0;

	res = malloc(sizeof(t_term_table));
	res->cap = 19;
	res->size = res->cap;
	res->terms = (t_term**)malloc(sizeof(t_term*) * res->cap);
	add_term(res, "TRUE", i++);
	add_term(res, "FALSE", i++);
	add_term(res, "if", i++);
	add_term(res, "then", i++);
	add_term(res, "else", i++);
	add_term(res, ";", i++);
	add_term(res, "(", i++);
	add_term(res, ")", i++);
	add_term(res, "begin", i++);
	add_term(res, "end", i++);
	add_term(res, "or", i++);
	add_term(res, "xor", i++);
	add_term(res, "and", i++);
	add_term(res, "<>", i++);
	add_term(res, "<", i++);
	add_term(res, ">", i++);
	add_term(res, "=", i++);
	add_term(res, "\n", i++);
	add_term(res, ":=", i++);
	*table = res;
}

void	init_target_term_table(t_term_table **table)
{
	t_term_table *res;
	int i = 0;

	res = malloc(sizeof(t_term_table));
	res->cap = 19;
	res->size = res->cap;
	res->terms = (t_term**)malloc(sizeof(t_term*) * res->cap);
	add_term(res, "1", i++);
	add_term(res, "0", i++);
	add_term(res, "if", i++);
	add_term(res, "", i++);
	add_term(res, "else", i++);
	add_term(res, ";", i++);
	add_term(res, "(", i++);
	add_term(res, ")", i++);
	add_term(res, "{", i++);
	add_term(res, "}", i++);
	add_term(res, "||", i++);
	add_term(res, "^", i++);
	add_term(res, "&&", i++);
	add_term(res, "!=", i++);
	add_term(res, "<", i++);
	add_term(res, ">", i++);
	add_term(res, "==", i++);
	add_term(res, "\n", i++);
	add_term(res, "=", i++);
	*table = res;
}


void	exit_error(char *str, int code)
{
	write(2, str, strlen(str));
	exit (code);
}

char	*str_join(char *str1, char *str2)
{
	char	*res;
	if (!str1)
		return (strdup(str2));
	if (!str2)
		return (strdup(str1));
	res = malloc (strlen(str1) + strlen(str2) + 1);
	if (res)
	{
		strcpy(res, str1);
		strcat(res, str2);
	}
	return (res);
}

void	ft_free(char **buff)
{
	if (*buff)
	{
		free(*buff);
		*buff = NULL;
	}
}

char	*read_file(char *filename)
{
	int	fd;
	char	*res;
	char	*tmp;
	char	*buff;
	int	rd;

	if ((fd = open (filename, O_RDONLY)) == -1)
		exit_error("Нет такого файла\n", 1);
	res = NULL;
	buff = malloc(BUF_SIZE + 1);
	while ((rd = read(fd, buff, BUF_SIZE)))
	{
		buff[rd] = 0;
		tmp = res;
		res = str_join(res, buff);
		ft_free(&tmp);
	}
	free(buff);
	return (res);
}

void	next_lexem(t_list **lexems)
{}

void	normalize_str(char *str)
{
	while (*str)
	{
		if (strchr("\t\n\r", *str))
			*str = ' ';
		str++;
	}
}

t_term	*get_token(t_term_table *table, char **str)
{
	int	i = 0;
	t_term	*cur;
	int	f = 0;
	char	*st;
	char	*tmp;

	while (**str == ' ')
		*str = *str + 1;
	while (i < table->size)
	{
		cur = table->terms[i];
		if (!strncmp(cur->value, *str, cur->len))
		{
			*str = *str + cur->len;
			return (cur);
		}
		i++;
	}
	st = *str;
	while (**str && !strchr(" ;:\n()><=-+", **str))
		*str = *str + 1;
	tmp = ft_substr(st, 0, *str - st);
	return (new_term(tmp, T_IDENT));
}

t_list	*tokenize(t_term_table *table, char *str)
{
	t_list *res = NULL;
	t_term	*tmp;
	int	undef = 0;
	while (*str)
	{
		tmp = get_token(table, &str);
		ft_lstadd_back(&res, ft_lstnew((void*)tmp));
	}
	return (res);
}

void print_tokens(t_term_table *table, t_list *tokens, int mode)
{
	t_list *p = tokens;
	t_term *t;
	int i;
	int f;

	if (mode == 1)
		printf("Полученные лексемы:\n");
	while (p)
	{
		t = (t_term*)(p->content);
		if (t->token == T_ENDLINE)
			printf("\n");
		else
		{
			if (mode == 1)
				printf("|%s|%d) ", t->value, t->token);
			else if (mode == 0)
				printf("%s ", t->value);
		}
		p = p->next;
	}
	printf("\n");
}

void	skip_endlines(t_list **lexems)
{
	while (*lexems && ((t_term*)((*lexems)->content))->token == T_ENDLINE)
		*lexems = (*lexems)->next;
}

// <assign> := <ident> := <ident>;
int	assign_nonterm(t_list **lexems)
{
	if ((flags & F_PRINT_CALLS))
	printf("assign_nonterm\n");
	if (!(*lexems))
		return (false);
	if (((t_term*)((*lexems)->content))->token != T_IDENT)
		return (false);
	*lexems = (*lexems)->next;
	if (*(lexems) && ((t_term*)((*lexems)->content))->token != T_ASSIGN)
		return (false);
	*lexems = (*lexems)->next;
	if (*(lexems) && ((t_term*)((*lexems)->content))->token != T_IDENT)
		return (false);
	*lexems = (*lexems)->next;
	if (*(lexems) && ((t_term*)((*lexems)->content))->token != T_SEMICOLON)
		return (false);
	*lexems = (*lexems)->next;
	return (true);
}

// <operator> := ; | <ident> <operator> | <if> | <assign>
int	operator_nonterm(t_list **lexems)
{
	int look;

	if ((flags & F_PRINT_CALLS))
	printf("operator_nonterm\n");
	if (!(*lexems))
		return (false);
	if (((t_term*)((*lexems)->content))->token == T_IF)
		return (if_nonterm(lexems));
	if ((*lexems)->next && ((t_term*)(((*lexems)->next)->content))->token == T_ASSIGN)
	{
		return (assign_nonterm(lexems));
	}
	if (((t_term*)((*lexems)->content))->token == T_SEMICOLON)
	{
		*lexems = (*lexems)->next;
		return (true);
	}
	if (((t_term*)((*lexems)->content))->token != T_IDENT)
		return (false);
	*lexems = (*lexems)->next;
	return (operator_nonterm(lexems));
}

// <operators> := <operator> | <operator> <operators>
int	operators_nonterm(t_list **lexems)
{
	int	look;

	if ((flags & F_PRINT_CALLS))
	printf("operators_nonterm\n");
	if (!(*lexems))
		return (false);
	if (!operator_nonterm(lexems))
		return (false);
	look = ((t_term*)((*lexems)->content))->token ;
	if (look == T_IDENT || look == T_IF)
	{
		int  ret = (operators_nonterm(lexems));
		return (ret);
	}
	return (true);
}

// <complex_body> := begin <operator> [<operator>] end
int	complex_body_nonterm(t_list **lexems)
{
	if ((flags & F_PRINT_CALLS))
	printf("complex_body_nonterm\n");
	if (!(*lexems))
		return (false);
	if (((t_term*)((*lexems)->content))->token != T_BEGIN)
		return (false);
	*lexems = (*lexems)->next;
	if (!operators_nonterm(lexems))
		return (false);
	if (((t_term*)((*lexems)->content))->token != T_END)
		return (false);
	return (true);
}

// <body> := <if> | <operator> | <complex_body>
int	body_nonterm(t_list **lexems)
{
	int	type;

	if ((flags & F_PRINT_CALLS))
	printf("body_nonterm\n");
	//printf("body [%d]\n", ((t_term*)((*lexems)->content))->token );
	if (!(*lexems))
		return (false);
	type = ((t_term*)((*lexems)->content))->token;
	if (type == T_IF)
		return (if_nonterm(lexems));
	if (type == T_BEGIN)
		return (complex_body_nonterm(lexems));
	if (type == T_IDENT)
		return (operator_nonterm(lexems));
	return false;
}

// <operand> : <ident>
int	operand_nonterm(t_list **lexems)
{
	if ((flags & F_PRINT_CALLS))
	printf("operand_nonterm\n");
	if (!(*lexems))
		return (false);
	if (((t_term*)((*lexems)->content))->token != T_IDENT)
		return (false);
	return (true);
}

// <comp> := < | > | = | <>
int	comp_nonterm(t_list **lexems)
{
	int	type;

	if ((flags & F_PRINT_CALLS))
	printf("comp_nonterm\n");
	if (!(*lexems))
		return (false);
	type = ((t_term*)((*lexems)->content))->token;
	if (type >= T_COM_NE && type <= T_COM_EQ)
		return (true);
	return (false);
}

// <condition> := (<operand> <comp> <operand>) |
// 		  TRUE | FALSE
int	condition_nonterm(t_list **lexems)
{
	if ((flags & F_PRINT_CALLS))
	printf("condition_nonterm\n");
	if (!(*lexems))
		return (false);
	if (!(*lexems) || ((t_term*)((*lexems)->content))->token != T_LP)
		return (false);
	*lexems = (*lexems)->next;
	if (!operand_nonterm(lexems))
		return (false);
	*lexems = (*lexems)->next;
	if (!comp_nonterm(lexems))
		return (false);
	*lexems = (*lexems)->next;
	if (!operand_nonterm(lexems))
		return (false);
	*lexems = (*lexems)->next;
	if (!(*lexems) || ((t_term*)((*lexems)->content))->token != T_RP)
		return (false);
	return true;
}

// <if> := if <condition> then <body> [else <body>] | <if> <if>
int	if_nonterm(t_list **lexems)
{
	if ((flags & F_PRINT_CALLS))
	printf("if_nonterm\n");
	if (!(*lexems))
		return (false);
	if (((t_term*)((*lexems)->content))->token != T_IF)
		return (false);
	*lexems = (*lexems)->next;
	if (!condition_nonterm(lexems))
		return (false);
	*lexems = (*lexems)->next;
	if (((t_term*)((*lexems)->content))->token != T_THEN)
		return (false);
	*lexems = (*lexems)->next;
	if (!body_nonterm(lexems))
		return (false);
	//if (*(lexems) && (*lexems)->next && ((t_term*)(((*lexems)->next)->content))->token == T_ELSE)
	if (*(lexems)  && ((t_term*)((*lexems)->content))->token == T_ELSE)
	{
		*lexems = (*lexems)->next;
		if (!body_nonterm(lexems))
			return (false);
	}
	*lexems = (*lexems)->next;
	//printf("body [%d]\n", ((t_term*)((*lexems)->content))->token );
	skip_endlines(lexems);
	//printf("body [%d]\n", ((t_term*)((*lexems)->content))->token );
	if ((*lexems) && ((t_term*)((*lexems)->content))->token == T_IF)
		return (if_nonterm(lexems));
	return (true);
}

int	syntax_analyze(t_list *lexems)
{
	int ret;
	if ((flags & F_PRINT_CALLS))
	printf("Порядок вызова нетерминалов:\n");
	ret = if_nonterm(&lexems);
	if ((flags & F_PRINT_CALLS))
	printf("\n");
	return (ret);
}

void	parse_args(char ac, char **av)
{
	int i;

	flags = 0;
	i = 3;
	while (i < ac)
	{
		if (!strcmp(av[i],"-p"))
			flags |= F_PRINT_CALLS;
		if (!strcmp(av[i],"-l"))
			flags |= F_PRINT_LEXEMS;
		i++;
	}
}

t_term	*get_tr_term(t_term *term, t_term_table *table)
{
	int	i = 0;
	t_term	*cur;

	if (term->token == T_IDENT)
		return (term);
	while (i < table->size)
	{
		cur = table->terms[i];
		if (cur->token == term->token)
			return (cur);
		i++;
	}
	return (term);
}

t_list *translate(t_list *lexems)
{
	t_list 		*p = lexems;
	t_list 		*res = NULL;
	t_term_table	*table;

	init_target_term_table(&table);
	while (p)
	{
		ft_lstadd_back(&res, ft_lstnew((void*)get_tr_term((t_term*)(p->content), table)));
		p = p->next;
	}
	return (res);
}

void	write_result(t_list *result, char *filename)
{
	int	fd;
	t_list	*p;
	char	*tmp;

	if ((fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644))== -1)
		exit_error("Не удалось открыть выходной файл для записи\n", 6);
	p = result;
	while(p)
	{
		tmp = ((t_term*)(p->content))->value;
		write(fd, tmp, ft_strlen(tmp));
		if (((t_term*)(p->content))->token != T_ENDLINE)
		write(fd, " ", 1);
		p = p->next;
	}
	close(fd);
}

int main (int ac, char **av)
{
	t_term_table	*term_table;
	init_term_table(&term_table);
	int analysis;
	if (ac < 3)
		exit_error("Необходимо указать входной и выходной файл\n", 2);
	if (!ft_strcmp(av[1], av[2]))
		exit_error("Необходимо указать разные файлы для чтения и для записи\n", 3);
	char *str = read_file(av[1]);
	parse_args(ac, av);
	//normalize_str(str);
	t_list *lexems = tokenize(term_table, str);
	if ((flags & F_PRINT_LEXEMS))
	print_tokens(term_table, lexems, 1);
	analysis = syntax_analyze(lexems);
	if (analysis)
		printf("Входной текст синтаксически корректен\n");
	else
		exit_error("Во входном тексте присутствюут синтаксические ошибки\n", 4);
	t_list *trans = translate(lexems);
	write_result(trans, av[2]);
	printf("Трансляция завершна\n");
	//print_tokens(term_table, trans, 0);
	//printf("|%s\n|", str);
}
