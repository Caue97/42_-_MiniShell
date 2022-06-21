
/* 
	WORD,				string, ex: echo "WORD", nome de arquivos para redirecionamento
	ASSIGNMENT_WORD,	option (-n)
	OR_IF,				||
	LESS,				<
	DLESS,				<<
	GREAT,				>
	DGREAT,				>>
	AND_IF,				&&
	LBRACE,				(
	RBRACE,				)
	PIPE				|
*/

char    **split_specific(char **com_line)
{
    int     count_1;
    char    **return_line;

    count_1 = -1;
    while(com_line[count_1])
    {
        count_1++;
        if (com_line[count_1] == NULL)
            break
        divide_further(com_line[count_1])
    }
}

char    **divide_further(char *c_line_part)
{
    int     count_2;
    char    **ret

    count_2 = -1;
    while(c_line_part[count_2])
    {
        count_2++;
        if (c_line_part[count_2] == NULL)
            break
    }
}

