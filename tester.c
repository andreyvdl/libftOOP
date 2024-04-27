#include "headers/libft.h"
#include "libCAssert/include/libassert.h"
#include <ctype.h>
#include <strings.h>

#define MAX_TEST 7


static void testIsLower(t_inst *inst) {
	int64_t	resi[MAX_TEST];
	int64_t	expi[MAX_TEST];

	resi[0] = !ft_islower('y'), expi[0] = !islower('y');
	resi[1] = ft_islower('Y'), expi[1] = islower('Y');
	resi[2] = ft_islower(' '), expi[2] = islower(' ');
	resi[3] = ft_islower('7'), expi[3] = islower('7');
	resi[4] = ft_islower('@'), expi[4] = islower('@');
	resi[5] = ft_islower('\r'), expi[5] = islower('\r');
	resi[6] = ft_islower('~'), expi[6] = islower('~');
	test_int(inst, resi, expi, MAX_TEST);
}

static void testIsSpace(t_inst *inst) {
	int64_t	resi[MAX_TEST];
	int64_t	expi[MAX_TEST];

	resi[0] = ft_isspace('y'), expi[0] = isspace('y');
	resi[1] = ft_isspace('Y'), expi[1] = isspace('Y');
	resi[2] = !ft_isspace('\n'), expi[2] = !isspace('\n');
	resi[3] = ft_isspace('7'), expi[3] = isspace('7');
	resi[4] = ft_isspace('@'), expi[4] = isspace('@');
	resi[5] = !ft_isspace('\r'), expi[5] = !isspace('\r');
	resi[6] = ft_isspace('~'), expi[6] = isspace('~');
	test_int(inst, resi, expi, MAX_TEST);
}

static void testIsUpper(t_inst *inst) {
	int64_t	resi[MAX_TEST];
	int64_t	expi[MAX_TEST];

	resi[0] = ft_isupper('y'), expi[0] = isupper('y');
	resi[1] = !ft_isupper('Y'), expi[1] = !isupper('Y');
	resi[2] = ft_isupper('\n'), expi[2] = isupper('\n');
	resi[3] = ft_isupper('7'), expi[3] = isupper('7');
	resi[4] = ft_isupper('@'), expi[4] = isupper('@');
	resi[5] = ft_isupper('\r'), expi[5] = isupper('\r');
	resi[6] = ft_isupper('~'), expi[6] = isupper('~');
	test_int(inst, resi, expi, MAX_TEST);
}

static void testAtoi(t_inst *inst) {
	int64_t	resi[MAX_TEST];
	int64_t	expi[MAX_TEST];

	resi[0] = ft_atoi(" +42  "), expi[0] = atoi(" +42  ");
	resi[1] = ft_atoi(" -42  "), expi[1] = atoi(" -42  ");
	resi[2] = ft_atoi(" abc 42"), expi[2] = atoi(" abc 42");
	resi[3] = ft_atoi("000042"), expi[3] = atoi("000042");
	resi[4] = ft_atoi(""), expi[4] = atoi("");
	resi[5] = ft_atoi("-2147483648"), expi[5] = atoi("-2147483648");
	resi[6] = ft_atoi("2147483647"), expi[6] = atoi("2147483647");
	test_int(inst, resi, expi, MAX_TEST);
}

static void testBZero(t_inst *inst) {
	char str[10] = "123456789";
	char str2[10] = "123456789";
	char str3[10] = "abcdefghi";
	char str4[10] = "abcdefghi";
	int64_t	resi[3];
	int64_t	expi[3] = {0};

	ft_bzero(str, 10);
	bzero(str2, 10);
	ft_bzero(str3, 0);
	bzero(str4, 0);
	resi[1] = memcmp(str3, str4, 10), resi[0] = memcmp(str, str2, 10);
	test_int(inst, resi, expi, 2);
}

static void testCalloc(t_inst *inst) {
	void	*resv[6];
	void	*expv[6];

	resv[0] = ft_calloc(10, 1), expv[0] = calloc(10, 1);
	resv[1] = ft_calloc(INT32_MAX, 2), expv[1] = calloc(INT32_MAX, 2);
	resv[2] = ft_calloc(0, 0), expv[2] = calloc(0, 0);
	resv[3] = ft_calloc(0, 1), expv[3] = calloc(0, 1);
	resv[4] = ft_calloc(1, 0), expv[4] = calloc(1, 0);
	resv[5] = ft_calloc(INT32_MAX, 5), expv[5] = calloc(INT32_MAX, 5);
	test_ptr(inst, resv, expv, 6);
	quick_test_int(*inst, memcmp(resv[0], expv[0], 10), 0);
}

static void testIsAlNum(t_inst *inst) {
	int64_t	resi[MAX_TEST];
	int64_t	expi[MAX_TEST];

	resi[0] = !ft_isalnum('y'), expi[0] = !isalnum('y');
	resi[1] = !ft_isalnum('Y'), expi[1] = !isalnum('Y');
	resi[2] = ft_isalnum(' '), expi[2] = isalnum(' ');
	resi[3] = !ft_isalnum('7'), expi[3] = !isalnum('7');
	resi[4] = ft_isalnum('@'), expi[4] = isalnum('@');
	resi[5] = ft_isalnum('\r'), expi[5] = isalnum('\r');
	resi[6] = ft_isalnum('~'), expi[6] = isalnum('~');
	test_int(inst, resi, expi, MAX_TEST);
}

static void testIsAlpha(t_inst *inst) {
	int64_t	resi[MAX_TEST];
	int64_t	expi[MAX_TEST];

	resi[0] = !ft_isalpha('y'), expi[0] = !isalpha('y');
	resi[1] = !ft_isalpha('Y'), expi[1] = !isalpha('Y');
	resi[2] = ft_isalpha(' '), expi[2] = isalpha(' ');
	resi[3] = ft_isalpha('7'), expi[3] = isalpha('7');
	resi[4] = ft_isalpha('@'), expi[4] = isalpha('@');
	resi[5] = ft_isalpha('\r'), expi[5] = isalpha('\r');
	resi[6] = ft_isalpha('~'), expi[6] = isalpha('~');
	test_int(inst, resi, expi, MAX_TEST);
}

static void testIsDigit(t_inst *inst) {
	int64_t	resi[MAX_TEST];
	int64_t	expi[MAX_TEST];

	resi[0] = ft_isdigit('y'), expi[0] = isdigit('y');
	resi[1] = ft_isdigit('Y'), expi[1] = isdigit('Y');
	resi[2] = ft_isdigit(' '), expi[2] = isdigit(' ');
	resi[3] = !ft_isdigit('7'), expi[3] = !isdigit('7');
	resi[4] = ft_isdigit('@'), expi[4] = isdigit('@');
	resi[5] = ft_isdigit('\r'), expi[5] = isdigit('\r');
	resi[6] = ft_isdigit('~'), expi[6] = isdigit('~');
	test_int(inst, resi, expi, MAX_TEST);
}

static void testIsPrint(t_inst *inst) {
	int64_t	resi[MAX_TEST];
	int64_t	expi[MAX_TEST];

	resi[0] = !ft_isprint('y'), expi[0] = !isprint('y');
	resi[1] = !ft_isprint('Y'), expi[1] = !isprint('Y');
	resi[2] = !ft_isprint(' '), expi[2] = !isprint(' ');
	resi[3] = !ft_isprint('7'), expi[3] = !isprint('7');
	resi[4] = !ft_isprint('@'), expi[4] = !isprint('@');
	resi[5] = ft_isprint('\r'), expi[5] = isprint('\r');
	resi[6] = !ft_isprint('~'), expi[6] = !isprint('~');
	test_int(inst, resi, expi, MAX_TEST);
}

static void testMemChr(t_inst *inst) {
	char	str[] = "42";
	char	str2[] = "4242";
	void	*resi[MAX_TEST];
	void	*expi[MAX_TEST];

	resi[0] = ft_memchr(str, '1', 3), expi[0] = memchr(str, '1', 3);
	resi[1] = ft_memchr(str, '4', 3), expi[1] = memchr(str, '4', 3);
	resi[2] = ft_memchr(str, '2', 3), expi[2] = memchr(str, '2', 3);
	resi[3] = ft_memchr(str2, '4', 5), expi[3] = memchr(str2, '4', 5);
	resi[4] = ft_memchr(str2, '\0', 5), expi[4] = memchr(str2, '\0', 5);
	resi[5] = ft_memchr(str2, '\0', 0), expi[5] = memchr(str2, '\0', 0);
	resi[6] = ft_memchr(str2, '1', 5), expi[6] = memchr(str2, '1', 5);
	test_ptr(inst, resi, expi, MAX_TEST);
}

static void testMemCmp(t_inst *inst) {
	char	str[] = "42";
	char	str2[] = "4242";
	int64_t	resi[MAX_TEST];
	int64_t	expi[MAX_TEST];

	resi[0] = ft_memcmp(str, str, 3), expi[0] = memcmp(str, str, 3);
	resi[1] = ft_memcmp(str, str2, 3), expi[1] = memcmp(str, str2, 3);
	resi[2] = ft_memcmp(str, str2, 2), expi[2] = memcmp(str, str2, 2);
	resi[3] = ft_memcmp(str2, str2, 5), expi[3] = memcmp(str2, str2, 5);
	resi[4] = ft_memcmp(str2, str, 2), expi[4] = memcmp(str2, str, 2);
	resi[5] = ft_memcmp(str2, str, 0), expi[5] = memcmp(str2, str, 0);
	resi[6] = ft_memcmp(str2, str2, 100), expi[6] = memcmp(str2, str2, 100);
	test_int(inst, resi, expi, MAX_TEST);
}

static void testMemCpy(t_inst *inst) {
	char	str[] = "42";
	char	str2[4];
	char	str3[4];
	char	str4[4];
	char	str5[4];
	void	*resv[4];
	void	*expv[4];
	int64_t	resi[4];
	int64_t	expi[4];

	resv[0] = ft_memcpy(str2, str, 3), resi[0] = memcmp(str2, str, 3);
	expv[0] = memcpy(str2, str, 3), expi[0] = memcmp(str2, str, 3);
	resv[1] = ft_memcpy(str3, str2, 2), resi[1] = memcmp(str3, str2, 2);
	expv[1] = memcpy(str3, str2, 2), expi[1] = memcmp(str3, str2, 2);
	resv[2] = ft_memcpy(str4, str3, 4), resi[2] = memcmp(str4, str3, 4);
	expv[2] = memcpy(str4, str3, 4), expi[2] = memcmp(str4, str3, 4);
	resv[3] = ft_memcpy(str5, str4, 0), resi[3] = memcmp(str5, str4, 0);
	expv[3] = memcpy(str5, str4, 0), expi[3] = memcmp(str5, str4, 0);
	test_ptr(inst, resv, expv, 4);
	test_int(inst, resi, expi, 4);
}

static void testMemSet(t_inst *inst) {
	char str[10] = "123456789";
	char str2[10] = "123456789";
	char str3[10] = "abcdefghi";
	char str4[10] = "abcdefghi";
	int64_t	resi[2];
	int64_t	expi[2] = {0, 0};

	ft_memset(str, 'a', 10);
	memset(str2, 'a', 10);
	ft_memset(str3, '9', 1);
	memset(str4, '9', 1);
	resi[1] = memcmp(str3, str4, 10), resi[0] = memcmp(str, str2, 10);
	test_int(inst, resi, expi, 2);
}

int main() {
	t_inst	inst[MAX_TEST];

	inst[0] = init_instance_default(NULL);
	inst[6] = inst[5] = inst[4] = inst[3] = inst[2] = inst[1] = inst[0];
	inst[0].title = (t_text){"ft_islower", COLOR_YELLOW};
	inst[0].desc = (t_text){"Testing extras", COLOR_CYAN};
	testIsLower(inst);

	inst[0].title.text = "ft_isspace";
	testIsSpace(inst);

	inst[0].title.text = "ft_isupper";
	testIsUpper(inst);

	inst[0].title.text = "ft_atoi";
	inst[0].desc.text = "Testing part 1";
	testAtoi(inst);

	inst[0].title.text = "ft_bzero";
	testBZero(inst);

	inst[0].title.text = "ft_calloc";
	inst[4].comp_type = inst[3].comp_type = inst[2].comp_type = inst[0].comp_type = LESS_EQUAL;
	testCalloc(inst);

	inst[0].title.text = "ft_isalnum";
	inst[4].comp_type = inst[3].comp_type = inst[2].comp_type = inst[0].comp_type = EQUAL;
	testIsAlNum(inst);

	inst[0].title.text = "ft_isalpha";
	testIsAlpha(inst);

	// isascii doesn't exist in c99
	// inst[0].title.text = "ft_isascii";
	// testIsAscii(inst);

	inst[0].title.text = "ft_isdigit";
	testIsDigit(inst);

	inst[0].title.text = "ft_isprint";
	testIsPrint(inst);

	inst[0].title.text = "ft_memchr";
	testMemChr(inst);

	inst[0].title.text = "ft_memcmp";
	testMemCmp(inst);

	inst[0].title.text = "ft_memcpy";
	testMemCpy(inst);

	inst[0].title.text = "ft_memset";
	testMemSet(inst);
}
