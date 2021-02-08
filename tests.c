#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "svsnprintf.c"


#define TERR_OUT(fmt, ...) fprintf(stderr, "%s:%u: " fmt "\n", \
  __FILE__, __LINE__, ##__VA_ARGS__)
#define TERR(fmt, ...) do { TERR_OUT(fmt, ##__VA_ARGS__); return 0; } while (0)
#define TEST_NULL {NULL, NULL}
struct test {
	int (*test)(void);
	char *title;
};

int
test0_0(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%", &fmtspec);
	if (ret != 1)
		TERR("ret must be 1 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_fun != NULL)
		TERR("conv_fun must be NULL instead of %p",
		  fmtspec.conv_fun);

	return 1;
}

int
test0_1(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%%", &fmtspec);
	if (ret != 2)
		TERR("ret must be 2 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_fun != conv_PERCENT)
		TERR("conv_spec must be %p instead of %p",
		  conv_PERCENT, fmtspec.conv_fun);

	return 1;
}

int
test0_2(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%N", &fmtspec);
	if (ret != 2)
		TERR("ret must be 2 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_fun != NULL)
		TERR("conv_spec must be NULL instead of %p",
		  fmtspec.conv_fun);

	return 1;
}

int
test0_2_1(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("% n", &fmtspec);
	if (ret != 3)
		TERR("ret must be 3 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_fun != NULL)
		TERR("conv_spec must be NULL instead of %p",
		  fmtspec.conv_fun);

	return 1;
}

int
test0_2_2(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("% ", &fmtspec);
	if (ret != 2)
		TERR("ret must be 2 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_fun != NULL)
		TERR("conv_spec must be NULL instead of %p",
		  fmtspec.conv_fun);

	return 1;
}

int
test0_3(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%d", &fmtspec);
	if (ret != 2)
		TERR("ret must be 2 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_d)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_d, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);

	return 1;
}

int
test0_3_1(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%hhd", &fmtspec);
	if (ret != 4)
		TERR("ret must be 4 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_hh)
		TERR("len_mod must be %d instead of %d",
		  len_mod_hh, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_d)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_d, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);

	return 1;
}

int
test0_3_2(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%hd", &fmtspec);
	if (ret != 3)
		TERR("ret must be 3 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_h)
		TERR("len_mod must be %d instead of %d",
		  len_mod_h, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_d)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_d, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);

	return 1;
}

int
test0_3_3(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%ld", &fmtspec);
	if (ret != 3)
		TERR("ret must be 3 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_l)
		TERR("len_mod must be %d instead of %d",
		  len_mod_l, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_d)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_d, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);

	return 1;
}

int
test0_3_4(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%lld", &fmtspec);
	if (ret != 4)
		TERR("ret must be 4 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_ll)
		TERR("len_mod must be %d instead of %d",
		  len_mod_ll, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_d)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_d, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);

	return 1;
}

int
test0_4(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%o", &fmtspec);
	if (ret != 2)
		TERR("ret must be 2 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_o)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_o, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);

	return 1;
}

int
test0_5(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%u", &fmtspec);
	if (ret != 2)
		TERR("ret must be 2 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_u)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_u, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);

	return 1;
}

int
test0_6(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%x", &fmtspec);
	if (ret != 2)
		TERR("ret must be 2 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_x)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_x, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);

	return 1;
}

int
test0_7(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%X", &fmtspec);
	if (ret != 2)
		TERR("ret must be 2 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_X)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_X, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);

	return 1;
}

int
test0_8(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%f", &fmtspec);
	if (ret != 2)
		TERR("ret must be 2 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_f)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_f, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_double)
		TERR("conv_fun must be %p instead of %p",
		  conv_double, fmtspec.conv_fun);

	return 1;
}

int
test0_9(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%c", &fmtspec);
	if (ret != 2)
		TERR("ret must be 2 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_c)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_c, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_char)
		TERR("conv_fun must be %p instead of %p",
		  conv_char, fmtspec.conv_fun);

	return 1;
}

int
test0_10(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%s", &fmtspec);
	if (ret != 2)
		TERR("ret must be 2 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_s)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_s, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_str)
		TERR("conv_fun must be %p instead of %p",
		  conv_str, fmtspec.conv_fun);

	return 1;
}

int
test0_11(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%0d", &fmtspec);
	if (ret != 3)
		TERR("ret must be 3 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_zero)
		TERR("pad_type must be %d instead of %d",
		  pad_with_zero, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_d)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_d, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);

	return 1;
}

int
test0_12(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%+d", &fmtspec);
	if (ret != 3)
		TERR("ret must be 3 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_d)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_d, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);
	if (fmtspec.use_plus_sign != 1)
		TERR("use_plus_sign must be 1 instead of %p", fmtspec.use_plus_sign);

	return 1;
}

int
test0_13(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%+0d", &fmtspec);
	if (ret != 4)
		TERR("ret must be 4 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_zero)
		TERR("pad_type must be %d instead of %d",
		  pad_with_zero, fmtspec.pad_type);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_d)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_d, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);
	if (fmtspec.use_plus_sign != 1)
		TERR("use_plus_sign must be 1 instead of %p", fmtspec.use_plus_sign);

	return 1;
}

int
test0_14(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%-d", &fmtspec);
	if (ret != 3)
		TERR("ret must be 3 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.left_adjust != 1)
		TERR("left_adjust must be 1 instead of %p", fmtspec.left_adjust);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_d)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_d, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);
	if (fmtspec.use_plus_sign != 0)
		TERR("use_plus_sign must be 0 instead of %p", fmtspec.use_plus_sign);

	return 1;
}

int
test0_15(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%-0d", &fmtspec);
	if (ret != 4)
		TERR("ret must be 4 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.left_adjust != 1)
		TERR("left_adjust must be 1 instead of %p", fmtspec.left_adjust);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_d)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_d, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);
	if (fmtspec.use_plus_sign != 0)
		TERR("use_plus_sign must be 0 instead of %p", fmtspec.use_plus_sign);

	return 1;
}

int
test0_16(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%-+0d", &fmtspec);
	if (ret != 5)
		TERR("ret must be 5 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.left_adjust != 1)
		TERR("left_adjust must be 1 instead of %p", fmtspec.left_adjust);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_d)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_d, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);
	if (fmtspec.use_plus_sign != 1)
		TERR("use_plus_sign must be 1 instead of %p", fmtspec.use_plus_sign);

	return 1;
}

int
test0_17(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%b", &fmtspec);
	if (ret != 2)
		TERR("ret must be 2 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.left_adjust != 0)
		TERR("left_adjust must be 0 instead of %p", fmtspec.left_adjust);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_b)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_b, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);
	if (fmtspec.use_plus_sign != 0)
		TERR("use_plus_sign must be 0 instead of %p", fmtspec.use_plus_sign);

	return 1;
}

int
test0_18(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%p", &fmtspec);
	if (ret != 2)
		TERR("ret must be 2 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.alternate_form != 0)
		TERR("alternate_form must be 0 instead of %p",
		  fmtspec.alternate_form);
	if (fmtspec.left_adjust != 0)
		TERR("left_adjust must be 0 instead of %p", fmtspec.left_adjust);
	if (fmtspec.width != 0)
		TERR("width must be 0 instead of %d", fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_p)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_p, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);
	if (fmtspec.use_plus_sign != 0)
		TERR("use_plus_sign must be 0 instead of %p", fmtspec.use_plus_sign);

	return 1;
}

int
test0_19(void)
{
	int ret;
	struct _fmtspec fmtspec = FMTSPEC_INITIAL;

	ret = _fmtspec_collect("%*d", &fmtspec);
	if (ret != 3)
		TERR("ret must be 3 instead of %d", ret);
	if (fmtspec.pad_type != pad_with_space)
		TERR("pad_type must be %d instead of %d",
		  pad_with_space, fmtspec.pad_type);
	if (fmtspec.alternate_form != 0)
		TERR("alternate_form must be 0 instead of %p",
		  fmtspec.alternate_form);
	if (fmtspec.left_adjust != 0)
		TERR("left_adjust must be 0 instead of %p", fmtspec.left_adjust);
	if (fmtspec.width != WIDTH_ASTERISK)
		TERR("width must be %d instead of %d",
		  WIDTH_ASTERISK, fmtspec.width);
	if (fmtspec.precision != -1)
		TERR("precision must be -1 instead of %d", fmtspec.precision);
	if (fmtspec.len_mod != len_mod_none)
		TERR("len_mod must be %d instead of %d",
		  len_mod_none, fmtspec.len_mod);
	if (fmtspec.conv_spec != conv_spec_d)
		TERR("conv_spec must be %d instead of %d",
		  conv_spec_d, fmtspec.conv_spec);
	if (fmtspec.conv_fun != conv_int)
		TERR("conv_fun must be %p instead of %p",
		  conv_int, fmtspec.conv_fun);
	if (fmtspec.use_plus_sign != 0)
		TERR("use_plus_sign must be 0 instead of %p", fmtspec.use_plus_sign);

	return 1;
}

int
test1_0(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "");
	if (ret != 0)
		TERR("ret must be 0 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_0_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 10, "");
	if (ret != 0)
		TERR("ret must be 0 instead of %d", ret);
	if (strcmp(buf, "") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 1; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_0_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(NULL, 10, "");
	if (ret != 0)
		TERR("ret must be 0 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_0_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(NULL, 10, "some text");
	if (ret != 9)
		TERR("ret must be 9 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_0_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, NULL);
	if (ret != 0)
		TERR("ret must be 0 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_0_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 10, NULL);
	if (ret != 0)
		TERR("ret must be 0 instead of %d", ret);
	if (strcmp(buf, "") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 1; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_0_6(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some %s text", NULL);
	if (ret != 16)
		TERR("ret must be 16 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_0_7(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 8, "some %s text", NULL);
	if (ret != 16)
		TERR("ret must be 16 instead of %d", ret);
	if (strcmp(buf, "some (n") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 8; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_0_8(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "some %s text", NULL);
	if (ret != 16)
		TERR("ret must be 16 instead of %d", ret);
	if (strcmp(buf, "some (null) text") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 17; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some words");
	if (ret != 10)
		TERR("ret must be 10 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "%");
	if (ret != 10)
		TERR("ret must be 10 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_2_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "%");
	if (ret != 10)
		TERR("ret must be 10 instead of %d", ret);
	if (strcmp(buf, "%<-ERRSPEC") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 11; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "%%");
	if (ret != 1)
		TERR("ret must be 1 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_3_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some%%");
	if (ret != 5)
		TERR("ret must be 5 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_3_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "%%word");
	if (ret != 5)
		TERR("ret must be 5 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_3_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some%%word");
	if (ret != 9)
		TERR("ret must be 9 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_3_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%%word");
	if (ret != 9)
		TERR("ret must be 9 instead of %d", ret);
	if (strcmp(buf, "some%word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 10; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "%d", 5);
	if (ret != 1)
		TERR("ret must be 1 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test1_4_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "%d", -5);
	if (ret != 2)
		TERR("ret must be 2 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "%d", 5);
	if (ret != 1)
		TERR("ret must be 1 instead of %d", ret);
	if (strcmp(buf, "5") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 2; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_4_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%d", 5);
	if (ret != 5)
		TERR("ret must be 5 instead of %d", ret);
	if (strcmp(buf, "some5") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 6; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_4_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "%dword", 5);
	if (ret != 5)
		TERR("ret must be 5 instead of %d", ret);
	if (strcmp(buf, "5word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 6; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_4_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%dword", 5);
	if (ret != 9)
		TERR("ret must be 9 instead of %d", ret);
	if (strcmp(buf, "some5word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 10; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_4_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "%d", 0);
	if (ret != 1)
		TERR("ret must be 1 instead of %d", ret);
	if (strcmp(buf, "0") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 2; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%hhdword", 0x7172737475767778);
	if (ret != 11)
		TERR("ret must be 11 instead of %d %s", ret, buf);
	if (strcmp(buf, "some120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 12; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_6(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%hdword", 0x7172737475767778);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some30584word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_7(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%dword", 0x7172737475767778);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "some1970698104word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 19; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_8(void)
{
	int ret, i, res_size;
	char buf[1024], *res_str;

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%ldword", 0x7172737475767778);
	if (ret != 27)
		TERR("ret must be 27 instead of %d", ret);
	if (strcmp(buf, "some8174723217654970232word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 28; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_9(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%lldword", 0x7172737475767778);
	if (ret != 27)
		TERR("ret must be 27 instead of %d", ret);
	if (strcmp(buf, "some8174723217654970232word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 28; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_10(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%hhuword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 11)
		TERR("ret must be 11 instead of %d %s", ret, buf);
	if (strcmp(buf, "some248word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 12; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_11(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%huword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some63480word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_12(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%uword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "some4126603256word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 19; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_13(void)
{
	int ret, i, res_size;
	char buf[1024], *res_str;

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%luword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 28)
		TERR("ret must be 28 instead of %d", ret);
	if (strcmp(buf, "some17434265340928784376word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 29; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_14(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%lluword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 28)
		TERR("ret must be 28 instead of %d", ret);
	if (strcmp(buf, "some17434265340928784376word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 29; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_15(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 10)
		TERR("ret must be 10 instead of %d %s", ret, buf);
	if (strcmp(buf, "some-8word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 11; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_16(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%hdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some-2056word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_17(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%dword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "some-168364040word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 19; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_18(void)
{
	int ret, i, res_size;
	char buf[1024], *res_str;

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%ldword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 28)
		TERR("ret must be 28 instead of %d", ret);
	if (strcmp(buf, "some-1012478732780767240word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 29; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_19(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%lldword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 28)
		TERR("ret must be 28 instead of %d", ret);
	if (strcmp(buf, "some-1012478732780767240word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 29; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_20(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%04hhdword", 0x7172737475767778);
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "some0120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 13; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_20_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%04hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "some-008word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 13; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_20_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%04d-%02d-%02dword", 2021, 01, 01);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "some2021-01-01word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 19; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_21(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%.4hhdword", 0x7172737475767778);
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "some0120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 13; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_21_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%.4hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some-0008word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_22(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%05.4hhdword", 0x7172737475767778);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some00120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_22_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%04.5hhdword", 0x7172737475767778);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some00120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_22_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%05.4hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some-0008word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_22_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%04.5hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some-00008word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_22_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%5.4hhdword", 0x7172737475767778);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some 0120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_22_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%4.5hhdword", 0x7172737475767778);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some00120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_22_6(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%6.4hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some -0008word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_22_7(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%4.5hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some-00008word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_23(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+dword", 0x7172737475767778);
	if (ret != 19)
		TERR("ret must be 19 instead of %d", ret);
	if (strcmp(buf, "some+1970698104word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 20; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_23_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+dword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "some-168364040word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 19; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_24(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+04hhdword", 0x7172737475767778);
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "some+120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 13; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_24_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+05hhdword", 0x7172737475767778);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some+0120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_24_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+04hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "some-008word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 13; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_25(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+.4hhdword", 0x7172737475767778);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some+0120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_25_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+.4hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some-0008word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_26(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+05.4hhdword", 0x7172737475767778);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some+0120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_26_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+04.5hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some+00120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_26_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+05.4hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some-0008word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_26_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+04.5hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some-00008word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_26_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+6.4hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some +0120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_26_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+4.5hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some+00120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_26_6(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+6.4hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some -0008word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_26_7(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+4.5hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some-00008word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_27(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-dword", 0x7172737475767778);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "some1970698104word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 19; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_27_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-15dword", 0x7172737475767778);
	if (ret != 23)
		TERR("ret must be 23 instead of %d", ret);
	if (strcmp(buf, "some1970698104     word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 26; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_27_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+15dword", 0x7172737475767778);
	if (ret != 23)
		TERR("ret must be 23 instead of %d", ret);
	if (strcmp(buf, "some+1970698104    word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 26; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_27_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-5dword", 0x7172737475767778);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "some1970698104word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 19; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_27_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+5dword", 0x7172737475767778);
	if (ret != 19)
		TERR("ret must be 19 instead of %d", ret);
	if (strcmp(buf, "some+1970698104word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 20; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_27_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-15dword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 23)
		TERR("ret must be 23 instead of %d", ret);
	if (strcmp(buf, "some-168364040     word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 24; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_27_6(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+.4hhdword", 0x7172737475767778);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some+0120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_27_7(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+.4hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some-0008word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_27_8(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some+0120 word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_27_9(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+4.5hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some+00120word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_27_10(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some-0008 word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_27_11(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+4.5hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some-00008word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_28(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some%-+4.5hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_29_0(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 3, "some%+6.4hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "so") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 3; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_29_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 5, "some%+6.4hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 5; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_29_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 6, "some%+6.4hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some ") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 6; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_29_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 7, "some%+6.4hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some +") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 7; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_29_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 7, "some%6.4hhdword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some -") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 7; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_29_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 8, "some%+6.4hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some +0") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 8; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_29_6(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 9, "some%+6.4hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some +01") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 9; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_29_7(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 10, "some%+6.4hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some +012") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 10; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_29_8(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 11, "some%+6.4hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some +0120") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 11; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_29_9(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 12, "some%+6.4hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some +0120w") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 12; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_29_10(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 10, "some%-+6.4hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some+0120") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 10; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_29_11(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 11, "some%-+6.4hhdword", 0x7172737475767778);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some+0120 ") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 11; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_30(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some%*dword", 5, 12);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_30_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "some%*dword", 5, 12);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some   12word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_30_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "some%0*dword", 5, 12);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some00012word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_30_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "some%01*dword", 5, 12);
	if (ret != 17)
		TERR("ret must be 17 instead of %d", ret);
	if (strcmp(buf, "some%01*<-ERRSPEC") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 18; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test2_30_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "some%*0dword", 5, 12);
	if (ret != 16)
		TERR("ret must be 16 instead of %d", ret);
	if (strcmp(buf, "some%*0<-ERRSPEC") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 17; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test3_0(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4hhoword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some0370  word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test3_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4howord", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some173770word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test3_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4oword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 19)
		TERR("ret must be 19 instead of %d", ret);
	if (strcmp(buf, "some36575573770word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 20; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test3_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4loword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 30)
		TERR("ret must be 30 instead of %d", ret);
	if (strcmp(buf, "some1707627477236575573770word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 31; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test3_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4lloword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 30)
		TERR("ret must be 30 instead of %d", ret);
	if (strcmp(buf, "some1707627477236575573770word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 31; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test3_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some%-+6.4lloword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 30)
		TERR("ret must be 30 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test4_0(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4hhxword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some00f8  word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test4_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4hxword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "somef7f8  word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test4_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4xword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 16)
		TERR("ret must be 16 instead of %d", ret);
	if (strcmp(buf, "somef5f6f7f8word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 19; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test4_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4lxword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 24)
		TERR("ret must be 24 instead of %d", ret);
	if (strcmp(buf, "somef1f2f3f4f5f6f7f8word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 25; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test4_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4lxword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 24)
		TERR("ret must be 24 instead of %d", ret);
	if (strcmp(buf, "somef1f2f3f4f5f6f7f8word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 25; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test4_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some%-+6.4lxword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 24)
		TERR("ret must be 24 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test5_0(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4hhXword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some00F8  word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test5_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4hXword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "someF7F8  word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test5_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4Xword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 16)
		TERR("ret must be 16 instead of %d", ret);
	if (strcmp(buf, "someF5F6F7F8word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 19; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test5_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4lXword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 24)
		TERR("ret must be 24 instead of %d", ret);
	if (strcmp(buf, "someF1F2F3F4F5F6F7F8word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 25; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test5_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4lXword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 24)
		TERR("ret must be 24 instead of %d", ret);
	if (strcmp(buf, "someF1F2F3F4F5F6F7F8word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 25; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test5_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some%-+6.4lXword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 24)
		TERR("ret must be 24 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test6_0(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+12.10hhbword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 20)
		TERR("ret must be 20 instead of %d", ret);
	if (strcmp(buf, "some0011111000  word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 21; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test6_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4hbword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 24)
		TERR("ret must be 24 instead of %d", ret);
	if (strcmp(buf, "some1111011111111000word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 25; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test6_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4bword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 40)
		TERR("ret must be 40 instead of %d", ret);
	if (strcmp(buf, "some11110101111101101111011111111000word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 41; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test6_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4lbword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 72)
		TERR("ret must be 72 instead of %d", ret);
	if (strcmp(buf, "some1111000111110010111100111111010011110101111101101111011111111000word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 73; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test6_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+6.4lbword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 72)
		TERR("ret must be 72 instead of %d", ret);
	if (strcmp(buf, "some1111000111110010111100111111010011110101111101101111011111111000word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 73; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test6_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some%-+6.4lbword", 0xF1F2F3F4F5F6F7F8);
	if (ret != 72)
		TERR("ret must be 72 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_0(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%fword", 33.87654);
	if (ret != 17)
		TERR("ret must be 17 instead of %d", ret);
	if (strcmp(buf, "some33.876540word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 18; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%.0fword", 33.87654);
	if (ret != 10)
		TERR("ret must be 10 instead of %d", ret);
	if (strcmp(buf, "some34word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 11; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%.1fword", 33.87654);
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "some33.9word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 13; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%.2fword", 33.87654);
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some33.88word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%.3fword", 33.87654);
	if (ret != 14)
		TERR("ret must be 14 instead of %d", ret);
	if (strcmp(buf, "some33.877word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 15; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%.4fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some33.8765word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 16; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_6(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%07.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some0033.88word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 16; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_6_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+07.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some+033.88word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 16; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_7(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some  33.88word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 16; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_7_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%+7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some +33.88word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 16; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_7_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%7.2fword", -33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some -33.88word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 16; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_8(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some33.88  word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 16; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_8_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-+7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some+33.88 word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 16; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_8_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-7.2fword", -33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some-33.88 word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 16; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_9(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some%-7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_0(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 4, "some%7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "som") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 4; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 5, "some%7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 5; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 6, "some%7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some ") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 6; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 7, "some%7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some  ") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 7; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 8, "some%7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some  3") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 8; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 6, "some%+7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some ") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 6; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_6(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 7, "some%+7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some +") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 7; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_7(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 8, "some%+7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some +3") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 8; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_8(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 8, "some%+7.2fword", -33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some -3") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 8; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_9(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 8, "some%+7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some +3") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 8; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_10(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 9, "some%+7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some +33") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 9; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_11(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 10, "some%+7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some +33.") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 10; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_12(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 11, "some%+7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some +33.8") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 11; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_13(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 12, "some%+7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some +33.88") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 12; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_14(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 13, "some%+7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some +33.88w") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 13; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_15(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 12, "some%-+7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some+33.88 ") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 12; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_10_16(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 13, "some%-+7.2fword", 33.87654);
	if (ret != 15)
		TERR("ret must be 15 instead of %d", ret);
	if (strcmp(buf, "some+33.88 w") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 13; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_11(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some%*fword", 5, 1.2);
	if (ret != 16)
		TERR("ret must be 16 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_11_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "some%*fword", 10, 1.2);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "some  1.200000word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 22; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_11_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "some%0*fword", 10, 1.2);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "some001.200000word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 22; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_11_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "some%01*fword", 10, 1.2);
	if (ret != 17)
		TERR("ret must be 17 instead of %d", ret);
	if (strcmp(buf, "some%01*<-ERRSPEC") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 18; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test7_11_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "some%*0fword", 10, 1.2);
	if (ret != 16)
		TERR("ret must be 16 instead of %d", ret);
	if (strcmp(buf, "some%*0<-ERRSPEC") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 17; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test8_0(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%cword", 'A');
	if (ret != 9)
		TERR("ret must be 9 instead of %d", ret);
	if (strcmp(buf, "someAword") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 10; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test8_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some%cword", 'A');
	if (ret != 9)
		TERR("ret must be 9 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_0(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "sometestword") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 13; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%sword", "");
	if (ret != 8)
		TERR("ret must be 8 instead of %d", ret);
	if (strcmp(buf, "someword") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 9; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%.2sword", "test");
	if (ret != 10)
		TERR("ret must be 10 instead of %d", ret);
	if (strcmp(buf, "someteword") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 11; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_2_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%.0sword", "test");
	if (ret != 8)
		TERR("ret must be 8 instead of %d", ret);
	if (strcmp(buf, "someword") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 9; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "some  teword") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 13; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%-4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "somete  word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 13; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some%-4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_6_0(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 4, "some%4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "som") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 4; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_6_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 5, "some%4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "some") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 5; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_6_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 6, "some%4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "some ") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 6; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_6_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 7, "some%4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "some  ") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 7; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_6_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 8, "some%4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "some  t") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 8; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_6_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 9, "some%4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "some  te") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 9; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_6_6(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 10, "some%4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "some  tew") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 10; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_6_7(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 6, "some%-4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "somet") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 6; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_6_8(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 7, "some%-4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "somete") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 7; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_6_9(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 8, "some%-4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "somete ") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 8; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_6_10(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 9, "some%-4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "somete  ") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 9; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_6_11(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 10, "some%-4.2sword", "test");
	if (ret != 12)
		TERR("ret must be 12 instead of %d", ret);
	if (strcmp(buf, "somete  w") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 10; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_7(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "some%*sword", 5, "Ab");
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_7_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "some%*sword", 5, "Ab");
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some   Abword") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_7_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "some%0*sword", 5, "Ab");
	if (ret != 13)
		TERR("ret must be 13 instead of %d", ret);
	if (strcmp(buf, "some   Abword") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 14; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_7_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "some%01*sword", 5, "Ab");
	if (ret != 17)
		TERR("ret must be 17 instead of %d", ret);
	if (strcmp(buf, "some%01*<-ERRSPEC") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 18; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test9_7_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "some%*0sword", 5, "Ab");
	if (ret != 16)
		TERR("ret must be 16 instead of %d", ret);
	if (strcmp(buf, "some%*0<-ERRSPEC") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 17; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test10_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 100, "some%pword", 0xA1B2C3D4E5F6F7F8);
	if (ret != 26)
		TERR("ret must be 26 instead of %d", ret);
	if (strcmp(buf, "some0xa1b2c3d4e5f6f7f8word") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 27; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test11_0(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 0, "wrong % Spec", NULL);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	for(i = 0; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test11_1(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 9, "wrong % Spec", NULL);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "wrong % ") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 9; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test11_2(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 10, "wrong % Spec", NULL);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "wrong % S") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 10; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test11_3(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 11, "wrong % Spec", NULL);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "wrong % S<") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 11; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test11_4(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 18, "wrong % Spec", NULL);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "wrong % S<-ERRSPE") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 18; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test11_5(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 19, "wrong % Spec", NULL);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "wrong % S<-ERRSPEC") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 19; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test11_6(void)
{
	int ret, i;
	char buf[1024];

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	ret = ssnprintf(buf, 20, "wrong % Spec", NULL);
	if (ret != 18)
		TERR("ret must be 18 instead of %d", ret);
	if (strcmp(buf, "wrong % S<-ERRSPEC") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 19; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}

int
test12(void)
{
	int ret, i, len;
	char buf[1024], *pos;

	for(i = 0; i < 1024; i++)
		buf[i] = 1;
	pos = buf;
	len = 10;
	ret = ssnprintf(pos, len, "test");
	if (ret != 4)
		TERR("ret must be 4 instead of %d", ret);
	pos += ret;
	len -= (ret < len) ? ret : len;

	ret = ssnprintf(pos, len, "test");
	if (ret != 4)
		TERR("ret must be 4 instead of %d", ret);
	pos += ret;
	len -= (ret < len) ? ret : len;

	ret = ssnprintf(pos, len, "test");
	if (ret != 4)
		TERR("ret must be 4 instead of %d", ret);
	pos += ret;
	len -= (ret < len) ? ret : len;

	ret = ssnprintf(pos, len, "test");
	if (ret != 4)
		TERR("ret must be 4 instead of %d", ret);
	pos += ret;
	len -= (ret < len) ? ret : len;

	if (strcmp(buf, "testtestt") != 0)
		TERR("result is wrong: '%s'", buf);
	for(i = 10; i < 1024; i++)
		if (buf[i] != 1)
			TERR("buf[%d] is %d", i, buf[i]);

	return 1;
}


struct test tests[] = {
	{test0_0, "_fmtspec_collect() with single %"},
	{test0_1, "_fmtspec_collect() with %%"},
	{test0_2, "_fmtspec_collect() with wrong spec"},
	{test0_2_1, "_fmtspec_collect() with wrong spec(% )"},
	{test0_2_2, "_fmtspec_collect() with wrong spec(% )"},
	{test0_3, "_fmtspec_collect() with %d"},
	{test0_3_1, "_fmtspec_collect() with %hhd"},
	{test0_3_2, "_fmtspec_collect() with %hd"},
	{test0_3_3, "_fmtspec_collect() with %ld"},
	{test0_3_4, "_fmtspec_collect() with %lld"},
	{test0_4, "_fmtspec_collect() with %o"},
	{test0_5, "_fmtspec_collect() with %u"},
	{test0_6, "_fmtspec_collect() with %x"},
	{test0_7, "_fmtspec_collect() with %X"},
	{test0_8, "_fmtspec_collect() with %f"},
	{test0_9, "_fmtspec_collect() with %c"},
	{test0_10, "_fmtspec_collect() with %s"},
	{test0_11, "_fmtspec_collect() with %0d"},
	{test0_12, "_fmtspec_collect() with %+d"},
	{test0_13, "_fmtspec_collect() with %+0d"},
	{test0_14, "_fmtspec_collect() with %-d"},
	{test0_15, "_fmtspec_collect() with %-0d"},
	{test0_16, "_fmtspec_collect() with %-+0d"},
	{test0_17, "_fmtspec_collect() with %b"},
	{test0_18, "_fmtspec_collect() with %p"},
	{test0_19, "_fmtspec_collect() with %*d"},
	{test1_0, "svsnprintf() with empty string (size=0)"},
	{test1_0_1, "svsnprintf() with empty string"},
	{test1_0_2, "svsnprintf() with empty string(str=NULL)"},
	{test1_0_3, "svsnprintf() with some text(str=NULL)"},
	{test1_0_4, "svsnprintf() with NULL fmt(size = 0)"},
	{test1_0_5, "svsnprintf() with NULL fmt"},
	{test1_0_6, "svsnprintf() with some text(size = 0, with NULL)"},
	{test1_0_7, "svsnprintf() with some text(size = 8, with NULL)"},
	{test1_0_8, "svsnprintf() with some text(with NULL)"},
	{test1_1, "svsnprintf() without spec (size=0)"},
	{test1_2, "svsnprintf() with single % (size=0)"},
	{test1_2_1, "svsnprintf() with single %"},
	{test1_3, "svsnprintf() with %% (size=0)"},
	{test1_3_1, "svsnprintf() with %% (size=0)"},
	{test1_3_2, "svsnprintf() with %% (size=0)"},
	{test1_3_3, "svsnprintf() with %% (size=0)"},
	{test1_3_4, "svsnprintf() with %%"},
	{test1_4, "svsnprintf() with %d (size=0)"},
	{test1_4_1, "svsnprintf() with %d (=-5, size=0)"},
	{test2_4, "svsnprintf() with %d"},
	{test2_4_1, "svsnprintf() with %d"},
	{test2_4_2, "svsnprintf() with %d"},
	{test2_4_3, "svsnprintf() with %d"},
	{test2_4_4, "svsnprintf() with %d(=0)"},
	{test2_5, "svsnprintf() with %hhd"},
	{test2_6, "svsnprintf() with %hd"},
	{test2_7, "svsnprintf() with %d"},
	{test2_8, "svsnprintf() with %ld"},
	{test2_9, "svsnprintf() with %lld"},
	{test2_10, "svsnprintf() with %hhu"},
	{test2_11, "svsnprintf() with %hu"},
	{test2_12, "svsnprintf() with %u"},
	{test2_13, "svsnprintf() with %lu"},
	{test2_14, "svsnprintf() with %llu"},
	{test2_15, "svsnprintf() with %hhd"},
	{test2_16, "svsnprintf() with %hd"},
	{test2_17, "svsnprintf() with %d"},
	{test2_18, "svsnprintf() with %ld"},
	{test2_19, "svsnprintf() with %lld"},
	{test2_20, "svsnprintf() with %04hhd"},
	{test2_20_1, "svsnprintf() with %04hhd(<0)"},
	{test2_20_2, "svsnprintf() with %04d-%02d-%02d"},
	{test2_21, "svsnprintf() with %.4hhd"},
	{test2_21_1, "svsnprintf() with %.4hhd(<0)"},
	{test2_22, "svsnprintf() with %05.4hhd"},
	{test2_22_1, "svsnprintf() with %04.5hhd"},
	{test2_22_2, "svsnprintf() with %05.4hhd(<0)"},
	{test2_22_3, "svsnprintf() with %04.5hhd(<0)"},
	{test2_22_4, "svsnprintf() with %5.4hhd"},
	{test2_22_5, "svsnprintf() with %4.5hhd"},
	{test2_22_6, "svsnprintf() with %6.4hhd(<0)"},
	{test2_22_7, "svsnprintf() with %4.5hhd(<0)"},
	{test2_23, "svsnprintf() with %+d"},
	{test2_23_1, "svsnprintf() with %+d(<0)"},
	{test2_24, "svsnprintf() with %+04hhd"},
	{test2_24_1, "svsnprintf() with %+05hhd"},
	{test2_24_2, "svsnprintf() with %+04hhd(<0)"},
	{test2_25, "svsnprintf() with %+.4hhd"},
	{test2_25_1, "svsnprintf() with %+.4hhd(<0)"},
	{test2_26, "svsnprintf() with %+05.4hhd"},
	{test2_26_1, "svsnprintf() with %+04.5hhd"},
	{test2_26_2, "svsnprintf() with %+05.4hhd(<0)"},
	{test2_26_3, "svsnprintf() with %+04.5hhd(<0)"},
	{test2_26_4, "svsnprintf() with %+6.4hhd"},
	{test2_26_5, "svsnprintf() with %+4.5hhd"},
	{test2_26_6, "svsnprintf() with %+6.4hhd(<0)"},
	{test2_26_7, "svsnprintf() with %+4.5hhd(<0)"},
	{test2_27, "svsnprintf() with %-d"},
	{test2_27_1, "svsnprintf() with %-15d"},
	{test2_27_2, "svsnprintf() with %-+15d"},
	{test2_27_3, "svsnprintf() with %-5d"},
	{test2_27_4, "svsnprintf() with %-+5d"},
	{test2_27_5, "svsnprintf() with %-15d(<0)"},
	{test2_27_6, "svsnprintf() with %-+.4hhd"},
	{test2_27_7, "svsnprintf() with %-+.4hhd(<0)"},
	{test2_27_8, "svsnprintf() with %-+6.4hhd"},
	{test2_27_9, "svsnprintf() with %-+4.5hhd"},
	{test2_27_10, "svsnprintf() with %-+6.4hhd(<0)"},
	{test2_27_11, "svsnprintf() with %-+4.5hhd(<0)"},
	{test2_28, "svsnprintf() with %-+4.5hhd(<0, size=0)"},
	{test2_29_0, "svsnprintf() with %+6.4hhd(size=3)"},
	{test2_29_1, "svsnprintf() with %+6.4hhd(size=5)"},
	{test2_29_2, "svsnprintf() with %+6.4hhd(size=6)"},
	{test2_29_3, "svsnprintf() with %+6.4hhd(size=7)"},
	{test2_29_4, "svsnprintf() with %6.4hhd(<0, size=7)"},
	{test2_29_5, "svsnprintf() with %+6.4hhd(size=8)"},
	{test2_29_6, "svsnprintf() with %+6.4hhd(size=9)"},
	{test2_29_7, "svsnprintf() with %+6.4hhd(size=10)"},
	{test2_29_8, "svsnprintf() with %+6.4hhd(size=11)"},
	{test2_29_9, "svsnprintf() with %+6.4hhd(size=12)"},
	{test2_29_10, "svsnprintf() with %-+6.4hhd(size=10)"},
	{test2_29_11, "svsnprintf() with %-+6.4hhd(size=11)"},
	{test2_30, "svsnprintf() with %*d(size=0)"},
	{test2_30_1, "svsnprintf() with %*d"},
	{test2_30_2, "svsnprintf() with %0*d"},
	{test2_30_3, "svsnprintf() with %01*d"},
	{test2_30_4, "svsnprintf() with %*0d"},
	{test3_0, "svsnprintf() with %-+6.4hho"},
	{test3_1, "svsnprintf() with %-+6.4ho"},
	{test3_2, "svsnprintf() with %-+6.4o"},
	{test3_3, "svsnprintf() with %-+6.4lo"},
	{test3_4, "svsnprintf() with %-+6.4llo"},
	{test3_5, "svsnprintf() with %-+6.4llo(size=0)"},
	{test4_0, "svsnprintf() with %-+6.4hhx"},
	{test4_1, "svsnprintf() with %-+6.4hx"},
	{test4_2, "svsnprintf() with %-+6.4x"},
	{test4_3, "svsnprintf() with %-+6.4lx"},
	{test4_4, "svsnprintf() with %-+6.4llx"},
	{test4_5, "svsnprintf() with %-+6.4llx(size=0)"},
	{test5_0, "svsnprintf() with %-+6.4hhX"},
	{test5_1, "svsnprintf() with %-+6.4hX"},
	{test5_2, "svsnprintf() with %-+6.4X"},
	{test5_3, "svsnprintf() with %-+6.4lX"},
	{test5_4, "svsnprintf() with %-+6.4llX"},
	{test5_5, "svsnprintf() with %-+6.4llX(size=0)"},
	{test6_0, "svsnprintf() with %-+12.10hhb"},
	{test6_1, "svsnprintf() with %-+6.4hb"},
	{test6_2, "svsnprintf() with %-+6.4b"},
	{test6_3, "svsnprintf() with %-+6.4lb"},
	{test6_4, "svsnprintf() with %-+6.4llb"},
	{test6_5, "svsnprintf() with %-+6.4llb(size=0)"},
	{test7_0, "svsnprintf() with %f"},
	{test7_1, "svsnprintf() with %.0f"},
	{test7_2, "svsnprintf() with %.1f"},
	{test7_3, "svsnprintf() with %.2f"},
	{test7_4, "svsnprintf() with %.3f"},
	{test7_5, "svsnprintf() with %.4f"},
	{test7_6, "svsnprintf() with %07.2f"},
	{test7_6_1, "svsnprintf() with %+07.2f"},
	{test7_7, "svsnprintf() with %7.2f"},
	{test7_7_1, "svsnprintf() with %+7.2f"},
	{test7_7_2, "svsnprintf() with %7.2f(<0)"},
	{test7_8, "svsnprintf() with %-7.2f"},
	{test7_8_1, "svsnprintf() with %-+7.2f"},
	{test7_8_2, "svsnprintf() with %-7.2f(<0)"},
	{test7_9, "svsnprintf() with %-7.2f(size=0)"},
	{test7_10_0, "svsnprintf() with %7.2f(size=4)"},
	{test7_10_1, "svsnprintf() with %7.2f(size=5)"},
	{test7_10_2, "svsnprintf() with %7.2f(size=6)"},
	{test7_10_3, "svsnprintf() with %7.2f(size=7)"},
	{test7_10_4, "svsnprintf() with %7.2f(size=8)"},
	{test7_10_5, "svsnprintf() with %+7.2f(size=6)"},
	{test7_10_6, "svsnprintf() with %+7.2f(size=7)"},
	{test7_10_7, "svsnprintf() with %+7.2f(size=8)"},
	{test7_10_8, "svsnprintf() with %+7.2f(<0, size=8)"},
	{test7_10_9, "svsnprintf() with %+7.2f(size=8)"},
	{test7_10_10, "svsnprintf() with %+7.2f(size=9)"},
	{test7_10_11, "svsnprintf() with %+7.2f(size=10)"},
	{test7_10_12, "svsnprintf() with %+7.2f(size=11)"},
	{test7_10_13, "svsnprintf() with %+7.2f(size=12)"},
	{test7_10_14, "svsnprintf() with %+7.2f(size=13)"},
	{test7_10_15, "svsnprintf() with %-+7.2f(size=12)"},
	{test7_10_16, "svsnprintf() with %-+7.2f(size=13)"},
	{test7_11, "svsnprintf() with %*f(size=0)"},
	{test7_11_1, "svsnprintf() with %*f"},
	{test7_11_2, "svsnprintf() with %0*f"},
	{test7_11_3, "svsnprintf() with %01*f"},
	{test7_11_4, "svsnprintf() with %*0f"},
	{test8_0, "svsnprintf() with %c"},
	{test8_1, "svsnprintf() with %c(size=0)"},
	{test9_0, "svsnprintf() with %s"},
	{test9_1, "svsnprintf() with %s(empty string)"},
	{test9_2, "svsnprintf() with %.2s"},
	{test9_2_1, "svsnprintf() with %.0s"},
	{test9_3, "svsnprintf() with %4.2s"},
	{test9_4, "svsnprintf() with %-4.2s"},
	{test9_5, "svsnprintf() with %-4.2s(size=0)"},
	{test9_6_0, "svsnprintf() with %4.2s(size=4)"},
	{test9_6_1, "svsnprintf() with %4.2s(size=5)"},
	{test9_6_2, "svsnprintf() with %4.2s(size=6)"},
	{test9_6_3, "svsnprintf() with %4.2s(size=7)"},
	{test9_6_4, "svsnprintf() with %4.2s(size=8)"},
	{test9_6_5, "svsnprintf() with %4.2s(size=9)"},
	{test9_6_6, "svsnprintf() with %4.2s(size=10)"},
	{test9_6_7, "svsnprintf() with %-4.2s(size=6)"},
	{test9_6_8, "svsnprintf() with %-4.2s(size=7)"},
	{test9_6_9, "svsnprintf() with %-4.2s(size=8)"},
	{test9_6_10, "svsnprintf() with %-4.2s(size=9)"},
	{test9_6_11, "svsnprintf() with %-4.2s(size=10)"},
	{test9_7, "svsnprintf() with %*s(size=0)"},
	{test9_7_1, "svsnprintf() with %*s"},
	{test9_7_2, "svsnprintf() with %0*s"},
	{test9_7_3, "svsnprintf() with %01*s"},
	{test9_7_4, "svsnprintf() with %*0s"},
	{test10_1, "svsnprintf() with %p"},
	{test11_0, "svsnprintf() with wrong spec (size=0)"},
	{test11_1, "svsnprintf() with wrong spec (size=9)"},
	{test11_2, "svsnprintf() with wrong spec (size=10)"},
	{test11_3, "svsnprintf() with wrong spec (size=11)"},
	{test11_4, "svsnprintf() with wrong spec (size=18)"},
	{test11_5, "svsnprintf() with wrong spec (size=19)"},
	{test11_6, "svsnprintf() with wrong spec"},
	{test12, "fill a buffer"},
	TEST_NULL
};

int
main(int argc, char **argv)
{
	int i, cnt, ret, total = 0;

	for(i = 0; tests[i].test; i++)
		total++;

	for(i = 0, cnt = 0; tests[i].test; i++) {
		fprintf(stderr, "%s:%s... ", argv[0], tests[i].title);
		ret = tests[i].test();
		fprintf(stderr, "%s\n", ret ? "ok" : "fail");
		if (ret)
			cnt++;
	}

	printf("TOTAL %d/%d\n", cnt, total);
	return 0;
}
