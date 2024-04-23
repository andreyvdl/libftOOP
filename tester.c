#include "headers/libft.h"
#include "libCAssert/include/libassert.h"
#include <ctype.h>

#define MAX_TEST 5

int main() {
	t_inst	inst[MAX_TEST];
	int64_t	resi[MAX_TEST];
	int64_t	expi[MAX_TEST];
	// void	*resv[MAX_TEST];
	// void	*expv[MAX_TEST];

	inst[0] = init_instance_default(NULL);
	inst[4] = inst[3] = inst[2] = inst[1] = inst[0];
	inst[0].title = (t_text){"ft_islower", COLOR_YELLOW};
	inst[0].desc = (t_text){"Testing extras", COLOR_CYAN};
	resi[0] = !ft_islower('y'), expi[0] = !islower('y');
	resi[1] = ft_islower('Y'), expi[1] = islower('Y');
	resi[2] = ft_islower(' '), expi[2] = islower(' ');
	resi[3] = ft_islower('7'), expi[3] = islower('7');
	resi[4] = ft_islower('@'), expi[4] = islower('@');
	test_int(inst, resi, expi, MAX_TEST);

	inst[0].title.text = "ft_isspace";
	resi[0] = ft_isspace('y'), expi[0] = isspace('y');
	resi[1] = ft_isspace('Y'), expi[1] = isspace('Y');
	resi[2] = !ft_isspace('\n'), expi[2] = !isspace('\n');
	resi[3] = ft_isspace('7'), expi[3] = isspace('7');
	resi[4] = ft_isspace('@'), expi[4] = isspace('@');
	test_int(inst, resi, expi, MAX_TEST);

	inst[0].title.text = "ft_isupper";
	resi[0] = ft_isupper('y'), expi[0] = isupper('y');
	resi[1] = !ft_isupper('Y'), expi[1] = !isupper('Y');
	resi[2] = ft_isupper('\n'), expi[2] = isupper('\n');
	resi[3] = ft_isupper('7'), expi[3] = isupper('7');
	resi[4] = ft_isupper('@'), expi[4] = isupper('@');
	test_int(inst, resi, expi, MAX_TEST);

	inst[0].title.text = "ft_atoi";
	inst[0].desc.text = "Testing part 1";
	resi[0] = ft_atoi(" 42  "), expi[0] = atoi(" 42  ");
	resi[1] = ft_atoi(" -42  "), expi[1] = atoi(" -42  ");
	resi[2] = ft_atoi(" abc 42"), expi[2] = atoi(" abc 42");
	resi[3] = ft_atoi("000042"), expi[3] = atoi("000042");
	resi[4] = ft_atoi(""), expi[4] = atoi("");
	test_int(inst, resi, expi, MAX_TEST);
}
